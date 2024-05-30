using System.ComponentModel;
using UtadLab3.Mobile.ViewModels;
using Xamarin.Forms;

namespace UtadLab3.Mobile.Views
{
    public partial class ItemDetailPage : ContentPage
    {
        public ItemDetailPage()
        {
            InitializeComponent();
            BindingContext = new ItemDetailViewModel();
        }
    }
}