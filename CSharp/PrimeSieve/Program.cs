
class PrimeSieve
{
    public static void Main()
    {
        int sieveSize = 1000000;

        DateTime start = DateTime.Now;
        DateTime end;
        TimeSpan dur;
        int passes = 0;
        bool[] isPrime = new bool[sieveSize+1];
        float timeLimit = 5.0f;
        while(true)
        {
            for(int i=1;i<=sieveSize;i+=2)
                isPrime[i] = true;
            int k, currNum;

            isPrime[0] = false;
            isPrime[1] = false;
            isPrime[2] = false;
            
            int upperLimit = (int)Math.Sqrt(sieveSize);
            for(int i=3; i<=upperLimit; i++)
            {
                if(isPrime[i])
                {
                    k = i;
                    while(true)
                    {
                        currNum = i*k;
                        if(currNum>sieveSize)
                            break;

                        isPrime[currNum] = false;
                        k+=2;
                    }
                }
            }
            end = DateTime.Now;
            passes++;
            dur = end-start;

            if(dur.TotalSeconds > timeLimit)
                break;
        }
        
        Console.WriteLine("----------------------------------------------------");
        Console.WriteLine("It ran " + passes + " passes in " + dur.TotalSeconds + " seconds.");
        Console.WriteLine("Performance: " + passes/dur.TotalSeconds+ " passes/sec");
        Console.WriteLine("----------------------------------------------------");
    }
}