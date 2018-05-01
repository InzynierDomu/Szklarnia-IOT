using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel;
using System.IO;
using System.Xml;
using System.Xml.Serialization;

namespace PC_App.Models
{
    [Serializable()]
    public class Defaults : INotifyPropertyChanged
    {
        public Defaults()
        {

        }

        private MQTTConnect defSettingsMQTT;
        public MQTTConnect DefSettingsMQTT
        {
            get { return defSettingsMQTT; }
            set
            {
                if (defSettingsMQTT != value)
                {
                    defSettingsMQTT = value;
                    OnPropertyChanged("DefSettingsMQTT");
                }
            }
        }

        private Settings defGHSettings;
        public Settings DefGHSettings
        {
            get { return defGHSettings; }
            set
            {
                if (defGHSettings != value)
                {
                    defGHSettings = value;
                    OnPropertyChanged("DefGHSettings");
                }
            }
        }

        public void SaveXML(Defaults settings)
        {
            string path = System.IO.Directory.GetCurrentDirectory();
            path += "\\Config\\Defaults.xml";

            XmlSerializer SerializerObj = new XmlSerializer(typeof(Defaults));
            TextWriter WriteFileStream = new StreamWriter(@path);
            SerializerObj.Serialize(WriteFileStream, settings);
            WriteFileStream.Close();
        }

        public Defaults OpenXML()
        {
            Defaults openSettings = new Defaults();
            XmlSerializer DeserializerObj = new XmlSerializer(typeof(Defaults));
            string path = System.IO.Directory.GetCurrentDirectory();
            path += "\\Config\\Defaults.xml";
            FileStream fs = new FileStream(path, FileMode.Open);
            XmlReader reader = XmlReader.Create(fs);
            openSettings = (Defaults)DeserializerObj.Deserialize(reader);
            fs.Close();
            return openSettings;
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
