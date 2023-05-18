import java.time.Instant;
import java.time.Duration;

class PrimeSieve
{
    public static void main(String args[])
    {
        int sieveSize = 1000000;

        Instant start = Instant.now();
        Instant end;
        Duration dur;
        int passes = 0;
        byte[] isPrime = new byte[sieveSize+1];
        float timeLimit = 5.0f;
        while(true)
        {
            for(int i=0;i<sieveSize;i+=2)
            {
                isPrime[i] = 0;
                isPrime[i+1] = 1;
            }
            int currNum;

            isPrime[0] = 0;
            isPrime[1] = 0;
            isPrime[2] = 1;

            int upperLimit = (int)Math.sqrt(sieveSize);
            for(int i=3; i<=upperLimit; i++)
            {
                if(isPrime[i]==1)
                {
                    currNum = i*i;
                    while(currNum <= sieveSize)
                    {
                        isPrime[currNum] = 0;
                        currNum+=2*i;
                    }
                }
            }
            end = Instant.now();
            passes++;
            dur = Duration.between(start, end);

            if((dur.getSeconds() + dur.getNano()/1000000000.0) > timeLimit)
                break;
        }
        System.out.println("----------------------------------------------------");
        System.out.println("It ran " + passes + " passes in " + (dur.getSeconds() + dur.getNano()/1000000000.0)  + " seconds.");
        System.out.println("Performance: " + (passes/(dur.getSeconds() + dur.getNano()/1000000000.0)) + " passes/sec");

        int primeCount = 0;

        for (int i=0; i<=sieveSize; i++)
        {
            primeCount += isPrime[i];
        }
        if(primeCount == 78498)
        {
            System.out.println("And, it's working correctly!");
        } 
        else
        {
            System.out.println("But, it's not working correctly!");
        }

        System.out.println("----------------------------------------------------");
    }
}