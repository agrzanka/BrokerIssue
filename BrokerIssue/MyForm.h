#pragma once
#include "Broker.h"
#include <string>

namespace BrokerIssue {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	Broker broker;
	TransportInput tIn;
	TransportInput tIn2;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 27);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(427, 22);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 67);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(427, 22);
			this->textBox2->TabIndex = 1;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(12, 104);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(427, 22);
			this->textBox3->TabIndex = 2;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(576, 67);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(427, 22);
			this->textBox4->TabIndex = 3;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(576, 112);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(427, 22);
			this->textBox5->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(576, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(54, 17);
			this->label1->TabIndex = 5;
			this->label1->Text = L"alphas:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(576, 92);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"betas:";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(759, 189);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightCoral;
			this->ClientSize = System::Drawing::Size(1061, 269);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}

			 
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		broker.alphaCoefs = { 16,15,14 };
		textBox4->Text = ((broker.alphaCoefs[0]).ToString());
		//while -> textbox.append(--||--)
		//std::vector<std::vector<adjacencyMatrixObject>> adjMatrix(3);
		//for (int i = 0; i < 3; i++)
		//	adjMatrix[i].resize(4);
		std::vector<std::vector<adjacencyMatrixObject>>adjMatrix{ {adjacencyMatrixObject(8,0), adjacencyMatrixObject(14,0),
			adjacencyMatrixObject(17,0), adjacencyMatrixObject(0,0)}, { adjacencyMatrixObject(12,0), adjacencyMatrixObject(9,0),
			adjacencyMatrixObject(19,0), adjacencyMatrixObject(0,0)},{adjacencyMatrixObject(0,0), adjacencyMatrixObject(0,0),
			adjacencyMatrixObject(0,0), adjacencyMatrixObject(0,0)} };

		tIn.adjacencyMatrix = adjMatrix;
		tIn.costOfPurchase = { 10,12 };
		tIn.costOfVending = { 30,25,30 };
		tIn.demand = { 10, 28, 27 };
		tIn.supply = { 20,30 };

		

		//push backi - dodaæ do konstruktora koniecznie!!!
		tIn.demand.push_back(20+30);
		tIn.supply.push_back(10 + 28 + 27);

		tIn.suppliers = { Supplier(), Supplier() };
		tIn.customers = { Customer(), Customer(), Customer() };

		//trzeba utworzyæ rzeczy do drugiego Transport Inputu, ¿eby sprawdziæ, czy konstruktor dobrze dzia³a
		std::vector<Supplier>suppliers = { Supplier(), Supplier() };
		std::vector<Customer>customers = { Customer(), Customer(), Customer() };

		//tIn2 = new TransportInput(suppliers,customers,);

		tIn.calculateFinalCosts();

		tIn.calculateTransportUnits();

		textBox1->Text=("done");
	}
};
}
