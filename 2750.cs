public class Example
{
    public static void Main(string[] args)
    {
        var sr = new StreamReader(Console.OpenStandardInput());
        var sw = new StreamWriter(Console.OpenStandardOutput());

        int n = int.Parse(sr.ReadLine());

        int[] arr = new int[n];

        for (int i = 0; i < arr.Length; i++)
        {
            arr[i] = int.Parse(sr.ReadLine());
        }

        Array.Sort(arr);

        for (int i = 0; i < arr.Length; i++)
        {
            sw.WriteLine(arr[i]);
            sw.Flush();
        }
    }
}