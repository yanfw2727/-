public class S0254023{
	public static void main(String Args[]){CScore stu[]=new CScore[5]; 
	stu[0]=new CScore("陳世明",60,88);
	stu[1]=new CScore("張國志",90,80);
	stu[2]=new CScore("蕭博文",80,76);
	stu[3]=new CScore("蔡孟儒",95,65);
	stu[4]=new CScore("鄭鈺雯",66,70);
		for(int i = 0 ; i < 5; i++){
			stu[i].stuAvg();
			}
		stu[0].showMax(stu);
	}
	}
abstract class Score {
   protected String name;
   protected int math;
   protected int eng;
   public abstract void stuAvg();
}
class CScore extends Score{
	public CScore(String str, int m, int e){
		this.name = str;
		this.math = m;
		this.eng = e;
	
	}
	public void stuAvg(){
		double avg = (math + eng)/2;
		System.out.println(name + ", " + avg);
	}
	public void showMax(CScore c[]){
		int eMax = 0, mMax = 0;
		for(int i = 0; i < c.length; i ++){
			if( c[i].eng > eMax){
				eMax = c[i].eng;
				}
			if( c[i].math > mMax){
				mMax = c[i].math;
				}
			}
		System.out.println("math highest score: " + mMax);
		System.out.println("english highest score: " + eMax);
		}
		}