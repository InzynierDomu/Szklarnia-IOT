namespace PC_App
{
    using System;
    using System.Collections.Generic;
    using System.ComponentModel.DataAnnotations;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Data.Entity.Spatial;

    [Table("dom_testdb.GreenHouseDB")]
    public partial class GreenHouseDB
    {
        [Key]
        public int No { get; set; }

        public int Temperature { get; set; }

        public int WaterLvl { get; set; }

        public int LightLvl { get; set; }

        public int AirHumidity { get; set; }

        public int Error { get; set; }

        public bool LightStatus { get; set; }

        public bool PumpStatus { get; set; }

        public DateTime DateTime { get; set; }
    }
}
