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
	case 106://奸商
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
			g_pMainState->MakeAPet(Pet4, e超级神虎, 100, 14, addpoint);
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

			g_pMainState->LoadCharacterData2(g_pMainState->m_HeroID, "主角");
			g_pMainState->SetCharacter(g_pMainState->m_HeroID);
			g_pCharacter->m_PCData.m_Controler.Set(0, 0);
			g_pHeroObj->Reset();
			g_pHeroObj->Set(POS_STAND);
			g_pCharacter->m_PCData.m_Money[0] = 10000;
			g_pMainState->m_Map.LoadMap(25, 139, "建邺城", FALSE);

		

			//g_pCharacter->m_PCData.GetShangPinPet(6);
		//	g_pMainState->GivePcAPet(g_pMainState->m_HeroID,);
			//g_pCharacter->m_PCData.GetShangPinPet(6);
			//g_pCharacter->m_PCData.Followlv(170);
			////g_pMainState->m_Friend.AddFriend("羽灵神");
			//g_pCharacter->m_PCData.m_Money[0] = 200000000;
			//Invite("怀念");
			//Invite("羽灵神");
			//g_pMainState->m_Friend.AddFriend("敖白");
			///*int id = g_pMainState->m_Friend.FindFriend("小蛮");
			//g_pMainState->m_Friend.m_FriendList[id].m_dataFileName = "小蛮2";*/
			//Invite("敖白");
			//	g_pMainState->m_Friend.AddFriend("清风");
			//	
			//	int id = g_pMainState->m_Friend.FindFriend("清风");
			//	g_pMainState->m_Friend.m_FriendList[id].m_dataFileName = "清风2";
			//	Invite("清风");
			//	g_pMainState->m_Friend.AddFriend("怀念");
			//	Invite("怀念");
			//	SetJiangLi2(0, 9999999);
			//	SetChapter(9);
			//	Process9(1);
			//	return TRUE;
			/*for (int i = 6; i < 11; i++)
				SetJiangLiItem(i, 27);*/
			//g_pCharacter->m_PCData.GoldLivePercent.d1 = 100;

			//g_pMainState->m_Map.Load(521, 124, "长安城");
			//g_pMainState->m_Map.LoadMap(56, 44, "阴曹地府");
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
			TalkList(15, 21, 7, 38, 101); //梦幻精灵
			AddChannel(m_Textlist[38]);
			g_pMainState->m_ZhiXian2.Process(0);
		}
		return TRUE;
	case 36:
		for (int i = 0; i < 3; i++)
		{
			AddFriend(48 + i);
		}
		TalkList(20, 66, 67, 43, 38, 34);//（66镇塔之神67大雁塔七层45爬上7层 case 38 ）
		break;
	case 34:
		{
			int id;
			for (int i = 0; i<3; i++)
			{
				AutoGetPet(m_Textlist[48 + i], 1);//48 49 50 敖白 紫菜 怀念
				g_pMainState->m_Friend.Invite(m_Textlist[48 + i]);
				
			}
			id = g_pMainState->m_Friend.FindFriend("泡芙");
			g_pMainState->m_Friend.m_FriendList[id].m_dataFileName = "泡芙2";
			if (id > -1)g_pMainState->m_Friend.Invite("泡芙");
			g_pMainState->m_Map.RemoveNpc(g_pMainState->m_pNowSelect, 1);
			RemoveTriggerObjMap();
			RemoveNpc(40, TRUE);
			
		}
		break;

	case 38:
			AddTriggerDialog2(25);//感谢你们 给奖励
			UpdateJob2(68);//升级到35
			//SetJiangLi(30,1,0,50,200,200);
			SetJiangLi2(80000, 10000, 200000, 80000, TRUE);//镇塔之神奖励SetJiangLi2(50000, 10000, 150000, 50000, TRUE)
			AddTriggerLv(37, 30);//升级到35 触发任务37
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
	
	case 101://宠物仙子
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
	case 1: //找到兵铁铺
		{
			NowNpcTalk(m_Textlist[5]);
			AddTriggerObj(m_Textlist[6], m_Textlist[7], 2);
			UpdateJob2(5);
			AddChannel(m_Textlist[46]);
		}
		return FALSE;
	case 2://找到装备鉴定商
		{
			cObj* pob = g_pMainState->FindObjByName(m_Textlist[6]);
			pob->Talk(m_Textlist[8]);
			for (int i = 0; i < 60; i++)
			{
				if (g_pCharacter->m_PCData.m_Item[i].GetNum())
				if (g_pCharacter->m_PCData.m_Item[i].GetType() == eWeaponType棒)
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
	case 3: //泡芙出现
		{
			sNpc npc;
			npc.Set("泡芙", "东海海底", 2002, 14, 53,0);
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
			g_pMainState->m_Friend.AddFriend("泡芙");
			//给泡芙买个BB
			AutoGetPet("泡芙",0);
			g_pMainState->m_Friend.Invite("泡芙");
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
		AddTriggerObj("牛大胆", m_Textlist[7], 43);
		return TRUE;
	case 43:
		AddTriggerDialog2(27, 44);
		return TRUE;
	case 44://找雷黑子
		RemoveTriggerObjMap(43);
		UpdateJob2(73);
		AddTriggerObj("雷黑子", m_Textlist[7], 45);
		return TRUE;
	case 45:
		AddTriggerDialog2(28, 46);
		return TRUE;
	case 46: //旺财战斗
	{
				 cPetData* petdata = AddPetEnemy2(2000, e狼, 15, 74);
				 SetMusic();
				 g_StateType = STATE_FIGHT;
				 AddTriggerFightSuccess(47);
	}
		return TRUE;
	case 47://旺财奖励
	{
				SetJiangLi2(1000, 2000, 5000, 2000, TRUE);
				AddTriggerObj("雷黑子", m_Textlist[7], 48);
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
	case 14://进入BOSS战
		
		{
			cPetData* petdata = AddPetEnemy2(2000, e野鬼, 12, 58);
			petdata->AddSkill(ePS_连击);
			petdata->AddSkill(ePS_吸血);
			petdata->AddSkill(ePS_反击);
			//petdata->m_CounterRate.d1 = 20;
			//petdata->m_Combo.d1 = 50;
			//petdata->m_Pierce.d1 = 20;

			g_pMainState->m_Mp3.Load("战斗BOSS");
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(15);		
			AddTriggerDialog2(22, -1);
		}
		return TRUE;
	case -15:
		
		{
			RemoveTriggerObjMap();
			AddTriggerObj("商人的鬼魂", m_Textlist[18], 14); break;//战斗失败
		}
		break;
	case 15://商人的鬼魂奖励
		
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
		AddTriggerObjMap("东海湾", 49, FALSE);
		//AddTriggerObj("楚恋依", "东海湾", 49);
		return TRUE;
	case 49:AddTriggerDialog2(30, 50); return TRUE;
	case 50://去找楚恋依
		RemoveTriggerObjMap(49);
		UpdateJob2(76);
		AddTriggerObj("楚恋依", "东海湾", 51);
		return TRUE;
	case 51:
		AddTriggerDialog2(31, 52);
		return TRUE;
	case 52://找小花
		RemoveTriggerObjMap(51);
		UpdateJob2(77);
		AddTriggerObj("小花", m_Textlist[7], 53);
		return TRUE;
	case 53:
		AddTriggerDialog2(32, 54);
		return TRUE;
	case 54:
		RemoveTriggerObjMap(53);
		//UpdateJob2(78);
		AddTriggerObj("楚恋依", "东海湾", 55);
		return TRUE;
	case 55:
		AddTriggerDialog2(33, 56);
		return TRUE;
	case 56://县令
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
	case 18://商人的鬼魂结束
		
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
			g_pMainState->m_Friend.UnInvite("泡芙");
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
	//case 25://拜师
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
			npc = g_pMainState->m_Friend.m_FriendList[g_pMainState->m_Friend.FindFriend("泡芙")];
			npc.m_Npc.m_mapname = "长安城";
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
	UpdateJob(text, "主线");
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
	case 1://找南极仙翁
		UnInvite("怀念");
		UnInvite("敖白");
		UnInvite("紫菜");
		RemoveTriggerObj();
		UpdateJob2(85);
		AddTriggerObj2(86, 87, 2);
		g_pMainState->LockLv(45);
		g_pMainState->m_GlobalButton[4] = 1;
		break;
	case 2:
		AddTriggerDialog2(52, 3);
		UpdateJob2(91);
		return TRUE;//镇塔之神对话
	case 3:
	{
			  sNpc npc;
			  npc.Set(m_Textlist[90], "花果山", e天兵, 25, 18, 1, 2);
			  AddTriggerObjMap(&npc, 4, FALSE);
	}
		return TRUE;
	case 4:AddTriggerDialog2(53, 5); break;
	case 5:
		RemoveTriggerObjMap(4);
		RemoveNpc(90, TRUE);
		AddTriggerObj("老虎小兵", "花果山", 6);
		UpdateJob2(88);
		break;
	case 6:	
		AddTriggerDialog2(54, 7); 
		break;
	case 7: //老虎小兵战斗
	{
				cPetData* pPet = AddPCPetEnemy2(3000, e老虎, 30, eMP_狮驼岭, 89);
				pPet->AddSkill(ePS_高级反震); pPet->AddSkill(ePS_高级反击); pPet->m_MagicNumAdd += 1;
				pPet->m_StartMagic.d1 = 145;
				for (int i = 0; i < 4; i++)
				{
					AddPCPetEnemy2(1500, e羊头怪, 25, (eMengPai)(rand() % 12), 93);
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
			   pPet= AddPCPetEnemy2(3000, e巨力神猿, 35, eMP_大唐官府, 92);
			   pPet->AddSkill(ePS_高级反震); pPet->AddSkill(ePS_高级反击); pPet->m_MagicNumAdd += 1; pPet->m_SuckBloodRate.d1 += 10; pPet->SetJinJie(2);
			   pPet = AddPCPetEnemy2(3000, e老虎, 30, eMP_狮驼岭, 89);
			   pPet->AddSkill(ePS_高级反震); pPet->AddSkill(ePS_高级反击); pPet->m_MagicNumAdd += 1;pPet->m_StartMagic.d1 = 145;
			   for (int i = 0; i < 2; i++)
			   {
				   ePetID petid;
				   switch (rand() % 3)
				   {
				   case 0:petid = e狼;
					   break;
				   case 1:petid = e黑熊;
					   break;
				   default:petid = e花妖;
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
	case 9://崩将军奖励

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
			  AddTriggerObj("侯医仙", "花果山", 11);
	}
		break;
	case 11://侯医仙
		AddTriggerDialog2(60);
		AddTriggerGive("侯医仙", 22, 24, 13);
		break;
	case 13:
		AddTriggerDialog2(61, 14); break;
	case 14:
		SetJiangLiItem(25, 22); 
		RemoveTriggerObjMap(11); 
		AddTriggerObj("老虎小兵", "花果山", 15);
		break;
	case 15://老虎小兵
		AddTriggerDialog2(59, 16); 
		UpdateJob2(95);
		return TRUE;
	case 16:
	{
		sNpc npc;
		npc.Set("天兵飞剑", "花果山", e天兵, 133, 111, 7, 2);
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
		AddTriggerObj("玉兔菇娘", "月宫", 19);
		UpdateJob2(96);
		break;
	case 19:
		AddTriggerDialog2(63, 20);
		UpdateJob2(97);
		return TRUE;
	case 20:
	{
			   sNpc npc;
			   npc.Set("月香侍女", "月宫", e雾中仙, 30, 74, 7, 2);
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
			  pPet = AddPCPetEnemy2(2000, e雾中仙, 20, eMP_东海龙宫, 99);
			  pPet->SetJinJie(2);
			  for (int i = 0; i < 4; i++)
			  {
				  AddPCPetEnemy2(500, e幽萤娃娃, 30, (eMengPai)(rand() % 12), 100);
			  }
			  SetMusic();
			  g_StateType = STATE_FIGHT;
			  AddTriggerFightSuccess(23);
	}
		return TRUE;
	case -22:
		AddTriggerDialog2(66);
		break;
	case 23://月香侍女奖励
		SetJiangLi2(10000, 5000, 500000, 20000, TRUE);
		UpdateJob2(101);
		RemoveTriggerObjMap(21);
		RemoveNpc(99, TRUE);
		AddTriggerObj("玉兔菇娘", "月宫", 24);
		break;
	case 24:
		AddTriggerDialog2(67,25);
		break;
	case 25:
		RemoveTriggerObjMap(24);
		AddTriggerObj("天兵飞剑", "天宫", 26);
		UpdateJob2(102);
		break;
	case 26:
		g_pMainState->m_Friend.AddFriend("北斗");
		AddTriggerDialog2(68, -26);
		AddTriggerObj("天将巨灵", "天宫", 27);
		UpdateJob2(103);
		break;
	case -26:

	{
		g_pMainState->m_Friend.Invite("北斗");
		RemoveTriggerObjMap();
	}
		break;
	case 27:
		AddTriggerDialog2(69, 28); 
		AddTriggerObj("钟书生", "长寿村", 28);
		UpdateJob2(104);
		break;
	case 28:
		AddTriggerDialog2(70, 29);
		AddTriggerObj("毛驴张", "长寿村", 29);
		UpdateJob2(105);
		break;
	case 29://毛驴张
		AddTriggerDialog2(71);
		AddTriggerGive("毛驴张", 33, 4, 30);
		break;
	case 30:
		AddTriggerDialog2(61, 14); break;
	case 149999:
		SetJiangLiItem(25, 22);
		RemoveTriggerObjMap(11);
		AddTriggerObj("老虎小兵", "花果山", 15);
		break;
		/************分界线*************/
		/**
	case 13:
		g_pMainState->m_Friend.AddFriend("清风");
		AddTriggerDialog2(8, -13);
		AddTriggerObj2(16, 17, 14);
		UpdateJob2(19);
		break;
	case -13:
		
		{
			g_pMainState->m_Friend.Invite("清风");
			RemoveTriggerObjMap();
		}
		break;
	case 14:AddTriggerDialog2(9, 15); break;//天将
	case 15: 
		
		{
			cPetData* pPet = AddPCPetEnemy2(8000, e天将, 50, eMP_天宫, 16);
			pPet->m_MagicNumAdd += 1;
			for (int i = 0; i < 4; i++) AddPetEnemy2(3000, e天兵, 42);
			SetMusic("绯雪千夜");
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

	case 19://白琉璃
		
		{
			cPetData* pPet = AddPCPetEnemy2(8000, e星灵仙子, 48, eMP_普陀山, 20);
			pPet->SetJinJie(2);
			for (int i = 0; i < 4; i++) AddPetEnemy2(3000, e星灵仙子, 40);
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
	case 23://酒肉2
		
		{
			cPetData* pPet = AddPCPetEnemy2(12000, e雨师, 55, eMP_东海龙宫, 10);
			pPet->AddSkill(ePS_高级法术连击);
			pPet->AddSkill(ePS_高级魔之心);
			pPet->AddSkill(ePS_高级法术波动);
			pPet->AddSkill(ePS_高级精神集中);
			pPet->SetJinJie(3);
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 3)
				{
				case 0:petid = e强盗;
					break;
				default:petid = e强盗;
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
	case 125://青莲仙女
	
		{
			TalkList(49, 75, 76, 77, 126);
			sMapObjTrigger obj;
			obj.m_Npc.Set(m_Textlist[75], m_Textlist[76], e超级大熊猫, 84, 59);
			obj.m_Stage = 126;
			obj.m_pTask = this;
			AddTriggerObjMap(&obj);
		}
		break;
	case 126:
		
		{
			AddPCPetEnemy2(6500, e超级大熊猫, 50, eMP_狮驼岭);
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 3)
				{
				case 0:petid = e黑熊;
					break;
				case 1:petid = e白熊;
					break;
				default:petid = e黑熊精;
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
		sppet.Set(e超级大熊猫, 0, 100, TRUE);
		GetPet(m_Textlist[64], &sppet, 100);
		}
		break;

	case 25://青莲仙女
		AddFriend(84);
		AddTriggerDialog2(16, -1);
		AddTriggerObj2(25, 26, 26);
		UpdateJob2(27);
		break;
	case 26://孟婆
		AddTriggerDialog2(17, -1);
		AddTriggerObj2(28, 29, 27);
		UpdateJob2(30);
		break;

	case 27://幽冥鬼
		AddTriggerDialog2(18, 28);
		break;
		***********/
	case 289999:

		{
			cPetData* pPet = AddPCPetEnemy2(10000, e鬼将, 52, eMP_阴曹地府, 28);
			pPet->SetJinJie(2);
			pPet->m_MagicNumAdd += 3;
			for (int i = 0; i < 4; i++)
			{
				ePetID petid;
				switch (rand() % 4)
				{
				case 0:petid = e僵尸;
					break;
				default:petid = e僵尸;
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
	case 309999://文秀
		AddTriggerObj2(28, 29, 31);
		AddTriggerDialog2(20, -30);	
		break;
	case -30:
		SetJiangLiItem(16, 22, 10);
		SetJiangLiItem(36, 40);
		UpdateJob2(30);
		break;
	case 31://幽冥鬼
		AddTriggerObj2(25, 26, 32);
		AddTriggerDialog2(21, -1);
		UpdateJob2(27);
		break;
	case 32://孟婆
		AddTriggerObj2(22, 11, 33);
		AddTriggerDialog2(22, -1);
		UpdateJob2(40);
		break;
	case 33://玄奘
		AddTriggerObj2(34, 8, 34);
		AddTriggerDialog2(23, -1);
		UpdateJob2(35);
		break;
	case 34://守卫
		AddTriggerDialog2(24, 35); break;
	case 35:
		
		{
			for (int i = 0; i < 5; i++)
			{
				AddPCPetEnemy2(6500, e护卫, 53, eMP_大唐官府,34);
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
	case 37://殷温娇
		AddTriggerObj2(41, 8, 38);
		AddTriggerDialog2(26, -1);
		UpdateJob2(42);
		break;
	case 38:AddTriggerDialog2(27, 39);
		break;
	case 39://虾兵战斗
		
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(8000,e虾兵, 58, eMP_东海龙宫, 41);
			pPet->m_MagicWater.d2 += 20;
			pPet->m_MagicNumAdd += 2;
			for (int i = 0; i < 4; i++)
			{
				ePetID petid;
				switch (rand() % 4)
				{
				case 0:petid = e章鱼;
					break;
				default:petid = e章鱼;
					break;
				}
				pPet= AddPCPetEnemy2(5000,petid, 40, (eMengPai)(rand() % 12));
				pPet->m_MagicWater.d2 += 10;
			}
			g_pMainState->m_Mp3.Load("战斗BOSS");
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
		//蟹将战斗
	case 41:AddTriggerDialog2(28, 42);
		break;
	case 42:
		
		{
			cPetData* pPet;
			 pPet= AddPCPetEnemy2(10000, e鲛人, 60, eMP_东海龙宫,71);
			 pPet->SetJinJie(3);
			 pPet->m_MagicNumAdd += 3;
			 pPet->m_MagicWater.d2 += 20;
			 pPet->AddSkill(ePS_高级魔之心);
			 pPet->AddSkill(ePS_高级法术波动);
			for (int i = 0; i < 4; i++)
			{
				ePetID petid;
				switch (rand() % 4)
				{
				case 0:petid = e蟹将;
					break;
				default:petid = e蟹将;
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
	case 44://龟千岁
		TalkList(30, 36, 8, 37, 45);
		break;
	case 45://殷温娇
		TalkList(31, 49, 50, 48, 46);
		break;
	case 46://殷丞相
		TalkList(32, 52, 53, 51, 47);
		AddTriggerGive(m_Textlist[49] ,22,30, 49);
		break;
	case 47://江湖奸商
		AddTriggerDialog2(33, 48); break;
	case 48:
		SetJiangLiItem(30, 22);
		SetJiangLi2(0, -50000);
		break;
	case 49://殷丞相
	
		{
			AddTriggerDialog2(34, -1);
			UpdateJob2(56);
			sNpc npc;
			npc.Set(m_Textlist[66], m_Textlist[8], 2012, 226, 190, 3);
			AddTriggerObjMap(&npc, 152);
			npc.Set(m_Textlist[67], m_Textlist[8], e山贼, 230, 186, 7);
			AddTriggerObjMap(&npc, 152, 0);
			npc.Set(m_Textlist[67], m_Textlist[8], e山贼, 233, 194, 1);
			AddTriggerObjMap(&npc, 152, 0);
			AddTriggerObjMap(m_Textlist[8], 151,0);
		}
		break;
	case 151:
		AddTriggerDialog2(44, -1);
		RemoveTriggerObjMap(151);
		UpdateJob2(68);
		break;
	case 152://山贼战斗
		AddTriggerDialog2(45, 153);
		break;
	case 153:
		
		{
			for (int i = 0; i < 10; i++)
			{
				ePetID petid;
				switch (rand() % 4)
				{
				case 0:petid = e山贼;
					break;
				default:petid = e强盗;
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
	case 50://刘洪1
		AddTriggerDialog2(35, 51);
		break;
	case 51:
		{
			AddPCPetEnemy2(8000,e强盗, 65, eMP_大唐官府, 54);
			for (int i = 0; i < 7; i++)
			{
				ePetID petid;
				switch (rand() % 4)
				{
				case 0:petid = e山贼;
					break;
				default:petid = e强盗;
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
	case 53://刘洪2
		AddTriggerDialog2(37, 54);
		break;
	case 54:
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(10000, e护卫, 60, eMP_大唐官府, 54);
			pPet->m_AtkDownHPHurt.d1 += 5;
			pPet= AddPCPetEnemy2(10000, e强盗, 60, eMP_阴曹地府, 59);
			pPet->AddSkill(ePS_鬼魂术);
			for (int i = 0; i < 5; i++)
			{
				ePetID petid;
				switch (rand() % 4)
				{
				case 0:petid = e强盗;
					break;
				default:petid = e护卫;
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
			cPetData* pPet= AddPCPetEnemy2(15000, e黑山老妖, 75, eMP_阴曹地府, 59);
			pPet->AddSkill(ePS_鬼魂术);
			pPet->m_MagicNumAdd += 2;
			pPet->m_SuckBloodRate.d1 += 10;
			pPet->SetJinJie(2);
			for (int i = 0; i < 8; i++)
			{
				ePetID petid;
				switch (rand() % 4)
				{
				case 0:petid = e黑山老妖;
					break;
				default:petid = e黑山老妖;
					break;
				}
				AddPCPetEnemy2(5000, petid, 50, (eMengPai)(rand() % 12));
			}
			SetMusic("凶夢伝染");
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
	case 58://刘母
		AddTriggerDialog2(40, 59);
		g_pMainState->m_DialogList.clear();
		break;
	case 59:
		AddTriggerObj2(36, 8, 60);
		UpdateJob2(37);
		break;
	case 60://殷温娇
		AddTriggerDialog2(41, -1);
		AddTriggerObj2(22, 11, 61);
		UpdateJob2(63);
		break;
	case 61://玄奘
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
{//四琉璃
	switch (stage)
	{
	case 0:
		SetChapter(2);
		g_pMainState->m_GlobalButton[5] = 2;
		AddTriggerDialog2(0,-1);
		AddTriggerObj2(1, 2, 1);
		UpdateJob2(16);
		break;
	case 1://卷帘大将
		AddTriggerDialog2(1, -1);
		AddTriggerObj2(3, 4, 2);
		UpdateJob2(15);
		break;
	case 2://粟粟娘
		AddTriggerDialog2(2, -1);
		AddTriggerObj2(5, 6, 3);
		UpdateJob2(17);
		break;
	case 3://女妖
		AddTriggerDialog2(3, 4);
		break;
	case 4: 
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(5000, e芙蓉仙子, 75, eMP_盘丝岭, 5);
			pPet->m_LiveHpLv += 10;
			pPet->m_Combo.d1 += 60;
			pPet->m_MagicNumAdd += 3;
			pPet->SetJinJie(2);
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 3)
				{
				case 0:petid = e蜘蛛精;
					break;
				default:petid = e蜘蛛精;
					break;
				}
				AddPetEnemy2(8000, petid, 70);
			}
			SetMusic("镜影命缘");

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
	case 6://金琉璃
		AddTriggerDialog2(5, 7);
		break;
	case 7:
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(8000, e如意仙子, 75, eMP_普陀山, 7);
			pPet->poisonRate.d1 += 20;
			pPet->m_MagicNumAdd += 3;
			pPet->SetJinJie(3);
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 3)
				{
				case 0:petid = e如意仙子;
					break;
				default:petid = e如意仙子;
					break;
				}
				AddPetEnemy2(8000, petid, 70);
			}
			SetMusic("镜影命缘");
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
	case 9://柳飞絮
		AddTriggerDialog2(7, -1);
		AddTriggerObj2(9, 10, 10);
		UpdateJob2(20);
		break;
	case 10://青琉璃
		AddTriggerDialog2(8, -1);
		AddTriggerObj2(26, 10, 11);
		UpdateJob2(21);
		break;
	case 11://翻天怪
		AddTriggerDialog2(9,12);
		break;
	case 12:
		{
		    cPetData* pPet;
			pPet = AddPCPetEnemy2(18000, e踏云兽, 80, eMP_狮驼岭, 26);
			pPet->m_StabRate.d1 = 60;
			pPet->m_StabDamageRate.d1 = 40;
			pPet->SetJinJie(3);
			AddPetEnemy2(15000, e踏云兽, 75);
			AddPetEnemy2(15000, e踏云兽, 75);
			
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
	case 14://青琉璃
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
	case 17://青琉璃
		AddTriggerDialog2(13, -1);
		AddTriggerObj2(1, 2, 18);
		UpdateJob2(16);
		break;
	case 18://卷帘大将
		AddTriggerDialog2(14, -1);
		AddTriggerObj2(12, 2, 19);
		UpdateJob2(24);
		break;
	case 19://阿紫
		AddTriggerDialog2(15, -1);
		AddTriggerObj2(1, 2, 20);
		UpdateJob2(16);
		break;
	case 20://卷帘大将
		AddTriggerDialog2(16, -1);
		AddTriggerObj2(12, 2, 21);
		UpdateJob2(24);
		break;
	case 21://姚太尉
		AddTriggerDialog2(17, 22);
		break;
	case 22:
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(22000, e天将, 82, eMP_天宫, 27);
		    pPet->m_StabRate.d1 = 20;
			pPet->m_StabDamageRate.d1 = 40;
			pPet->m_MagicNumAdd += 2;
			pPet->SetJinJie(3);
			AddPetEnemy2(20000, e天兵, 65);
			AddPetEnemy2(20000, e天兵, 65);

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
	case 24://卷帘大将
		AddTriggerDialog2(19, -1);
		AddTriggerObj2(13, 14, 25);
		UpdateJob2(25);
		break;
	case 25://王母娘娘
		AddTriggerDialog2(20, 26);
		break;
	case 26:
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(25000, e李靖, 92, eMP_天宫);
			pPet->comboNumDown += 1;
			pPet->m_MagicNumAdd += 3;
			pPet->m_AtkDownHPHurt.d1 += 1;
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 3)
				{
				case 0:petid = e天兵;
					break;
				default:petid = e天兵;
					break;
				}
				AddPetEnemy2(20000, petid, 85);
			}
			SetMusic("镜影命缘");
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
	case 28://卷帘大将
		TalkList(22, -1, -1, 30, -1);
		g_pMainState->m_TaskZhuaGui.SetTrigger(this, 9, 29);
		break;
	case 29://转到西梁女国剧情
		Process8(0);
		return TRUE;
	default:
		break;
	}
	return TRUE;
}

BOOL cTaskZhuXian::Process3(int stage)
{//小白龙
	switch (stage)
	{
	case 0:
		g_pMainState->m_GlobalButton[5] = 4;
		SetChapter(3);
		AddTriggerObj2(7, 8, 1);
		UpdateJob2(9);
		AddTriggerDialog2(1, -1);
		break;
	case 1://小白龙
		AddTriggerDialog2(2, 2);
		break;
	case 2://超级海豚
		{
			cPetData* petdata= AddPCPetEnemy2(30000, e超级海豚, 75, eMP_东海龙宫);
			petdata->m_MagicWater.d1 += 20;
			ePetID petid;
			for (int i = 0; i < 5; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e龟丞相; break;
				default:petid = e龟丞相; break;
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
			sppet.Set(e超级海豚,&addpoint,100,TRUE);
			GetPet(m_Textlist[35], &sppet, 100);
		}
		break;
	case 6://小白龙
		TalkList(0, 10, 11, 12, 7);
		break;
	case 7://塔塔之神
		AddTriggerDialog2(6, -1);
		AddTriggerObj2(13, 14, 8);
		UpdateJob2(15);
		break;
	case 8://奔波儿霸
		AddTriggerDialog2(7, -1);
		AddTriggerObj2(16, 17, 9);
		UpdateJob2(18);
		break;
	case 9://蟹将
		AddTriggerDialog2(8, 10);
		break;
	case 10://蟹将
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(50000, e碧水夜叉, 95, eMP_东海龙宫,29);
			pPet->m_MagicWater.d2 += 20;
			pPet->m_MagicNumAdd += 2;
			pPet->SetJinJie(3);
			ePetID petid;
			for (int i = 0; i < 5; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e鲛人;
					break;
				default:petid = e鲛人;
					break;
				}
				AddPCPetEnemy2(15000, petid, 90, (eMengPai)(rand() % 12));
			}
			SetMusic("魔方少女纹");
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
	case 12://万胜公主
		{
			AddTriggerDialog2(10, -1);
			AddTriggerObj2(21, 22, 13);
			UpdateJob2(23);
			
		}
		break;
	case 13://九头精怪
		g_pMainState->SetDialogListNpc(m_Textlist[19], 1001);
		AddTriggerDialog2(11, 14);
		break;
	case 14://
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(55000, e九头精怪, 115, eMP_狮驼岭,21);
			pPet->m_AtkDownHPHurt.d1 = 5;
			pPet->m_MagicNumAdd += 1;
			pPet= AddPCPetEnemy2(35000, e千年蛇魅, 95, eMP_东海龙宫,19);
			pPet->m_MagicWater.d2 += 20;
			pPet->m_MagicNumAdd += 3;
			pPet->SetJinJie(3);
			ePetID petid;
			for (int i = 0; i < 3; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e牛妖;
					break;
				default:petid = e牛妖;
					break;
				}
				AddPCPetEnemy2(20000, petid, 75, eMP_魔王寨);
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
	case 16://玉皇大帝
		AddTriggerDialog2(13, -1);
		AddTriggerObj2(7, 8, 17);
		UpdateJob2(9);
		break;
	case 17://小白龙
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
		TalkList(1,4,2,5,2);break;//猪八戒
	case 2:TalkList(2,6,7,8,3); break;//土地公公
	case 3:TalkList(3,9,10,11,4); break;//高翠兰
	case 4:TalkList(4,6,7,8, 5); break;//月老
	case 5:TalkList(5, 1, 2, 3, 6); break;//高翠兰
	case 6:TalkList(6, 4, 2, 5, 7); break;//猪八戒
	case 7:TalkList(7, 12, 13, 14, 8); break;//土地公公
	case 8:TalkList(8, 15, 13, 14, 9); break;//月香侍女
	case 9://康太尉
		AddTriggerDialog2(9, 10);
		break;
	case 10:
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(30000, e天兵, 105, eMP_天宫,15);
			pPet->m_AtkDownHPHurt.d1 = 5;
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet= AddPCPetEnemy2(30000, e风伯, 105, eMP_东海龙宫,65);
			pPet->m_MagicWater.d2 += 20;
			pPet->m_MagicNumAdd += 5;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(20000, e雨师, 105, eMP_方寸山, 66);
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
	case 12:TalkList(11, 19, 20, 21, 13); break;//嫦娥
	case 13://杨戟
		AddTriggerDialog2(12, 14);
		break;
	case 14:
		{
			if (g_pMainState->m_GlobalButton[0]>50)
				AddTriggerDialog2(38);
			cPetData* pPet;
			pPet = AddPCPetEnemy2(50000, e二郎神, 115, eMP_天宫);
			pPet->m_MagicNumAdd += 2;
			pPet= AddPCPetEnemy2(20000, e啸天犬, 105, eMP_狮驼岭);
			pPet->m_SuckBloodRate.d1 += 10;
			pPet = AddPCPetEnemy2(30000, e天兵, 95, eMP_天宫);
			pPet->SetJinJie(1);
			pPet = AddPCPetEnemy2(30000, e天兵, 95, eMP_东海龙宫);
			pPet->SetJinJie(1);
			pPet = AddPCPetEnemy2(30000, e天兵, 95, eMP_方寸山);
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
	case 16:TalkList(14, 16, 17, 18, 115); break;//慧觉
	case 115:
		{
			
			sMapObjTrigger obj;
			obj.m_Npc.Set(m_Textlist[52], m_Textlist[13], e超级神兔, 72, 72);
			obj.m_pTask = this;
			obj.m_Stage = -1;
			AddTriggerObjMap(&obj);
			TalkList(31, 52, 13, 53, 116); break;//嫦娥
		}
		break;
	case 116://超级神兔
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(30000, e夜罗刹, 115, eMP_天宫,47);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet= AddPCPetEnemy2(20000, e地狱战神, 110, eMP_狮驼岭,48);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(20000, e鬼将, 110, eMP_阴曹地府,49);
			pPet->SetJinJie(2);
			pPet = AddPCPetEnemy2(15000, e超级神兔, 80, eMP_天宫);
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
			sppet.Set(e超级神兔, &addpoint, 100, TRUE);
			GetPet(m_Textlist[56], &sppet, 100);
		}
		break;
	case -118:
		AddTriggerDialog2(40);
		break;
	case 17:TalkList(15, 1, 2, 3, 18); break;//嫦娥
	case 18:TalkList(16, 4, 2, 5, 19); break;//天蓬元帅
	case 19:TalkList(17, 25, 26, 27, 20); break;//土地公公
	case 20:TalkList(18,28, 26, 29, 21); break;//春三十娘
	case 21:TalkList(19, 30, 2, 31, 22); break;//白晶晶
	case 22:TalkList(20, 32, 2, 33, 23); break;//至尊宝
	case 23:TalkList(21, 34, 35, 36, 24); break;//二当家
	case 24:TalkList(22, 37, 38, 39, 25); break;//江湖奸商
	case 25://龙神
	
		{
			sNpc npc;
			int x, y;
			g_pMainState->m_Map.AutoGetPos(x, y, m_Textlist[41]);
			npc.Set(m_Textlist[40], m_Textlist[41], 123, x, y,0);
			AddTriggerObjMap(&npc, -1);
			TalkList(23, 40, 41, 42, 26);
		}
		break;
	case 26://超级神龙
		AddTriggerDialog2(24, 27);
		break;
	case 27:
	
		{
			AddPCPetEnemy2(20000, e超级神龙, 100, eMP_东海龙宫);
			for (int i = 0; i < 7; i++)
			{
				AddPCPetEnemy2(10000, e蛟龙, 100, (eMengPai)(rand() % 12));
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
		break;//龙神
	case 133://去地府找六道轮回
		g_pMainState->m_Friend.AddFriend(m_Textlist[61]);
		TalkList(33, -1, -1, 64, -1, 134);
		//AddRangeMap(63, 95, 57, 10, 135);
		break;
	case 134:
		Invite(m_Textlist[61]);
		AddTriggerObj2(62, 63, 135);
		break;
	case 135://千年怨鬼
		AddTriggerDialog2(34, 136);
		break;
	case 136:
		
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(20000, e幽灵, 150, eMP_阴曹地府,62);
			pPet->m_MagicNumAdd += 6;	
			pPet->SetJinJie(3);
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e牛头; break;
				default:petid = e马面; break;
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
		break;//至尊宝
	case 31:TalkList(28, 25, 26, 27, 32); break;//白晶晶
	case 32:TalkList(29, 1, 2, 3, 33); break;//春三十娘
	case 33:
		TalkList(30, -1, -1, -1, -1,34); 
		SetJiangLiItem(50,40);
	/*	SetChapter(5);
		AddTriggerLv(0, 105);*/
		break;//天蓬元帅
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
		AddTriggerDialog2(3, 3); //美猴王
		break;
	case 3:
		
		{
			AddPCPetEnemy2(10000, e雨师, 100, eMP_化生寺,26);
			AddPCPetEnemy2(8000, e沙和尚, 100, eMP_东海龙宫,28);
			AddPCPetEnemy2(8000, e猪八戒, 100, eMP_狮驼岭,27);
			ePetID petid;
			for (int i = 0; i < 3; i++)
			{
				switch (rand() % 3)
				{
				case 0:petid = e巨力神猿; break;
				case 1:petid = e长眉灵猴; break;
				default:petid = e超级金猴; break;
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
			
			AddTriggerDialog2(4, -11); //美猴王
			g_pCharacter->m_PCData.AddGrowing(1);
			g_pMainState->LockLv(45);
		}
		return TRUE;
	case -11:
		
		{
			AddPCPetEnemy2(50000, e孙悟空, 999, eMP_大唐官府);
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e巨力神猿; break;
				case 1:petid = e长眉灵猴; break;
				default:petid = e超级金猴; break;
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


	case 12:TalkList(6, 14, 15, 16, next); break;//观音姐姐
	case 13:TalkList(7, 8, 9, 10, next); break;//李靖
	case 14:TalkList(8, 8, 17, 10, next); break;//美猴王
	case 15:AddTriggerDialog2(9, next); break;//美猴王
	case 16:
		
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(80000, e孙悟空, 165, eMP_狮驼岭);
			pPet->m_MagicFire.d2 += 20;
			pPet->m_CounterRate.d1 += 80;
			pPet->comboNumDown += 4;
			SetMusic("打不倒的空气人");
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
					AddTriggerObjMap2(35, 36, e鬼将,xp,yp,-1,-17);
					break;
				case 1:
					AddTriggerObjMap2(35, 36, e净瓶女娲, xp, yp, -1, -18);
					break;
				case 2:
					AddTriggerObjMap2(35, 36, e炎魔神, xp, yp, -1, -19);
					break;
				}	
			}
		}
		return TRUE;
	case -17:
		
		{
			m_pObj = g_pMainState->m_pNowSelect;
			int lv = g_pCharacter->m_PCData.m_LV;
			AddPCPetEnemy2(lv * 100, e鬼将, lv + 5, eMP_随机, 35);
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
			AddPCPetEnemy2(lv * 100, e净瓶女娲, lv + 5, eMP_随机, 35);
			for (int i = 0; i < 7; i++)
				AddPCPetEnemy2(lv * 80, (ePetID)(10 + rand() % 20),lv);

			SetMusic();
			g_StateType = STATE_FIGHT;
			AddTriggerFightSuccess(-117);
		}
		return TRUE;//
	case -19://炎魔神
		
		{
			m_pObj = g_pMainState->m_pNowSelect;
			int lv = g_pCharacter->m_PCData.m_LV;
			cPetData* pPet;
			pPet= AddPCPetEnemy2(lv * 100, e炎魔神, lv + 5, eMP_魔王寨, 35);
			pPet->AddSkill(ePS_高级反震);
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
	case 18:TalkList(11, 18, 19, 20, next); break;//李靖
	case 19:TalkList(12, 11, 12, 13, next); break;//地藏王
	case 20:TalkList(13, 21, 22, 23, -20); break;//观音姐姐
	case -20:TalkList(14, 24, 22, 25, 21); break;//黑熊精
	case 21:AddTriggerDialog2(15, next); break;//小龙女
	case 22:
		
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(25000, e律法女娲, 110, eMP_大唐官府, 24);
			pPet->SetJinJie(3);
			pPet->AddSkill(ePS_高级连击);
			pPet->AddSkill(ePS_风华武圣);
			pPet->AddSkill(ePS_高级反击);
			pPet->m_ParryRate.d1 += 100;
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 2)
				{
				case 0:petid = e律法女娲; break;
				default:petid = e律法女娲; break;
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
	case 24:AddTriggerDialog2(17, next); break;//美猴王
	case 25:
		
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(30000, e巨力神猿, 145, eMP_狮驼岭);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(30000, e长眉灵猴, 145, eMP_普陀山);
			pPet->SetJinJie(3);
			ePetID petid;
			for (int i = 0; i < 5; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e超级金猴; break;
				default:petid = e超级金猴; break;
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
			RemoveTriggerObjMap();//妖王没了
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
		UnInvite("清风");
		AddFriend(32);
		g_pMainState->SetDialogListNpc(m_Textlist[31], 1081);
		TalkList(19, -1, -1, -1, -1, 28); break;//
		break;
	case 28:
		
		{
			g_pMainState->ClearDialogList();
			UnInvite("泡芙");
			AddFriend(33);
			TalkList(20, -1, -1, -1, -1, -1);

			AutoGetPet(m_Textlist[33], 3);
			Invite(m_Textlist[33]);

			AutoGetPet(m_Textlist[32], 2);
			Invite(m_Textlist[32]);
			UnInvite("小蛮");
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
		g_pMainState->SetDialogListPet(m_Textlist[1],e猪八戒);
		TalkList(0, 2, 3, 4, next); break;//猪八戒
		break;
	case 1:
		g_pMainState->m_DialogList.clear();
		TalkList(1, 5, 26, 6, next); break;//云游僧
	case 2:TalkList(2, 9, 10, 11, next); break;//高老先生
	case 3:AddTriggerDialog2(3, next); break;//三大王
	case 4:
		
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(100000, e超级大鹏, 150, eMP_狮驼岭,9);
			pPet = AddPCPetEnemy2(60000, e锦毛貂精, 145, eMP_方寸山, 28);
			pPet->SetJinJie(3);
			pPet->m_MagicNumAdd += 2;
			pPet = AddPCPetEnemy2(80000, e野猪精, 145, eMP_五庄观, 29);
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
	case 6:TalkList(5, 12, 3, 13, next); break;//野猪王
	case 7:AddTriggerDialog2(6, next); break;//白衣人
	case 8:
		
		{
			sZiZhi zizhi;
			zizhi.Set(1800, 2200, 5000, 6000, 1200, 1200, 200);
			AddPCEnemy2(50000,1, &zizhi,150, eMP_方寸山,12);
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 2)
				{
				case 0:petid = e如意仙子; break;
					default:petid = e星灵仙子; break;
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
	case 10:TalkList(8, 12, 3, 13, next); break;//觉明
	case 11:TalkList(9, 2, 3, 4, next); break;//白衣人
	case 12:TalkList(10, 17, 3, 18, next); break;//云游僧
	case 13:AddTriggerDialog2(11, next); break;//少女
	case 14:
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(50000, e蜃气妖, 150, eMP_盘丝岭, 31);
			pPet->m_SuckBloodRate.d1 += 100;
			pPet->SetJinJie(3);
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e蜃气妖; break;
				default:petid = e蜃气妖; break;
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
	case 16:TalkList(13, 22, 3, 23, next); break;//李靖
	case 17:AddTriggerDialog2(14, next); break;//老太婆
	case 18:
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(80000, e孙婆婆, 155, eMP_女儿村,30);
			pPet->poisonRate.d1 += 80;
			pPet->m_SuckBloodRate.d1 += 80;
			pPet = AddPCPetEnemy2(50000, e猫灵, 140, eMP_大唐官府);
			pPet->m_SuckBloodRate.d1 += 50;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(50000, e猫灵, 140, eMP_五庄观);
			pPet->m_SuckBloodRate.d1 += 50;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(50000, e猫灵, 130, eMP_普陀山);
			pPet->m_SuckBloodRate.d1 += 50;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(50000, e猫灵, 130, eMP_天宫);
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
	case 20:TalkList(16, 24, 3, 25, next); break;//李靖
	case 21:AddTriggerDialog2(17, next); break;//老太爷
	case 22:
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(80000, e白晶晶, 155, eMP_盘丝岭,27);
			pPet->m_SuckBloodRate.d1 += 50;
			pPet->m_AtkDownDef.d1 = 2;
			pPet->m_MagicNumAdd += 8;
			ePetID petid;
			for (int i = 0; i < 9; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e骷髅怪; break;
				default:petid = e骷髅怪; break;
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
	case 24:TalkList(19, 5, 26, 6, next); break;//李靖
	case 25:	
		TalkList(20, -1, -1, -1,-1, next);
		break;
	case 26:
		Process7(0);
		break;//高老先生
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
		g_pMainState->SetDialogListPet(m_Textlist[1], e猪八戒);
		TalkList(0, 6, 3, 7, 3); break;
		break;
	case 3:
		g_pMainState->m_DialogList.clear();
		TalkList(3, 8, 3, 9, next); break;//火焰山土地
	case 4:TalkList(4, 10, 11, 12, next); break;//云里雾
	case 5:AddTriggerDialog2(5, 6); break;//铁扇公主
	case 6:
	{
		g_pMainState->m_Map.LoadMap(21, 46, m_Textlist[13].c_str(), 0);
		g_pHeroObj->Set(POS_DEAD,0);
		TalkList(6, 14, 15, 16, next); 
	
		
			AddTriggerObjMap2(35, 15, e观音姐姐, 14, 15, 3,7);
			AddTriggerObjMap2(33, 15, e空度禅师, 10, 14, 3,7);
			AddTriggerObjMap2(34, 15, e菩提祖师, 28, 8, 7,7);
		}
		break;//疥癞和尚
	case 7://镇元大仙
		if (CheckINT(12, 3))
		{
			g_pMainState->SetDialogListPC(m_Textlist[32], 9);
			AddTriggerDialog2(7, -7);
		}
		else
			AddTriggerDialog2(28, -7);
		break;
	case -7://超级泡泡
	
		{
			g_pMainState->ClearDialogList();
			cPetData* pPet;	
			pPet= AddPCPetEnemy2(60000, e镇元大仙, 175, eMP_五庄观);
			pPet->m_SealRate.d1 += 50;
			pPet->m_MagicNumAdd += 3;
			pPet = AddPCPetEnemy2(30000, e空度禅师, 170, eMP_化生寺,33);
			pPet->m_DamageAddPercentCure.d1 += 50;	
			pPet->m_MagicNumAdd += 3;
			if (CheckINT(12, 3))
			{
				AddPCEnemy2(50000, 9, 0, 170, eMP_五庄观, 32);
				
			}
			pPet = AddPetEnemy2(50000, e真陀护法, 140);
			pPet->m_Combo.d1 += 50;
			pPet = AddPetEnemy2(50000, e真陀护法, 140);
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
	
	case 8:AddTriggerDialog2(8, next); break;//铁扇公主
	case 9:
	
		{
			cPetData* pPet;	
			pPet = AddPCPetEnemy2(60000, e地涌夫人, 160, eMP_魔王寨, 10);
			pPet->m_SealRate.d1 += 50;
			pPet->m_MagicNumAdd += 3;
			pPet = AddPCPetEnemy2(50000, e持国巡守, 160, eMP_天宫);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(50000, e红萼仙子, 160, eMP_普陀山);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(50000, e蛟龙, 160, eMP_大唐官府);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);

			SetMusic("镜影命缘");
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
	case 11:TalkList(10, 17, 18, 19, next); break;//土地公公
	case 12:AddTriggerDialog2(11, next); break;//铁扇公主
	case 13:
		
		{
			cPetData* pPet;	
			pPet = AddPCEnemy2(100000, 2005, 0, 165, eMP_魔王寨, 52);
			pPet->m_SealRate.d1 += 50;
			pPet->m_MagicNumAdd += 3;
			pPet = AddPCPetEnemy2(20000, e炎魔神, 135, eMP_天宫);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(20000, e炎魔神, 135, eMP_魔王寨);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(20000, e炎魔神, 135, eMP_大唐官府);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(20000, e炎魔神, 135, eMP_大唐官府);
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
	case 15://觉岸
		
		{
			TalkList(13, 10, 11, 12, next);
			g_pCharacter->UseCard(133);
		}
		break;
	case 16:TalkList(14, 6, 3, 7, next); break;//铁扇公主
	case 17://火焰山土地
		
		{
			g_pCharacter->UseCard(-1);
			TalkList(15, 10, 11, 12, next); 
		}
		break;
	case 18:TalkList(16, 23, 3, 24, next); break;//铁扇公主
	case 19:TalkList(17, 25, 26, 27, next); break;//牛将军
	case 20:
		SetDialogList(25);
		TalkList(18, 17, 18, 19, next); break;//玉面公主
	case 21:AddTriggerDialog2(19, next); break;//牛魔王
	case 22:
		
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(80000, e牛魔王, 170, eMP_魔王寨);
			pPet->m_MagicFire.d2 += 80;
			pPet->m_MagicNumAdd += 6;
			pPet->AddSkill(ePS_法术波动);
			pPet= AddPCPetEnemy2(60000, e千年蛇魅, 165, eMP_盘丝岭,25);
			pPet->AddSkill(ePS_法术连击);
			pPet->m_MagicNumAdd += 3;
			ePetID petid;
			for (int i = 0; i < 3; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e踏云兽; break;
				default:petid = e踏云兽; break;
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
			pPet = AddPCPetEnemy2(80000, e曼珠沙华, 170, eMP_盘丝岭, 25);
			pPet->AddSkill(ePS_高级法术连击);
			pPet->SetJinJie(3);
			pPet->m_MagicNumAdd += 3;
			pPet=AddPCPetEnemy2(50000, e超级灵狐, 160, eMP_女儿村);
			pPet->AddSkill(ePS_高级鬼魂术);
			pPet->SetJinJie(3);
			ePetID petid;
			for (int i = 0; i < 3; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e曼珠沙华; break;
				default:petid = e曼珠沙华; break;
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
		g_pMainState->SetDialogListPet(m_Textlist[1], e猪八戒);
		TalkList(22, -1, -1, -1, -1,-26); break;//铁扇公主
	case -26:
		g_pMainState->m_DialogList.clear();
		//Process9(0);
		g_pMainState->m_TaskHuoDong.Start(门派闯关);
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
			id = g_pMainState->m_Friend.FindFriend("泡芙");
			g_pMainState->m_Friend.m_FriendList[id].m_dataFileName = "泡芙3";
			id = g_pMainState->m_Friend.FindFriend("傻妞");
			g_pMainState->m_Friend.m_FriendList[id].m_dataFileName = "傻妞2";
			Invite(m_Textlist[41]);
			Invite(m_Textlist[42]);
		}
		return TRUE;
	case 28:
		
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(50000, e蚩尤, 200, eMP_狮驼岭);
			pPet->restoreRate += 30;
			ePetID petid;
			for (int i = 0; i < 7; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e修罗傀儡鬼; break;
				case 1:petid = e持国巡守; break;
				case 2:petid = e毗舍童子; break;
				default:petid = e真陀护法; break;
				}
				AddPCPetEnemy2(100000, petid,155);
			}
			SetMusic("战斗比武2");
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
			int id = g_pMainState->m_Friend.FindFriend("清风");
			g_pMainState->m_Friend.m_FriendList[id].m_dataFileName = "清风2";
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
			g_pMainState->SetDialogListPet(m_Textlist[1],e沙和尚);
			TalkList(0, 2, 3, 4, next); break;
		}
		break;
	case 1:
		g_pMainState->m_DialogList.clear();
		TalkList(2, 8, 9, 10, 3); break;//西门将军
	case 3:TalkList(3, 11, 9, 12, next); break;//姜国师
	case 4:AddTriggerDialog2(4, next); break;//美美
	case 5:
		
		{
			cPetData* pPet;
			pPet= AddPCPetEnemy2(20000, e蚌精, 80, eMP_东海龙宫,11);
			pPet->m_MagicWater.d2 += 20;
			pPet->SetJinJie(3);
			for (int i = 0; i < 4; i++)
			{
				pPet= AddPCPetEnemy2(15000, e蚌精, 80);
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
	case 7:AddTriggerDialog2(6, next); break;//蝎子精
	case 8:
	
		{
			UnInvite(m_Textlist[27]);
			cPetData* pPet;
			pPet= AddPCPetEnemy2(50000, e蝎子精, 100, eMP_女儿村);
			pPet->poisonRate.d1 += 20;
			pPet->SetJinJie(3);
			for (int i = 0; i < 4; i++)
			{
				pPet = AddPCPetEnemy2(10000, e百足将军, 85);
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
	case 10:TalkList(8, 18, 6, 19, next); break;//玄奘
	case 11:	
		g_pMainState->SetDialogListNpc(m_Textlist[16],1074);
		TalkList(9, 20, 21, 22, next); 
		RemoveTriggerObjMap();
		break;//西梁女国国王
	case 12:
		g_pMainState->ClearDialogList();
		TalkList(10, 23, 24, 25, next); break;//月老
	case 13:
		Invite(m_Textlist[28]);
		Invite(m_Textlist[29]);
		Invite(m_Textlist[27]);
		TalkList(11, 20, 21, 22, next); 
		break;//青莲仙女
	case 14:AddTriggerDialog2(12, next); break;//玄藏幻影
	case 15:
		
		{
			AddTriggerDialog2(17);
			cPetData* pPet;
			 pPet= AddPCEnemy2(20000, 1, 0, 100, eMP_化生寺,26,0,6);
			 pPet->m_CureCriRate.d1 += 20;
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e蚌精; break;
				case 1:petid = e鲛人; break;
				case 2:petid = e碧水夜叉; break;
				default:petid = e蛟龙; break;
				}
				AddPCPetEnemy2(10000, petid, 68, (eMengPai)(rand() % 12));
			}
			SetMusic("白色相簿深爱");
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
	case 17:TalkList(14, 20, 21, 22, next); break;//西梁女国国王
	case 18:
		TalkList(15, -1, -1, -1, -1,19); 
		break;//月老
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
		AddTriggerObjMap2(1, 4, e巫奎虎, 143, 83, 3, 2);
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
			pPet = AddPCPetEnemy2(250000, e巫奎虎, 175, eMP_大唐官府);
			pPet->poisonRate.d1 = 100;
			pPet->poisonRate.d2 = 100;
			pPet->m_DamageAddPercentPoision.d1= 200;
			pPet->m_DamageAddPercentPoision.d2 = 200;
			AddFriend(3);
			Invite(m_Textlist[3], 11);
			pPet= AddPetEnemy2(120000, e超级白泽, 175);
			pPet->SetJinJie(3);
			pPet=AddPetEnemy2(120000, e超级赤焰兽, 175);
			pPet->SetJinJie(3);
			pPet = AddPetEnemy2(120000, e超级青鸾, 175);
			pPet->SetJinJie(3);
			ePetID petid;
			for (int i = 0; i < 3; i++)
			{
				switch (rand() % 4)
				{
				case 0:petid = e曼珠沙华; break;
				case 1:petid = e星灵仙子; break;
				case 2:petid = e如意仙子; break;
				default:petid = e巡游天神; break;
				}
				pPet=AddPCPetEnemy2(80000, petid, 155);
				pPet->SetJinJie(3);
			}
		
			SetMusic("满天");
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
		g_pMainState->SetDialogListPet(m_Textlist[14], e李靖);
		TalkList(2, -1, -1, 9,-1, -6);
	
		AddTriggerObjMap2(10, 11, e蚩尤, 151, 60, 3, 7,4);

		AddTriggerObjMap2(15, 11, e知了王, 153, 51, 3, 11, 3);
		AddTriggerObjMap2(15, 11, e狂豹人, 167, 59, 3, 12, 3);

		AddTriggerObjMap2(16, 11, e猫灵人, 176, 51, 3, 13, 3);
		AddTriggerObjMap2(16, 11, e鬼将, 162, 45, 3, 14, 3);

		/*AddTriggerObjMap2(17, 11, e修罗傀儡鬼, 175, 39, 3, 15, 3);
		AddTriggerObjMap2(17, 11, e修罗傀儡妖, 190, 45, 3, 16, 3);*/
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
			pPet->AddSkill(ePS_龙神守护);
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
	case 8://最终BOSS
		{
			cPetData* pPet;

			if (CheckINT(11, 1))
			{
				sZiZhi zizhi;
				zizhi.Set(2000, 2000, 5000, 90000, 2000, 2000, 170);
				pPet= AddPCEnemy2(1500000,2007,&zizhi,200,eMP_魔王寨,28,9,28);
				pPet->AddSkill(ePS_高级法术连击);
				pPet->AddSkill(ePS_高级法术暴击);
				pPet->AddSkill(ePS_高级法术波动);
				pPet->AddSkill(ePS_高级魔之心);
				pPet->AddSkill(ePS_高级精神集中);
				pPet->AddSkill(ePS_高级神佑复生);
				pPet->AddSkill(ePS_高级再生);
				pPet->AddSkill(ePS_高级防御);
				pPet->AddSkill(ePS_高级幸运);
				pPet->AddSkill(ePS_高级敏捷);
				pPet->GoldLivePercent.d1 += 990000;
				pPet->m_LiveHpLv += 10000;
			}
			pPet=AddPCPetEnemy2(100000, e蚩尤, 200, eMP_狮驼岭);
			pPet->restoreRate += 30;
			pPet->m_JinJieNum.m_PositionID = 3;
			pPet = AddPCPetEnemy2(100000, e蝎子精, 200, eMP_女儿村, 19);
			pPet->abnormalResist += 10;
			pPet->poisonRate.d1 += 50;
			pPet->m_DamageAddPercentPoision.d1 +=50;
			pPet->poisonRate.d2 += 50;
			pPet->m_JinJieNum.m_PositionID = 3;
			pPet = AddPCPetEnemy2(150000, e净瓶女娲, 200, eMP_普陀山,18);
			pPet->abnormalResist += 10;
			pPet->m_JinJieNum.m_PositionID = 3;
			pPet = AddPCPetEnemy2(150000, e吸血鬼, 200, eMP_阴曹地府, 21);
			pPet->m_SuckBloodRate.d1 += 20;
			pPet->m_SuckBloodRate.d2 += 50;
			pPet->abnormalResist += 10;
			pPet->m_JinJieNum.m_PositionID = 3;
			pPet = AddPCPetEnemy2(150000, e巨力神猿, 200, eMP_大唐官府, 20);
			pPet->abnormalResist += 10;
			pPet->m_AtkDownHPHurt.d1 += 10;
			pPet->m_JinJieNum.m_PositionID = 3;
			pPet = AddPCPetEnemy2(150000, e蛟龙, 200, eMP_天宫, 22);  
			pPet->m_DamagePercent.d2 += 20;
			pPet->abnormalResist += 10;
			pPet->m_JinJieNum.m_PositionID = 3;
			pPet = AddPCPetEnemy2(150000, e蚌精, 200, eMP_东海龙宫, 24);
			pPet->m_MagicWater.d2 += 30;
			pPet->m_MagicWater.d1 += 10;
			pPet->abnormalResist += 10;
			pPet->m_JinJieNum.m_PositionID = 3;
			pPet->m_Controler.Set(0);
			pPet = AddPCPetEnemy2(100000, e雨师, 200, eMP_化生寺, 23);
			pPet->m_MagicWater.d2 += 30;
			pPet->abnormalResist += 10;
			pPet->m_JinJieNum.m_PositionID = 3;
		
			pPet = AddPCPetEnemy2(100000, e雾中仙, 200, eMP_五庄观, 26);
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
				pPet = AddPCPetEnemy2(150000, e黑山老妖, 200, eMP_魔王寨, 25);
				pPet->abnormalResist += 10;
				pPet->m_LiveHpLv += 10;
				pPet->SetJinJie(3);
				pPet->m_Controler.Set(0);
				AddTriggerFightSuccess(next);
			}
			g_pMainState->m_InterfaceTeam.SetFormation(sky, TRUE);
			SetMusic("华夏萌战录");
			g_StateType = STATE_FIGHT;
		
		}
		return TRUE;
	case -9:
		{//只剩一个敌人,战斗结束
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
	case 11://知了王
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(16000, e知了王, 180, eMP_天宫,15);
			pPet->m_CounterRate.d1 += 50;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e灵符女娲, 170, eMP_魔王寨);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e净瓶女娲, 170, eMP_普陀山);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e芙蓉仙子, 165);
			pPet->m_LiveHpLv += 10;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e星灵仙子, 165);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e律法女娲, 165);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e红萼仙子, 165);
			pPet->m_Combo.d1 += 40;
			pPet->comboNumUp += 5;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e蚌精, 165, eMP_东海龙宫);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e曼珠沙华, 165);
			pPet->m_LiveHpLv += 30;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e藤蔓妖花, 165);
			pPet->SetJinJie(3);
			g_pMainState->m_InterfaceTeam.SetFormation(bird, TRUE);
			SetMusic("仙剑4战斗BGM");
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
	case 12://狂豹人
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(16000, e狂豹人, 175, eMP_大唐官府);
			pPet->m_CriRate.d1 += 30;
			pPet->m_CriAddPercent.d1 += 30;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e犀牛将军人, 170);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e狂豹, 170);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e犀牛将军, 165);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e毗舍童子, 165);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e混沌兽, 165);
			pPet->m_DamagePercent.d2 += 10;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e吸血鬼, 165);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e巡游天神, 166);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e真陀护法, 165);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e持国巡守, 166);
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
	case 13://e猫灵人
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(16000, e猫灵人, 170, eMP_大唐官府);
			pPet->m_SPD.AddDataAddPercent(30);
			pPet->m_AtkDownDef.d1 = 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e猫灵, 165);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e蝎子精, 160);
			pPet->poisonRate.d1 += 20;
			pPet->poisonRate.d2 += 20;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e鲛人, 160);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e雾中仙, 160);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e千年蛇魅, 160);
			pPet->poisonRate.d1 += 20;
			pPet->poisonRate.d2 += 20;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e腾蛇, 160);
			pPet->poisonRate.d1 += 20;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e噬天虎, 160);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e千年蛇魅, 160);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e鲛人, 160);
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
	case 14://e鬼将
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(16000, e鬼将, 165, eMP_大唐官府);
			pPet->m_CriRate.d1 += 20;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e天将, 160);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e天兵, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e机关人, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e机关兽, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e机关鸟, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e巴蛇, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e踏云兽, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e龙龟, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e连弩车, 155);
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
	case 15://e修罗傀儡鬼
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(16000, e修罗傀儡鬼, 160, eMP_大唐官府);
			pPet->m_SuckBloodRate.d1 += 20;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e古代瑞兽, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e蝴蝶仙子, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e凤凰, 155);
			pPet->m_MagicFire.d2 += 50;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e蛟龙, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e风伯, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e雨师, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e雷鸟人, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e百足将军, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e大力金刚, 155);
			pPet->m_DamagePercent.d2 += 20;
			pPet->SetJinJie(3);
			SetMusic("未来宇宙");
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
	case 16://e修罗傀儡妖
	
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(16000, e修罗傀儡妖, 160, eMP_大唐官府);
			pPet->m_LiveHpLv += 10;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e蜃气妖, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e烟花占卜师, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e小仙女, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e善财童子, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e小毛头, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e小魔头, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e小精灵, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e小仙灵, 155);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(16000, e小丫丫, 155);
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
{//修改普通召唤兽敌人加点
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
{//修改门派敌人加点
	string namet;
	sAddPoint m_AddPoint;
	if (name == -1)namet = "";
	else namet = m_Textlist[name];
	switch (mp)
	{
	case eMP_东海龙宫:
	case eMP_魔王寨:
	case eMP_方寸山:m_AddPoint.Set(0, 0, 4, 1, 0); break;
	case eMP_化生寺:
	case eMP_阴曹地府:m_AddPoint.Set(0, 2, 0, 2, 1); break;
	case eMP_女儿村:
	case eMP_普陀山:m_AddPoint.Set(0, 1, 0, 2, 2); break;
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
	case 0://无名野鬼
	
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
				pet.Set(e雾中仙, &point);
				pet.m_zizhi.m_MAGZZ = 5000;
				pet.m_zizhi.m_SPDZZ = 1700;
				pet.m_zizhi.m_HPZZ = 10000;
				pet.m_zizhi.m_Growing = 170;
				pet.AddSkill(ePS_奔雷咒);
				pet.AddSkill(ePS_雷击);
				pet.AddSkill(ePS_高级魔之心);
				pet.AddSkill(ePS_高级法术连击);
				pet.AddSkill(ePS_高级法术暴击);
				pet.AddSkill(ePS_高级再生);
				pet.AddSkill(ePS_高级精神集中);
				pet.AddSkill(ePS_高级神佑复生);
				pet.AddSkill(ePS_高级防御);
				pet.AddSkill(ePS_龙神守护);
				pet.AddSkill(ePS_高级敏捷);
				pet.AddSkill(ePS_高级招架);
				pet.AddSkill(ePS_高级飞行);
				pet.AddSkill(ePS_高级隐身);
				pet.AddSkill(ePS_高级慧根);
				pet.AddSkill(ePS_高级冥思);
				pet.AddSkill(ePS_移花接木);
				GetPet2(&pet, 100);
			}
		}
		break;
	case 3://李善人
		if (g_pCharacter->m_PCData.m_Money[0] < 2000)
		{
			AddTriggerDialog2(2);
			SetJiangLi2(0, 2000);
		}
		else AddTriggerDialog2(3);
		break;
	case 4:Select(6, 5, -1, 3, 5, 4, -1); break;//打造
	case 5:	g_pMainState->m_Dazao.OnOff(TRUE); break;
	case 6:
		if (g_pCharacter->m_PCData.m_BangPaiID == -1)
		{
			TalkList(4,-1,-1,-1,-1);
		}
		else Select(8,7,-1,3,7,4,-1);
		return TRUE;
	case 7:
		g_pMainState->m_Map.LoadMap(124, 115,"帮派", 0);
		break;
	case 8://幻境之王
		if (!CheckINT(11, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(300000, e大力金刚, 220, eMP_阴曹地府, 18);
			pPet->m_MagicFire.d2 += 50;
			pPet->m_MagicNumAdd += 8;
			pPet->SetJinJie(3);
			pPet->AddSkill(ePS_法术连击);
			pPet->AddSkill(ePS_高级精神集中);
			pPet->AddSkill(ePS_高级否定信仰);
			pPet = AddPCPetEnemy2(180000, e修罗傀儡鬼, 200, eMP_狮驼岭, 20);
			pPet->m_MagicNumAdd += 2;
			pPet->SetJinJie(3);

			for (int i = 0; i < 3; i++)
			{
				AddPetEnemy2(150000, e大力金刚, 220, 19);
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
			oss << "当前房屋规模为";
			oss << g_pMainState->m_FangWu.GetGuiMo();
			oss << "升级需要";
			oss << (g_pMainState->m_FangWu.GetGuiMo()+1) * 200;
			oss << "万,需要吗?";
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
		else g_pMainState->m_pNowSelect->Talk("钱不够");
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
			pet= AddPCPetEnemy2(20000, e赛太岁, 90);
			pet->ghostSpecial.d1 += 100;
			ePetID petid;
			for (int i = 0; i < 4; i++)
			{
				switch (rand() % 3)
				{
				case 0:petid = e百足将军; break;
				case 1:petid = e野猪精; break;
				default:petid = e锦毛貂精; break;
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
				oss << "你的出战召唤兽离下次进阶还需" << (Pet.m_JinJieNum.m_JinJieNum+1)*500000;
				break;
			default:
				oss << "你的出战召唤兽已经无法再进阶了";
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
				m_pObj->Talk("进阶成功");
				g_pMainState->m_PCHead.UpdatePet();
			}
			else m_pObj->Talk("钱不够");
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
				m_pObj->Talk("得到了坐骑");
			}
			else m_pObj->Talk("钱不够");
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
		else g_pMainState->m_Tags.Add("钱不够");
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
				oss << "(需要#R" << moneyneed << "#R钱)";
			else
				oss << "你现在没有出战召唤兽";
			g_pMainState->m_TriggerDialog.AddSelect(this, oss.str(), m_Textlist[16], -1,
				"强化", 27,
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
				g_pMainState->m_Tags.Add("召唤兽需要升级才能继续强化");
				return TRUE;
			}
			if (g_pCharacter->m_PCData.AddMoney(-moneyneed, 0, 0, FALSE))
			{
			
				for (int i = 0; i < 3;i++)
					Pet->m_PetDataZZ.lvUpFuZhuSkill(lvadd, i);
			}
			else g_pMainState->m_Tags.Add("钱不够");
		}
		else g_pMainState->m_Tags.Add("没有出战召唤兽");
		break;
	case 30:
		if (g_pCharacter->m_PCData.m_LV < 60)
			g_pMainState->m_LearnBangPaiSkill.OnOff(TRUE);
		else
			g_pMainState->m_pNowSelect->Talk("我只帮新人(60级以下的)");
		break;
	default:
		ERRBOX;
		break;
	case 31://地藏王师傅
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(200000, e地藏王, 200, eMP_阴曹地府);
			pPet->m_MagicNumAdd += 8;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_法术连击);
			pPet->AddSkill(ePS_高级精神集中);
			pPet->AddSkill(ePS_高级否定信仰);
			pPet = AddPCPetEnemy2(100000, e转轮王, 200, eMP_阴曹地府);
			pPet->m_MagicNumAdd += 2;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e转轮王, 200, eMP_阴曹地府);
			pPet->m_MagicNumAdd += 2;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e转轮王, 200, eMP_阴曹地府);
			pPet->m_MagicNumAdd += 2;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e转轮王, 200, eMP_阴曹地府);
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
	case 33://程咬金师傅
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(250000, e程咬金, 200, eMP_大唐官府);
			pPet->AddSkill(ePS_高级精神集中);
			pPet->AddSkill(ePS_高级否定信仰);
			pPet->restoreRate += 100;
			pPet = AddPCPetEnemy2(150000, e护卫, 200, eMP_大唐官府,21);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(150000, e护卫, 200, eMP_大唐官府, 21);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(150000, e护卫, 200, eMP_大唐官府, 21);
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(150000, e护卫, 200, eMP_大唐官府, 21);
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
	case 35://菩提祖师
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(200000, e菩提祖师, 200, eMP_方寸山);
			pPet->m_MagicNumAdd += 5;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_法术连击);
			pPet->AddSkill(ePS_高级精神集中);
			pPet->AddSkill(ePS_高级否定信仰);
			pPet = AddPCPetEnemy2(100000, e混沌兽, 200, eMP_方寸山, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e混沌兽, 200, eMP_方寸山, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e混沌兽, 200, eMP_方寸山, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e混沌兽, 200, eMP_方寸山, 21);
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
	case 37://东海龙王师傅
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(150000, e东海龙王, 200, eMP_东海龙宫);
			pPet->m_MagicNumAdd += 8;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_法术连击);
			pPet->AddSkill(ePS_高级精神集中);
			pPet->AddSkill(ePS_高级否定信仰);
			pPet = AddPCPetEnemy2(100000, e蛟龙, 200, eMP_东海龙宫, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e蛟龙, 200, eMP_东海龙宫, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e蛟龙, 200, eMP_东海龙宫, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e蛟龙, 200, eMP_东海龙宫, 21);
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
	case 39://观音姐姐师傅
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(200000, e观音姐姐, 200, eMP_普陀山);
			pPet->m_MagicNumAdd += 5;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_法术连击);
			pPet->AddSkill(ePS_高级精神集中);
			pPet->AddSkill(ePS_高级否定信仰);
			pPet = AddPCPetEnemy2(100000, e净瓶女娲, 200, eMP_普陀山, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e净瓶女娲, 200, eMP_普陀山, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e灵符女娲, 200, eMP_普陀山, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e灵符女娲, 200, eMP_普陀山, 21);
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
	case 41://化生寺师傅
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(150000, e空度禅师, 200, eMP_化生寺);
			pPet->m_MagicNumAdd += 2;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_高级精神集中);
			pPet->AddSkill(ePS_高级否定信仰);
			pPet = AddPCPetEnemy2(100000, e金身罗汉, 200, eMP_化生寺, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e金身罗汉, 200, eMP_化生寺, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e金身罗汉, 200, eMP_化生寺, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e金身罗汉, 200, eMP_化生寺, 21);
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
	case 43://猪八戒师傅
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(200000, e猪八戒, 200, eMP_天宫);
			pPet->m_MagicFire.d2 += 50;
			pPet->m_MagicNumAdd += 2;
			pPet->AddSkill(ePS_高级精神集中);
			pPet->AddSkill(ePS_高级否定信仰);

			for (int i = 0; i < 4; i++)
			{
				AddPetEnemy2(200000, e野猪精, 250);
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
	case 45://五庄观师傅
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(200000, e镇元大仙, 200, eMP_五庄观);
			pPet->m_MagicNumAdd += 2;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_高级精神集中);
			pPet->AddSkill(ePS_高级否定信仰);
			pPet = AddPCPetEnemy2(100000, e善财童子, 200, eMP_五庄观, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e善财童子, 200, eMP_五庄观, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e善财童子, 200, eMP_五庄观, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e善财童子, 200, eMP_五庄观, 21);
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
	case 47://狮驼岭师傅
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(150000, e大大王, 200, eMP_狮驼岭);
			pPet->m_MagicNumAdd += 1;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_高级精神集中);
			pPet->AddSkill(ePS_高级否定信仰);
			pPet = AddPCPetEnemy2(100000, e噬天虎, 200, eMP_狮驼岭, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e噬天虎, 200, eMP_狮驼岭, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e噬天虎, 200, eMP_狮驼岭, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e噬天虎, 200, eMP_狮驼岭, 21);
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
	case 49://魔王寨师傅
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(150000, e牛魔王, 200, eMP_魔王寨);
			pPet->m_MagicNumAdd += 8;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_高级精神集中);
			pPet->AddSkill(ePS_高级否定信仰);
			pPet = AddPCPetEnemy2(100000, e牛妖, 200, eMP_魔王寨, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e牛妖, 200, eMP_魔王寨, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e牛妖, 200, eMP_魔王寨, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e牛妖, 200, eMP_魔王寨, 21);
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
	case 51://盘丝洞师傅
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(150000, e白晶晶, 200, eMP_盘丝岭);
			pPet->m_MagicNumAdd += 5;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_高级精神集中);
			pPet->AddSkill(ePS_高级否定信仰);
			pPet = AddPCPetEnemy2(100000, e蜘蛛精, 200, eMP_盘丝岭, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e蜘蛛精, 200, eMP_盘丝岭, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e蜘蛛精, 200, eMP_盘丝岭, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e蜘蛛精, 200, eMP_盘丝岭, 21);
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
	case 53://女儿村师傅
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(150000, e孙婆婆, 200, eMP_女儿村);
			pPet->m_MagicNumAdd += 5;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_高级精神集中);
			pPet->AddSkill(ePS_高级否定信仰);
			pPet = AddPCPetEnemy2(100000, e曼珠沙华, 200, eMP_女儿村, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e曼珠沙华, 200, eMP_女儿村, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e曼珠沙华, 200, eMP_女儿村, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e曼珠沙华, 200, eMP_女儿村, 21);
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
	case 55://孙悟空挑战
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(250000, e孙悟空, 250, eMP_天宫);
			pPet->m_MagicNumAdd += 3;
			pPet->restoreRate += 100;
			pPet->AddSkill(ePS_高级精神集中);
			pPet->AddSkill(ePS_高级否定信仰);
			pPet->AddSkill(ePS_高级必杀);
			pPet->AddSkill(ePS_高级再生);
			pPet = AddPCPetEnemy2(150000, e巨力神猿, 200, eMP_狮驼岭, 22);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(150000, e长眉灵猴, 200, eMP_东海龙宫, 23);
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
	case 57://天宫师傅
		if (!CheckINT(14, 1))
		{
			cPetData* pPet;
			pPet = AddPCPetEnemy2(150000, e李靖, 200, eMP_天宫);
			pPet->m_MagicNumAdd += 5;
			pPet->AddSkill(ePS_高级精神集中);
			pPet->AddSkill(ePS_高级否定信仰);
			pPet = AddPCPetEnemy2(100000, e天将, 200, eMP_天宫, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e天将, 200, eMP_天宫, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e天将, 200, eMP_天宫, 21);
			pPet->m_MagicNumAdd += 1;
			pPet->SetJinJie(3);
			pPet = AddPCPetEnemy2(100000, e天将, 200, eMP_天宫, 21);
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
{//宝箱
	int baoxiangid;
	int baoxiangindex;
	GetBaoXiangID(stage, baoxiangid, baoxiangindex);
	SetINT(baoxiangid, baoxiangindex);
	switch (stage)
	{
	case -1:
		return TRUE;
		//东海海底
	case 0:SetJiangLiItem(0, 32); break;
	case 1:SetJiangLiItem(0, 33); break;
		//沉船
	case 2:SetJiangLiItem(0, 34); break;
		//东海岩洞
	case 3:SetJiangLiItem(2, 22,10); break;
	case 4:SetJiangLiItem(0, 23,30); break;
	case 5:SetJiangLiItem(10, 24); break;
		//建邺杂
	case 6:SetJiangLiItem(1, 27); SetJiangLiItem(2, 27); break;
		//
	case 7:SetJiangLiItem(0, 29); break;
	case 8:SetJiangLi2(0, 500000, 0, 0); break;
		//无名鬼城
	case 9:SetJiangLiItem(4, 24); break;
		//大雁塔
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
{//宝箱对应的脚本号
	id = 100 + type / 30;
	index = type % 30;
}

BOOL cTaskZhiXian::Process4(int stage)
{
	if (stage == -1)return TRUE;
	if (stage < 300)
	{//商店
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
		"是", stage,
		"否", -1
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
	path1+="任务//";
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
	case eMP_大唐官府:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("领悟了新技能");
			return TRUE;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级感知);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级偷袭);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级强力);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级永恒);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级必杀);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级连击);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_风刃);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_直死);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_普陀山:
	case eMP_化生寺:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("领悟了新技能");
			return TRUE;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级再生);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级夜战);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级防御);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级法术抵抗);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级法术连击);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级幸运);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级招架);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级永恒);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_方寸山:
	case eMP_女儿村:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("领悟了新技能");
			return TRUE;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级再生);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级夜战);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级防御);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级敏捷);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级否定信仰);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级法术抵抗);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级幸运);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级神迹);
			break;
		default:ERRBOX;
			break;
		}
		break;	
	case eMP_狮驼岭:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("领悟了新技能");
			return TRUE;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级强力);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级偷袭);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级防御);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级夜战);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级必杀);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级反击);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级反震);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级神迹);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_魔王寨:
	case eMP_东海龙宫:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("领悟了新技能");
			return TRUE;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级再生);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级防御);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级敏捷);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级法术波动);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级魔之心);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级法术连击);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级法术暴击);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级永恒);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_盘丝岭:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("领悟了新技能");
			return TRUE;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级再生);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级偷袭);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级法术抵抗);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级鬼魂术);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级必杀);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级连击);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_直死);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_风华武圣);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_阴曹地府:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("领悟了新技能");
			return TRUE;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级鬼魂术);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级防御);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级再生);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级法术抵抗);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级反震);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级招架);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_龙鳞防御);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级永恒);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_五庄观:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("领悟了新技能");
			return TRUE;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级再生);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级法术抵抗);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级防御);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级夜战);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级敏捷);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级强力);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级精神集中);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级神迹);
			break;
		default:ERRBOX;
			break;
		}
		break;
	case eMP_天宫:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("领悟了新技能");
			return TRUE;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_再生);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_偷袭);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_防御);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_夜战);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级魔之心);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级连击);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_风华武圣);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级永恒);
			break;
		default:ERRBOX;
			break;
		}
		break;
	default:
		switch (stage)
		{
		case 100:
			g_pHeroObj->Talk("领悟了新技能");
			return TRUE;
		case 0:
			AddTriggerLv(1, 20);
			break;
		case 1:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_再生);
			AddTriggerLv(2, 40);
			break;
		case 2:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_偷袭);
			AddTriggerLv(3, 60);
			break;
		case 3:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_防御);
			AddTriggerLv(4, 80);
			break;
		case 4:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_夜战);
			AddTriggerLv(5, 100);
			break;
		case 5:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级魔之心);
			AddTriggerLv(6, 120);
			break;
		case 6:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级连击);
			AddTriggerLv(7, 140);
			break;
		case 7:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_风华武圣);
			AddTriggerLv(8, 160);
			break;
		case 8:
			Process(100);
			g_pCharacter->m_PCData.AddSkill(ePS_高级永恒);
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
