#include &lt;iostream&gt;
#include &lt;cstdlib&gt;
#include &lt;ctime&gt;

using namespace std;

int main() {
    srand(time(0));
    cout &lt;&lt; "Random numbers:" &lt;&lt; endl;
    for(int i = 0; i &lt; 5; i++) {
        cout &lt;&lt; rand() % 100 &lt;&lt; endl;
    }
    cout &lt;&lt; "Another set:" &lt;&lt; endl;
    for(int i = 0; i &lt; 5; i++) {
        cout &lt;&lt; rand() % 100 &lt;&lt; endl;
    }
    cout &lt;&lt; "More random:" &lt;&lt; endl;
    for(int i = 0; i &lt; 5; i++) {
        cout &lt;&lt; rand() % 100 &lt;&lt; endl;
    }
    cout &lt;&lt; "End of random code." &lt;&lt; endl;
    return 0;
}