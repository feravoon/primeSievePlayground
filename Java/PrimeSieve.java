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
        boolean[] isPrime = new boolean[sieveSize+1];
        float timeLimit = 5.0f;
        while(true)
        {
            isPrime = new boolean[sieveSize+1];
            for(int i=1;i<=sieveSize;i+=2)
                isPrime[i] = true;

            int k,currNum;

            isPrime[1] = false;
            isPrime[2] = true;

            int upperLimit = (int)Math.sqrt(sieveSize);
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
            if(isPrime[i])
                primeCount ++;
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