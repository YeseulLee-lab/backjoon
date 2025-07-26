public class Example
{
    static int n;
    static int m;
    static bool[][] visited;
    static int[][] map;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    public static void Main(string[] args)
    {
        var sr = new StreamReader(Console.OpenStandardInput());
        var sw = new StreamWriter(Console.OpenStandardOutput());

        string[] size = sr.ReadLine().Split(" ");
        n = int.Parse(size[0]);
        m = int.Parse(size[1]);

        map = new int[n][];
        visited = new bool[n][];
        for (int i = 0; i < n; i++)
        {
            map[i] = new int[m];
            visited[i] = new bool[m];
        }

        for (int i = 0; i < n; i++)
        {
            string str = sr.ReadLine();
            for (int j = 0; j < str.Length; j++)
            {
                map[i][j] = int.Parse(str[j].ToString());
            }
        }

        BFS(0, 0);
        sw.WriteLine(map[n - 1][m - 1]);
        sw.Flush();
    }

    public static void BFS(int startX, int startY)
    {
        Queue<(int, int)> q = new Queue<(int, int)>();
        visited[startX][startY] = true;
        q.Enqueue((startX, startY));

        while (q.Count > 0)
        {
            var (x, y) = q.Dequeue(); 

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny] && map[nx][ny] == 1)
                {
                    q.Enqueue((nx, ny));
                    visited[nx][ny] = true;

                    map[nx][ny] = map[x][y] + 1;
                }
            }
        }
    }
}