using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PC_App.Models;
using OxyPlot;
using OxyPlot.Series;

namespace PC_App.ViewModels
{
    class Plot
    {
        public IList<DataPoint> InTemperture { get; private set; }
        public IList<DataPoint> HumLvl { get; private set; }
        public IList<DataPoint> LightLvl { get; private set; }
        public IList<DataPoint> WaterLvl { get; private set; }
        public IList<DataPoint> Lightlvl { get; private set; }
        public IList<DataPoint> LightStatus { get; private set; }


        public Plot(DBconnect Database)
        {
            InTemperture = new List<DataPoint>();
            ConvertPointsTemp(Database);         
        }


        private void ConvertPointsTemp(DBconnect database)
        {          
            foreach (RecordConverted point in database.DatabaseConverted)
            {
                DataPoint tempPoint = new DataPoint(point.No, point.InTemperature);
                InTemperture.Add(tempPoint);
            }
        }
    }
}
