#include "ScriptMgr.h"
#include "ScriptedCreature.h"

class npcRecycleBot : public CreatureScript
{
public:
    npcRecycleBot() : CreatureScript("npcRecycleBot") { }

    struct npcRecycleBotAI : public ScriptedAI
    {
        npcRecycleBotAI(Creature* creature) : ScriptedAI(creature) { }

        void IsSummonedBy(Unit* summoner) override
        {
            me->SetCanFly(false);
            me->SetDisableGravity(true);
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_NOT_ATTACKABLE_1);

            events.ScheduleEvent(EVENT_DESPAWN, 5 * MINUTE * IN_MILLISECONDS);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (events.ExecuteEvent() == EVENT_DESPAWN)
            {
                me->DespawnOrUnsummon();
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npcRecycleBotAI(creature);
    }
};

void AddSC_npcRecycleBot()
{
    new npcRecycleBot();
}
