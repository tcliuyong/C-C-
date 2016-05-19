import java.io.*;
class test
{
public static void main(String[] args) throws IOException
	      {
			        String command="ifconfig";//系统命令哦
					      Runtime r=Runtime.getRuntime();
						        Process p=r.exec(command);
								      BufferedReader br=new BufferedReader(new InputStreamReader(p.getInputStream()));
									        StringBuffer sb=new StringBuffer();
											      String inline;
												        while(null!=(inline=br.readLine())){
															      sb.append(inline).append("\n");
																        }
														      System.out.println(sb.toString());
															        }
}
