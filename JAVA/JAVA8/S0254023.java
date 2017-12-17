public class S0254023{
	public static void main(String Args[]){
		CSphere c1 = new CSphere(7, 4, 5, 2.0);
		CSphere c2 = new CSphere(6, 2, 8, 3.0);
		c1.isIntersect(c1, c2);
	}
}
class CSphere{
	private  int x;
	private  int y;
	private  int z;
	private  double radius;

	public CSphere(int a, int b, int c, double r){
		this.x = a;
		this.y = b;
		this.z = c;
		this.radius = r;
	}

	public  double distance(CSphere c1, CSphere c2){
		double dis;
		int tmpx = c1.x-c2.x;
		int tmpy = c1.y-c2.y;
		int tmpz = c1.z-c2.z;
		tmpx = tmpx*tmpx;
		tmpy = tmpy*tmpy;
		tmpz = tmpz*tmpz;
		dis = Math.sqrt(tmpx + tmpy + tmpz);
		System.out.println(dis);
		return dis;
	}
	public  void isIntersect(CSphere c1, CSphere c2) {
		double dis = distance(c1,c2);
		double disr = c1.radius + c2.radius;
		
		if(dis > disr){
			System.out.println("兩球未接觸");
		}
		else{
			System.out.println("兩球有接觸");
		}
	}
}
