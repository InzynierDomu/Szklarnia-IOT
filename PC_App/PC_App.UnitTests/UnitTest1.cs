using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using PC_App.Models;

namespace PC_App.UnitTests
{
    [TestClass]
    public class MQTTMsgTests
    {
        [TestMethod]
        public void ArrayWithSettingsPrepare_EmptyArrayAndnumerciValue_ArrayWithZeros()
        {
            //Arrange
            var mqttConnect = new MQTTMsg();

            //Act
            var testSettings = new Settings();
            //byte[] testArray = new byte[0];
            //int testValue = 0;
            //var result = mqttConnect.AddToArray(testArray, testValue);

            //Assert
            byte[] testArray = new byte[0];
            //Assert.AreEqual

        }
    }
}
