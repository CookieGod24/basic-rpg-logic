#include <iostream>
#include "playercharacter.hpp"
#include "item_manager.hpp"
#include "cleric.hpp"

int main() {
    PlayerCharacter mister(new Cleric());
    std::cout << "Mister's stats: " << std::endl
    << "-HP: " << mister.getCurrentHp() << "/" << mister.getMaxHp() << std::endl
    << "-Strength: " << mister.getClass()->Str << std::endl
    << "-Intelligence: " << mister.getClass()->Int << std::endl
    << "-Dexterity: " << mister.getClass()->Dex << std::endl
    << "-Physical Armor: " << mister.getClass()->PhysArmor << std::endl
    << "-Magical Armor: " << mister.getClass()->MagicArmor << std::endl
    << "-Level: " << mister.getCurrentLevel() << std::endl
    << "-Exp: " << mister.getCurrentExp() << "/" << mister.getExpForNextLevel() << std::endl
    << "Abilities: " << std::endl;
    for(auto& ability : mister.getClass()->Abilites) {
        std::cout << "-" << ability.name << std::endl;
    }
    std::cout << "Effects: " << std::endl;
    for(auto& e : mister.getEffects()) {
        std::cout << "-" << e.name << " (" << e.duration << ")" << std::endl;
    }

    std::cout << "Equipped Armors: " << std::endl;
    for(auto a = 0; a < (int)ARMORSLOT::NUM_SLOTS; a++) {
        if(mister.getEquippedArmorAt(a)) {
            std::cout << "-" << mister.getEquippedArmorAt(a)->name << std::endl;
        } else {
            std::cout << "-None" << std::endl;
        }
    }

    std::cout << "Equipped Weapons: " << std::endl;
    for(auto a = 0; a < 2; a++) {
        if(mister.getEquippedWeaponAt(a)) {
            std::cout << "-" << mister.getEquippedWeaponAt(a)->name << std::endl;
        } else {
            std:: cout << "-None" << std::endl;
        }
    }


    Effect stony("Stone Shield", 1, 0, 0, 0, 10, 0);

    Item* IronSword = ItemManager::CreateWeapon("Iron Sword", StatBlock(), 3, 6, WEAPONSLOT::ONEHAND, WEAPONTYPE::MELEE);
    mister.equip(IronSword);

    Item* PlateMail = ItemManager::CreateArmor("Plate Mail", StatBlock(0, 0, 0, 6, 0), ARMORSLOT::CHEST);
    mister.equip(PlateMail);

    Effect* FireHands = new Effect("Fire Hands", 2, 3, 0, -1, 0, 0);
    Item* FireHandsPot = ItemManager::CreatePotion("Fiery Hands Potion", FireHands, 1);
    if(mister.use(FireHandsPot)) {
        std::cout << "Fiery Hands Potion used. " << std::endl;
    } else {
        std::cout << "Fire Hands Potion not used!!" << std::endl;
    }

    mister.gainExp(567);
    std::cout << "Mister's stats: " << std::endl
    << "-HP: " << mister.getCurrentHp() << "/" << mister.getMaxHp() << std::endl
    << "-Strength: " << mister.getClass()->Str << std::endl
    << "-Intelligence: " << mister.getClass()->Int << std::endl
    << "-Dexterity: " << mister.getClass()->Dex << std::endl
    << "-Physical Armor: " << mister.getClass()->PhysArmor << std::endl
    << "-Magical Armor: " << mister.getClass()->MagicArmor << std::endl
    << "-Level: " << mister.getCurrentLevel() << std::endl
    << "-Exp: " << mister.getCurrentExp() << "/" << mister.getExpForNextLevel() << std::endl
    << "Abilities: " << std::endl;
    for(auto& ability : mister.getClass()->Abilites) {
        std::cout << "-" << ability.name << std::endl;
    }

    std::cout << "Effects: " << std::endl;
    for(auto& e : mister.getEffects()) {
        std::cout << "-" << e.name << " (" << e.duration << ")" << std::endl;
    }

    std::cout << "Equipped Armors: " << std::endl;
    for(auto a = 0; a < (int)ARMORSLOT::NUM_SLOTS; a++) {
        if(mister.getEquippedArmorAt(a)) {
            std::cout << "-" << mister.getEquippedArmorAt(a)->name << std::endl;
        } else {
            std::cout << "-None" << std::endl;
        }
    }

    std::cout << "Equipped Weapons: " << std::endl;
    for(auto a = 0; a < 2; a++) {
        if(mister.getEquippedWeaponAt(a)) {
            std::cout << "-" << mister.getEquippedWeaponAt(a)->name << std::endl;
        } else {
            std:: cout << "-None" << std::endl;
        }
    }

    return 0;
}