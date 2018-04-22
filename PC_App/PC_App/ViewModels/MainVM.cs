using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel;
using System.Windows.Controls;
using System.Windows;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Windows.Controls;
using PC_App.Models;
using PC_App.Commands;
//using PC_App.Data;
//using OxyPlot;

namespace PC_App.ViewModels
{
    class MainVM : INotifyPropertyChanged
    {

        #region Objects
        #endregion

        #region Commands
        #endregion

        #region MVVM

        public event PropertyChangedEventHandler PropertyChanged;

        private void OnPropertyChanged(string property)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(property));
            }
        }

    #endregion
    }
}
