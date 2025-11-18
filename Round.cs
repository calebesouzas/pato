
using System.Text.RegularExpressions;

namespace Round
{
    public class Round
    {
	    public static void Run(string code)
        {
            Dictionary<string, dynamic> variables = RoundParser.GetVariables(code);
            // string s_or_n = @"(?:\s+|\n)";
	        string functionPattern = @$"\s*(\w+)\((.*)\)";
            string stringPattern = "(?:\\\"|\\\')(.*)(?:\\\"|\\\')";
	        // string ifStatementPattern = @$"\s*if{s_or_n}(.*){s_or_n}then{s_or_n}(.*)";
            MatchCollection functions = Regex.Matches(code, functionPattern);
            foreach (Match function in functions)
            {
                switch (function.Groups[1].Value)
                {
                    case "print":
                        if (Regex.IsMatch(function.Groups[2].Value, stringPattern))
                        {
                            Console.Write(function.Groups[2].Value.Replace("\\n", "\n"));
                        }
                        if (variables.Keys.Contains(function.Groups[2].Value))
                        {
                            string argument = variables[function.Groups[2].Value.Replace("\\n", "\n")];
                            Console.Write(argument.Replace("\"", ""));
                        }
                        else
                        {
                            Console.WriteLine($"Couldn't find function '{function.Groups[2].Value.Replace("\\n", "\n")}'");
                        }
                        break;
                    default:
                        break;
                }
            }
        }
        public static void RunFunction(string functionName, string? parameters)
        {
            switch (functionName)
            {
                case "print":
		            Console.WriteLine(parameters);
		            break;
            }
        }
    }
}