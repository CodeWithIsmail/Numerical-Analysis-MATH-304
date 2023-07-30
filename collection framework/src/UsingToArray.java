import java.lang.reflect.Array;
import java.util.LinkedList;
import java.util.Arrays;
public class UsingToArray {
    public UsingToArray()
    {
        String color[]={"red","green","blue"};

        LinkedList<String>links=new LinkedList<String>(Arrays.asList(color));

        links.addLast("red");
        links.add("pink");
        links.add(3,"cyan");
        links.addFirst("yellow");

        for(String x:links)
        System.out.println(x);

        colors=links.toArray(new String[links.size()]);

    }
}
