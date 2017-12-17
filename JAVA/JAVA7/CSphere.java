public class CSphere{

	double pi = 3.14159;

	private int x; 
	private int y; 
	private int z; 
	private int radius; 
	
	public CSphere(){
		this(0, 0, 0, 0);
		}
	public CSphere(int x, int y, int z, int radius){
		this.x = x;
		this.y = y;
		this.z = z;
		this.radius = radius;
		}
	public void setLocation(int x, int y, int z) {
		this.x = x;
		this.y = y;
		this.z = z;
		}
	public void setRadius(int radius){
		this.radius = radius;
		}
	public double surfaceArea() {
		return 4*pi*radius*radius;
		}
	public double volume() {
		return 4*pi*radius*radius*radius/3;
		}
	public void showCenter(){
		System.out.println("x = " + x + ",y =" + y + ",z =" + z);
		}
	}