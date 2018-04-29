using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PC_App.Models
{
    class DBconnect
    {
        public DBconnect()
        {
            GHDataBase DBobject = new GHDataBase();
            

            Database = DBobject.GreenHouseDBs.ToList<GreenHouseDB>();
            DatabaseConverted = DatabaseConvert(Database);
        }

        public List<GreenHouseDB> Database { get; set; }
        public List<RecordConverted> DatabaseConverted { get; set; }

        private List<RecordConverted> DatabaseConvert(List<GreenHouseDB> databaseToConvert)
        {
            List<RecordConverted> DatabaseConverting = new List<RecordConverted>();

            foreach (GreenHouseDB row in databaseToConvert)
            {
                DatabaseConverting.Add(RowConvert(row));
            }

            return DatabaseConverting;
        }

        private RecordConverted RowConvert(GreenHouseDB row)
        {
            RecordConverted recordConverted = new RecordConverted();

            recordConverted.No = row.No;
            recordConverted.measuredTime = row.DateTime;
            recordConverted.InTemperature = row.Temperature / 1000.0;
            recordConverted.InHumidity = row.AirHumidity;
            recordConverted.InWaterLvl = row.WaterLvl;
            recordConverted.Outlight = row.LightLvl;
            recordConverted.SoilHumidity = 0;
            recordConverted.ErrorNumber = row.Error;
            recordConverted.LightStatus = row.LightStatus;
            recordConverted.PumpStatus = row.PumpStatus;

            return recordConverted;
        }
    }

    class RecordConverted
    {
        public int No { get; set; }
        public double InTemperature { get; set; }
        public int InHumidity { get; set; }
        public int InWaterLvl { get; set; }
        public int Outlight { get; set; }
        public int SoilHumidity { get; set; }
        public int ErrorNumber { get; set; }
        public bool LightStatus { get; set; }
        public bool PumpStatus { get; set; }
        public DateTime measuredTime { get; set; }
    }
}


