import java.util.*;

class Job {
    int id;
    int deadline;
    int profit;

    Job(int id, int deadline, int profit) {
        this.id = id;
        this.deadline = deadline;
        this.profit = profit;
    }
}

public class Main {

    public static void jobSchedule(List<Job> jobs) {
        int cntJob = 0;
        int totalProfit = 0;
        int n = jobs.size();

        // Find maximum deadline
        int maxDeadline = 0;
        for (Job job : jobs) {
            maxDeadline = Math.max(maxDeadline, job.deadline);
        }

        // Max heap based on profit
        PriorityQueue<Job> pq = new PriorityQueue<>(
                (a, b) -> b.profit - a.profit
        );

        pq.addAll(jobs);

        int[] hash = new int[maxDeadline];

        while (!pq.isEmpty()) {
            Job job = pq.poll();

            for (int i = job.deadline - 1; i >= 0; i--) {
                if (hash[i] == 0) {
                    cntJob++;
                    totalProfit += job.profit;
                    hash[i] = 1;
                    break;
                }
            }
        }

        System.out.println("total jobs scheduled: " + cntJob);
        System.out.println("total profit: " + totalProfit);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        List<Job> jobs = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            int id = sc.nextInt();
            int deadline = sc.nextInt();
            int profit = sc.nextInt();
            jobs.add(new Job(id, deadline, profit));
        }

        jobSchedule(jobs);
    }
}
