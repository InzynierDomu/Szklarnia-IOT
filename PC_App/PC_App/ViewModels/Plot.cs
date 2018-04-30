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
        public IList<DataPoint> SoilHumLvl { get; private set; }
        public IList<DataPoint> LightStatus { get; private set; }
        


        public Plot(DBconnect Database)
        {
            InTemperture = new List<DataPoint>();
            HumLvl = new List<DataPoint>();
            LightLvl = new List<DataPoint>();
            WaterLvl = new List<DataPoint>();
            SoilHumLvl = new List<DataPoint>();
            LightStatus = new List<DataPoint>();
            ConvertPointsTemp(Database);         
        }


        private void ConvertPointsTemp(DBconnect database)
        {          
            foreach (RecordConverted point in database.DatabaseConverted)
            {
                DataPoint tempPoint = new DataPoint(point.No, point.InTemperature);
                InTemperture.Add(tempPoint);

                DataPoint HumPoint = new DataPoint(point.No, point.InHumidity);
                HumLvl.Add(HumPoint);

                DataPoint LightLvlPoint = new DataPoint(point.No, point.Outlight);
                LightLvl.Add(LightLvlPoint);

                DataPoint WaterPoint = new DataPoint(point.No, point.InWaterLvl);
                WaterLvl.Add(WaterPoint);

                DataPoint SoilHumPoints = new DataPoint(point.No, point.SoilHumidity);
                SoilHumLvl.Add(SoilHumPoints);

                DataPoint LightStatusPoint = new DataPoint(point.No, Convert.ToInt16(point.LightStatus) * 100);
                LightStatus.Add(LightStatusPoint);

            }
        }
    }
}
