
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.Timer;

public class CosmicPixelSim extends JPanel implements ActionListener{
	private static final double FPS = 30.0;
	private static final int DELAY = (int)(1000.0/FPS);
	private static final int XSIZE = 8;
	private static final int YSIZE = 6;
	private static final int PIXELSIZE = 11;
	
	private static final Color[] gradient1 = new Color[] {
		new Color(0, 0, 0),
		// new Color(200, 0, 255),
		new Color(255, 0, 0),
		new Color(255, 190, 0),
		new Color(255, 255, 255)
	};

	private static final Color[] gradient2 = new Color[] {
		new Color(0, 0, 0),
		// new Color(0, 90, 255),
		new Color(0, 255, 0),
		new Color(190, 255, 0),
		new Color(255, 255, 255)
	};

	private static final Color[][] gradients = new Color[][] {gradient1, gradient2};
	
	private final float[][] pixValues = new float[XSIZE][YSIZE];
	private final int[][] pixGradientType = new int[XSIZE][YSIZE];
	
	public static void main(String[] args) {
		JFrame frame = new JFrame("Flip-Ring");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(300, 300);
		frame.setBackground(Color.black);
		frame.add(new CosmicPixelSim());
		frame.setVisible(true);
	}
	
	
	public CosmicPixelSim() {

		Timer drawingTimer = new Timer(DELAY, this);
		drawingTimer.start();

		Thread cosmicThread = new Thread(new cosmicShowers());
		cosmicThread.start();
	
	}

	// get the color from the gradient based on the value of the value, which is between 0 and 1
	Color getColorFromGradient(float val, int gradientTypeIndex) {
		Color[] choosenGradient = gradients[gradientTypeIndex];
		float gradientStepLength = 1.0f/choosenGradient.length;
		int startIndex = Math.min((int)(val * choosenGradient.length), choosenGradient.length-1);
		int stopIndex = Math.min(startIndex+1, choosenGradient.length-1);
		Color startColor = choosenGradient[startIndex];
		Color endColor = choosenGradient[stopIndex];
		float localVal = (val - startIndex*gradientStepLength)/gradientStepLength;
		int colorvalR = (int)(startColor.getRed()*(1-localVal) + endColor.getRed()*localVal);
		int colorvalG = (int)(startColor.getGreen()*(1-localVal) + endColor.getGreen()*localVal);
		int colorvalB = (int)(startColor.getBlue()*(1-localVal) + endColor.getBlue()*localVal);
		return new Color(colorvalR, colorvalG, colorvalB);
	}
	
	@Override
	public void paintComponent(Graphics g) {
		Graphics2D g2 = (Graphics2D)(g);
		g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
		g2.setColor(Color.lightGray);
		g2.fillRect(0, 0, getWidth(), getHeight());

		for( int i = 0; i<XSIZE; i++) {
			for( int j = 0; j<YSIZE; j++) {
				g2.setColor(Color.gray);
				g2.drawRect(i*PIXELSIZE, j*PIXELSIZE, PIXELSIZE, PIXELSIZE);
				g2.setColor(getColorFromGradient(pixValues[i][j], pixGradientType[i][j]));
				g2.fillRect(1+i*PIXELSIZE, 1+j*PIXELSIZE, PIXELSIZE-1, PIXELSIZE-1);
			}
		}
		
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		repaint();
	}

	private class cosmicShowers implements Runnable {
		@Override
		public void run() {
			while(true) {

				// decay the pixels
				for( int i = 0; i<XSIZE; i++) {
					for( int j = 0; j<YSIZE; j++) {
						pixValues[i][j] = pixValues[i][j]*0.95f;
					}
				}

				// add a ray across several pixels
				if( Math.random() < 0.1 ) {
					float rayStartX = (int)(Math.random()*XSIZE);
					float rayStartY = (int)(Math.random()*YSIZE);
					float rayStopX = (int)(Math.random()*XSIZE);
					float rayStopY = (int)(Math.random()*YSIZE);
					float rayLength = (int)(Math.sqrt((rayStopX-rayStartX)*(rayStopX-rayStartX) + (rayStopY-rayStartY)*(rayStopY-rayStartY)))+1;
					int rayGradient = (int)(Math.random()*gradients.length);
					if (rayLength > 2) {
						for( int i = 0; i<rayLength; i++) {
							int x = (int) (rayStartX + (rayStopX-rayStartX)*i/rayLength);
							int y = (int) (rayStartY + (rayStopY-rayStartY)*i/rayLength);
							pixValues[x][y] = 1.0f;
							pixGradientType[x][y] = rayGradient;
						}	
					}
				}
				try {
					Thread.sleep( DELAY );
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		}
		
	}
}
