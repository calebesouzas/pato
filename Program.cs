using System;
using System.IO;
using System.Net;
using System.Security.Cryptography.X509Certificates;
using System.Text.RegularExpressions;

namespace Round
{
    class Program
    {
		static void Main(string[] args)
		{
	    	string roundFile = args.Length > 0 ? File.ReadAllText(args[0]) : "";
	    	// Console.WriteLine(roundFile);
	    	Round.Run(roundFile);
		}
    }
}