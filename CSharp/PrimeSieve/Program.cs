class PrimeSieve
{
    public static void Main()
    {
        int sieveSize = 1000000;

        DateTime start = DateTime.Now;
        DateTime end;
        TimeSpan dur;
        int passes = 0;
        byte[] isPrime = new byte[sieveSize+1];
        float timeLimit = 5.0f;
        while(true)
        {
            for(int i=0; i<sieveSize; i+=2)
            {
                isPrime[i] = 0;
                isPrime[i+1] = 1;
            }
                
            int step,currNum;

            isPrime[1] = 0;
            isPrime[2] = 1;
            
            int upperLimit = (int)Math.Sqrt(sieveSize);
            for(int i=3; i<=upperLimit; i++)
            {
                if(isPrime[i]==1)
                {
                    currNum = i*i;
                    step = 2*i;
                    while(currNum <= sieveSize)
                    {
                        isPrime[currNum] = 0;
                        currNum += step;
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

        uint primeCount = 0;

        for (int i=0; i<=sieveSize; i++)
        {
            primeCount += isPrime[i];
        }
        if(primeCount == 78498)
        {
            Console.WriteLine("And, it's working correctly!");
        } 
        else
        {
           Console.WriteLine("But, it's not working correctly!");
        }

        Console.WriteLine("----------------------------------------------------");
    }
}