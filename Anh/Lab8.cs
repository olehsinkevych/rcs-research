using System;
using System.Collections.Generic;
using System.IO;
using System.Management;
using Microsoft.Win32;

namespace OSLab7
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> lines = new List<string>();
            string root = "HKEY_LOCAL_MACHINE\\HARDWARE\\DESCRIPTION\\System";
            var biosName = Registry.GetValue(root, "SystemBiosVersion", "None");
            lines.Add("Your BIOS info:");
            foreach (string str in (string[])biosName)
                lines.Add(str);
            lines.Add("Your Processor info:");
            int cores = 1;
            var proc0 = Registry.GetValue(root+"\\CentralProcessor\\0", "ProcessorNameString", "None");
            lines.Add(proc0.ToString());
            while (Registry.GetValue(root + "\\CentralProcessor\\"+cores, "ProcessorNameString", null) != null)
            {
                cores++;
            }
            lines.Add("You have "+cores+" virtual cores.");
            ManagementObjectSearcher searcher = new ManagementObjectSearcher("select * from Win32_PhysicalMemory");
            foreach (ManagementObject share in searcher.Get())
            {
                string mfc = "";
                long gb=0, speed = 0;
                foreach (PropertyData pd in share.Properties)
                {
                    if (pd.Name == "ConfiguredClockSpeed")
                        speed = Convert.ToInt32(pd.Value);
                    else if (pd.Name == "Capacity")
                        gb = Convert.ToInt64(pd.Value) / 1024L / 1024 / 1024;
                    else if (pd.Name == "Manufacturer")
                        mfc = (string)pd.Value;
                }
                lines.Add(string.Format("You have a {0} DDR-{1} memory of {2}GB", mfc, speed, gb));
            }
            File.WriteAllLines("result.txt", lines);
            foreach (string line in lines)
                Console.WriteLine(line);
            Console.Read();
        }
    }
}
