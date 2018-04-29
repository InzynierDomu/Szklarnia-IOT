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
        }

        public List<GreenHouseDB> Database { get; set; }
    }
}
