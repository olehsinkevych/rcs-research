using System;
using System.IO;
using System.Collections.Generic;
using Microsoft.Win32;

namespace WinInfo
{
    public class regRead
    {
       public static void Main()
        {
            List<string> getInfo = new List<string>(10);
                RegistryKey key = Registry.LocalMachine.OpenSubKey("HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0");                
                Object o = key.GetValue("ProcessorNameString");
                getInfo.Add("Processor: " + o.ToString());
                //========================================

                key = Registry.LocalMachine.OpenSubKey("HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0");
                o = key.GetValue("~MHz");
                getInfo.Add( "Processor Speed: " + o);
                //========================================

                key = Registry.LocalMachine.OpenSubKey("HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\5");
                o = key.GetValue("ProcessorBoost");
                getInfo.Add( "Boost Speed: " + o);

            //==========================================
                key = Registry.LocalMachine.OpenSubKey("HARDWARE\\DESCRIPTION\\System\\BIOS");
                o = key.GetValue("SystemVersion");
                getInfo.Add("Compuetr Name: " + o);
                //========================================

                File.WriteAllLines("D:\\info.txt", getInfo);
        }
    }
}
