using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel;
using uPLibrary.Networking.M2Mqtt;

namespace PC_App.Models
{
    public class MQTTConnect : INotifyPropertyChanged
    {
        private MqttClient client;

        private string user;
        public string User
        {
            get { return user; }
            set
            {
                if (user != value)
                {
                    user = value;
                    OnPropertyChanged("User");
                }
            }
        }

        private string server;
        public string Server
        {
            get { return server; }
            set
            {
                if (server != value)
                {
                    server = value;
                    OnPropertyChanged("Server");
                }
            }
        }

        private string pass;
        public string Pass
        {
            get { return pass; }
            set
            {
                if (pass != value)
                {
                    pass = value;
                    OnPropertyChanged("Pass");
                }
            }
        }

        private int port;
        public int Port
        {
            get { return port; }
            set
            {
                if (port != value)
                {
                    port = value;
                    OnPropertyChanged("Port");
                }
            }
        }

        //public int PortSSL = 22156;


        private string topicToSend;
        public string TopicToSend
        {
            get { return topicToSend; }
            set
            {
                if (topicToSend != value)
                {
                    topicToSend = value;
                    OnPropertyChanged("TopicToSend");
                }
            }
        }

        public MQTTConnect()
        {

        }

        public void Reset()
        {
            MsgSend('1', TopicToSend);
        }

        public void SendMeasurement()
        {
            MsgSend('2', TopicToSend);
        }

        public void ChangeLight()
        {
            MsgSend('3', TopicToSend);
        }

        public void Pump()
        {
            MsgSend('4', TopicToSend);
        }

        public void ClearErrors()
        {
            MsgSend('5', TopicToSend);
        }

        public void SendSettings(Settings settings)
        {
            string topic = TopicToSend + "/settings";
            this.client = new MqttClient(server, port, false, null, null, MqttSslProtocols.None);
            byte code = this.client.Connect(Guid.NewGuid().ToString(), user, pass);
            byte[] msg = new byte[7];

            msg[0] = Convert.ToByte(settings.MinTemp);
            msg[1] = Convert.ToByte(settings.MaxTemp);
            msg[2] = Convert.ToByte(settings.MinLight);
            msg[3] = Convert.ToByte(settings.MinHumSoil);
            msg[4] = Convert.ToByte(settings.MinWaterLvl);
            msg[5] = Convert.ToByte(settings.Start);
            msg[6] = Convert.ToByte(settings.Stop);

            this.client.Publish(topic, msg);
        }

        private void MsgSend(char toSend, string topic)
        {
            this.client = new MqttClient(server, port, false, null, null, MqttSslProtocols.None);

            byte code = this.client.Connect(Guid.NewGuid().ToString(), user, pass);
            byte[] msg = new byte[1];
            msg[0] = Convert.ToByte(toSend);
            this.client.Publish(topic, msg);
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
