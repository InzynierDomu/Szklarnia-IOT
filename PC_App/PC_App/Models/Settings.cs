using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel;

namespace PC_App.Models
{
    public class Settings : INotifyPropertyChanged
    {
        public Settings()
        {

        }

        private double minTemp;
        public double MinTemp
        {
            get { return minTemp; }
            set
            {
                if (minTemp != value)
                {
                    minTemp = value;
                    OnPropertyChanged("MinTemp");
                }
            }
        }

        private double maxTemp;
        public double MaxTemp
        {
            get { return maxTemp; }
            set
            {
                if (maxTemp != value)
                {
                    maxTemp = value;
                    OnPropertyChanged("MaxTemp");
                }
            }
        }

        private SByte minLight;
        public SByte MinLight
        {
            get { return minLight; }
            set
            {
                if (minLight != value)
                {
                    minLight = value;
                    OnPropertyChanged("MinLight");
                }
            }
        }

        private SByte minHumSoil;
        public SByte MinHumSoil
        {
            get { return minHumSoil; }
            set
            {
                if (minHumSoil != value)
                {
                    minHumSoil = value;
                    OnPropertyChanged("MinHumSoil");
                }
            }
        }

        private SByte minWaterLvl;
        public SByte MinWaterLvl
        {
            get { return minWaterLvl; }
            set
            {
                if (minWaterLvl != value)
                {
                    minWaterLvl = value;
                    OnPropertyChanged("MinWaterLvl");
                }
            }
        }

        private DateTime start;
        public DateTime Start
        {
            get { return start; }
            set
            {
                if (start != value)
                {
                    start = value;
                    OnPropertyChanged("Start");
                }
            }
        }

        private DateTime stop;
        public DateTime Stop
        {
            get { return stop; }
            set
            {
                if (stop != value)
                {
                    stop = value;
                    OnPropertyChanged("Stop");
                }
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
        private void OnPropertyChanged(string property)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(property));
            }
        }
    }
}
