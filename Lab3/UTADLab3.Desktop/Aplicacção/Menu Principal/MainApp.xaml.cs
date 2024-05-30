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

namespace Avaliacao1Lab3.Aplicacção.Menu_Principal
{
    /// <summary>
    /// Interaction logic for MainApp.xaml
    /// </summary>
    public partial class MainApp : Window
    {
        public MainApp()
        {
            InitializeComponent();
        }

        private void RemoveButton1_Click(object sender, RoutedEventArgs e)
        {

        }

        private void EditContentButton_Click(object sender, RoutedEventArgs e)
        {
            Aplicacção.InsideList.InsideList infowindow = new Aplicacção.InsideList.InsideList();
            infowindow.Show();
            this.Close();
        }

        private void ListBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {

        }

        private void Settings_Button_Click(object sender, RoutedEventArgs e)
        {
            ProfileEditor.SettingsScreen.SettingsScreen infowindow = new ProfileEditor.SettingsScreen.SettingsScreen();
            infowindow.Show();
            this.Close();
        }
    }
}
