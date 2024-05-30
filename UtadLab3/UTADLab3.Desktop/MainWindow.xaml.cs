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
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Configuration;

namespace Avaliacao1Lab3
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    
  public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        

        private void LoginButton1_Click(object sender, RoutedEventArgs e)
        {
             LoginScreen infowindow = new LoginScreen();
            infowindow.Show();
            this.Close();
        }

        private void RegisterButton_click(object sender, RoutedEventArgs e)
        {
            RegisterScreen infowindow = new RegisterScreen();
            infowindow.Show();
            this.Close();
        }

        private void ExitButtonMain_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }
    }

   



}
