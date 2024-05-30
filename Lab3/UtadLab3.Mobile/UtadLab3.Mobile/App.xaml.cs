using System;
using UtadLab3.Mobile.Services;
using UtadLab3.Mobile.Views;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace UtadLab3.Mobile
{
    public partial class App : Application
    {

        public App()
        {
            InitializeComponent();

            DependencyService.Register<MockDataStore>();
            MainPage = new AppShell();
        }

        protected override void OnStart()
        {
        }

        protected override void OnSleep()
        {
        }

        protected override void OnResume()
        {
        }
    }
}
