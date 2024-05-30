using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace Avaliacao1Lab3
{
    /// <summary>
    /// Interaction logic for LoginScreen.xaml
    /// </summary>
    public partial class LoginScreen : Window
    {
        public LoginScreen()
        {
            InitializeComponent();
        }

        private void BackButtonLogin_Click(object sender, RoutedEventArgs e)
        {
            MainWindow infowindow = new MainWindow();
            infowindow.Show();
            this.Close();
        }

        private void LoginButton_Click(object sender, RoutedEventArgs e)
        {
            Aplicacção.Menu_Principal.MainApp infowindow = new Aplicacção.Menu_Principal.MainApp();
            infowindow.Show();
            this.Close();
        }
    }
}
