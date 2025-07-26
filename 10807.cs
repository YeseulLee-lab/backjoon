public class Example
{
    public static void Main(string[] args)
    {
        var sw = new StreamWriter(Console.OpenStandardOutput());
        var sr = new StreamReader(Console.OpenStandardInput());

        int n = int.Parse(sr.ReadLine());

        string str = sr.ReadLine();
        string[] newstr = str.Split(" ");

        int v = int.Parse(sr.ReadLine());

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            if (int.Parse(newstr[i].ToString()) == v)
            {
                result++;
            }
        }

        sw.WriteLine(result);
        sw.Flush();
    }
}