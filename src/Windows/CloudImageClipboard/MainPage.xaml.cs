namespace CloudImageClipboard
{
    using System;
    using System.Collections.Generic;
    using System.Net.Http;
    using System.Net.Mime;
    using System.Text;
    using Windows.ApplicationModel.DataTransfer;
    using Windows.Storage.Streams;
    using Microsoft.Graph;
    using Windows.UI.Xaml;
    using Windows.UI.Xaml.Controls;
    using Windows.UI.Xaml.Input;
    using Windows.UI.Xaml.Media;
    using Windows.UI.Xaml.Media.Imaging;
    using Windows.UI.Xaml.Navigation;
    using Microsoft.IdentityModel.Tokens;
    using Newtonsoft.Json;
    using Newtonsoft.Json.Linq;

    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        private MainPageViewModel viewModel;

        public MainPage()
        {
            this.InitializeComponent();
        }

        protected override async void OnNavigatedTo(NavigationEventArgs e)
        {
            GraphServiceClient client = AuthenticationHelper.GetAuthenticatedClient();
            var allActivities = await client.Me.Activities.Recent().Request().GetAsync();
            this.viewModel = new MainPageViewModel();
            foreach (var activity in allActivities.CurrentPage)
            {
                string imageUrl = activity.ContentInfo["imageUrl"].ToString();
                viewModel.Images.Add(new CloudImageViewModel(imageUrl));
            }

            this.DataContext = viewModel;
        }

        private void OnLoginClicked(object sender, RoutedEventArgs e)
        {
            GraphServiceClient client = AuthenticationHelper.GetAuthenticatedClient();
        }

        private void OnLogoutClicked(object sender, RoutedEventArgs e)
        {
            AuthenticationHelper.SignOut();
        }

        private void UIElement_OnTapped(object sender, TappedRoutedEventArgs e)
        {
            Windows.UI.Xaml.Controls.Image cloudImage = sender as Windows.UI.Xaml.Controls.Image;
            CloudImageViewModel cloudImageViewModel = cloudImage.DataContext as CloudImageViewModel;
            DataPackage package = new DataPackage();
            package.SetBitmap(RandomAccessStreamReference.CreateFromUri(new Uri(cloudImageViewModel.ImageUrl)));
            Clipboard.SetContent(package);
        }

        private async void OnAddImageClicked(object sender, RoutedEventArgs e)
        {
            DataPackageView package = Clipboard.GetContent();
            string imageUrl = string.Empty;
            if (package.Contains(StandardDataFormats.Text))
            {
                imageUrl = await package.GetTextAsync();
            }
            else if (package.Contains(StandardDataFormats.ApplicationLink))
            {
                Uri imageUri = await package.GetWebLinkAsync();
                imageUrl = imageUri.AbsoluteUri;
            }

            GraphServiceClient client = AuthenticationHelper.GetAuthenticatedClient();
            var requestBuilder = client.Me.Activities.Request();
            UserActivity activity = new UserActivity()
            {
                ActivationUrl = "blah",
                ActivitySourceHost = "studiovn.life",
                AppActivityId = Base64UrlEncoder.Encode(imageUrl),
                VisualElements = new VisualInfo()
                {
                    DisplayText = "Test"
                },
                ContentInfo = new JObject()
            };
            activity.VisualElements.DisplayText = "Test";
            activity.ContentInfo["imageUrl"] = imageUrl;

            var result = await requestBuilder.AddUserActivityAsync(activity);

            this.viewModel.Images.Insert(0, new CloudImageViewModel(imageUrl));
        }

        private async void OnDeleteImagesClicked(object sender, RoutedEventArgs e)
        {
            GraphServiceClient client = AuthenticationHelper.GetAuthenticatedClient();
            var allActivities = await client.Me.Activities.Request().GetAsync();
            var requestBuilder = client.Me.Activities.Request();
            HttpClient httpClient = new HttpClient();
            foreach (var activity in allActivities.CurrentPage)
            {
                var requestMessage = requestBuilder.GetHttpRequestMessage();
                requestMessage.Method = HttpMethod.Delete;
                requestMessage.RequestUri = new Uri(requestMessage.RequestUri.AbsoluteUri + $"/{activity.AppActivityId}");
                requestMessage.Headers.Add("Authorization", $"Bearer {AuthenticationHelper.TokenForUser}");
                //var response1 = await httpClient.SendAsync(requestMessage);
                var response2 = await client.HttpProvider.SendAsync(requestMessage);
            }

        }
    }
}
