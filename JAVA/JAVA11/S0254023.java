class Bank{
	public static int money = 10000;
	public synchronized static int reduce(int n){
		int tmp = money;
		tmp = tmp - n;
		try{
			Thread.sleep(((int)(1000*Math.random())));
		}
		catch(InterruptedException e){}
		money = tmp;
		return money;
	}
}
class Customer extends Thread{
	public String id;
	public Customer(String str){
		this.id = str;
	}
	public synchronized void run(){
		for(int i = 1; i <= 8; i++){
			int a = (int)(Math.random()*20)*100;
			Bank.reduce(a);
		if(Bank.money > 0){
				System.out.print( this.id );
			System.out.println( a + "�A�Ѿl: " + Bank.money);
		}
		else{
			System.out.println("�l�B����");
		}
		}
	}
}
public class S0254023{
	public static void main(String Args[]){
		Customer c1 = new Customer("���_���l�����");
		Customer c2 = new Customer("���v�j�l�����");
		c1.start();
		c2.start();
	}
}