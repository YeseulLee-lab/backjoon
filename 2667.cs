public class Example
{
    static int n;
    static bool[][] visited;
    static int[][] map;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int aptIdx = 0;
    static List<int> apt = new List<int>();

    public static void Main(string[] args)
    {
        var sr = new StreamReader(Console.OpenStandardInput());
        var sw = new StreamWriter(Console.OpenStandardOutput());

        n = int.Parse(sr.ReadLine());
        
        map = new int[n][];
        visited = new bool[n][];
        for (int i = 0; i < n; i++)
        {
            string str = sr.ReadLine();
            map[i] = new int[n];
            visited[i] = new bool[n];
            for (int j = 0; j < str.Length; j++)
            {
                map[i][j] = int.Parse(str[j].ToString());
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && map[i][j] == 1)
                {
                    apt.Add(1);
                    BFS(i, j);
                    aptIdx++;
                }
            }
        }

        sw.WriteLine(apt.Count);
        apt.Sort();
        for (int i = 0; i < apt.Count; i++)
        {
            sw.WriteLine(apt[i]);
        }
        sw.Flush();
    }

    public static void BFS(int startX, int startY)
    {
        Queue<(int, int)> q = new Queue<(int, int)>();
        q.Enqueue((startX, startY));
        visited[startX][startY] = true;

        while (q.Count > 0)
        {
            var (x, y) = q.Dequeue();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n)
                {
                    if (!visited[nx][ny] && map[nx][ny] == 1)
                    {
                        q.Enqueue((nx, ny));
                        visited[nx][ny] = true;
                        apt[aptIdx]++;
                    }
                }
            }
        }
        
    }
}