using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using PC_App.Models;
using OxyPlot;

namespace PC_App.ViewModels
{
    class Plot
    {
        public IList<DataPoint> TempLvlPoints { get; private set; }
        public IList<DataPoint> HumLvlPoints { get; private set; }
        public IList<DataPoint> LightLvlPoints { get; private set; }
        public IList<DataPoint> WaterLvlPoints { get; private set; }
        public IList<DataPoint> LightPoints { get; private set; }


        public Plot(DBconnect Database)
        {
            TempLvlPoints = new List<DataPoint>();
            //ConvertPointsTemp(Database);
        }

        //public void ConvertPointsTemp(DBconnect database)
        //{
        //    //Points.Clear();
        //    foreach (temp point in database.Database)
        //    {
        //        DataPoint tempPoint = new DataPoint(point.Id, point.temperature);
        //        Points.Add(tempPoint);
        //    }
        //}
    }
}
