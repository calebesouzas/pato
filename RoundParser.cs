using System.Text.RegularExpressions;
namespace Round
{
    public class RoundParser
    {
        public static Dictionary<string, dynamic> GetVariables(string code)
	    {
	        string stringPattern = "(?:\\\"|\\\')(.*)(?:\\\"|\\\')";
	        // variablePattern groups explaination:
	        /* First: catches variable name (one or more alphanumeric and underscore characters)
	         * Second: catches type, like 'var_name: string'... This one is optional
	         * Third: gets the string, integer or float in it */
	        string variablePattern = @$"(\w+):\s*(string|int|float)\s*=\s*({stringPattern}|\d+|\d+\.\d+)";

	        MatchCollection getVariables = Regex.Matches(code, variablePattern);
	        Dictionary<string, dynamic> variables = [];
	        foreach (Match match in getVariables)
            {
                variables.Add(match.Groups[1].Value, match.Groups[3].Value);
            }
	        return variables;
	    }
    }
}