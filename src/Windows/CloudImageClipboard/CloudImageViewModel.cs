namespace CloudImageClipboard
{
    using System.ComponentModel;
    using System.Runtime.CompilerServices;
    using Annotations;

    class CloudImageViewModel: INotifyPropertyChanged
    {
        private string imageUrl;

        public event PropertyChangedEventHandler PropertyChanged;

        public string ImageUrl
        {
            get
            {
                return imageUrl;
            }
            set
            {
                if (!string.Equals(value, imageUrl))
                {
                    imageUrl = value;
                    OnPropertyChanged(nameof(ImageUrl));
                }
            }
        }

        public CloudImageViewModel(string imageUrl)
        {
            this.imageUrl = imageUrl;
        }

        [NotifyPropertyChangedInvocator]
        protected virtual void OnPropertyChanged([CallerMemberName] string propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }
}
