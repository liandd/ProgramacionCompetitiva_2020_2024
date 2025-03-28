import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;
import java.util.Scanner;

public class morass {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        String s = scanner.nextLine();
        scanner.close();

        for(int i=0;i<666;++i){
            s = s.replace("()", "(1)");
            s = s.replace("))", ")+1)");
            s = s.replace(")(", ")*(");
        }

        ScriptEngineManager manager = new ScriptEngineManager();
        ScriptEngine engine = manager.getEngineByName("JavaScript");
        try{
            Object result = engine.eval(s);
            System.out.println(result);
        }catch (ScriptException e){
        
        }
    }
}
