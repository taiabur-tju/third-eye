using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO.Ports;
using System.Speech.Synthesis;
namespace Project_Aultra
{
    public partial class Form1 : Form
    {
        SerialPort _serialPort;
        SpeechSynthesizer reader;
        delegate void SetTextDelegate(string value); 
        public Form1()
        {

            InitializeComponent();
            button2.Enabled = false;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            _serialPort = new SerialPort();
            reader = new SpeechSynthesizer();
             _serialPort.BaudRate = 9600;
             _serialPort.Parity = Parity.None;
             _serialPort.DataBits = 8;
             _serialPort.ReadTimeout = 500;
             _serialPort.WriteTimeout = 500;
             _serialPort.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);
             txtobj.Visible = false;
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            _serialPort.PortName = comboBox1.Text;
            try
            {
                if (!_serialPort.IsOpen)
                {
                    _serialPort.Open();
                    pictureBox1.Enabled = true;
                    button2.Enabled = true;
                }
            }
            catch
            {
                MessageBox.Show("Error opening the serial port!");
            }

        }
        public void SetText(string value)
        {
            if (InvokeRequired)
                try
                {
                    Invoke(new SetTextDelegate(SetText), value);
                }
                catch { }
            else
                label1.Text = value;
        }

        private void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            string indata = _serialPort.ReadLine();
            SetText(indata);
        }

        private void button2_Click(object sender, EventArgs e)
        {
           
                    _serialPort.Close();
                    pictureBox1.Enabled = false;
                     lblmessage.Text = "Application Paused";
                reader.Pause();
             
        }
        private void label1_TextChanged(object sender, EventArgs e)
        {
            if (int.Parse(label1.Text) <= 100)
            {

                reader.Resume();
                lblmessage.ForeColor = Color.Red;
                lblmessage.Text = "Be carefull an object in front of you";
                reader.SpeakAsync("Be carefull an object in front of you");
                txtobj.Visible = true;
                prgsCM.Value = (int)(int.Parse(label1.Text) /* * 0.25 */ );
              pictureBox1.Enabled = false;
            }
            else
            {
                lblmessage.ForeColor = Color.Green;
                lblmessage.Text = "Go a head";
                pictureBox1.Enabled = true;
                prgsCM.Value = 100;
                txtobj.Visible = false;
                reader.Pause();
            }
        }
        private void button3_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
