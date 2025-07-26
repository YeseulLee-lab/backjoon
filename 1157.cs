public class Example
{
    public static void Main(string[] args)
    {
        var sr = new StreamReader(Console.OpenStandardInput());
        var sw = new StreamWriter(Console.OpenStandardOutput());

        string str = sr.ReadLine();
        str = str.ToLower();

        int[] chars = new int[26];

        for (int i = 0; i < 26; i++)
        {
            chars[i] = 0;
        }

        for (int i = 0; i < str.Length; i++)
        {
            chars[str[i] - 'a']++;
        }

        string result = "";
        int max = 0;
        for (int i = 0; i < 26; i++)
        {
            if (chars[i] > max)
            {
                max = chars[i];
                result = ((char)(i + 'A')).ToString();
            }
            else if(chars[i] == max)
            {
                result = "?";
            }
        }

        sw.WriteLine(result);
        sw.Flush();
    }
}