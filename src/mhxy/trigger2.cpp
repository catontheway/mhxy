#include "global.h"


BOOL cTaskZhuXian::Process(int stage)
{
	Init();
	switch (m_Chapter)
	{
	case 0:return Process0(stage);
	case 1:return Process1(stage);
	case 2:return Process2(stage);
	case 3:return Process3(stage);
	case 4:return Process4(stage);
	case 5:return Process5(stage);
	case 6:return Process6(stage);
	case 7:return Process7(stage);
	case 8:return Process8(stage);
	case 9:return Process9(stage);
	}
	ERRBOX;
	return FALSE;
}

BOOL cTaskZhuXian::Process0(int stage)
{
	switch (stage)
	{
	case -1:break;
	case 106://����
		AddTriggerDialog2(17, 107); break;
	case 107:
		Select(54, 57, -1, 55, -1, 56, 109); break;
	case 109:
		AddTriggerDialog2(18, 110);
		break;
	case 110:
		
		{
			SetINT(12,3);
			cPet* Pet4 = 0;
			sAddPoint addpoint;
			addpoint.Set(4, 0, 0, 1, 0);
			g_pMainState->MakeAPet(Pet4, e������, 100, 14, addpoint);
			g_pMainState->GivePcAPet(0, Pet4);
			RemoveTriggerObjMap(106);
			RemoveNpc(53, TRUE);
		}
		break;
	case 0:
		
		{
			SetChapter(0);
			g_pMainState->m_GlobalButton[0] = 80;
			g_pMainState->m_GlobalButton[6] = 0;
			g_pMainState->m_GlobalButton[5] = 0;
			g_pMainState->m_GlobalButton[4] = 0;

			g_pMainState->LoadCharacterData2(g_pMainState->m_HeroID, "����");
			g_pMainState->SetCharacter(g_pMainState->m_HeroID);
			g_pCharacter->m_PCData.m_Controler.Set(0, 0);
			g_pHeroObj->Reset();
			g_pHeroObj->Set(POS_STAND);
			g_pCharacter->m_PCData.m_Money[0] = 10000;
			g_pMainState->m_Map.LoadMap(25, 139, "������", FALSE);

		

			//g_pCharacter->m_PCData.GetShangPinPet(6);
		//	g_pMainState->GivePcAPet(g_pMainState->m_HeroID,);
			//g_pCharacter->m_PCData.GetShangPinPet(6);
			//g_pCharacter->m_PCData.Followlv(170);
			////g_pMainState->m_Friend.AddFriend("������");
			//g_pCharacter->m_PCData.m_Money[0] = 200000000;
			//Invite("����");
			//Invite("������");
			//g_pMainState->m_Friend.AddFriend("����");
			///*int id = g_pMainState->m_Friend.FindFriend("С��");
			//g_pMainState->m_Friend.m_FriendList[id].m_dataFileName = "С��2";*/
			//Invite("����");
			//	g_pMainState->m_Friend.AddFriend("���");
			//	
			//	int id = g_pMainState->m_Friend.FindFriend("���");
			//	g_pMainState->m_Friend.m_FriendList[id].m_dataFileName = "���2";
			//	Invite("���");
			//	g_pMainState->m_Friend.AddFriend("����");
			//	Invite("����");
			//	SetJiangLi2(0, 9999999);
			//	SetChapter(9);
			//	Process9(1);
			//	return TRUE;
			/*for (int i = 6; i < 11; i++)
				SetJiangLiItem(i, 27);*/
			//g_pCharacter->m_PCData.GoldLivePercent.d1 = 100;

			//g_pMainState->m_Map.Load(521, 124, "������");
			//g_pMainState->m_Map.LoadMap(56, 44, "���ܵظ�");
			//return Process9(0);

			/*sItem2 item;
			item.m_Num = 1;
			for (int i = 10; i < 20; i++)
			{
				item.Set(24, i);
				g_pMainState->m_InterfaceItem.GetItem(g_pMainState->m_HeroID, &item);
			}*/
			/*SetChapter(5);
			Process5(17);
			return TRUE;*/
			g_pMainState->SetDialogList(m_Textlist[1], 0xB0212A04);
			TalkList(15, 21, 7, 38, 101); //�λþ���
			AddChannel(m_Textlist[38]);
			g_pMainState->m_ZhiXian2.Process(0);
		}
		return TRUE;
	case 36:
		for (int i = 0; i < 3; i++)
		{
			AddFriend(48 + i);
		}
		TalkList(20, 66, 67, 43, 38, 34);//��66����֮��67�������߲�45����7�� case 38 ��
		break;
	case 34:
		{
			int id;
			for (int i = 0; i<3; i++)
			{
				AutoGetPet(m_Textlist[48 + i], 1);//48 49 50 ���� �ϲ� ����
				g_pMainState->m_Friend.Invite(m_Textlist[48 + i]);
				
			}
			id = g_pMainState->m_Friend.FindFriend("��ܽ");
			g_pMainState->m_Friend.m_FriendList[id].m_dataFileName = "��ܽ2";
			if (id > -1)g_pMainState->m_Friend.Invite("��ܽ");
			g_pMainState->m_Map.RemoveNpc(g_pMainState->m_pNowSelect, 1);
			RemoveTriggerObjMap();
			RemoveNpc(40, TRUE);
			
		}
		break;

	case 38:
			AddTriggerDialog2(25);//��л���� ������
			UpdateJob2(68);//������35
			//SetJiangLi(30,1,0,50,200,200);
			SetJiangLi2(80000, 10000, 200000, 80000, TRUE);//����֮����SetJiangLi2(50000, 10000, 150000, 50000, TRUE)
			AddTriggerLv(37, 30);//������35 ��������37
			RemoveTriggerObj();
			break;
	case 37:
		{	
			SetChapter(1);
			Process(0);
		}
		break;
	case 105:
		g_pMainState->m_TaskNormal.Process(4);
		g_pMainState->m_Channel.AddNewString(m_Textlist[39]);
		break;
	
	case 101://��������
		{
			g_pMainState->m_DialogList.clear();
			NowNpcTalk(m_Textlist[20]);
			AddChannel(m_Textlist[2]);
			UpdateJob2(20);
			AddTriggerObj(m_Textlist[3], m_Textlist[4], 1);
			cPet* Pet4 = 0;
			sAddPoint addpoint;
			addpoint.Set(4, 0, 0, 1, 0);
			g_pMainState->MakeAPet(Pet4, 6, 100, 10, addpoint);
			g_pMainState->GivePcAPet(0, Pet4);
		}
		return TRUE;
	case 1: //�ҵ�������
		{
			NowNpcTalk(m_Textlist[5]);
			AddTriggerObj(m_Textlist[6], m_Textlist[7], 2);
			UpdateJob2(5);
			AddChannel(m_Textlist[46]);
		}
		return FALSE;
	case 2://�ҵ�װ��������
		{
			cObj* pob = g_pMainState->FindObjByName(m_Textlist[6]);
			pob->Talk(m_Textlist[8]);
			for (int i = 0; i < 60; i++)
			{
				if (g_pCharacter->m_PCData.m_Item[i].GetNum())
				if (g_pCharacter->m_PCData.m_Item[i].GetType() == eWeaponType��)
				{
					g_pMainState->m_ItemManage.AutoItemProperty(&g_pCharacter->m_PCData.m_Item[i]);
					break;
				}
			}
			AddChannel(m_Textlist[9]);
			RemoveTriggerObj();
			AddTriggerLv(3, 5);
			UpdateJob2(9);
			AddTriggerFightStart(6);
			AddTriggerFightSuccess(105);
		}
		return FALSE;
	case 3: //��ܽ����
		{
			sNpc npc;
			npc.Set("��ܽ", "��������", 2002, 14, 53,0);
			AddTriggerObjMap(&npc, 4);
			g_pMainState->m_Dialog.Talk(m_Textlist[10], m_Textlist[1], 0xB0212A04);
			UpdateJob2(10);
		}
		return TRUE;
	case 4: AddTriggerDialog2(0, 5); break;
	case 5:
		{
			
			AddTag(11);
			RemoveNpc(40,TRUE);
			g_pMainState->m_Friend.AddFriend("��ܽ");
			//����ܽ���BB
			AutoGetPet("��ܽ",0);
			g_pMainState->m_Friend.Invite("��ܽ");
			RemoveTriggerObjMap();
			AddTriggerLv(7, 8);
			g_pMainState->FindObj();
			
			AddTriggerDialog2(21, -5);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case -5:
		AddChannel(m_Textlist[47]);
		return TRUE;
	case 6:
		{
			g_pMainState->m_TriggerFightStart.ReMove(this);
			AddTag(12);
			AddChannel(m_Textlist[12]);
		}
		return TRUE;
	case 7:AddTriggerDialog2( 1, 8); break;
	case 8:
		{
			AddTriggerObj(m_Textlist[15], m_Textlist[16], 9);
			UpdateJob2(14);
		}
		return TRUE;
	case 9:
		
		{
			AddTriggerDialog2( 2,10);
		}
		return TRUE;
	case 10:
		
		{
			sNpc npc;
			npc.Set(m_Textlist[53], m_Textlist[7], 2009, 110, 54, 1);
			AddTriggerObjMap(&npc, 106,FALSE);

			//AddTriggerObjMap(&npc, 4);
			UpdateJob2(70);
			AddTriggerObjMap(m_Textlist[7], 11,FALSE);
		}
		return TRUE;
	case 11:
		AddTriggerDialog2( 3, 12);
		break;
	case 12:
		RemoveTriggerObjMap(11);
		AddTriggerObj("ţ��", m_Textlist[7], 43);
		return TRUE;
	case 43:
		AddTriggerDialog2(27, 44);
		return TRUE;
	case 44://���׺���
		RemoveTriggerObjMap(43);
		UpdateJob2(73);
		AddTriggerObj("�׺���", m_Textlist[7], 45);
		return TRUE;
	case 45:
		AddTriggerDialog2(28, 46);
		return TRUE;
	case 46: //����ս��
	{
				 cPetData* petdata = AddPetEnemy2(2000, e��, 15, 74);
				 SetMusic();
				 g_StateType = STATE_FIGHT;
				 AddTriggerFightSuccess(47);
	}
		return TRUE;
	case 47://���ƽ���
	{
				SetJiangLi2(1000, 2000, 5000, 2000, TRUE);
				AddTriggerObj("�׺���", m_Textlist[7], 48);
				UpdateJob2(74);
	}
		return TRUE;
	case 48:
		AddTriggerDialog2(29);
		RemoveTriggerObjMap(45);
		UpdateJob2(17);
		AddTriggerObjMap(m_Textlist[18], 13, FALSE);
		return TRUE;
	case 13:AddTriggerDialog2(4, -14); break;
	case -14:
		
		{
			AddTriggerFightFalse(-15);//
			AddTriggerFightEscape(-15);//
		}
	case 14://����BOSSս
		
		{
			cPetData* petdata = AddPetEnemy2(2000, eҰ��, 12, 58);
			petdata->AddSkill(ePS_����);
			petdata->AddSkill(ePS_��Ѫ);
			petdata->AddSkill(ePS_����);
			//petdata->m_CounterRate.d1 = 20;
			//petdata->m_Combo.d1 = 50;
			//petdata->m_Pierce.d1 = 20;

			g_pMainState->m_Mp3.Load("ս��BOSS");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(15);		
			AddTriggerDialog2(22, -1);
		}
		return TRUE;
	case -15:
		
		{
			RemoveTriggerObjMap();
			AddTriggerObj("���˵Ĺ��", m_Textlist[18], 14); break;//ս��ʧ��
		}
		break;
	case 15://���˵Ĺ�꽱��
		
		{
			SetJiangLi2(5000, 10000, 50000, 10000, TRUE);
			RemoveTriggerObjMap();
			AddTriggerDialog2( 5, 16);
			g_pMainState->m_GlobalButton[14]+= 200;
			g_pMainState->m_GlobalButton[15] += 200;
			UpdateJob2(29);
			RemoveTriggerObj();
			g_pCharacter->m_PCData.AddHpZZ(100);
			g_pCharacter->m_PCData.AddAtkZZ(50);
			g_pCharacter->m_PCData.AddGrowing(1);
		}
		return TRUE;
	case 16:
		AddTag(44);
		AddTriggerObjMap("������", 49, FALSE);
		//AddTriggerObj("������", "������", 49);
		return TRUE;
	case 49:AddTriggerDialog2(30, 50); return TRUE;
	case 50://ȥ�ҳ�����
		RemoveTriggerObjMap(49);
		UpdateJob2(76);
		AddTriggerObj("������", "������", 51);
		return TRUE;
	case 51:
		AddTriggerDialog2(31, 52);
		return TRUE;
	case 52://��С��
		RemoveTriggerObjMap(51);
		UpdateJob2(77);
		AddTriggerObj("С��", m_Textlist[7], 53);
		return TRUE;
	case 53:
		AddTriggerDialog2(32, 54);
		return TRUE;
	case 54:
		RemoveTriggerObjMap(53);
		//UpdateJob2(78);
		AddTriggerObj("������", "������", 55);
		return TRUE;
	case 55:
		AddTriggerDialog2(33, 56);
		return TRUE;
	case 56://����
		RemoveTriggerObj();
		SetJiangLi2(1000, 1000, 50000, 2000, TRUE);
		AddTriggerObj2(15, 16, 17);
		return TRUE;
	case 17:
		RemoveTriggerObj();
		if (!CheckINT(12,3))
			AddTriggerDialog2( 6, 18);
		else
			AddTriggerDialog2( 19, 18);
		return TRUE;
	case 18://���˵Ĺ�����
		
		{
			AddTag(22);
			UpdateJob2(28);
			AddTriggerObjMap(m_Textlist[23], 19);
			g_pMainState->LockLv(45);
			g_pMainState->m_Map.SetLock();
			sNpc npc;
			npc.Set(m_Textlist[52], m_Textlist[7], 2011, 92, 49,1);
			AddTriggerObjMap(&npc, -18);
			AddTriggerDialog2(23);
		}
		return TRUE;
	case -18:TalkList(16,-1,-1,-1,-1); break;
	case 19:AddTriggerDialog2(7, 20); 
		RemoveTriggerObjMap();
		break;
	case 20://
		
		{
			g_pMainState->m_Friend.UnInvite("��ܽ");
			AddTriggerObjMap2(48, 23, 2007, 473, 26, 3, -20);
			UpdateJob2(69);
			g_pMainState->m_Map.ShadowNpc(m_Textlist[27], FALSE, FALSE);
		}
		return TRUE;
	case -20:
		TalkList(26, 27, 23, 26, 23);
		RemoveTriggerObjMap();
		g_pMainState->m_Map.ShadowNpc(m_Textlist[27], TRUE, TRUE);
		return TRUE;
	case 23:AddTriggerDialog2( 9, 24); break;
	case 24:
		
		{
			RemoveTriggerObj();
	//	AddTriggerObj(m_Textlist[30], m_Textlist[31], 25);
	//	UpdateJob2(51);
	//	return TRUE;
	//case 25://��ʦ
	//	AddTag(32);
	//	g_pMainState->m_Channel.AddNewString(m_Textlist[33]);
	//	g_pCharacter->m_PCData.m_MengPaiID = 6;
		LockMap();
		LockMap(FALSE);
	/*	SetJiangLiItem(0, 27, 30);
		SetJiangLiItem(12, 28, 3);
		AddChannel(m_Textlist[45]);*/
		g_pMainState->m_FangWu.SetGuiMo(0);
		UpdateJob2(37);
	
			sMapObjTrigger npc;
			npc = g_pMainState->m_Friend.m_FriendList[g_pMainState->m_Friend.FindFriend("��ܽ")];
			npc.m_Npc.m_mapname = "������";
			npc.m_pTask = this;
			npc.m_Stage = 36;
			npc.m_Npc.Set(444, 245);
			AddTriggerObjMap(&npc);
			LockMap();
		}
		break;
	default:
		ERRBOX;
		return TRUE;
	}
	return TRUE;
}

void cTaskJuQing::UpdateJob2(string text)
{
	UpdateJob(text, "����");
}

void cTaskJuQing::UpdateJob2(int id)
{
	if (id == -1)
		g_pMainState->m_Job.ReMoveJob(this);
	else
		UpdateJob2(m_Textlist[id]);
}

BOOL cTaskZhuXian::Process1(int stage)
{
	switch (stage)
	{
	case -1:return TRUE;
	case 0:AddTriggerDialog2(0, 1); break;
	case 1://���ϼ�����
		UnInvite("����");
		UnInvite("����");
		UnInvite("�ϲ�");
		RemoveTriggerObj();
		UpdateJob2(85);
		AddTriggerObj2(86, 87, 2);
		g_pMainState->LockLv(45);
		g_pMainState->m_GlobalButton[4] = 1;
		break;
	case 2:
		AddTriggerDialog2(52, 3);
		UpdateJob2(91);
		return TRUE;//����֮��Ի�
	case 3:
	{
			  sNpc npc;
			  npc.Set(m_Textlist[90], "����ɽ", e���, 25, 18, 1, 2);
			  AddTriggerObjMap(&npc, 4, FALSE);
	}
		return TRUE;
	case 4:AddTriggerDialog2(53, 5); break;
	case 5:
		RemoveTriggerObjMap(4);
		RemoveNpc(90, TRUE);
		AddTriggerObj("�ϻ�С��", "����ɽ", 6);
		UpdateJob2(88);
		break;
	case 6:	
		AddTriggerDialog2(54, 7); 
		break;
	case 7: //�ϻ�С��ս��
	{
				cPetData* pPet = AddPCPetEnemy2(3000, e�ϻ�, 30, eMP_ʨ����, 89);
				pPet->AddSkill(ePS_�߼�����); pPet->AddSkill(ePS_�߼�����); pPet->m_MagicNumAdd += 1;
				pPet->m_StartMagic.d1 = 145;
				for (int i = 0; i < 4; i++)
				{
					AddPCPetEnemy2(1500, e��ͷ��, 25, (eMengPai)(rand() % 12), 93);
				}
				SetMusic();
				g_StateType = STATE_FIGHT;
				AddTriggerFightSuccess(8);
	}
		break;
	case 8:
	{
			   AddTriggerDialog2(56, -9);
			   cPetData* pPet;
			   pPet= AddPCPetEnemy2(3000, e������Գ, 35, eMP_���ƹٸ�, 92);
			   pPet->AddSkill(ePS_�߼�����); pPet->AddSkill(ePS_�߼�����); pPet->m_MagicNumAdd += 1; pPet->m_SuckBloodRate.d1 += 10; pPet->SetJinJie(2);
			   pPet = AddPCPetEnemy2(3000, e�ϻ�, 30, eMP_ʨ����, 89);
			   pPet->AddSkill(ePS_�߼�����); pPet->AddSkill(ePS_�߼�����); pPet->m_MagicNumAdd += 1;pPet->m_StartMagic.d1 = 145;
			   for (int i = 0; i < 2; i++)
			   {
				   ePetID petid;
				   switch (rand() % 3)
				   {
				   case 0:petid = e��;
					   break;
				   case 1:petid = e����;
					   break;
				   default:petid = e����;
					   break;
				   }
				   AddPCPetEnemy2(1500, petid,30, (eMengPai)(rand() % 12), 93);
			   }
			   SetMusic();
			   g_StateType = STATE_FIGHT;
			   AddTriggerFightSuccess(9);
	}
		return TRUE;
	case -9:
		AddTriggerDialog2(55);
		break;
	case 9://����������

	{
			   SetJiangLi2(100000, 20000, 500000, 200000, TRUE);
			   AddTriggerDialog2(57, 10);
			   g_pCharacter->m_PCData.AddDefZZ(50);
			   g_pCharacter->m_PCData.AddGrowing(1);
			   g_pMainState->LockLv(55);
	}
		return TRUE;
	case 10:

	{
			  UpdateJob2(94);
			  AddTriggerObj("��ҽ��", "����ɽ", 11);
	}
		break;
	case 11://��ҽ��
		AddTriggerDialog2(60);
		AddTriggerGive("��ҽ��", 22, 24, 13);
		break;
	case 13:
		AddTriggerDialog2(61, 14); break;
	case 14:
		SetJiangLiItem(25, 22); 
		RemoveTriggerObjMap(11); 
		AddTriggerObj("�ϻ�С��", "����ɽ", 15);
		break;
	case 15://�ϻ�С��
		AddTriggerDialog2(59, 16); 
		UpdateJob2(95);
		return TRUE;
	case 16:
	{
		sNpc npc;
		npc.Set("����ɽ�", "����ɽ", e���, 133, 111, 7, 2);
		AddTriggerObjMap(&npc, 17, FALSE);
	}
		return TRUE;
	case 17:
		AddTriggerDialog2(62, 18); 
		RemoveTriggerObjMap(15);
		break;
	case 18:
		RemoveTriggerObjMap(17);
		RemoveNpc(90, TRUE);
		AddTriggerObj("���ù���", "�¹�", 19);
		UpdateJob2(96);
		break;
	case 19:
		AddTriggerDialog2(63, 20);
		UpdateJob2(97);
		return TRUE;
	case 20:
	{
			   sNpc npc;
			   npc.Set("������Ů", "�¹�", e������, 30, 74, 7, 2);
			   AddTriggerObjMap(&npc, 21, FALSE);
	}
		return TRUE;
	case 21:
		AddTriggerDialog2(64, 22);
		UpdateJob2(98);
		RemoveTriggerObjMap(19);
		break;
	case 22:
	{
			  AddTriggerDialog2(65, -22);
			  cPetData* pPet;
			  pPet = AddPCPetEnemy2(2000, e������, 20, eMP_��������, 99);
			  pPet->SetJinJie(2);
			  for (int i = 0; i < 4; i++)
			  {
				  AddPCPetEnemy2(500, e��ө����, 30, (eMengPai)(rand() % 12), 100);
			  }
			  SetMusic();
			  g_StateType = STATE_FIGHT;
			  AddTriggerFightSuccess(23);
	}
		return TRUE;
	case -22:
		AddTriggerDialog2(66);
		break;
	case 23://������Ů����
		SetJiangLi2(10000, 5000, 500000, 20000, TRUE);
		UpdateJob2(101);
		RemoveTriggerObjMap(21);
		RemoveNpc(99, TRUE);
		AddTriggerObj("���ù���", "�¹�", 24);
		break;
	case 24:
		AddTriggerDialog2(67,25);
		break;
	case 25:
		RemoveTriggerObjMap(24);
		AddTriggerObj("����ɽ�", "�칬", 26);
		UpdateJob2(102);
		break;
	case 26:
		g_pMainState->m_Friend.AddFriend("����");
		AddTriggerDialog2(68, -26);
		AddTriggerObj("�콫����", "�칬", 27);
		UpdateJob2(103);
		break;
	case -26:

	{
		g_pMainState->m_Friend.Invite("����");
		RemoveTriggerObjMap();
	}
		break;
	case 27:
		AddTriggerDialog2(69, 28); 
		AddTriggerObj("������", "���ٴ�", 28);
		UpdateJob2(104);
		break;
	case 28:
		AddTriggerDialog2(70, 29);
		AddTriggerObj("ë¿��", "���ٴ�", 29);
		UpdateJob2(105);
		break;
	case 29://ë¿��
		AddTriggerDialog2(71);
		AddTriggerGive("ë¿��", 33, 4, 30);
		break;
	case 30:
		AddTriggerDialog2(61, 14); break;
	case 149999:
		SetJiangLiItem(25, 22);
		RemoveTriggerObjMap(11);
		AddTriggerObj("�ϻ�С��", "����ɽ", 15);
		break;
		/************�ֽ���*************/
		/**
	case 13:
		g_pMainState->m_Friend.AddFriend("���");
		AddTriggerDialog2(8, -13);
		AddTriggerObj2(16, 17, 14);
		UpdateJob2(19);
		break;
	case -13:
		
		{
			g_pMainState->m_Friend.Invite("���");
			RemoveTriggerObjMap();
		}
		break;
	case 14:AddTriggerDialog2(9, 15); break;//�콫
	case 15: 
		
		{
			cPetData* pPet = AddPCPetEnemy2(8000, e�콫, 50, eMP_�칬, 16);
			pPet->m_MagicNumAdd += 1;
			for (int i = 0; i < 4; i++) AddPetEnemy2(3000, e���, 42);
			SetMusic("�ѩǧҹ");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(16);
			
		}
		break;
	case 16:
		AddTriggerObj2(20, 8, 17);
		AddTriggerDialog2(10, -1);
		SetJiangLi2(100000, 20000, 50000, 120000);
		UpdateJob2(18);
		g_pCharacter->m_PCData.AddDefZZ(50);
		g_pCharacter->m_PCData.AddGrowing(1);
		g_pMainState->LockLv(45);
		break;
	case 17:
		AddTriggerDialog2(11, 19);
		break;

	case 19://������
		
		{
			cPetData* pPet = AddPCPetEnemy2(8000, e��������, 48, eMP_����ɽ, 20);
			pPet->SetJinJie(2);
			for (int i = 0; i < 4; i++) AddPetEnemy2(3000, e��������, 40);
			SetMusic();
			
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(20);

		}
		break;
	case 20:
		AddTriggerGive(m_Textlist[12], 22, 44, 21);
		AddTriggerDialog2(12, -1);
		SetJiangLi2(80000, 30000, 5000, 50000);
		UpdateJob2(38);
		g_pMainState->LockLv(45);
		break;
	case 21:
		AddTriggerDialog2(13, -21);
		UpdateJob2(21);
		AddTriggerObj2(22,11,22);
		g_pMainState->m_Friend.AddFriend(m_Textlist[64]);
		break;
	case -21:g_pMainState->m_Friend.Invite(m_Textlist[64]);
		break;

	case 22:AddTriggerDialog2(14, 23);
		break;
	case 23://����2
		
		{
			cPetData* pPet = AddPCPetEnemy2(12000, e��ʦ, 55, eMP_��������, 10);
			pPet->AddSkill(ePS_�߼���������);
			pPet->AddSkill(ePS_�߼�ħ֮��);
			pPet->AddSkill(ePS_�߼���������);
			pPet->AddSkill(ePS_�߼�������);
			pPet->SetJinJie(3);
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 3)
				{
				case 0:petid = eǿ��;
					break;
				default:petid = eǿ��;
					break;
				}
				AddPetEnemy2(6000, petid, 50);
			}
			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(24);
		}
		break;
	case 24:
		TalkList(15, 23, 24, 39, 125);
		SetJiangLi2(150000, 20000, 50000, 250000);
		g_pCharacter->m_PCData.AddAtkZZ(50);
		g_pCharacter->m_PCData.AddHpZZ(100);
		g_pCharacter->m_PCData.AddGrowing(1);
		g_pMainState->LockLv(45);
		break;
	case 125://������Ů
	
		{
			TalkList(49, 75, 76, 77, 126);
			sMapObjTrigger obj;
			obj.m_Npc.Set(m_Textlist[75], m_Textlist[76], e��������è, 84, 59);
			obj.m_Stage = 126;
			obj.m_pTask = this;
			AddTriggerObjMap(&obj);
		}
		break;
	case 126:
		
		{
			AddPCPetEnemy2(6500, e��������è, 50, eMP_ʨ����);
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 3)
				{
				case 0:petid = e����;
					break;
				case 1:petid = e����;
					break;
				default:petid = e���ܾ�;
					break;
				}
				AddPetEnemy2(3000, petid, 39);
			}
			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(127);
		}
		break;
	case 127:
		
		{
		SetJiangLi2(80000, 20000, 50000, 200000);
		AddTriggerObj2(23, 24, 25);
		UpdateJob2(39);
	
		RemoveTriggerObjMap();
		RemoveNpc(81,TRUE);
		g_pMainState->LockLv(45);
		g_pMainState->m_GlobalButton[14] += 200;
		g_pMainState->m_GlobalButton[15] += 200;
		g_pCharacter->m_PCData.AddAtkZZ(50);
		g_pCharacter->m_PCData.AddGrowing(1);
		AddChannel2(82);
		AddChannel2(83);
		sShangPinPet sppet;
		sppet.Set(e��������è, 0, 100, TRUE);
		GetPet(m_Textlist[64], &sppet, 100);
		}
		break;

	case 25://������Ů
		AddFriend(84);
		AddTriggerDialog2(16, -1);
		AddTriggerObj2(25, 26, 26);
		UpdateJob2(27);
		break;
	case 26://����
		AddTriggerDialog2(17, -1);
		AddTriggerObj2(28, 29, 27);
		UpdateJob2(30);
		break;

	case 27://��ڤ��
		AddTriggerDialog2(18, 28);
		break;
		***********/
	case 289999:

		{
			cPetData* pPet = AddPCPetEnemy2(10000, e��, 52, eMP_���ܵظ�, 28);
			pPet->SetJinJie(2);
			pPet->m_MagicNumAdd += 3;
			for (int i = 0; i < 4; i++)
			{
				ePetID petid;
				switch (rand() % 4)
				{
				case 0:petid = e��ʬ;
					break;
				default:petid = e��ʬ;
					break;
				}
				AddPCPetEnemy2(4000, petid, 52);
			}
			SetMusic();

			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(29);
		}
		break;
	case 299999:
		TalkList(19, 31, 32, 33, 30);
	
		SetJiangLi2(150000, 120000, 50000, 250000);

		g_pCharacter->m_PCData.AddDefZZ(200);
		g_pCharacter->m_PCData.AddGrowing(1);
		g_pMainState->LockLv(45);
		break;
	case 309999://����
		AddTriggerObj2(28, 29, 31);
		AddTriggerDialog2(20, -30);	
		break;
	case -30:
		SetJiangLiItem(16, 22, 10);
		SetJiangLiItem(36, 40);
		UpdateJob2(30);
		break;
	case 31://��ڤ��
		AddTriggerObj2(25, 26, 32);
		AddTriggerDialog2(21, -1);
		UpdateJob2(27);
		break;
	case 32://����
		AddTriggerObj2(22, 11, 33);
		AddTriggerDialog2(22, -1);
		UpdateJob2(40);
		break;
	case 33://����
		AddTriggerObj2(34, 8, 34);
		AddTriggerDialog2(23, -1);
		UpdateJob2(35);
		break;
	case 34://����
		AddTriggerDialog2(24, 35); break;
	case 35:
		
		{
			for (int i = 0; i < 5; i++)
			{
				AddPCPetEnemy2(6500, e����, 53, eMP_���ƹٸ�,34);
			}
			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(36);
		}
		break;
	case 36:
		AddTriggerObj2(36, 8, 37);
		AddTriggerDialog2(25, -1);
		SetJiangLi2(120000, 50000, 50000, 270000);
		UpdateJob2(37);
		g_pCharacter->m_PCData.AddHpZZ(100);
		g_pCharacter->m_PCData.AddGrowing(1);
		g_pMainState->LockLv(45);
		break;
	case 37://���½�
		AddTriggerObj2(41, 8, 38);
		AddTriggerDialog2(26, -1);
		UpdateJob2(42);
		break;
	case 38:AddTriggerDialog2(27, 39);
		break;
	case 39://Ϻ��ս��
		
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(8000,eϺ��, 58, eMP_��������, 41);
			pPet->m_MagicWater.d2 += 20;
			pPet->m_MagicNumAdd += 2;
			for (int i = 0; i < 4; i++)
			{
				ePetID petid;
				switch (rand() % 4)
				{
				case 0:petid = e����;
					break;
				default:petid = e����;
					break;
				}
				pPet= AddPCPetEnemy2(5000,petid, 40, (eMengPai)(rand() % 12));
				pPet->m_MagicWater.d2 += 10;
			}
			g_pMainState->m_Mp3.Load("ս��BOSS");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(40);
			AddTriggerDialog2(51);
		}
		break;
	case 40:
		AddTriggerObj2(44, 45, 41);
		SetJiangLi2(80000, 100000, 50000, 300000);
		UpdateJob2(43);
		g_pCharacter->m_PCData.AddMagZZ(100);
		g_pCharacter->m_PCData.AddGrowing(1);
		g_pMainState->LockLv(45);
		break;
		//з��ս��
	case 41:AddTriggerDialog2(28, 42);
		break;
	case 42:
		
		{
			cPetData* pPet;
			 pPet= AddPCPetEnemy2(10000, e����, 60, eMP_��������,71);
			 pPet->SetJinJie(3);
			 pPet->m_MagicNumAdd += 3;
			 pPet->m_MagicWater.d2 += 20;
			 pPet->AddSkill(ePS_�߼�ħ֮��);
			 pPet->AddSkill(ePS_�߼���������);
			for (int i = 0; i < 4; i++)
			{
				ePetID petid;
				switch (rand() % 4)
				{
				case 0:petid = eз��;
					break;
				default:petid = eз��;
					break;
				}
				AddPCPetEnemy2(8000, petid, 50, (eMengPai)(rand() % 12));
				pPet->m_MagicWater.d2 += 20;
			}
			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(43);
		}
		break;
	case 43:
		TalkList(29, 46, 45, 47, 44);
		SetJiangLi2(150000, 80000, 50000, 320000);
		g_pCharacter->m_PCData.AddMagZZ(300);
		g_pCharacter->m_PCData.AddGrowing(1);
		g_pMainState->LockLv(45);
		break;	
	case 44://��ǧ��
		TalkList(30, 36, 8, 37, 45);
		break;
	case 45://���½�
		TalkList(31, 49, 50, 48, 46);
		break;
	case 46://��ة��
		TalkList(32, 52, 53, 51, 47);
		AddTriggerGive(m_Textlist[49] ,22,30, 49);
		break;
	case 47://��������
		AddTriggerDialog2(33, 48); break;
	case 48:
		SetJiangLiItem(30, 22);
		SetJiangLi2(0, -50000);
		break;
	case 49://��ة��
	
		{
			AddTriggerDialog2(34, -1);
			UpdateJob2(56);
			sNpc npc;
			npc.Set(m_Textlist[66], m_Textlist[8], 2012, 226, 190, 3);
			AddTriggerObjMap(&npc, 152);
			npc.Set(m_Textlist[67], m_Textlist[8], eɽ��, 230, 186, 7);
			AddTriggerObjMap(&npc, 152, 0);
			npc.Set(m_Textlist[67], m_Textlist[8], eɽ��, 233, 194, 1);
			AddTriggerObjMap(&npc, 152, 0);
			AddTriggerObjMap(m_Textlist[8], 151,0);
		}
		break;
	case 151:
		AddTriggerDialog2(44, -1);
		RemoveTriggerObjMap(151);
		UpdateJob2(68);
		break;
	case 152://ɽ��ս��
		AddTriggerDialog2(45, 153);
		break;
	case 153:
		
		{
			for (int i = 0; i < 10; i++)
			{
				ePetID petid;
				switch (rand() % 4)
				{
				case 0:petid = eɽ��;
					break;
				default:petid = eǿ��;
					break;
				}
				AddPCPetEnemy2(2500, petid, 19, (eMengPai)(rand() % 12));
			}
			SetMusic();

			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(154);
		}
		break;
	case 154:
		RemoveNpc(67);
		RemoveNpc(67,1);
		RemoveTriggerObjMap(-1);
		TalkList(46, 54, 55, 56, 50,155);
		SetJiangLi2(50000, 50000, 50000, 300000);
		g_pCharacter->m_PCData.AddGrowing(5);
		g_pMainState->LockLv(45);
		break;
	case 155:
		RemoveNpc(66,1);
		break;
	case 50://����1
		AddTriggerDialog2(35, 51);
		break;
	case 51:
		{
			AddPCPetEnemy2(8000,eǿ��, 65, eMP_���ƹٸ�, 54);
			for (int i = 0; i < 7; i++)
			{
				ePetID petid;
				switch (rand() % 4)
				{
				case 0:petid = eɽ��;
					break;
				default:petid = eǿ��;
					break;
				}
				AddPCPetEnemy2(3000, petid, 50, (eMengPai)(rand() % 12));
			}
			SetMusic();

			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(52);
		}
		break;
	case 52:
		{
			TalkList(36, 54, 57, 58, 53);
		
			SetJiangLi2(120000, 80000, 50000, 350000);
			g_pCharacter->m_PCData.AddAtkZZ(50);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
		}
		break;
	case 53://����2
		AddTriggerDialog2(37, 54);
		break;
	case 54:
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(10000, e����, 60, eMP_���ƹٸ�, 54);
			pPet->m_AtkDownHPHurt.d1 += 5;
			pPet= AddPCPetEnemy2(10000, eǿ��, 60, eMP_���ܵظ�, 59);
			pPet->AddSkill(ePS_�����);
			for (int i = 0; i < 5; i++)
			{
				ePetID petid;
				switch (rand() % 4)
				{
				case 0:petid = eǿ��;
					break;
				default:petid = e����;
					break;
				}
				AddPCPetEnemy2(5000, petid, 45);//(eMengPai)(rand() % 12));
			}
			SetMusic("OneLight");

			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(55);
		}
		break; 
	case 55:
		{
			AddTriggerDialog2(38, -57);
			cPetData* pPet= AddPCPetEnemy2(15000, e��ɽ����, 75, eMP_���ܵظ�, 59);
			pPet->AddSkill(ePS_�����);
			pPet->m_MagicNumAdd += 2;
			pPet->m_SuckBloodRate.d1 += 10;
			pPet->SetJinJie(2);
			for (int i = 0; i < 8; i++)
			{
				ePetID petid;
				switch (rand() % 4)
				{
				case 0:petid = e��ɽ����;
					break;
				default:petid = e��ɽ����;
					break;
				}
				AddPCPetEnemy2(5000, petid, 50, (eMengPai)(rand() % 12));
			}
			SetMusic("�׉�Ⱦ");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(57);
			
		}
		break;
	case -57:
		AddTriggerDialog2(47);
		break;
	case 57:
		AddTriggerDialog2(39, -1);
		AddTriggerObj2(61, 8, 58);
		SetJiangLi2(180000, 120000, 30000, 400000);
		UpdateJob2(62);
		g_pCharacter->m_PCData.AddDefZZ(200);
		g_pCharacter->m_PCData.AddHpZZ(500);
		g_pCharacter->m_PCData.AddGrowing(1);
		g_pMainState->LockLv(45);
		break;
	case 58://��ĸ
		AddTriggerDialog2(40, 59);
		g_pMainState->m_DialogList.clear();
		break;
	case 59:
		AddTriggerObj2(36, 8, 60);
		UpdateJob2(37);
		break;
	case 60://���½�
		AddTriggerDialog2(41, -1);
		AddTriggerObj2(22, 11, 61);
		UpdateJob2(63);
		break;
	case 61://����
		TalkList(42, -1, -1, -1, -1,62); 
		break;
	case 62:
		SetJiangLiItem(7, 40);
		AddTriggerDialog2(48);
		Process2(0);
		break;
	default:
		ERRBOX;
		break;
	}
	return TRUE;
}

void cTaskJuQing::RemoveNpc(int id, BOOL needfind /*= FALSE*/)
{
	g_pMainState->m_Map.RemoveNpc(m_Textlist[id], needfind);
}



void cTaskJuQing::AddChannel2(int id)
{
	AddChannel(m_Textlist[id]);
}

void cTaskJuQing::AddTriggerObj2(int name, int mapname, int ret, BOOL bHuChi)
{
	if (name == -1)
		RemoveTriggerObj();
	else
		AddTriggerObj(m_Textlist[name], m_Textlist[mapname], ret,bHuChi);
}

void cTaskJuQing::AddTriggerDialog2(int id, int ret)
{
	AddTriggerDialog(SetUpPathJuQing(m_Textlist[0]), id, ret);
}

void cTaskJuQing::UnInvite(string name)
{
	g_pMainState->m_Friend.UnInvite(name);
}

void cTaskJuQing::FollowLv(int id, int lv)
{
	g_pMainState->m_FightList[id].m_pData->FollowLv(lv);
}

BOOL cTaskZhuXian::Process2(int stage)
{//������
	switch (stage)
	{
	case 0:
		SetChapter(2);
		g_pMainState->m_GlobalButton[5] = 2;
		AddTriggerDialog2(0,-1);
		AddTriggerObj2(1, 2, 1);
		UpdateJob2(16);
		break;
	case 1://������
		AddTriggerDialog2(1, -1);
		AddTriggerObj2(3, 4, 2);
		UpdateJob2(15);
		break;
	case 2://������
		AddTriggerDialog2(2, -1);
		AddTriggerObj2(5, 6, 3);
		UpdateJob2(17);
		break;
	case 3://Ů��
		AddTriggerDialog2(3, 4);
		break;
	case 4: 
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(5000, eܽ������, 75, eMP_��˿��, 5);
			pPet->m_LiveHpLv += 10;
			pPet->m_Combo.d1 += 60;
			pPet->m_MagicNumAdd += 3;
			pPet->SetJinJie(2);
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 3)
				{
				case 0:petid = e֩�뾫;
					break;
				default:petid = e֩�뾫;
					break;
				}
				AddPetEnemy2(8000, petid, 70);
			}
			SetMusic("��Ӱ��Ե");

			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(5);
		}
		return TRUE;
	case 5:
		{
			SetJiangLi2(150000, 100000, 50000, 450000);
			AddTriggerDialog2(4, -1);
			AddTriggerObj2(7,6,6);
			UpdateJob2(18);
			g_pCharacter->m_PCData.AddDefZZ(80);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 6://������
		AddTriggerDialog2(5, 7);
		break;
	case 7:
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(8000, e��������, 75, eMP_����ɽ, 7);
			pPet->poisonRate.d1 += 20;
			pPet->m_MagicNumAdd += 3;
			pPet->SetJinJie(3);
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 3)
				{
				case 0:petid = e��������;
					break;
				default:petid = e��������;
					break;
				}
				AddPetEnemy2(8000, petid, 70);
			}
			SetMusic("��Ӱ��Ե");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(8);
		}
		return TRUE;
	case 8:
		{
			g_pMainState->m_Friend.AddFriend(m_Textlist[28]);
			SetJiangLi2(150000, 150000, 50000, 480000);
			AddTriggerDialog2(6, 88);
			AddTriggerObj2(8, 4, 9);
			UpdateJob2(15);
			g_pCharacter->m_PCData.AddDefZZ(80);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 88:
		g_pMainState->m_Friend.Invite(m_Textlist[28]);
		AddChannel2(29);
		break;
	case 9://������
		AddTriggerDialog2(7, -1);
		AddTriggerObj2(9, 10, 10);
		UpdateJob2(20);
		break;
	case 10://������
		AddTriggerDialog2(8, -1);
		AddTriggerObj2(26, 10, 11);
		UpdateJob2(21);
		break;
	case 11://�����
		AddTriggerDialog2(9,12);
		break;
	case 12:
		{
		    cPetData* pPet;
			pPet = AddPCPetEnemy2(18000, e̤����, 80, eMP_ʨ����, 26);
			pPet->m_StabRate.d1 = 60;
			pPet->m_StabDamageRate.d1 = 40;
			pPet->SetJinJie(3);
			AddPetEnemy2(15000, e̤����, 75);
			AddPetEnemy2(15000, e̤����, 75);
			
			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(13);
		}
		return TRUE;
	case 13:
		{
			SetJiangLi2(200000, 100000, 200000, 500000);
			AddTriggerDialog2(10, -1);
			AddTriggerObj2(9, 10, 14);
			UpdateJob2(22);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 14://������
		AddTriggerDialog2(11, -1);
		AddTriggerObj2(11, 10, 15);
		AddTriggerGive(m_Textlist[9],22,30,17);
		UpdateJob2(23);
		break;
	case 15:AddTriggerDialog2(12, 16); break;
	case 16:
		SetJiangLiItem(30,22);
		SetJiangLi2(0, 40000);
		RemoveTriggerObj();
		AddTriggerDialog2(23, -1);
		break;
	case 17://������
		AddTriggerDialog2(13, -1);
		AddTriggerObj2(1, 2, 18);
		UpdateJob2(16);
		break;
	case 18://������
		AddTriggerDialog2(14, -1);
		AddTriggerObj2(12, 2, 19);
		UpdateJob2(24);
		break;
	case 19://����
		AddTriggerDialog2(15, -1);
		AddTriggerObj2(1, 2, 20);
		UpdateJob2(16);
		break;
	case 20://������
		AddTriggerDialog2(16, -1);
		AddTriggerObj2(12, 2, 21);
		UpdateJob2(24);
		break;
	case 21://Ҧ̫ξ
		AddTriggerDialog2(17, 22);
		break;
	case 22:
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(22000, e�콫, 82, eMP_�칬, 27);
		    pPet->m_StabRate.d1 = 20;
			pPet->m_StabDamageRate.d1 = 40;
			pPet->m_MagicNumAdd += 2;
			pPet->SetJinJie(3);
			AddPetEnemy2(20000, e���, 65);
			AddPetEnemy2(20000, e���, 65);

			SetMusic();	
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(23);
		}
		return TRUE;
	case 23:
		{
			SetJiangLi2(150000, 100000, 50000, 550000);
			AddTriggerDialog2(18, 123);
			AddTriggerObj2(1, 2, 24);
			UpdateJob2(16);
			g_pCharacter->m_PCData.AddAtkZZ(150);
			g_pCharacter->m_PCData.AddGrowing(2);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 123:AddTriggerDialog2(24, -1); return TRUE;
	case 24://������
		AddTriggerDialog2(19, -1);
		AddTriggerObj2(13, 14, 25);
		UpdateJob2(25);
		break;
	case 25://��ĸ����
		AddTriggerDialog2(20, 26);
		break;
	case 26:
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(25000, e�, 92, eMP_�칬);
			pPet->comboNumDown += 1;
			pPet->m_MagicNumAdd += 3;
			pPet->m_AtkDownHPHurt.d1 += 1;
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 3)
				{
				case 0:petid = e���;
					break;
				default:petid = e���;
					break;
				}
				AddPetEnemy2(20000, petid, 85);
			}
			SetMusic("��Ӱ��Ե");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(27);
		}
		return TRUE;
	case 27:
		{
			SetJiangLi2(200000, 150000, 50000, 850000);
			AddTriggerDialog2(21, -1);
			AddTriggerObj2(1, 2, 28);
			UpdateJob2(16);
			g_pMainState->m_GlobalButton[14] += 200;
			g_pMainState->m_GlobalButton[15] += 200;
			g_pCharacter->m_PCData.AddDefZZ(200);
			g_pCharacter->m_PCData.AddGrowing(2);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 28://������
		TalkList(22, -1, -1, 30, -1);
		g_pMainState->m_TaskZhuaGui.SetTrigger(this, 9, 29);
		break;
	case 29://ת������Ů������
		Process8(0);
		return TRUE;
	default:
		break;
	}
	return TRUE;
}

BOOL cTaskZhuXian::Process3(int stage)
{//С����
	switch (stage)
	{
	case 0:
		g_pMainState->m_GlobalButton[5] = 4;
		SetChapter(3);
		AddTriggerObj2(7, 8, 1);
		UpdateJob2(9);
		AddTriggerDialog2(1, -1);
		break;
	case 1://С����
		AddTriggerDialog2(2, 2);
		break;
	case 2://��������
		{
			cPetData* petdata= AddPCPetEnemy2(30000, e��������, 75, eMP_��������);
			petdata->m_MagicWater.d1 += 20;
			ePetID petid;
			for (int i = 0; i < 5; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e��ة��; break;
				default:petid = e��ة��; break;
				}
				AddPCPetEnemy2(15000, petid, 60, (eMengPai)(rand() % 12));
			}
			SetMusic("Paranoia");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(5);
		}
		return TRUE;
	case 5:
		{
			SetJiangLi2(180000, 100000, 50000, 800000);	
			AddChannel2(27);
			AddChannel2(38);
			AddTriggerObj2(7, 8, 6);
		
			g_pMainState->m_GlobalButton[14] += 200;
			g_pMainState->m_GlobalButton[15] += 200;
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pCharacter->m_PCData.AddAvoidZZ(100);
			g_pCharacter->m_PCData.AddHpZZ(100);
			g_pMainState->LockLv(45);

			sShangPinPet sppet;
			sAddPoint addpoint;
			addpoint.Set(0, 0, 4, 1, 0);
			sppet.Set(e��������,&addpoint,100,TRUE);
			GetPet(m_Textlist[35], &sppet, 100);
		}
		break;
	case 6://С����
		TalkList(0, 10, 11, 12, 7);
		break;
	case 7://����֮��
		AddTriggerDialog2(6, -1);
		AddTriggerObj2(13, 14, 8);
		UpdateJob2(15);
		break;
	case 8://��������
		AddTriggerDialog2(7, -1);
		AddTriggerObj2(16, 17, 9);
		UpdateJob2(18);
		break;
	case 9://з��
		AddTriggerDialog2(8, 10);
		break;
	case 10://з��
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(50000, e��ˮҹ��, 95, eMP_��������,29);
			pPet->m_MagicWater.d2 += 20;
			pPet->m_MagicNumAdd += 2;
			pPet->SetJinJie(3);
			ePetID petid;
			for (int i = 0; i < 5; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e����;
					break;
				default:petid = e����;
					break;
				}
				AddPCPetEnemy2(15000, petid, 90, (eMengPai)(rand() % 12));
			}
			SetMusic("ħ����Ů��");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(11);
		}
		return TRUE;
	case 11:
		{
			SetJiangLi2(180000, 100000, 50000, 810000);
			AddTriggerDialog2(9, -1);
			AddTriggerObj2(19, 17, 12);
			UpdateJob2(20);
			g_pCharacter->m_PCData.AddMagZZ(50);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 12://��ʤ����
		{
			AddTriggerDialog2(10, -1);
			AddTriggerObj2(21, 22, 13);
			UpdateJob2(23);
			
		}
		break;
	case 13://��ͷ����
		g_pMainState->SetDialogListNpc(m_Textlist[19], 1001);
		AddTriggerDialog2(11, 14);
		break;
	case 14://
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(55000, e��ͷ����, 115, eMP_ʨ����,21);
			pPet->m_AtkDownHPHurt.d1 = 5;
			pPet->m_MagicNumAdd += 1;
			pPet= AddPCPetEnemy2(35000, eǧ������, 95, eMP_��������,19);
			pPet->m_MagicWater.d2 += 20;
			pPet->m_MagicNumAdd += 3;
			pPet->SetJinJie(3);
			ePetID petid;
			for (int i = 0; i < 3; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = eţ��;
					break;
				default:petid = eţ��;
					break;
				}
				AddPCPetEnemy2(20000, petid, 75, eMP_ħ��կ);
			}
			SetMusic("redmoon");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(15);
		}
		return TRUE;
	case 15:
		{
			g_pMainState->ClearDialogList();
			SetJiangLi2(450000, 250000, 50000, 850000);
			
			AddTriggerDialog2(12, -1);
			AddTriggerObj2(24, 25, 16);
			UpdateJob2(26);
			g_pMainState->ClearDialogList();
			g_pCharacter->m_PCData.AddHpZZ(600);
			g_pCharacter->m_PCData.AddGrowing(2);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 16://��ʴ��
		AddTriggerDialog2(13, -1);
		AddTriggerObj2(7, 8, 17);
		UpdateJob2(9);
		break;
	case 17://С����
		TalkList(14, -1, -1, -1,-1, 18); 
		break;
	case 18:
		Process4(0);
		break;
	default:
		break;
	}
	return TRUE;
}

BOOL cTaskZhuXian::Process4(int stage)
{
	switch (stage)
	{
	case 0:
		g_pMainState->m_GlobalButton[5] = 6;
		SetChapter(4);
		TalkList(0, 1, 2, 3, 1,100);
		break;
	case 100:
		UnInvite(m_Textlist[44]);
		break;
	case 1:
		g_pMainState->m_DialogList.clear();
		TalkList(1,4,2,5,2);break;//��˽�
	case 2:TalkList(2,6,7,8,3); break;//���ع���
	case 3:TalkList(3,9,10,11,4); break;//�ߴ���
	case 4:TalkList(4,6,7,8, 5); break;//����
	case 5:TalkList(5, 1, 2, 3, 6); break;//�ߴ���
	case 6:TalkList(6, 4, 2, 5, 7); break;//��˽�
	case 7:TalkList(7, 12, 13, 14, 8); break;//���ع���
	case 8:TalkList(8, 15, 13, 14, 9); break;//������Ů
	case 9://��̫ξ
		AddTriggerDialog2(9, 10);
		break;
	case 10:
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(30000, e���, 105, eMP_�칬,15);
			pPet->m_AtkDownHPHurt.d1 = 5;
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet= AddPCPetEnemy2(30000, e�粮, 105, eMP_��������,65);
			pPet->m_MagicWater.d2 += 20;
			pPet->m_MagicNumAdd += 5;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(20000, e��ʦ, 105, eMP_����ɽ, 66);
			pPet->m_MagicWater.d2 += 20;
			pPet->m_MagicNumAdd += 2;
			pPet->SetJinJie(3);

			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(11);
		}
		return TRUE;
	case 11:
		{
			SetJiangLi2(300000, 100000, 100000, 900000);
			
			TalkList(10, 16, 17, 18, 12);
			g_pCharacter->m_PCData.AddAtkZZ(200);
			g_pCharacter->m_PCData.AddGrowing(5);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 12:TalkList(11, 19, 20, 21, 13); break;//�϶�
	case 13://���
		AddTriggerDialog2(12, 14);
		break;
	case 14:
		{
			if (g_pMainState->m_GlobalButton[0]>50)
				AddTriggerDialog2(38);
			cPetData* pPet;
			pPet = AddPCPetEnemy2(50000, e������, 115, eMP_�칬);
			pPet->m_MagicNumAdd += 2;
			pPet= AddPCPetEnemy2(20000, eХ��Ȯ, 105, eMP_ʨ����);
			pPet->m_SuckBloodRate.d1 += 10;
			pPet = AddPCPetEnemy2(30000, e���, 95, eMP_�칬);
			pPet->SetJinJie(1);
			pPet = AddPCPetEnemy2(30000, e���, 95, eMP_��������);
			pPet->SetJinJie(1);
			pPet = AddPCPetEnemy2(30000, e���, 95, eMP_����ɽ);
			pPet->SetJinJie(1);
			
			SetMusic("stonecoldFictionJunction");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(15);
		}
		return TRUE;
	case 15:
		{
			SetJiangLi2(300000, 100000, 150000, 1000000);
			
			TalkList(13, 22, 23, 24, 16);
			g_pCharacter->m_PCData.AddDefZZ(100);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 16:TalkList(14, 16, 17, 18, 115); break;//�۾�
	case 115:
		{
			
			sMapObjTrigger obj;
			obj.m_Npc.Set(m_Textlist[52], m_Textlist[13], e��������, 72, 72);
			obj.m_pTask = this;
			obj.m_Stage = -1;
			AddTriggerObjMap(&obj);
			TalkList(31, 52, 13, 53, 116); break;//�϶�
		}
		break;
	case 116://��������
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(30000, eҹ��ɲ, 115, eMP_�칬,47);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet= AddPCPetEnemy2(20000, e����ս��, 110, eMP_ʨ����,48);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(20000, e��, 110, eMP_���ܵظ�,49);
			pPet->SetJinJie(2);
			pPet = AddPCPetEnemy2(15000, e��������, 80, eMP_�칬);
			pPet->SetJinJie(2);
			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(118);
		}
		return TRUE;
	case 118:
		
		{
			RemoveTriggerObjMap();
			RemoveTriggerObj();
			RemoveNpc(52,TRUE);
			SetJiangLi2(600000, 300000, 300000, 1500000);
			AddChannel2(67);
			TalkList(32, 16, 17, 18,17,-118);
			g_pMainState->m_GlobalButton[14] += 200;
			g_pMainState->m_GlobalButton[15] += 200;
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pCharacter->m_PCData.AddAvoidZZ(200);
			g_pCharacter->m_PCData.AddHpZZ(1000);
			g_pMainState->LockLv(45);
	
			sShangPinPet sppet;
			sAddPoint addpoint;
			addpoint.Set(4, 0, 0, 1, 0);
			sppet.Set(e��������, &addpoint, 100, TRUE);
			GetPet(m_Textlist[56], &sppet, 100);
		}
		break;
	case -118:
		AddTriggerDialog2(40);
		break;
	case 17:TalkList(15, 1, 2, 3, 18); break;//�϶�
	case 18:TalkList(16, 4, 2, 5, 19); break;//����Ԫ˧
	case 19:TalkList(17, 25, 26, 27, 20); break;//���ع���
	case 20:TalkList(18,28, 26, 29, 21); break;//����ʮ��
	case 21:TalkList(19, 30, 2, 31, 22); break;//�׾���
	case 22:TalkList(20, 32, 2, 33, 23); break;//����
	case 23:TalkList(21, 34, 35, 36, 24); break;//������
	case 24:TalkList(22, 37, 38, 39, 25); break;//��������
	case 25://����
	
		{
			sNpc npc;
			int x, y;
			g_pMainState->m_Map.AutoGetPos(x, y, m_Textlist[41]);
			npc.Set(m_Textlist[40], m_Textlist[41], 123, x, y,0);
			AddTriggerObjMap(&npc, -1);
			TalkList(23, 40, 41, 42, 26);
		}
		break;
	case 26://��������
		AddTriggerDialog2(24, 27);
		break;
	case 27:
	
		{
			AddPCPetEnemy2(20000, e��������, 100, eMP_��������);
			for (int i = 0; i < 7; i++)
			{
				AddPCPetEnemy2(10000, e����, 100, (eMengPai)(rand() % 12));
			}
			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(28);
		}
		return TRUE;
	case 28:
		
		{
			SetJiangLi2(200000, 100000, 200000, 1120000);
			g_pMainState->m_GlobalButton[14] += 200;
			g_pMainState->m_GlobalButton[15] += 200;
			RemoveTriggerObjMap();
			TalkList(25, 37, 38, 39, 29);
			g_pCharacter->m_PCData.AddDefZZ(100);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 29: TalkList(26, 59, 60, 58, 133);
		break;//����
	case 133://ȥ�ظ��������ֻ�
		g_pMainState->m_Friend.AddFriend(m_Textlist[61]);
		TalkList(33, -1, -1, 64, -1, 134);
		//AddRangeMap(63, 95, 57, 10, 135);
		break;
	case 134:
		Invite(m_Textlist[61]);
		AddTriggerObj2(62, 63, 135);
		break;
	case 135://ǧ��Թ��
		AddTriggerDialog2(34, 136);
		break;
	case 136:
		
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(20000, e����, 150, eMP_���ܵظ�,62);
			pPet->m_MagicNumAdd += 6;	
			pPet->SetJinJie(3);
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = eţͷ; break;
				default:petid = e����; break;
				}
				AddPCPetEnemy2(30000, petid, 110, (eMengPai)(rand() % 12));
			}
			SetMusic("OneLight");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(137);
			//AddTriggerFightEscape(-137);
		}
		return TRUE;
	//case -137:
	//	AddTriggerObj2(62, 63, 135);
	//	return TRUE;
	case 137:
		
		{
			SetJiangLi2(300000, 100000, 200000, 1200000);
			
			RemoveTriggerObjMap();
			TalkList(35, 32, 2, 33, 138);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 138:
		AddTriggerDialog2(36, 139);
		UpdateJob2(-1);
		return TRUE;
	case 139:
		TalkList(37, 30, 2, 31, 30);
		return TRUE;
	case 30: TalkList(27, 28, 26, 29, 31);
		SetJiangLiItem(11,24);
		break;//����
	case 31:TalkList(28, 25, 26, 27, 32); break;//�׾���
	case 32:TalkList(29, 1, 2, 3, 33); break;//����ʮ��
	case 33:
		TalkList(30, -1, -1, -1, -1,34); 
		SetJiangLiItem(50,40);
	/*	SetChapter(5);
		AddTriggerLv(0, 105);*/
		break;//����Ԫ˧
	case 34:
		Process5(0);
		break;
	default:
		break;
	}
	return TRUE;
}

void cTaskJuQing::TalkList(int textid, int nextname, int nextmap, int jobtext, int ret, int dialogret)
{
	AddTriggerDialog2(textid, dialogret);
	if (nextname > -1)
		AddTriggerObj2(nextname, nextmap, ret);
	UpdateJob2(jobtext);
}

BOOL cTaskZhuXian::Process5(int stage)
{
	int next = stage + 1;
	switch (stage)
	{
	case 0:
		g_pMainState->m_GlobalButton[6] = 8;
		g_pMainState->m_GlobalButton[5] = 7;
		SetChapter(5);
		AddTriggerObj2(8, 9, 1);
		UpdateJob2(10);
		break;
	case 1:
		AddTriggerDialog2(3, 3); //������
		break;
	case 3:
		
		{
			AddPCPetEnemy2(10000, e��ʦ, 100, eMP_������,26);
			AddPCPetEnemy2(8000, eɳ����, 100, eMP_��������,28);
			AddPCPetEnemy2(8000, e��˽�, 100, eMP_ʨ����,27);
			ePetID petid;
			for (int i = 0; i < 3; i++)
			{
				switch (rand() % 3)
				{
				case 0:petid = e������Գ; break;
				case 1:petid = e��ü���; break;
				default:petid = e�������; break;
				}
				AddPCPetEnemy2(15000, petid, 80);
			}
			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(11);
		}
		return TRUE;
	case 11:
		
		{
			SetJiangLi2(300000, 200000, 250000, 1250000);
			
			AddTriggerDialog2(4, -11); //������
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case -11:
		
		{
			AddPCPetEnemy2(50000, e�����, 999, eMP_���ƹٸ�);
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e������Գ; break;
				case 1:petid = e��ü���; break;
				default:petid = e�������; break;
				}
				AddPCPetEnemy2(25000, petid, 120);
			}
			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(-13);
			AddTriggerFightFalse(-13);
			AddTriggerFightEscape(-13);
		}
		return TRUE;
	case -13:
		
		{
			TalkList(5, 11, 12, 13, 12);
		}
		return TRUE;


	case 12:TalkList(6, 14, 15, 16, next); break;//�������
	case 13:TalkList(7, 8, 9, 10, next); break;//�
	case 14:TalkList(8, 8, 17, 10, next); break;//������
	case 15:AddTriggerDialog2(9, next); break;//������
	case 16:
		
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(80000, e�����, 165, eMP_ʨ����);
			pPet->m_MagicFire.d2 += 20;
			pPet->m_CounterRate.d1 += 80;
			pPet->comboNumDown += 4;
			SetMusic("�򲻵��Ŀ�����");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(17);
		}
		return TRUE;
	case 17:
		
		{
			SetJiangLi2(800000, 800000, 250000, 1300000);
			
			TalkList(10, 14, 15, 16, next);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
			AddChannel2(37);
			int xp, yp;
			for (int i = 0; i < 10; i++)
			{
				g_pMainState->m_Map.AutoGetPos(xp, yp, m_Textlist[36]);
				switch (rand() % 3)
				{
				case 0:
					AddTriggerObjMap2(35, 36, e��,xp,yp,-1,-17);
					break;
				case 1:
					AddTriggerObjMap2(35, 36, e��ƿŮ�, xp, yp, -1, -18);
					break;
				case 2:
					AddTriggerObjMap2(35, 36, e��ħ��, xp, yp, -1, -19);
					break;
				}	
			}
		}
		return TRUE;
	case -17:
		
		{
			m_pObj = g_pMainState->m_pNowSelect;
			int lv = g_pCharacter->m_PCData.m_LV;
			AddPCPetEnemy2(lv * 100, e��, lv + 5, eMP_���, 35);
			for (int i = 0; i < 7;i++)
			AddPCPetEnemy2(lv*80, (ePetID)(10+rand()%20),lv);
		
			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(-117);
		}
		return TRUE;
	case -18:
		
		{
			m_pObj = g_pMainState->m_pNowSelect;
			int lv = g_pCharacter->m_PCData.m_LV;
			AddPCPetEnemy2(lv * 100, e��ƿŮ�, lv + 5, eMP_���, 35);
			for (int i = 0; i < 7; i++)
				AddPCPetEnemy2(lv * 80, (ePetID)(10 + rand() % 20),lv);

			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(-117);
		}
		return TRUE;//
	case -19://��ħ��
		
		{
			m_pObj = g_pMainState->m_pNowSelect;
			int lv = g_pCharacter->m_PCData.m_LV;
			cPetData* pPet;
			pPet= AddPCPetEnemy2(lv * 100, e��ħ��, lv + 5, eMP_ħ��կ, 35);
			pPet->AddSkill(ePS_�߼�����);
			for (int i = 0; i < 7; i++)
				AddPCPetEnemy2(lv * 80, (ePetID)(10 + rand() % 20),lv);

			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(-117);
		}
		return TRUE;
	case -117:
		SetJiangLi2(500000, 50000, 50000, 100000);
		RemoveTriggerObjMap2(m_pObj);
		g_pMainState->m_Map.RemoveNpc(m_pObj, TRUE);
		return TRUE;
	case 18:TalkList(11, 18, 19, 20, next); break;//�
	case 19:TalkList(12, 11, 12, 13, next); break;//�ز���
	case 20:TalkList(13, 21, 22, 23, -20); break;//�������
	case -20:TalkList(14, 24, 22, 25, 21); break;//���ܾ�
	case 21:AddTriggerDialog2(15, next); break;//С��Ů
	case 22:
		
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(25000, e�ɷ�Ů�, 110, eMP_���ƹٸ�, 24);
			pPet->SetJinJie(3);
			pPet->AddSkill(ePS_�߼�����);
			pPet->AddSkill(ePS_�绪��ʥ);
			pPet->AddSkill(ePS_�߼�����);
			pPet->m_ParryRate.d1 += 100;
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 2)
				{
				case 0:petid = e�ɷ�Ů�; break;
				default:petid = e�ɷ�Ů�; break;
				}
				AddPCPetEnemy2(25000, petid, 100, (eMengPai)(rand() % 12));
			}
			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(23);
		}
		return TRUE;
	case 23:
		
		{
			
			SetJiangLi2(500000, 250000, 250000, 1320000);
			
			TalkList(16, 8, 9, 10, next);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 24:AddTriggerDialog2(17, next); break;//������
	case 25:
		
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(30000, e������Գ, 145, eMP_ʨ����);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(30000, e��ü���, 145, eMP_����ɽ);
			pPet->SetJinJie(3);
			ePetID petid;
			for (int i = 0; i < 5; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e�������; break;
				default:petid = e�������; break;
				}
				AddPCPetEnemy2(20000, petid, 115, (eMengPai)(rand() % 12));
			}
			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(26);
			
		}
		return TRUE;
	case 26:
		
		{
			RemoveTriggerObjMap();//����û��
			SetJiangLi2(80000, 5000, 1000, 5000);
			
			TalkList(18,-1,-1,-1 ,-1,-26);
			g_pMainState->m_GlobalButton[14] += 200;
			g_pMainState->m_GlobalButton[15] += 200;
			g_pCharacter->m_PCData.m_BangPaiID = 0;
			g_pCharacter->m_PCData.AddDefZZ(50);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case -26:
		UnInvite("���");
		AddFriend(32);
		g_pMainState->SetDialogListNpc(m_Textlist[31], 1081);
		TalkList(19, -1, -1, -1, -1, 28); break;//
		break;
	case 28:
		
		{
			g_pMainState->ClearDialogList();
			UnInvite("��ܽ");
			AddFriend(33);
			TalkList(20, -1, -1, -1, -1, -1);

			AutoGetPet(m_Textlist[33], 3);
			Invite(m_Textlist[33]);

			AutoGetPet(m_Textlist[32], 2);
			Invite(m_Textlist[32]);
			UnInvite("С��");
			AddFriend(34);
			AutoGetPet(m_Textlist[34], 4,5);
			Invite(m_Textlist[34]);

		}
	case 29:
		Process6(0);
		break;
	}
	return TRUE;
}

BOOL cTaskZhuXian::Process6(int stage)
{
	int next = stage + 1;
	switch (stage)
	{
	case 0:
		g_pMainState->m_GlobalButton[5] = 8;
		SetChapter(6);
		g_pMainState->SetDialogListPet(m_Textlist[1],e��˽�);
		TalkList(0, 2, 3, 4, next); break;//��˽�
		break;
	case 1:
		g_pMainState->m_DialogList.clear();
		TalkList(1, 5, 26, 6, next); break;//����ɮ
	case 2:TalkList(2, 9, 10, 11, next); break;//��������
	case 3:AddTriggerDialog2(3, next); break;//������
	case 4:
		
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(100000, e��������, 150, eMP_ʨ����,9);
			pPet = AddPCPetEnemy2(60000, e��ë����, 145, eMP_����ɽ, 28);
			pPet->SetJinJie(3);
			pPet->m_MagicNumAdd += 2;
			pPet = AddPCPetEnemy2(80000, eҰ��, 145, eMP_��ׯ��, 29);
			pPet->SetJinJie(3);
			pPet->m_MagicNumAdd += 1;
			
			g_pMainState->m_InterfaceTeam.SetFormation(sky, TRUE);
			SetMusic("Magia");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(next);
		}
		return TRUE;
	case 5:
		
		{
			SetJiangLi2(1000000, 200000, 300000, 1500000);
			
			TalkList(4, 7, 3, 8, next);
			g_pMainState->m_GlobalButton[14] += 200;
			g_pMainState->m_GlobalButton[15] += 200;
			g_pCharacter->m_PCData.AddHpZZ(500);
			g_pCharacter->m_PCData.AddSpdZZ(100);
			g_pCharacter->m_PCData.AddGrowing(2);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 6:TalkList(5, 12, 3, 13, next); break;//Ұ����
	case 7:AddTriggerDialog2(6, next); break;//������
	case 8:
		
		{
			sZiZhi zizhi;
			zizhi.Set(1800, 2200, 5000, 6000, 1200, 1200, 200);
			AddPCEnemy2(50000,1, &zizhi,150, eMP_����ɽ,12);
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 2)
				{
				case 0:petid = e��������; break;
					default:petid = e��������; break;
				}
				AddPCPetEnemy2(20000, petid, 125);
			}
			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(next);
		}
		return TRUE;
	case 9:
		{
			SetJiangLi2(700000, 250000, 350000, 1550000);
			
			TalkList(7, 14, 15, 16, next);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 10:TalkList(8, 12, 3, 13, next); break;//����
	case 11:TalkList(9, 2, 3, 4, next); break;//������
	case 12:TalkList(10, 17, 3, 18, next); break;//����ɮ
	case 13:AddTriggerDialog2(11, next); break;//��Ů
	case 14:
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(50000, e������, 150, eMP_��˿��, 31);
			pPet->m_SuckBloodRate.d1 += 100;
			pPet->SetJinJie(3);
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e������; break;
				default:petid = e������; break;
				}
				AddPCPetEnemy2(40000, petid, 125);
			}
			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(next);
		}
		return TRUE;
	case 15:
		{
			SetJiangLi2(600000, 200000, 400000, 1600000);
			
			TalkList(12, 19, 20, 21, next);
			g_pCharacter->m_PCData.AddDefZZ(50);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 16:TalkList(13, 22, 3, 23, next); break;//�
	case 17:AddTriggerDialog2(14, next); break;//��̫��
	case 18:
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(80000, e������, 155, eMP_Ů����,30);
			pPet->poisonRate.d1 += 80;
			pPet->m_SuckBloodRate.d1 += 80;
			pPet = AddPCPetEnemy2(50000, eè��, 140, eMP_���ƹٸ�);
			pPet->m_SuckBloodRate.d1 += 50;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(50000, eè��, 140, eMP_��ׯ��);
			pPet->m_SuckBloodRate.d1 += 50;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(50000, eè��, 130, eMP_����ɽ);
			pPet->m_SuckBloodRate.d1 += 50;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(50000, eè��, 130, eMP_�칬);
			pPet->m_SuckBloodRate.d1 += 50;
			pPet->SetJinJie(3);

			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(next);
		}
		return TRUE;
	case 19:
		{
			SetJiangLi2(1000000, 200000, 400000, 2000000);
			
			TalkList(15, 19, 20, 21, next);
			g_pCharacter->m_PCData.AddDefZZ(100);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 20:TalkList(16, 24, 3, 25, next); break;//�
	case 21:AddTriggerDialog2(17, next); break;//��̫ү
	case 22:
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(80000, e�׾���, 155, eMP_��˿��,27);
			pPet->m_SuckBloodRate.d1 += 50;
			pPet->m_AtkDownDef.d1 = 2;
			pPet->m_MagicNumAdd += 8;
			ePetID petid;
			for (int i = 0; i < 9; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e���ù�; break;
				default:petid = e���ù�; break;
				}
				AddPCPetEnemy2(20000, petid, 140);
			}
			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(next);
		}
		return TRUE;
	case 23:
		{
			SetJiangLi2(1000000, 300000, 400000, 1800000);
			
			TalkList(18, 19, 20, 21, next);
			g_pCharacter->m_PCData.AddDefZZ(150);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 24:TalkList(19, 5, 26, 6, next); break;//�
	case 25:	
		TalkList(20, -1, -1, -1,-1, next);
		break;
	case 26:
		Process7(0);
		break;//��������
	default:
		break;

	}
	return TRUE;
}

BOOL cTaskZhuXian::Process7(int stage)
{
	int next = stage + 1;
	switch (stage)
	{
	case -1:return TRUE;
	case 0:
		g_pMainState->m_GlobalButton[4] = 50;
		g_pMainState->m_GlobalButton[6] = 12;
		g_pMainState->m_GlobalButton[5] = 10;
		SetChapter(7);
		g_pMainState->SetDialogListPet(m_Textlist[1], e��˽�);
		TalkList(0, 6, 3, 7, 3); break;
		break;
	case 3:
		g_pMainState->m_DialogList.clear();
		TalkList(3, 8, 3, 9, next); break;//����ɽ����
	case 4:TalkList(4, 10, 11, 12, next); break;//������
	case 5:AddTriggerDialog2(5, 6); break;//���ȹ���
	case 6:
	{
		g_pMainState->m_Map.LoadMap(21, 46, m_Textlist[13].c_str(), 0);
		g_pHeroObj->Set(POS_DEAD,0);
		TalkList(6, 14, 15, 16, next); 
	
		
			AddTriggerObjMap2(35, 15, e�������, 14, 15, 3,7);
			AddTriggerObjMap2(33, 15, e�ն���ʦ, 10, 14, 3,7);
			AddTriggerObjMap2(34, 15, e������ʦ, 28, 8, 7,7);
		}
		break;//������
	case 7://��Ԫ����
		if (CheckINT(12, 3))
		{
			g_pMainState->SetDialogListPC(m_Textlist[32], 9);
			AddTriggerDialog2(7, -7);
		}
		else
			AddTriggerDialog2(28, -7);
		break;
	case -7://��������
	
		{
			g_pMainState->ClearDialogList();
			cPetData* pPet;	
			pPet= AddPCPetEnemy2(60000, e��Ԫ����, 175, eMP_��ׯ��);
			pPet->m_SealRate.d1 += 50;
			pPet->m_MagicNumAdd += 3;
			pPet = AddPCPetEnemy2(30000, e�ն���ʦ, 170, eMP_������,33);
			pPet->m_DamageAddPercentCure.d1 += 50;	
			pPet->m_MagicNumAdd += 3;
			if (CheckINT(12, 3))
			{
				AddPCEnemy2(50000, 9, 0, 170, eMP_��ׯ��, 32);
				
			}
			pPet = AddPetEnemy2(50000, e���ӻ���, 140);
			pPet->m_Combo.d1 += 50;
			pPet = AddPetEnemy2(50000, e���ӻ���, 140);
			pPet->m_Combo.d1 += 50;
			
			SetMusic("Lacrimosa");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(-6);
		}
		return TRUE;
	case -6:
	
		{

			RemoveTriggerObjMap();
			g_pMainState->m_Map.RemoveAllNpc();
			SetJiangLi2(1500000, 250000, 500000, 2000000);
			
			TalkList(23,10,11,12,8);
			g_pMainState->m_GlobalButton[14] += 200;
			g_pMainState->m_GlobalButton[15] += 200;
			g_pCharacter->m_PCData.GetShangPinPet(6);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pCharacter->m_PCData.AddHpZZ(800);
			g_pCharacter->m_PCData.AddAtkZZ(200);
			g_pCharacter->m_PCData.AddAvoidZZ(200);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	
	case 8:AddTriggerDialog2(8, next); break;//���ȹ���
	case 9:
	
		{
			cPetData* pPet;	
			pPet = AddPCPetEnemy2(60000, e��ӿ����, 160, eMP_ħ��կ, 10);
			pPet->m_SealRate.d1 += 50;
			pPet->m_MagicNumAdd += 3;
			pPet = AddPCPetEnemy2(50000, e�ֹ�Ѳ��, 160, eMP_�칬);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(50000, e��������, 160, eMP_����ɽ);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(50000, e����, 160, eMP_���ƹٸ�);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);

			SetMusic("��Ӱ��Ե");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(next);
		}
		return TRUE;
	case 10:
		
		{
			SetJiangLi2(1000000, 500000, 500000, 2100000);
			
			TalkList(9, 6, 3, 7, next);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 11:TalkList(10, 17, 18, 19, next); break;//���ع���
	case 12:AddTriggerDialog2(11, next); break;//���ȹ���
	case 13:
		
		{
			cPetData* pPet;	
			pPet = AddPCEnemy2(100000, 2005, 0, 165, eMP_ħ��կ, 52);
			pPet->m_SealRate.d1 += 50;
			pPet->m_MagicNumAdd += 3;
			pPet = AddPCPetEnemy2(20000, e��ħ��, 135, eMP_�칬);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(20000, e��ħ��, 135, eMP_ħ��կ);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(20000, e��ħ��, 135, eMP_���ƹٸ�);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(20000, e��ħ��, 135, eMP_���ƹٸ�);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);

			SetMusic("Magia");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(next);
		}
		return TRUE;
	case 14:
	
		{

			SetJiangLi2(1000000, 5000000, 600000, 2200000);
			
			TalkList(12, 20, 21, 22, next);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 15://����
		
		{
			TalkList(13, 10, 11, 12, next);
			g_pCharacter->UseCard(133);
		}
		break;
	case 16:TalkList(14, 6, 3, 7, next); break;//���ȹ���
	case 17://����ɽ����
		
		{
			g_pCharacter->UseCard(-1);
			TalkList(15, 10, 11, 12, next); 
		}
		break;
	case 18:TalkList(16, 23, 3, 24, next); break;//���ȹ���
	case 19:TalkList(17, 25, 26, 27, next); break;//ţ����
	case 20:
		SetDialogList(25);
		TalkList(18, 17, 18, 19, next); break;//���湫��
	case 21:AddTriggerDialog2(19, next); break;//ţħ��
	case 22:
		
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(80000, eţħ��, 170, eMP_ħ��կ);
			pPet->m_MagicFire.d2 += 80;
			pPet->m_MagicNumAdd += 6;
			pPet->AddSkill(ePS_��������);
			pPet= AddPCPetEnemy2(60000, eǧ������, 165, eMP_��˿��,25);
			pPet->AddSkill(ePS_��������);
			pPet->m_MagicNumAdd += 3;
			ePetID petid;
			for (int i = 0; i < 3; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e̤����; break;
				default:petid = e̤����; break;
				}
				AddPCPetEnemy2(50000, petid, 150);
			}
			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(next);
		}
		return TRUE;
	case 23:
		
		{	
			AddTriggerDialog2(20, next);
		}
		break;
	case 24:
		
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(80000, e����ɳ��, 170, eMP_��˿��, 25);
			pPet->AddSkill(ePS_�߼���������);
			pPet->SetJinJie(3);
			pPet->m_MagicNumAdd += 3;
			pPet=AddPCPetEnemy2(50000, e�������, 160, eMP_Ů����);
			pPet->AddSkill(ePS_�߼������);
			pPet->SetJinJie(3);
			ePetID petid;
			for (int i = 0; i < 3; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e����ɳ��; break;
				default:petid = e����ɳ��; break;
				}
				AddPCPetEnemy2(50000, petid, 130);
			}
			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(next);
		}
		return TRUE;
	case 25:
		
		{
			SetJiangLi2(2000000, 500000, 1000000, 5500000);
			
			TalkList(21, 10, 11, 12, next);
			g_pMainState->ClearDialogList();
			g_pMainState->m_GlobalButton[14] += 200;
			g_pMainState->m_GlobalButton[15] += 200;
			g_pCharacter->m_PCData.AddMagZZ(150);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pCharacter->m_PCData.AddHpZZ(500);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 26:
		g_pMainState->SetDialogListPet(m_Textlist[1], e��˽�);
		TalkList(22, -1, -1, -1, -1,-26); break;//���ȹ���
	case -26:
		g_pMainState->m_DialogList.clear();
		//Process9(0);
		g_pMainState->m_TaskHuoDong.Start(���ɴ���);
		g_pMainState->m_TaskHuoDong.SetTrigger(this, 27, 24);
		return TRUE;
	case 27:
		TalkList(24, 36, 37, 38, 28, -27);
		return TRUE;
	case -27:
	
		{
			int id;
			UnInvite(m_Textlist[39]);
			UnInvite(m_Textlist[40]);
			id = g_pMainState->m_Friend.FindFriend("��ܽ");
			g_pMainState->m_Friend.m_FriendList[id].m_dataFileName = "��ܽ3";
			id = g_pMainState->m_Friend.FindFriend("ɵ�");
			g_pMainState->m_Friend.m_FriendList[id].m_dataFileName = "ɵ�2";
			Invite(m_Textlist[41]);
			Invite(m_Textlist[42]);
		}
		return TRUE;
	case 28:
		
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(50000, e���, 200, eMP_ʨ����);
			pPet->restoreRate += 30;
			ePetID petid;
			for (int i = 0; i < 7; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e���޿��ܹ�; break;
				case 1:petid = e�ֹ�Ѳ��; break;
				case 2:petid = e����ͯ��; break;
				default:petid = e���ӻ���; break;
				}
				AddPCPetEnemy2(100000, petid,155);
			}
			SetMusic("ս������2");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(next);
		}
		return TRUE;
	case 29:
	
		{
			SetJiangLi2(3000000, 500000, 1000000, 2500000);
			
			TalkList(25, -1, -1, -1, -1,30);
			g_pCharacter->m_PCData.AddGrowing(5);
			g_pCharacter->m_PCData.AddAtkZZ(200);
			g_pCharacter->m_PCData.AddDefZZ(100);
			g_pCharacter->m_PCData.AddMagZZ(200);
			g_pCharacter->m_PCData.AddHpZZ(1000);
			g_pCharacter->m_PCData.AddSpdZZ(100);
			g_pCharacter->m_PCData.AddAvoidZZ(100);

			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 30:
		
		{
			UnInvite(m_Textlist[41]);
			UnInvite(m_Textlist[42]);
			UnInvite(m_Textlist[43]);
			UnInvite(m_Textlist[44]);
			AddTriggerObjMap2(46, 45, 2000, 17, 13, 3);
			AddTriggerObjMap2(39, 45, 2010, 24, 12, 9);
			AddTriggerObjMap2(47, 45, 2001, 30, 10, 8);
			g_pMainState->m_Map.LoadMap(29, 12, m_Textlist[45].c_str(), 0);
			g_pHeroObj->Set(POS_DEAD, 0);
			TalkList(26,-1,-1,51,-1,31);
		}
		return TRUE;
	case 31:
	
		{
			g_pMainState->m_Map.RemoveAllNpc();
			RemoveTriggerObjMap();
			Invite(m_Textlist[46]);
			Invite(m_Textlist[47]);
			g_pMainState->FindObj();
			AddTriggerObjMap2(49, 50, 2013, 84, 37, 7,32);
			AddTriggerObjMap2(48, 50, 2008, 79, 41, 3,32);
		}
		return TRUE;
	case 32:
		
		{
			TalkList(27, -1, -1, -1, -1, 33);
			RemoveNpc(48);
			RemoveNpc(49, TRUE);
			int id = g_pMainState->m_Friend.FindFriend("���");
			g_pMainState->m_Friend.m_FriendList[id].m_dataFileName = "���2";
			Invite(m_Textlist[48]);
			Invite(m_Textlist[49]);
			g_pMainState->FindObj();
		}
		return TRUE;
	case 33:
		Process9(0);
		return TRUE;
	}
	return TRUE;
}

void cTaskJuQing::SetDialogList(int id)
{
	g_pMainState->SetDialogList(g_pMainState->FindObjByName(m_Textlist[id]));
}

BOOL cTaskZhuXian::Process8(int stage)
{
	int next = stage + 1;
	switch (stage)
	{
	case 0:
	
		{
			SetChapter(8);
			g_pMainState->m_GlobalButton[5] = 3;
			g_pMainState->SetDialogListPet(m_Textlist[1],eɳ����);
			TalkList(0, 2, 3, 4, next); break;
		}
		break;
	case 1:
		g_pMainState->m_DialogList.clear();
		TalkList(2, 8, 9, 10, 3); break;//���Ž���
	case 3:TalkList(3, 11, 9, 12, next); break;//����ʦ
	case 4:AddTriggerDialog2(4, next); break;//����
	case 5:
		
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(20000, e����, 80, eMP_��������,11);
			pPet->m_MagicWater.d2 += 20;
			pPet->SetJinJie(3);
			for (int i = 0; i < 4; i++)
			{
				pPet= AddPCPetEnemy2(15000, e����, 80);
				pPet->m_MagicWater.d2 += 20;
			}
			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(next);
		}
		return TRUE;
	case 6:
		
		{
			SetJiangLi2(250000, 100000, 50000, 600000);
			
			sNpc npc;
			npc.Reset();
			npc.Set(m_Textlist[13], m_Textlist[14], 82, 41, 73,3);
			AddTriggerObjMap(&npc, -1);
			npc.Set(m_Textlist[16], m_Textlist[14], 1074, 32, 75,3);
			AddTriggerObjMap(&npc,-1,FALSE);
			TalkList(5, 13, 14, 15, next);
			AddTriggerObj2(8, 9, 106, FALSE);
			g_pCharacter->m_PCData.AddDefZZ(50);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 106:
		AddTriggerDialog2(16);
		return TRUE;
	case 7:AddTriggerDialog2(6, next); break;//Ы�Ӿ�
	case 8:
	
		{
			UnInvite(m_Textlist[27]);
			cPetData* pPet;
			pPet= AddPCPetEnemy2(50000, eЫ�Ӿ�, 100, eMP_Ů����);
			pPet->poisonRate.d1 += 20;
			pPet->SetJinJie(3);
			for (int i = 0; i < 4; i++)
			{
				pPet = AddPCPetEnemy2(10000, e���㽫��, 85);
				pPet->m_MagicWater.d2 += 20;
			}
			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(next);
		}
		return TRUE;
	case 9:
		
		{
			RemoveNpc(13,TRUE);
			RemoveTriggerObjMap(7);
			SetJiangLi2(300000, 100000, 50000, 650000);
			
			sNpc npc;
			npc.Set(m_Textlist[13], m_Textlist[14], 82, 50, 50,0);
			TalkList(7, 16, 14, 17, next,109);
			g_pCharacter->m_PCData.AddHpZZ(300);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 109:
		UnInvite(m_Textlist[28]);
		UnInvite(m_Textlist[29]);
		break;
	case 10:TalkList(8, 18, 6, 19, next); break;//����
	case 11:	
		g_pMainState->SetDialogListNpc(m_Textlist[16],1074);
		TalkList(9, 20, 21, 22, next); 
		RemoveTriggerObjMap();
		break;//����Ů������
	case 12:
		g_pMainState->ClearDialogList();
		TalkList(10, 23, 24, 25, next); break;//����
	case 13:
		Invite(m_Textlist[28]);
		Invite(m_Textlist[29]);
		Invite(m_Textlist[27]);
		TalkList(11, 20, 21, 22, next); 
		break;//������Ů
	case 14:AddTriggerDialog2(12, next); break;//���ػ�Ӱ
	case 15:
		
		{
			AddTriggerDialog2(17);
			cPetData* pPet;
			 pPet= AddPCEnemy2(20000, 1, 0, 100, eMP_������,26,0,6);
			 pPet->m_CureCriRate.d1 += 20;
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e����; break;
				case 1:petid = e����; break;
				case 2:petid = e��ˮҹ��; break;
				default:petid = e����; break;
				}
				AddPCPetEnemy2(10000, petid, 68, (eMengPai)(rand() % 12));
			}
			SetMusic("��ɫ�ಾ�");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(next);
		}
		return TRUE;
	case 16:
		{
			SetJiangLi2(250000, 100000, 50000, 700000);
		
			TalkList(13, 18, 6, 19, next);
			g_pCharacter->m_PCData.AddSpdZZ(50);
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 17:TalkList(14, 20, 21, 22, next); break;//����Ů������
	case 18:
		TalkList(15, -1, -1, -1, -1,19); 
		break;//����
	case 19:
		g_pCharacter->m_PCData.AddGrowing(5);
		SetJiangLiItem(12, 41);
		return Process3(0);

	}
	return TRUE;
}

BOOL cTaskZhuXian::Process9(int stage)
{
	int next = stage + 1;
	switch (stage)
	{
	case 0:
		g_pMainState->m_GlobalButton[4] = 180;
		g_pMainState->m_GlobalButton[6] = 30;
		SetChapter(9);
		g_pMainState->m_GlobalButton[5] = 16;
		AddTriggerObj2(6,7,1);
		UpdateJob2(8);
		return TRUE;
	case 1:
		TalkList(4,-1,-1,-1,5,-1);
		SetJiangLi2(10000000, 1000000, 5000000);
		SetJiangLiItem(23,28);
		AddTriggerObjMap2(1, 4, e�׿���, 143, 83, 3, 2);
		AddTriggerObjMap2(3, 4, 2014, 149, 83, 2, 2);
		AddTriggerObjMap2(2, 4, 2012, 146, 87, 2, 2);
		UpdateJob2(5);
		return TRUE;
	case 2:
		AddTriggerDialog2(0, next);
		break;
	case 3://
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(250000, e�׿���, 175, eMP_���ƹٸ�);
			pPet->poisonRate.d1 = 100;
			pPet->poisonRate.d2 = 100;
			pPet->m_DamageAddPercentPoision.d1= 200;
			pPet->m_DamageAddPercentPoision.d2 = 200;
			AddFriend(3);
			Invite(m_Textlist[3], 11);
			pPet= AddPetEnemy2(120000, e��������, 175);
			pPet->SetJinJie(3);
			pPet=AddPetEnemy2(120000, e����������, 175);
			pPet->SetJinJie(3);
			pPet = AddPetEnemy2(120000, e�������, 175);
			pPet->SetJinJie(3);
			ePetID petid;
			for (int i = 0; i < 3; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e����ɳ��; break;
				case 1:petid = e��������; break;
				case 2:petid = e��������; break;
				default:petid = eѲ������; break;
				}
				pPet=AddPCPetEnemy2(80000, petid, 155);
				pPet->SetJinJie(3);
			}
		
			SetMusic("����");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(next);
		}
		return TRUE;
	case 4:
		
		{
			SetJiangLi2(3000000, 1000000, 1000000, 3000000);
		
			TalkList(1,-1,-1,-1,-1,5);
			g_pMainState->m_GlobalButton[14] += 200;
			g_pMainState->m_GlobalButton[15] += 200;
			g_pCharacter->m_PCData.AddSpdZZ(100);
			g_pCharacter->m_PCData.AddGrowing(2);
			if (CheckINT(11, 1))
			{
				g_pCharacter->m_PCData.GoldLivePercent.d1 += 100;
			}
			else
			{
				LockMap(32);
				LockMap(33);
				AddChannel2(27);
			}
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case 5:
		UnInvite(m_Textlist[12]);
		UnInvite(m_Textlist[13]);
		Invite(m_Textlist[2]);
		Invite(m_Textlist[3]);
		RemoveTriggerObjMap();
		RemoveNpc(1);
		RemoveNpc(3);
		RemoveNpc(2,TRUE);
		g_pMainState->m_TaskFB.Start(4);
		g_pMainState->m_TaskFB.Process(0);
		g_pMainState->m_TaskFB.SetTask(this, 6);
		return TRUE;
	case 6:
		g_pMainState->SetDialogListPet(m_Textlist[14], e�);
		TalkList(2, -1, -1, 9,-1, -6);
	
		AddTriggerObjMap2(10, 11, e���, 151, 60, 3, 7,4);

		AddTriggerObjMap2(15, 11, e֪����, 153, 51, 3, 11, 3);
		AddTriggerObjMap2(15, 11, e����, 167, 59, 3, 12, 3);

		AddTriggerObjMap2(16, 11, eè����, 176, 51, 3, 13, 3);
		AddTriggerObjMap2(16, 11, e��, 162, 45, 3, 14, 3);

		/*AddTriggerObjMap2(17, 11, e���޿��ܹ�, 175, 39, 3, 15, 3);
		AddTriggerObjMap2(17, 11, e���޿�����, 190, 45, 3, 16, 3);*/
		UpdateJob2(9);
		if (CheckINT(11, 1))
		{
			AddTriggerObjMap2(28,11,2007,160,54,1,7);	
			UpdateJob2(31);
		}
		return TRUE;
	case -6:
		if (CheckINT(11, 1))
		{
			TalkList(8, 29, 30, 9, -7);
			UpdateJob2(9);
		}
		return TRUE;
	case -7:
		for (int i = 0; i < 5; i++)
		{
			cPetData* pPet;
			g_pMainState->m_FightList[i].m_pData->GetDateP(pPet);
			pPet->AddSkill(ePS_�����ػ�);
		}
		AddTriggerDialog2(9);
		RemoveTriggerObj();
		return TRUE;
	case 7:
		g_pMainState->ClearDialogList();
		AddTriggerDialog2(3, -8);
		break;
	case -8:
		if (CheckINT(11, 1))
		AddTriggerDialog2(6, 8);
		else Process9(8);
		break;
	case 8://����BOSS
		{
			cPetData* pPet;

			if (CheckINT(11, 1))
			{
				sZiZhi zizhi;
				zizhi.Set(2000, 2000, 5000, 90000, 2000, 2000, 170);
				pPet= AddPCEnemy2(1500000,2007,&zizhi,200,eMP_ħ��կ,28,9,28);
				pPet->AddSkill(ePS_�߼���������);
				pPet->AddSkill(ePS_�߼���������);
				pPet->AddSkill(ePS_�߼���������);
				pPet->AddSkill(ePS_�߼�ħ֮��);
				pPet->AddSkill(ePS_�߼�������);
				pPet->AddSkill(ePS_�߼����Ӹ���);
				pPet->AddSkill(ePS_�߼�����);
				pPet->AddSkill(ePS_�߼�����);
				pPet->AddSkill(ePS_�߼�����);
				pPet->AddSkill(ePS_�߼�����);
				pPet->GoldLivePercent.d1 += 990000;
				pPet->m_LiveHpLv += 10000;
			}
			pPet=AddPCPetEnemy2(100000, e���, 200, eMP_ʨ����);
			pPet->restoreRate += 30;
			pPet->m_JinJieNum.m_PositionID = 3;
			pPet = AddPCPetEnemy2(100000, eЫ�Ӿ�, 200, eMP_Ů����, 19);
			pPet->abnormalResist += 10;
			pPet->poisonRate.d1 += 50;
			pPet->m_DamageAddPercentPoision.d1 +=50;
			pPet->poisonRate.d2 += 50;
			pPet->m_JinJieNum.m_PositionID = 3;
			pPet = AddPCPetEnemy2(150000, e��ƿŮ�, 200, eMP_����ɽ,18);
			pPet->abnormalResist += 10;
			pPet->m_JinJieNum.m_PositionID = 3;
			pPet = AddPCPetEnemy2(150000, e��Ѫ��, 200, eMP_���ܵظ�, 21);
			pPet->m_SuckBloodRate.d1 += 20;
			pPet->m_SuckBloodRate.d2 += 50;
			pPet->abnormalResist += 10;
			pPet->m_JinJieNum.m_PositionID = 3;
			pPet = AddPCPetEnemy2(150000, e������Գ, 200, eMP_���ƹٸ�, 20);
			pPet->abnormalResist += 10;
			pPet->m_AtkDownHPHurt.d1 += 10;
			pPet->m_JinJieNum.m_PositionID = 3;
			pPet = AddPCPetEnemy2(150000, e����, 200, eMP_�칬, 22);  
			pPet->m_DamagePercent.d2 += 20;
			pPet->abnormalResist += 10;
			pPet->m_JinJieNum.m_PositionID = 3;
			pPet = AddPCPetEnemy2(150000, e����, 200, eMP_��������, 24);
			pPet->m_MagicWater.d2 += 30;
			pPet->m_MagicWater.d1 += 10;
			pPet->abnormalResist += 10;
			pPet->m_JinJieNum.m_PositionID = 3;
			pPet->m_Controler.Set(0);
			pPet = AddPCPetEnemy2(100000, e��ʦ, 200, eMP_������, 23);
			pPet->m_MagicWater.d2 += 30;
			pPet->abnormalResist += 10;
			pPet->m_JinJieNum.m_PositionID = 3;
		
			pPet = AddPCPetEnemy2(100000, e������, 200, eMP_��ׯ��, 26);
			pPet->GoldLivePercent.d1 += 10;
			pPet->abnormalResist += 10;
			pPet->m_JinJieNum.m_PositionID = 3;
	
			if (CheckINT(11, 1))
			{
				AddTriggerFightTurn(-9);
				AddTriggerFightSuccess(9);
			}
			else
			{
				pPet = AddPCPetEnemy2(150000, e��ɽ����, 200, eMP_ħ��կ, 25);
				pPet->abnormalResist += 10;
				pPet->m_LiveHpLv += 10;
				pPet->SetJinJie(3);
				pPet->m_Controler.Set(0);
				AddTriggerFightSuccess(next);
			}
			g_pMainState->m_InterfaceTeam.SetFormation(sky, TRUE);
			SetMusic("������ս¼");
			g_StateType = STATE_FIGHT;
		
		}
		return TRUE;
	case -9:
		{//ֻʣһ������,ս������
			int num = g_pMainState->GetLiveNum(10, 20);
			//cAttackAI& ai = g_pMainState->m_AI.m_AttackAI;
			if (num<2)
			{
				g_pMainState->m_pFightState->SuccessFight();
			}
		}
		return TRUE;
	case 9:
		g_pMainState->LockLv(45);
		if (CheckINT(11, 1))
		{
			TalkList(7, -1, -1, -1, -1, 10);
		}
		else
		TalkList(5, -1, -1, -1, -1, 10);
		return TRUE;
	case 10:
		g_StateType = STATE_EXT;
		return TRUE;
	case 11://֪����
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(16000, e֪����, 180, eMP_�칬,15);
			pPet->m_CounterRate.d1 += 50;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e���Ů�, 170, eMP_ħ��կ);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e��ƿŮ�, 170, eMP_����ɽ);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, eܽ������, 165);
			pPet->m_LiveHpLv += 10;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e��������, 165);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e�ɷ�Ů�, 165);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e��������, 165);
			pPet->m_Combo.d1 += 40;
			pPet->comboNumUp += 5;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e����, 165, eMP_��������);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e����ɳ��, 165);
			pPet->m_LiveHpLv += 30;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e��������, 165);
			pPet->SetJinJie(3);
			g_pMainState->m_InterfaceTeam.SetFormation(bird, TRUE);
			SetMusic("�ɽ�4ս��BGM");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(-11);
		}
		return TRUE;
	case -11:
		{
			SetJiangLi2(4000000, 1000000, 1000000, 3000000);
			
			g_pMainState->m_Map.RemoveNpc(153 * 20, g_pMainState->m_Map.m_pMap->m_Height - 51 * 20,  m_Textlist[15], TRUE);
			RemoveTriggerObjMap(11);
			g_pCharacter->m_PCData.AddGrowing(1);
		}
		return TRUE;
	case 12://����
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(16000, e����, 175, eMP_���ƹٸ�);
			pPet->m_CriRate.d1 += 30;
			pPet->m_CriAddPercent.d1 += 30;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, eϬţ������, 170);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e��, 170);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, eϬţ����, 165);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e����ͯ��, 165);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e������, 165);
			pPet->m_DamagePercent.d2 += 10;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e��Ѫ��, 165);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, eѲ������, 166);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e���ӻ���, 165);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e�ֹ�Ѳ��, 166);
			pPet->SetJinJie(3);
			SetMusic("UnfathomedForce");
			g_pMainState->m_InterfaceTeam.SetFormation(eagle, TRUE);
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(-12);
			
		}
		return TRUE;
	case -12:
		{
			SetJiangLi2(4000000, 1500000, 1500000, 3000000);
			
			g_pMainState->m_Map.RemoveNpc(167 * 20, g_pMainState->m_Map.m_pMap->m_Height - 59 * 20, m_Textlist[15], TRUE);
			RemoveTriggerObjMap(12);
			g_pCharacter->m_PCData.AddGrowing(1);
		}
		return TRUE;
	case 13://eè����
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(16000, eè����, 170, eMP_���ƹٸ�);
			pPet->m_SPD.AddDataAddPercent(30);
			pPet->m_AtkDownDef.d1 = 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, eè��, 165);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, eЫ�Ӿ�, 160);
			pPet->poisonRate.d1 += 20;
			pPet->poisonRate.d2 += 20;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e����, 160);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e������, 160);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, eǧ������, 160);
			pPet->poisonRate.d1 += 20;
			pPet->poisonRate.d2 += 20;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e����, 160);
			pPet->poisonRate.d1 += 20;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e���컢, 160);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, eǧ������, 160);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e����, 160);
			pPet->SetJinJie(3);
			SetMusic();
			g_pMainState->m_InterfaceTeam.SetFormation(dragon, TRUE);
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(-13);
		}
		return TRUE;
	case -13:
		{
			SetJiangLi2(3000000, 1500000, 1500000, 3000000);
		
			g_pMainState->m_Map.RemoveNpc(176 * 20, g_pMainState->m_Map.m_pMap->m_Height - 51 * 20, m_Textlist[16], TRUE);
			RemoveTriggerObjMap(13);
			g_pCharacter->m_PCData.AddGrowing(1);
		}
		return TRUE;
	case 14://e��
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(16000, e��, 165, eMP_���ƹٸ�);
			pPet->m_CriRate.d1 += 20;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e�콫, 160);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e���, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e������, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e������, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e������, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e����, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e̤����, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e����, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e����, 155);
			pPet->SetJinJie(3);
			SetMusic("stonecoldFictionJunction");
			g_StateType = STATE_FIGHT;
			g_pMainState->m_InterfaceTeam.SetFormation(wind, TRUE);
			AddTriggerFightSuccess(-14);
		}
		return TRUE;
	case -14:
		{
			SetJiangLi2(3000000, 1000000, 1000000, 3000000);
			
			g_pMainState->m_Map.RemoveNpc(162*20,g_pMainState->m_Map.m_pMap->m_Height- 45*20, m_Textlist[16], TRUE);
			RemoveTriggerObjMap(14);
			g_pCharacter->m_PCData.AddGrowing(1);
		}
		return TRUE;
	case 15://e���޿��ܹ�
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(16000, e���޿��ܹ�, 160, eMP_���ƹٸ�);
			pPet->m_SuckBloodRate.d1 += 20;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e�Ŵ�����, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e��������, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e���, 155);
			pPet->m_MagicFire.d2 += 50;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e����, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e�粮, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e��ʦ, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e������, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e���㽫��, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e�������, 155);
			pPet->m_DamagePercent.d2 += 20;
			pPet->SetJinJie(3);
			SetMusic("δ������");
			g_pMainState->m_InterfaceTeam.SetFormation(land, TRUE);
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(-15);
		}
		return TRUE;
	case -15:
		{
			SetJiangLi2(2500000, 1000000, 1000000, 2500000);
			
			g_pMainState->m_Map.RemoveNpc(175 * 20, g_pMainState->m_Map.m_pMap->m_Height - 39 * 20, m_Textlist[17], TRUE);
			RemoveTriggerObjMap(15);
			g_pCharacter->m_PCData.AddGrowing(1);
		}
		return TRUE;
	case 16://e���޿�����
	
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(16000, e���޿�����, 160, eMP_���ƹٸ�);
			pPet->m_LiveHpLv += 10;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e������, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e�̻�ռ��ʦ, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, eС��Ů, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e�Ʋ�ͯ��, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, eСëͷ, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, eСħͷ, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, eС����, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, eС����, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, eСѾѾ, 155);
			pPet->SetJinJie(3);
			SetMusic();
			g_pMainState->m_InterfaceTeam.SetFormation(tiger, TRUE);
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(-16);
		}
		return TRUE;
	case -16:
	
		{
			SetJiangLi2(2500000, 1000000, 1000000, 2500000);
			
			g_pMainState->m_Map.RemoveNpc(190 * 20, g_pMainState->m_Map.m_pMap->m_Height - 45 * 20, m_Textlist[17], TRUE);
			RemoveTriggerObjMap(16);
			g_pCharacter->m_PCData.AddGrowing(1);
		}
		return TRUE;
	}
	return TRUE;
}


void cTaskJuQing::Select(int title, int name, int cancelret, int select0, int ret0, int select1, int ret1, int select2, int ret2, int select3, int ret3)
{
	if (select3 > -1)
	{
		g_pMainState->m_TriggerDialog.AddSelect(this, m_Textlist[title], m_Textlist[name], cancelret,
			m_Textlist[select0], ret0,
			m_Textlist[select1], ret1,
			m_Textlist[select2], ret2,
			m_Textlist[select3], ret3
			);
	}
	else
	if (select2 > -1)
	{
		g_pMainState->m_TriggerDialog.AddSelect(this, m_Textlist[title], m_Textlist[name], cancelret,
			m_Textlist[select0], ret0,
			m_Textlist[select1], ret1,
			m_Textlist[select2], ret2
			);
	}
	else
	{
		g_pMainState->m_TriggerDialog.AddSelect(this, m_Textlist[title], m_Textlist[name], cancelret,
			m_Textlist[select0], ret0,
			m_Textlist[select1], ret1
			);
	}
	g_pMainState->m_Dialog.m_bRetSelect = TRUE;
}

cPetData* cTaskJuQing::GetPetData(int id)
{
	cPetData* p;
	g_pMainState->m_FightList[id].m_pData->GetDateP(p);
	return p;
}

int cTaskJuQing::GetCharacterID(string name)
{
	for (int i = 0; i < 5; i++)
	{
		if (g_pMainState->m_FightList[i].m_pData->m_TrueName.GetString() == name)
		{
			return i;
		}
	}
	return -1;
}

void cTaskJuQing::Invite(string name,int fighterid)
{
	g_pMainState->m_Friend.Invite(name,fighterid);
}

int cTaskJuQing::AddPetEnemy(ePetID id, int lv, int name/*=""*/, BOOL bOur, int pos)
{//�޸���ͨ�ٻ��޵��˼ӵ�
	string namet;
	sAddPoint m_AddPoint;
	if (name == -1)namet = "";
	else namet = m_Textlist[name];
	switch (id)
	{
	case 0:
	case 15:
	case 17:
	case 18:
	case 22:
	case 27:
	case 29:
	case 31:
	case 37:
	case 38:
	case 39:
	case 40:
	case 44:
	case 45:
	case 48:
	case 50:
	case 52:
	case 55:
	case 58:
	case 61:
	case 69:
	case 89:
	case 93:
	case 137:
		m_AddPoint.Set(0, 0, 4, 1, 0); break;
	default:
		m_AddPoint.Set(4, 0, 0, 1, 0); break;
	}
	return g_pMainState->AddPetEnemy(namet, id, lv, &m_AddPoint, -1, pos, bOur);
}

int cTaskJuQing::AddPCPetEnemy(ePetID id, int lv, eMengPai mp, int name /*= ""*/, BOOL bOur, int pos)
{//�޸����ɵ��˼ӵ�
	string namet;
	sAddPoint m_AddPoint;
	if (name == -1)namet = "";
	else namet = m_Textlist[name];
	switch (mp)
	{
	case eMP_��������:
	case eMP_ħ��կ:
	case eMP_����ɽ:m_AddPoint.Set(0, 0, 4, 1, 0); break;
	case eMP_������:
	case eMP_���ܵظ�:m_AddPoint.Set(0, 2, 0, 2, 1); break;
	case eMP_Ů����:
	case eMP_����ɽ:m_AddPoint.Set(0, 1, 0, 2, 2); break;
	default:m_AddPoint.Set(4, 0, 0, 1, 0); break;
	}
	return g_pMainState->AddPCPetEnemy(id, lv, &m_AddPoint, mp, namet,-1, bOur,pos);
}

int cTaskJuQing::AddPCEnemy(int id, sZiZhi* zz, int lv, eMengPai mp, int name /*= ""*/, int weapontype, int weaponid, BOOL bOur, int pos)
{
	string namet;
	if (name == -1)namet = "";
	else namet = m_Textlist[name];
	if (weaponid == -1)
	{
		return g_pMainState->AddPCEnemy(namet, id, lv, &m_AddPoint, zz, mp, 0, -1, -1,  pos, bOur);
	}
	else
	{
		sItem2 item;
		item.Set(weapontype, weaponid);
		return g_pMainState->AddPCEnemy(namet, id, lv, &m_AddPoint, zz, mp, &item, -1, -1, pos, bOur);
	}
}



void cTaskJuQing::Init()
{
	if (m_Chapter == -1)return;
	if (m_bInit)return;
	m_bInit = TRUE;
	ifstream File;
	string data;
	File.open(SetUpPathJuQing("index"));
	if (!File)
		ERRBOX;
	for (int i = 0; i <= m_Chapter; i++)
	{
		getline(File, data);
	}
	File.close();
	//}
	File.open(SetUpPathJuQing(data));
	if (!File)
		ERRBOX;
	int num;
	File >> num;
	getline(File, data);
	m_Textlist.resize(num);
	for (int i = 0; i < num; i++)
	{
		getline(File, data); 
		m_Textlist[i]=data;
	}
	File.close();
	m_AddPoint.Set(4, 0, 0, 1, 0);
}



BOOL cTaskZhiXian::Process(int stage)
{
	
	switch (m_Chapter)
	{
	case 0:return Process0(stage);
	case 2:return Process2(stage);
	case 3:return Process3(stage);
	case 4:return Process4(stage);
	case 6:return Process6(stage);
	default:return Process1(stage);
	}
}

BOOL cTaskZhiXian::Process0(int stage)
{
//	int lv = g_pCharacter->m_PCData.m_LV;
	switch (stage)
	{
	case -1:return TRUE;
	case 0://����Ұ��
	
		{
			int& num = g_pMainState->m_GlobalButton[11];
			if (num & 0x01)return TRUE;
			AddTriggerDialog2(0, 1);
		}
		break;
	case 1:Select(2, 1, -1, 3, 2, 4, -1);break;
	case 2:
		
		{
			sItem2* pItem= FindItem(28, 23);
			if (pItem)
			{
				pItem->m_Num = 0;
				SetINT(11, 0);
				sShangPinPet pet;
				sAddPoint point;
				point.Set(0, 0, 4, 1, 0);
				pet.Set(e������, &point);
				pet.m_zizhi.m_MAGZZ = 5000;
				pet.m_zizhi.m_SPDZZ = 1700;
				pet.m_zizhi.m_HPZZ = 10000;
				pet.m_zizhi.m_Growing = 170;
				pet.AddSkill(ePS_������);
				pet.AddSkill(ePS_�׻�);
				pet.AddSkill(ePS_�߼�ħ֮��);
				pet.AddSkill(ePS_�߼���������);
				pet.AddSkill(ePS_�߼���������);
				pet.AddSkill(ePS_�߼�����);
				pet.AddSkill(ePS_�߼�������);
				pet.AddSkill(ePS_�߼����Ӹ���);
				pet.AddSkill(ePS_�߼�����);
				pet.AddSkill(ePS_�����ػ�);
				pet.AddSkill(ePS_�߼�����);
				pet.AddSkill(ePS_�߼��м�);
				pet.AddSkill(ePS_�߼�����);
				pet.AddSkill(ePS_�߼�����);
				pet.AddSkill(ePS_�߼��۸�);
				pet.AddSkill(ePS_�߼�ڤ˼);
				pet.AddSkill(ePS_�ƻ���ľ);
				GetPet2(&pet, 100);
			}
		}
		break;
	case 3://������
		if (g_pCharacter->m_PCData.m_Money[0] < 2000)
		{
			AddTriggerDialog2(2);
			SetJiangLi2(0, 2000);
		}
		else AddTriggerDialog2(3);
		break;
	case 4:Select(6, 5, -1, 3, 5, 4, -1); break;//����
	case 5:	g_pMainState->m_Dazao.OnOff(TRUE); break;
	case 6:
		if (g_pCharacter->m_PCData.m_BangPaiID == -1)
		{
			TalkList(4,-1,-1,-1,-1);
		}
		else Select(8,7,-1,3,7,4,-1);
		return TRUE;
	case 7:
		g_pMainState->m_Map.LoadMap(124, 115,"����", 0);
		break;
	case 8://�þ�֮��
		if (!CheckINT(11, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(300000, e�������, 220, eMP_���ܵظ�, 18);
			pPet->m_MagicFire.d2 += 50;
			pPet->m_MagicNumAdd += 8;
			pPet->SetJinJie(3);
			pPet->AddSkill(ePS_��������);
			pPet->AddSkill(ePS_�߼�������);
			pPet->AddSkill(ePS_�߼�������);
			pPet = AddPCPetEnemy2(180000, e���޿��ܹ�, 200, eMP_ʨ����, 20);
			pPet->m_MagicNumAdd += 2;
			pPet->SetJinJie(3);

			for (int i = 0; i < 3; i++)
			{
				AddPetEnemy2(150000, e�������, 220, 19);
			}
			SetMusic(m_Textlist[9]);
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(9);
		}
		else AddTriggerDialog2(11);
		return TRUE;
	case 9: //
		
		{
			SetJiangLi2(30000000, 5000000, 500000, 1000000, TRUE);
			SetJiangLiItem(23,24);
			SetJiangLiItem(100, 40);
			SetJiangLiItem(76, 40);
			AddTriggerDialog2(5);
			SetINT(11, 1);
			g_pMainState->m_GlobalButton[14] += 200;
			g_pMainState->m_GlobalButton[15] += 200;
			g_pCharacter->m_PCData.AddGrowing(5);
			g_pCharacter->m_PCData.AddAtkZZ(1000);
			g_pCharacter->m_PCData.AddDefZZ(1000);
		}
		return TRUE;
	case 10:
		if (g_pMainState->m_State.CheckAddPoint())
		{
			Select(12, 10, -1, 3, 12, 4, -1);
		}
		else
		{
			Select(11, 10, -1, 3, 11, 4, -1);
		}
		return TRUE;
	case 11:
		g_pMainState->m_State.SetAddPoint();
		return TRUE;
	case 12:
		
		{
			g_pCharacter->m_PCData.ResetAddPoint();
			g_pMainState->m_State.SetAddPoint();
		}
		return TRUE;
	case 13:
		
		{
			if (g_pMainState->m_FangWu.GetGuiMo() > 3)
			{
				AddTriggerDialog2(6);
				return TRUE;
			}
			ostringstream oss;
			oss << "��ǰ���ݹ�ģΪ";
			oss << g_pMainState->m_FangWu.GetGuiMo();
			oss << "������Ҫ";
			oss << (g_pMainState->m_FangWu.GetGuiMo()+1) * 200;
			oss << "��,��Ҫ��?";
			g_pMainState->m_TriggerDialog.AddSelect(this, oss.str(), g_pMainState->m_pNowSelect->m_TrueName.GetString(), -1,
				m_Textlist[3], 14,
				m_Textlist[4], -1
				);
		}
		return TRUE;
	case 14:
		if (g_pCharacter->m_PCData.AddMoney(-(g_pMainState->m_FangWu.GetGuiMo() + 1) * 2000000,0,0,FALSE))
		{
			g_pMainState->m_FangWu.SetGuiMo(g_pMainState->m_FangWu.GetGuiMo() + 1);
		}
		else g_pMainState->m_pNowSelect->Talk("Ǯ����");
		return TRUE;
	case 15:
		if (!CheckINT(12, 5))
		{
			AddTriggerDialog2(7);
			SetINT(12, 4);
		}
		return TRUE;
	case 16:
		if (CheckINT(12, 4)&&(!CheckINT(12,5)))
		{
			AddTriggerDialog2(8,17);
		}
		return TRUE;
	case 17:
		
		{
			cPetData* pet;
			pet= AddPCPetEnemy2(20000, e��̫��, 90);
			pet->ghostSpecial.d1 += 100;
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 3)
				{
				case 0:petid = e���㽫��; break;
				case 1:petid = eҰ��; break;
				default:petid = e��ë����; break;
				}
				AddPCPetEnemy2(15000, petid, 85, (eMengPai)(rand() % 12));
			}
			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(18);
		}
		return TRUE;
	case 18:
		
		{
			SetJiangLi2(1250000, 250000, 250000, 1250000);
			AddTriggerDialog2(9); 
			SetJiangLiItem(44,40);
			SetJiangLiItem(25,24);
			g_pCharacter->m_PCData.AddGrowing(1);
			SetINT(12,5);
		}
		return TRUE;
	case 19:
		
		{
			if (g_pCharacter->m_PCData.m_FightPetID == -1)return TRUE;
			cPetData& Pet = g_pCharacter->m_PCData.m_pPetDataList[g_pCharacter->m_PCData.m_FightPetID]->m_PetDataZZ;
			ostringstream oss;
			switch (Pet.m_JinJieNum.m_JinJieNum)
			{
			case 0:
			case 1:
			case 2:
				oss << "��ĳ�ս�ٻ������´ν��׻���" << (Pet.m_JinJieNum.m_JinJieNum+1)*500000;
				break;
			default:
				oss << "��ĳ�ս�ٻ����Ѿ��޷��ٽ�����";
				break;
			}
			m_pObj = g_pMainState->m_pNowSelect;
			g_pMainState->m_TriggerDialog.AddSelect(this, oss.str(), m_pObj->m_TrueName.GetString(), -1,
				m_Textlist[3], 20,
				m_Textlist[4], -1);
		}
		break;
	case 20:
		
		{
			if (g_pCharacter->m_PCData.m_FightPetID == -1)return TRUE;
			cPetData& Pet = g_pCharacter->m_PCData.m_pPetDataList[g_pCharacter->m_PCData.m_FightPetID]->m_PetDataZZ;
			if (g_pCharacter->m_PCData.AddMoney(-(Pet.m_JinJieNum.m_JinJieNum + 1) * 500000,0,0,0))
			{
				Pet.SetJinJie(1);
				m_pObj->Talk("���׳ɹ�");
				g_pMainState->m_PCHead.UpdatePet();
			}
			else m_pObj->Talk("Ǯ����");
		}
		break;
	case 21:
		
		{
			m_pObj = g_pMainState->m_pNowSelect;
			g_pMainState->m_TriggerDialog.AddSelect(this,m_Textlist[13], m_pObj->m_TrueName.GetString(), -1,
				m_Textlist[3], 22,
				m_Textlist[4], -1);
		}
		break;
	case 22:
		
		{
			if (g_pCharacter->m_PCData.AddMoney(-1000000, 0, 0, 0))
			{
				vector<int> lis;
				g_pMainState->m_ZuoQi.GetShiPei(lis, g_pCharacter->m_PCData.modeid);
				g_pMainState->m_ZuoQi.GetZuoQi(g_pCharacter->m_PCData, lis[rand()%lis.size()]);
				m_pObj->Talk("�õ�������");
			}
			else m_pObj->Talk("Ǯ����");
		}
		break;
	case 23:
		
		{
			BOOL bhave[5] = {0};
			for (int i = 0; i < 60; i++)
			{
				if (27 == g_pCharacter->m_PCData.m_Item[i].GetType())
				{
					switch (g_pCharacter->m_PCData.m_Item[i].GetID())
					{
					case 6:bhave[0] = TRUE; break;
					case 7:bhave[1] = TRUE; break;
					case 8:bhave[2] = TRUE; break;
					case 9:bhave[3] = TRUE; break;
					case 10:bhave[4] = TRUE; break;
					default:break;
					}
				}
			}
			for (int i = 0; i < 5; i++)
			{
				if (!bhave[i])
				{
					AddTriggerDialog2(10);
					return TRUE;
				}
			}
			for (int i = 0; i < 60; i++)
			{
				if (27 == g_pCharacter->m_PCData.m_Item[i].GetType())
				{
					switch (g_pCharacter->m_PCData.m_Item[i].GetID())
					{
					case 6:
						if (bhave[0])
						{
							bhave[0] = 0;
							g_pCharacter->m_PCData.m_Item[i].m_Num -= 1;
						}
						break;
					case 7:
						if (bhave[1])
						{
							bhave[1] = 0;
							g_pCharacter->m_PCData.m_Item[i].m_Num -= 1;
						}
						break;
					case 8:
						if (bhave[2])
						{
							bhave[2] = 0;
							g_pCharacter->m_PCData.m_Item[i].m_Num -= 1;
						}
						break;
					case 9:
						if (bhave[3])
						{
							bhave[3] = 0;
							g_pCharacter->m_PCData.m_Item[i].m_Num -= 1;
						}
						break;
					case 10:
						if (bhave[4])
						{
							bhave[4] = 0;
							g_pCharacter->m_PCData.m_Item[i].m_Num -= 1;
						}
						break;
					default:break;
					}
				}
			}
			SetJiangLiItem(23,28);
		}
		break;
	case 24:Select(14, 15, -1, 3, 25, 4, -1); break;
	case 25:
		if (g_pCharacter->m_PCData.AddMoney(-1000000, 0, 0, FALSE))
		{
			g_pCharacter->m_PCData.AddPopularity(10);
		}
		else g_pMainState->m_Tags.Add("Ǯ����");
		break;
	case 26:
		
		{
			int moneyneed;
			if (g_pMainState->m_FightList[g_pMainState->m_HeroID + 5].isLive)
			{
				cPet* Pet = (cPet*)g_pMainState->m_FightList[g_pMainState->m_HeroID + 5].m_pData->m_pIndex;
				moneyneed = 10000 * (Pet->m_PetDataZZ.m_LV - Pet->m_PetDataZZ.m_FuZhuSkillLvList[0]);
			}
			else moneyneed = -1;
			ostringstream oss;
			oss << m_Textlist[17];
			if (moneyneed > -1)
				oss << "(��Ҫ#R" << moneyneed << "#RǮ)";
			else
				oss << "������û�г�ս�ٻ���";
			g_pMainState->m_TriggerDialog.AddSelect(this, oss.str(), m_Textlist[16], -1,
				"ǿ��", 27,
				m_Textlist[21], -1
		/*		m_Textlist[19], 28,
				m_Textlist[20], 29,
				m_Textlist[21], -1*/
				);
		}
		break;
	case 27:
	case 28:
	case 29:
		if (g_pMainState->m_FightList[g_pMainState->m_HeroID + 5].isLive)
		{
			cPet* Pet = (cPet*)g_pMainState->m_FightList[g_pMainState->m_HeroID + 5].m_pData->m_pIndex;
			int lvadd = Pet->m_PetDataZZ.m_LV - Pet->m_PetDataZZ.m_FuZhuSkillLvList[0];
			int moneyneed = 10000 * lvadd;
			if (lvadd<1)
			{
				g_pMainState->m_Tags.Add("�ٻ�����Ҫ�������ܼ���ǿ��");
				return TRUE;
			}
			if (g_pCharacter->m_PCData.AddMoney(-moneyneed, 0, 0, FALSE))
			{
			
				for (int i = 0; i < 3;i++)
					Pet->m_PetDataZZ.lvUpFuZhuSkill(lvadd, i);
			}
			else g_pMainState->m_Tags.Add("Ǯ����");
		}
		else g_pMainState->m_Tags.Add("û�г�ս�ٻ���");
		break;
	case 30:
		if (g_pCharacter->m_PCData.m_LV < 60)
			g_pMainState->m_LearnBangPaiSkill.OnOff(TRUE);
		else
			g_pMainState->m_pNowSelect->Talk("��ֻ������(60�����µ�)");
		break;
	default:
		ERRBOX;
		break;
	case 31://�ز���ʦ��
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(200000, e�ز���, 200, eMP_���ܵظ�);
			pPet->m_MagicNumAdd += 8;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_��������);
			pPet->AddSkill(ePS_�߼�������);
			pPet->AddSkill(ePS_�߼�������);
			pPet = AddPCPetEnemy2(100000, eת����, 200, eMP_���ܵظ�);
			pPet->m_MagicNumAdd += 2;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, eת����, 200, eMP_���ܵظ�);
			pPet->m_MagicNumAdd += 2;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, eת����, 200, eMP_���ܵظ�);
			pPet->m_MagicNumAdd += 2;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, eת����, 200, eMP_���ܵظ�);
			pPet->m_MagicNumAdd += 2;
			pPet->SetJinJie(3);

			SetMusic(m_Textlist[9]);
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(32);
		}
		else AddTriggerDialog2(5);
		return TRUE;
	case 32: //

	{
				 SetJiangLi2(1000000, 500000, 50000, 100000, TRUE);
				AddTriggerDialog2(5);

	}
		return TRUE;
	case 33://��ҧ��ʦ��
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(250000, e��ҧ��, 200, eMP_���ƹٸ�);
			pPet->AddSkill(ePS_�߼�������);
			pPet->AddSkill(ePS_�߼�������);
			pPet->restoreRate += 100;
			pPet = AddPCPetEnemy2(150000, e����, 200, eMP_���ƹٸ�,21);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(150000, e����, 200, eMP_���ƹٸ�, 21);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(150000, e����, 200, eMP_���ƹٸ�, 21);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(150000, e����, 200, eMP_���ƹٸ�, 21);
			pPet->SetJinJie(3);

			SetMusic(m_Textlist[9]);
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(34);
		}
		else AddTriggerDialog2(5);
		return TRUE;
	case 34: //

	{
				 SetJiangLi2(1000000, 500000, 50000, 100000, TRUE);
				 AddTriggerDialog2(5);
	}
		return TRUE;
	case 35://������ʦ
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(200000, e������ʦ, 200, eMP_����ɽ);
			pPet->m_MagicNumAdd += 5;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_��������);
			pPet->AddSkill(ePS_�߼�������);
			pPet->AddSkill(ePS_�߼�������);
			pPet = AddPCPetEnemy2(100000, e������, 200, eMP_����ɽ, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e������, 200, eMP_����ɽ, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e������, 200, eMP_����ɽ, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e������, 200, eMP_����ɽ, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);

			SetMusic(m_Textlist[9]);
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(36);
		}
		else AddTriggerDialog2(5);
		return TRUE;
	case 36: //

	{
				 SetJiangLi2(1000000, 500000, 50000, 100000, TRUE);
				 AddTriggerDialog2(5);
	}
		return TRUE;
	case 37://��������ʦ��
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(150000, e��������, 200, eMP_��������);
			pPet->m_MagicNumAdd += 8;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_��������);
			pPet->AddSkill(ePS_�߼�������);
			pPet->AddSkill(ePS_�߼�������);
			pPet = AddPCPetEnemy2(100000, e����, 200, eMP_��������, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e����, 200, eMP_��������, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e����, 200, eMP_��������, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e����, 200, eMP_��������, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);

			SetMusic(m_Textlist[9]);
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(38);
		}
		else AddTriggerDialog2(5);
		return TRUE;
	case 38: //

	{
				 SetJiangLi2(1000000, 500000, 50000, 100000, TRUE);
				 AddTriggerDialog2(5);
	}
		return TRUE;
	case 39://�������ʦ��
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(200000, e�������, 200, eMP_����ɽ);
			pPet->m_MagicNumAdd += 5;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_��������);
			pPet->AddSkill(ePS_�߼�������);
			pPet->AddSkill(ePS_�߼�������);
			pPet = AddPCPetEnemy2(100000, e��ƿŮ�, 200, eMP_����ɽ, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e��ƿŮ�, 200, eMP_����ɽ, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e���Ů�, 200, eMP_����ɽ, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e���Ů�, 200, eMP_����ɽ, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);

			SetMusic(m_Textlist[9]);
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(40);
		}
		else AddTriggerDialog2(5);
		return TRUE;
	case 40: //

	{
				 SetJiangLi2(1000000, 500000, 50000, 100000, TRUE);
				 AddTriggerDialog2(5);
	}
		return TRUE;
	case 41://������ʦ��
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(150000, e�ն���ʦ, 200, eMP_������);
			pPet->m_MagicNumAdd += 2;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_�߼�������);
			pPet->AddSkill(ePS_�߼�������);
			pPet = AddPCPetEnemy2(100000, e�����޺�, 200, eMP_������, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e�����޺�, 200, eMP_������, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e�����޺�, 200, eMP_������, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e�����޺�, 200, eMP_������, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);

			SetMusic(m_Textlist[9]);
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(42);
		}
		else AddTriggerDialog2(5);
		return TRUE;
	case 42: //

	{
				 SetJiangLi2(1000000, 500000, 50000, 100000, TRUE);
				 AddTriggerDialog2(5);
	}
		return TRUE;
	case 43://��˽�ʦ��
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(200000, e��˽�, 200, eMP_�칬);
			pPet->m_MagicFire.d2 += 50;
			pPet->m_MagicNumAdd += 2;
			pPet->AddSkill(ePS_�߼�������);
			pPet->AddSkill(ePS_�߼�������);

			for (int i = 0; i < 4; i++)
			{
				AddPetEnemy2(200000, eҰ��, 250);
			}
			SetMusic(m_Textlist[9]);
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(44);
		}
		else AddTriggerDialog2(5);
		return TRUE;
	case 44: //

	{
				 SetJiangLi2(1000000, 500000, 50000, 100000, TRUE);
				 AddTriggerDialog2(5);
	}
		return TRUE;
	case 45://��ׯ��ʦ��
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(200000, e��Ԫ����, 200, eMP_��ׯ��);
			pPet->m_MagicNumAdd += 2;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_�߼�������);
			pPet->AddSkill(ePS_�߼�������);
			pPet = AddPCPetEnemy2(100000, e�Ʋ�ͯ��, 200, eMP_��ׯ��, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e�Ʋ�ͯ��, 200, eMP_��ׯ��, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e�Ʋ�ͯ��, 200, eMP_��ׯ��, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e�Ʋ�ͯ��, 200, eMP_��ׯ��, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);

			SetMusic(m_Textlist[9]);
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(46);
		}
		else AddTriggerDialog2(5);
		return TRUE;
	case 46: //

	{
				 SetJiangLi2(1000000, 500000, 50000, 100000, TRUE);
				 AddTriggerDialog2(5);
	}
		return TRUE;
	case 47://ʨ����ʦ��
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(150000, e�����, 200, eMP_ʨ����);
			pPet->m_MagicNumAdd += 1;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_�߼�������);
			pPet->AddSkill(ePS_�߼�������);
			pPet = AddPCPetEnemy2(100000, e���컢, 200, eMP_ʨ����, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e���컢, 200, eMP_ʨ����, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e���컢, 200, eMP_ʨ����, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e���컢, 200, eMP_ʨ����, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);

			SetMusic(m_Textlist[9]);
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(48);
		}
		else AddTriggerDialog2(5);
		return TRUE;
	case 48: //

	{
				 SetJiangLi2(1000000, 500000, 50000, 100000, TRUE);
				 AddTriggerDialog2(5);
	}
		return TRUE;
	case 49://ħ��կʦ��
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(150000, eţħ��, 200, eMP_ħ��կ);
			pPet->m_MagicNumAdd += 8;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_�߼�������);
			pPet->AddSkill(ePS_�߼�������);
			pPet = AddPCPetEnemy2(100000, eţ��, 200, eMP_ħ��կ, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, eţ��, 200, eMP_ħ��կ, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, eţ��, 200, eMP_ħ��կ, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, eţ��, 200, eMP_ħ��կ, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);

			SetMusic(m_Textlist[9]);
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(50);
		}
		else AddTriggerDialog2(5);
		return TRUE;
	case 50: //

	{
				 SetJiangLi2(1000000, 500000, 50000, 100000, TRUE);
				 AddTriggerDialog2(5);
	}
		return TRUE;
	case 51://��˿��ʦ��
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(150000, e�׾���, 200, eMP_��˿��);
			pPet->m_MagicNumAdd += 5;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_�߼�������);
			pPet->AddSkill(ePS_�߼�������);
			pPet = AddPCPetEnemy2(100000, e֩�뾫, 200, eMP_��˿��, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e֩�뾫, 200, eMP_��˿��, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e֩�뾫, 200, eMP_��˿��, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e֩�뾫, 200, eMP_��˿��, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);

			SetMusic(m_Textlist[9]);
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(52);
		}
		else AddTriggerDialog2(5);
		return TRUE;
	case 52: //

	{
				 SetJiangLi2(1000000, 500000, 50000, 100000, TRUE);
				 AddTriggerDialog2(5);
	}
		return TRUE;
	case 53://Ů����ʦ��
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(150000, e������, 200, eMP_Ů����);
			pPet->m_MagicNumAdd += 5;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_�߼�������);
			pPet->AddSkill(ePS_�߼�������);
			pPet = AddPCPetEnemy2(100000, e����ɳ��, 200, eMP_Ů����, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e����ɳ��, 200, eMP_Ů����, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e����ɳ��, 200, eMP_Ů����, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e����ɳ��, 200, eMP_Ů����, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);

			SetMusic(m_Textlist[9]);
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(54);
		}
		else AddTriggerDialog2(5);
		return TRUE;
	case 54: //

	{
				 SetJiangLi2(1000000, 500000, 50000, 100000, TRUE);
				 AddTriggerDialog2(5);
	}
		return TRUE;
	case 55://�������ս
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(250000, e�����, 250, eMP_�칬);
			pPet->m_MagicNumAdd += 3;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_�߼�������);
			pPet->AddSkill(ePS_�߼�������);
			pPet->AddSkill(ePS_�߼���ɱ);
			pPet->AddSkill(ePS_�߼�����);
			pPet = AddPCPetEnemy2(150000, e������Գ, 200, eMP_ʨ����, 22);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(150000, e��ü���, 200, eMP_��������, 23);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);

			SetMusic(m_Textlist[9]);
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(56);
		}
		else AddTriggerDialog2(5);
		return TRUE;
	case 56: //

	{
				 SetJiangLi2(1000000, 500000, 50000, 100000, TRUE);
				 AddTriggerDialog2(5);
	}
		return TRUE;
	case 57://�칬ʦ��
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(150000, e�, 200, eMP_�칬);
			pPet->m_MagicNumAdd += 5;
			pPet->AddSkill(ePS_�߼�������);
			pPet->AddSkill(ePS_�߼�������);
			pPet = AddPCPetEnemy2(100000, e�콫, 200, eMP_�칬, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e�콫, 200, eMP_�칬, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e�콫, 200, eMP_�칬, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e�콫, 200, eMP_�칬, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);

			SetMusic(m_Textlist[9]);
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(58);
		}
		else AddTriggerDialog2(5);
		return TRUE;
	case 58: //

	{
				 SetJiangLi2(1000000, 500000, 50000, 100000, TRUE);
				 AddTriggerDialog2(5);
	}
		return TRUE;
		
	}
	return TRUE;

}

BOOL cTaskZhiXian::Process1(int stage)
{
	if (stage < 0)return TRUE;
	AddTriggerDialog2(stage);
	return TRUE;
}

BOOL cTaskZhiXian::Process2(int stage)
{
	if (stage < 0)return TRUE;
	switch (stage)
	{
	case 5:
		if (CheckINT(12, 0))
		{
			AddTriggerDialog2(-stage);
		}
		else
		{
			SetINT(12, 2);
			AddTriggerDialog2(stage);
		}
		break;
	case 6:
		if (CheckINT(12, 0))
		{
			AddTriggerDialog2(-stage);
		}
		else
		{
			SetINT(12, 1);
			AddTriggerDialog2(stage);
		}
		break;
	case 7:
		if (CheckINT(12, 1) && CheckINT(12, 2))
		{
			if (!CheckINT(12, 0))
			{
				SetINT(12,0);
				AddTriggerDialog2(-stage);
				SetJiangLiItem(4,40);
			}
			else
			{
				AddTriggerDialog2(-stage-100);
			}
		}
		else
		{		
			AddTriggerDialog2(stage);
		}
		break;
	default:
		AddTriggerDialog2(stage);
		break;
	}
	return TRUE;
}

BOOL cTaskZhiXian::Process3(int stage)
{//����
	int baoxiangid;
	int baoxiangindex;
	GetBaoXiangID(stage, baoxiangid, baoxiangindex);
	SetINT(baoxiangid, baoxiangindex);
	switch (stage)
	{
	case -1:
		return TRUE;
		//��������
	case 0:SetJiangLiItem(0, 32); break;
	case 1:SetJiangLiItem(0, 33); break;
		//����
	case 2:SetJiangLiItem(0, 34); break;
		//�����Ҷ�
	case 3:SetJiangLiItem(2, 22,10); break;
	case 4:SetJiangLiItem(0, 23,30); break;
	case 5:SetJiangLiItem(10, 24); break;
		//������
	case 6:SetJiangLiItem(1, 27); SetJiangLiItem(2, 27); break;
		//
	case 7:SetJiangLiItem(0, 29); break;
	case 8:SetJiangLi2(0, 500000, 0, 0); break;
		//�������
	case 9:SetJiangLiItem(4, 24); break;
		//������
	case 10:SetJiangLiItem(59, 27); break;
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		SetJiangLi(1,0,0,0,100,50); break;
	case 16:
		SetJiangLi2(500); break;
	case 17:
		SetJiangLiItem(3,24);
		break;
	case 18:
		SetJiangLiItem(77, 40);
		break;
	default:
		break;
	}
	g_pMainState->m_Map.RemoveNpc(g_pMainState->m_pNowSelect, TRUE);
	return TRUE;
}

void cTaskZhiXian::GetBaoXiangID(int type, int& id, int& index)
{//�����Ӧ�Ľű���
	id = 100 + type / 30;
	index = type % 30;
}

BOOL cTaskZhiXian::Process4(int stage)
{
	if (stage == -1)return TRUE;
	if (stage < 300)
	{//�̵�
		g_pMainState->m_InterFaceBuy.Open(stage);
		return TRUE;
	}
	switch (stage)
	{
	case -1:return TRUE;
	default:ERRBOX;
		break;
		
	}
	return TRUE;
}
void cTaskZhiXian::ProcessSelect(int stage)
{
	m_pObj = g_pMainState->m_pNowSelect;
	g_pMainState->m_TriggerDialog.AddSelect(this, m_Textlist[stage], g_pMainState->m_pNowSelect->m_TrueName.GetString(), -1,
		"��", stage,
		"��", -1
		);
}

BOOL cTaskZhiXian::Process6(int stage)
{
	switch (stage)
	{
	case -1:return TRUE;
	case 0:Select(2, 1, -1, 3, 1, 4, 2, 5, 3);break;
	case 1:
	case 2:
	case 3:
		
		{
			int& k = g_pMainState->m_GlobalButton[0];
			switch (stage)
			{
			case 1:
				if (k <= 50)g_pCharacter->m_PCData.GoldLivePercent.d1 -= 100;
				k = 100; 
				g_pMainState->m_pFightState->m_FightMenu.SetTeamControl(TRUE);
				break;
			case 2:
				if (k<=50)g_pCharacter->m_PCData.GoldLivePercent.d1 -= 100;
				k = 80; 	
				g_pMainState->m_pFightState->m_FightMenu.SetTeamControl(FALSE);
				break;
			case 3:
				if (k > 50)g_pCharacter->m_PCData.GoldLivePercent.d1 += 100;
				k = 50;
				g_pMainState->m_pFightState->m_FightMenu.SetTeamControl(FALSE);
				break;
			}
		}
		break;
	default:
		ERRBOX;
		break;
	}
	return TRUE;
}

void cTaskJuQing::SetChapter(int chapter)
{
	if (chapter == m_Chapter)return;
	m_Chapter = chapter;
	m_bInit = FALSE;
	Init();
}

void cTaskJuQing::Save(ofstream& File)
{
	File << "\n";
	File << m_Chapter << " ";
}

void cTaskJuQing::Load(ifstream& File)
{
	File >> m_Chapter;
	m_bInit = FALSE;
//	m_bInit2 = FALSE;
	Init();
}

std::string cTaskJuQing::SetUpPathJuQing(string str)
{
	string path1 = gStrMediaPath;
	path1+="����//";
	path1 += m_AutoPath;
	path1 += "//";
	path1 += str;
	path1 += ".txt";
	return path1;
}

cPetData* cTaskJuQing::AddPetEnemy2(int hp, ePetID id, int lv, int name /*= -1*/, BOOL bOur /*= FALSE*/, int pos)
{
	cPetData* p;
	int k= AddPetEnemy(id, lv, name, bOur,pos);
	g_pMainState->m_FightList[k].m_pData->GetDateP(p);
	if (hp > 0)
	{
		p->m_HPMax.SetData(hp);
		p->FillHPMP();
	}
	return p;
}

cPetData* cTaskJuQing::AddPCPetEnemy2(int hp, ePetID id, int lv, eMengPai mp, int name /*= -1*/, BOOL bOur /*= FALSE*/, int pos)
{
	cPetData* p;
	int k= AddPCPetEnemy(id, lv, mp, name, bOur,pos);
	if (k == -1)return 0;
	g_pMainState->m_FightList[k].m_pData->GetDateP(p);
	if (hp > 0)
	{
		p->m_HPMax.AddDataAdd(hp);
		p->FillHPMP();
	}
	return p;
}

cPetData* cTaskJuQing::AddPCEnemy2(int hp, int id, sZiZhi* zz, int lv, eMengPai mp, int name /*= -1*/, int weapontype /*= -1*/, int weaponid /*= -1*/, BOOL bOur /*= FALSE*/, int pos)
{
	cPetData* p;
	int k=AddPCEnemy(id, zz, lv, mp, name, weapontype, weaponid, bOur,pos);
	g_pMainState->m_FightList[k].m_pData->GetDateP(p);
	if (hp > 0)
	{
		p->m_HPMax.SetData(hp);
		p->FillHPMP();
	}
	return p;
}



void cTaskJuQing::AddTag(int str, int time/*=500*/)
{
	g_pMainState->m_Tags.Add(m_Textlist[str], time);
}

void cTaskJuQing::LockMap(int name/*=-1*/)
{
	switch (name)
	{
	case -1:
		g_pMainState->m_Map.SetLock("");
		break;
	case 0:
	case 1:
		g_pMainState->m_Map.SetLock(name);
		break;
	default:
		g_pMainState->m_Map.SetLock(m_Textlist[name]);
		break;
	}
	
}

void cTaskJuQing::AddRangeMap(int mapname, int x, int y, int range, int ret)
{
	sTriggerRange data;
	data.Set(m_Textlist[mapname], x, y, range, this, ret);
	g_pMainState->m_Map.AddTriggerRange(data);
}

sItem2* cTaskJuQing::FindItem(int Type, int id)
{
	for (int i = 0; i < 60; i++)
	{
		sItem2* pItem= &g_pCharacter->m_PCData.m_Item[i];
		if (pItem->m_Num)
		if (pItem->GetID()==id)
		if (pItem->GetType() == Type)
			return pItem;
	}
	return 0;
}

void cTaskJuQing::AddFriend(int i)
{
	g_pMainState->m_Friend.AddFriend(m_Textlist[i]);
}

void cTaskJuQing::AddTriggerObjMap2(int name, int mapname, int modeid, int x, int y, int direction, int ret /*= -1*/, int jinjie)
{
	
	sMapObjTrigger obj;
	obj.m_pTask = this;
	obj.m_Stage = ret;
	obj.m_Npc.Set(m_Textlist[name], m_Textlist[mapname], modeid, x, y, direction,jinjie);
	AddTriggerObjMap(&obj);
}





BOOL cTaskZhiXian2::Process(int stage)
{
	switch (g_pCharacter->m_PCData.m_MengPaiID)
	{
	case eMP_���ƹٸ�:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("�������¼���");
			return TRUE;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼���֪);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�͵Ϯ);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�ǿ��);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼���ɱ);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_����);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_ֱ��);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_����ɽ:
	case eMP_������:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("�������¼���");
			return TRUE;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�ҹս);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼������ֿ�);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼���������);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼��м�);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_����ɽ:
	case eMP_Ů����:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("�������¼���");
			return TRUE;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�ҹս);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�������);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼������ֿ�);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼���);
			break;
		default:ERRBOX;
			break;
		}
		break;	
	case eMP_ʨ����:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("�������¼���");
			return TRUE;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�ǿ��);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�͵Ϯ);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�ҹս);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼���ɱ);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼���);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_ħ��կ:
	case eMP_��������:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("�������¼���");
			return TRUE;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼���������);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�ħ֮��);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼���������);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼���������);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_��˿��:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("�������¼���");
			return TRUE;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�͵Ϯ);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼������ֿ�);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼������);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼���ɱ);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_ֱ��);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�绪��ʥ);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_���ܵظ�:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("�������¼���");
			return TRUE;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼������);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼������ֿ�);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼��м�);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_���۷���);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_��ׯ��:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("�������¼���");
			return TRUE;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼������ֿ�);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�ҹս);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�ǿ��);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�������);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼���);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_�칬:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("�������¼���");
			return TRUE;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_����);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_͵Ϯ);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_����);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_ҹս);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�ħ֮��);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�绪��ʥ);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			break;
		default:ERRBOX;
			break;
		}
		break;
	default:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("�������¼���");
			return TRUE;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_����);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_͵Ϯ);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_����);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_ҹս);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�ħ֮��);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�绪��ʥ);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_�߼�����);
			break;
		default:ERRBOX;
			break;
		}
		break;
	
	}
	
	return TRUE;
}
BOOL cTaskZhiXian3::Process(int stage)
{
	return TRUE;
}
