namespace PC_App
{
    using System;
    using System.Data.Entity;
    using System.ComponentModel.DataAnnotations.Schema;
    using System.Linq;

    public partial class GHDataBase : DbContext
    {
        public GHDataBase()
            : base("name=GHDataBase")
        {
        }

        public virtual DbSet<GreenHouseDB> GreenHouseDBs { get; set; }

        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
        }
    }
}
