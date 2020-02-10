package mainStack;

import java.awt.EventQueue;
import java.awt.Font;

import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

import java.awt.GridLayout;

import javax.swing.border.MatteBorder;

import java.awt.Color;
import java.util.EmptyStackException;
import java.util.Stack;

import javax.swing.SwingConstants;
import javax.swing.border.TitledBorder;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JTextArea;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

@SuppressWarnings("serial")
public class StackSimulationFrame extends JFrame 
{
	private JPanel contentPane;
	
	Stack<Integer> stack = new Stack<Integer>();
	private JPanel stackPanel;
	
	private JPanel pushPane;
	
	Font times = new Font("TimesNewroman", Font.BOLD, 15);
	int top;
	private JTextField txtPush;
	private JButton btnPop;
	private JPanel dataPane;
	private JLabel lblNewLabel;
	private JTextField txtTop;
	private JPanel outputPane;
	private JLabel lblStack;
	private JLabel lblDevelopedByc;
	
	public static void main(String[] args) 
	{
		EventQueue.invokeLater(new Runnable() 
		{
			public void run() 
			{
				try 
				{
					StackSimulationFrame frame = null;
					String m = JOptionPane.showInputDialog(frame,"Please Tell Stack Size");
					int MAX_SIZE = Integer.parseInt(m);
					frame = new StackSimulationFrame(MAX_SIZE);
					frame.setVisible(true);
				} 
				catch (Exception e) 
				{
					e.printStackTrace();
				}
			}
		});
	}
	public StackSimulationFrame(int MAX) 
	{
		JTextField tf[] = new JTextField[MAX];
		top = MAX-1;
		setTitle("Stack Simulation in an Array");
		setResizable(false);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 618, 488);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JMenuBar mbr = new JMenuBar();
		setJMenuBar(mbr);
		JMenu file = new JMenu("File");
		mbr.add(file);
		
		JMenuItem infoxToPostfix = new JMenuItem("Infix to PostFix");
		file.add(infoxToPostfix);
		
		JMenuItem close = new JMenuItem("Close...!!");
		file.add(close);
		
		JMenu help = new JMenu("Help");
		mbr.add(help);
		
		JMenuItem about = new JMenuItem("About ©");
		help.add(about);
		
		JMenuItem helpContent = new JMenuItem("Help Content");
		help.add(helpContent);
		
		infoxToPostfix.addActionListener(new ActionListener() 
		{
			public void actionPerformed(ActionEvent arg0) 
			{
				InfixPostfix i = new InfixPostfix();
				i.setVisible(true);
			}
		});
		
		stackPanel = new JPanel();
		stackPanel.setBorder(new MatteBorder(0, 5, 5, 5, (Color) new Color(0, 0, 0)));
		stackPanel.setBounds(486, 27, 99, 353);
		contentPane.add(stackPanel);
		stackPanel.setLayout(new GridLayout(0,1));
		
		pushPane = new JPanel();
		pushPane.setBorder(new TitledBorder(new MatteBorder(2, 3, 2, 3, (Color) new Color(0, 0, 0)), 
				"Push", TitledBorder.LEADING, TitledBorder.TOP, times, null));
		pushPane.setBounds(27, 27, 244, 113);
		contentPane.add(pushPane);
		pushPane.setLayout(null);
		
		txtPush = new JTextField();
		txtPush.setFont(new Font("Courier New", Font.BOLD, 14));
		txtPush.setHorizontalAlignment(SwingConstants.CENTER);
		txtPush.setBounds(10, 30, 224, 26);
		pushPane.add(txtPush);
		txtPush.setColumns(10);
		
		JButton btnPush = new JButton("Push");
		btnPush.setFont(new Font("Courier New", Font.BOLD, 15));
		btnPush.setBounds(58, 67, 105, 35);
		pushPane.add(btnPush);
		
		btnPop = new JButton("Pop");
		btnPop.setFont(new Font("Courier New", Font.BOLD, 15));
		btnPop.setBounds(330, 113, 105, 35);
		contentPane.add(btnPop);
		
		dataPane = new JPanel();
		dataPane.setBorder(new MatteBorder(2, 3, 2, 3, (Color) new Color(0, 0, 0)));
		dataPane.setBounds(27, 151, 295, 95);
		contentPane.add(dataPane);
		dataPane.setLayout(null);
		
		lblNewLabel = new JLabel("Peek of Stack: ");
		lblNewLabel.setFont(new Font("Courier New", Font.BOLD, 13));
		lblNewLabel.setBounds(10, 29, 136, 30);
		dataPane.add(lblNewLabel);
		
		txtTop = new JTextField();
		txtTop.setEditable(false);
		txtTop.setHorizontalAlignment(SwingConstants.CENTER);
		txtTop.setFont(new Font("Courier New", Font.BOLD, 14));
		txtTop.setColumns(10);
		txtTop.setBounds(156, 32, 122, 26);
		dataPane.add(txtTop);
		
		outputPane = new JPanel();
		outputPane.setBorder(new MatteBorder(2, 1, 2, 1, (Color) new Color(0, 0, 0)));
		outputPane.setBounds(27, 257, 408, 119);
		contentPane.add(outputPane);
		outputPane.setLayout(null);
		
		JTextArea taOutput = new JTextArea();
		taOutput.setEditable(false);
		taOutput.setFont(new Font("Courier New", Font.PLAIN, 14));
		taOutput.setBounds(10, 11, 388, 97);
		outputPane.add(taOutput);
		
		JScrollPane jspTa = new JScrollPane(taOutput);
		outputPane.add(jspTa);
		jspTa.setBounds(10, 11, 388, 97);
		
		lblStack = new JLabel("Stack: ");
		lblStack.setFont(new Font("Courier New", Font.BOLD, 13));
		lblStack.setBounds(401, 27, 75, 30);
		contentPane.add(lblStack);
		
		lblDevelopedByc = new JLabel("Developed by (c) Bilal Hungund");
		lblDevelopedByc.setHorizontalAlignment(SwingConstants.RIGHT);
		lblDevelopedByc.setFont(new Font("Courier New", Font.BOLD, 13));
		lblDevelopedByc.setBounds(341, 400, 244, 30);
		contentPane.add(lblDevelopedByc);
		
		for (int i = 0; i < tf.length; i++) 
		{
			tf[i] = new JTextField();
			tf[i].setEditable(false);
			tf[i].setFont(new Font("Courier New", Font.BOLD, 15));
			tf[i].setHorizontalAlignment(SwingConstants.CENTER);
			stackPanel.add(tf[i]);
			stackPanel.validate();
		}

		btnPush.addActionListener(new ActionListener() 
		{
			public void actionPerformed(ActionEvent arg0) 
			{
				int item = Integer.parseInt(txtPush.getText());
				stack.push(item);
				tf[top].setText(Integer.toString(item));
				top--;
				txtPush.setText("");
				taOutput.append("Item Pushed: "+item+"\n");
				txtTop.setText(Integer.toString((int) stack.peek()));			
			}
		});

		btnPop.addActionListener(new ActionListener() 
		{
			public void actionPerformed(ActionEvent arg0) 
			{
				try
				{
					int item = (int) stack.pop();
					tf[top+1].setText(" ");
					top++;
					if(stack.isEmpty())
						throw new EmptyStackException();
					taOutput.append("Item Popped: "+item+"\n");
					txtTop.setText(Integer.toString((int) stack.peek()));
				}
				catch(EmptyStackException e)
				{
					String exc = e.toString();
					taOutput.append(exc+"\n");
				}
			}
		});

		txtPush.addKeyListener(new KeyAdapter() 
		{
			public void keyPressed(KeyEvent arg0) 
			{
				if(arg0.getKeyCode() == KeyEvent.VK_ENTER)
				{
					int item = Integer.parseInt(txtPush.getText());
					stack.push(item);
					tf[top].setText(Integer.toString(item));
					top--;
					txtPush.setText("");
					taOutput.append("Item Pushed: "+item+"\n");
					txtTop.setText(Integer.toString((int) stack.peek()));
				}
				if(arg0.getKeyCode()== KeyEvent.VK_F1)
				{
					try
					{
						int item = (int) stack.pop();
						tf[top+1].setText(" ");
						top++;
						if(stack.isEmpty())
							throw new EmptyStackException();
						taOutput.append("Item Popped: "+item+"\n");
						txtTop.setText(Integer.toString((int) stack.peek()));
					}
					catch(EmptyStackException e)
					{
						String exc = e.toString();
						taOutput.append(exc+"\n");
					}
				}
			}
		});
	}
}