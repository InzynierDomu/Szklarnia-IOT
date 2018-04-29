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
        public MainVM()
        {
            Mqtt = new MQTTConnect();
            Database = new DBconnect();
            Chart = new Plot(Database);

            SendGHLightChange = new Command(lightChange);
            SendGHPump = new Command(pump);
            SendGHRestart = new Command(restart);
            SendGHClearErrors = new Command(clearerrors);
        }

        #region Objects

        private MQTTConnect _mqtt;
        public MQTTConnect Mqtt
        {
            get { return _mqtt; }
            set { _mqtt = value; OnPropertyChanged("Mqtt"); }
        }

        private DBconnect _database;
        public DBconnect Database
        {
            get { return _database; }
            set { _database = value; OnPropertyChanged("Database"); }
        }

        private Plot _chart;
        public Plot Chart
        {
            get { return _chart; }
            set { _chart = value; OnPropertyChanged("Chart"); }
        }

        #endregion

        #region Commands
        public Command SendGHLightChange { get; set; }
        private void lightChange()
        {
            Mqtt.ChangeLight();
        }

        public Command SendGHPump { get; set; }
        private void pump()
        {
            Mqtt.Pump();
        }

        public Command SendGHRestart { get; set; }
        private void restart()
        {
            Mqtt.Reset();
        }

        public Command SendGHClearErrors { get; set; }
        private void clearerrors()
        {
            Mqtt.ClearErrors();
        }
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
