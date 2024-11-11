#include "Config.h"


using json = nlohmann::json;

ConfigSettings Config;

static json ImVec4ToJson(const ImVec4& vec) {
    return json{
        {"x", vec.x},
        {"y", vec.y},
        {"z", vec.z},
        {"w", vec.w}
    };
}

static ImVec4 JsonToImVec4(const json& j) {
    return ImVec4(
        j["x"].get<float>(),
        j["y"].get<float>(),
        j["z"].get<float>(),
        j["w"].get<float>()
    );
}

static json BindToJson(const KeyBind& bind) {
     return json{ 
      {"key", bind.key}, 
      {"name", bind.name},
      {"BindMode",bind.keybindmode}
     };
}

static void JsonToBind(const json& j, KeyBind& bind) {
    bind.key= j["key"].get<int>(),
    bind.name = j["name"].get<std::string>(),
    bind.keybindmode = j["BindMode"].get<int>();
}


 void ConfigSettings::LoadConfig(const std::string& filename){

     const std::string path = "C:/LynchWare/";
     std::string finalpath = path + filename + ".json";

    std::ifstream inputFile(finalpath);
    if (!inputFile.is_open()) {
        return;
    }

    json j;
    inputFile >> j;
    inputFile.close();

    Config.aimbot.bAimbot = j["aimbot"]["enabled"].get<bool>();

   JsonToBind(j["aimbot"]["AimKey"], Config.aimbot.AimKey);
   JsonToBind(j["aimbot"]["AimKeyMinions"],Config.aimbot.AimKeyMinions);
   JsonToBind(j["aimbot"]["AimKeyXp"],Config.aimbot.AimKeyXp);

    Config.aimbot.fov = j["aimbot"]["fov"].get<float>();
    Config.aimbot.magicbullet = j["aimbot"]["magicbullet"].get<bool>();

    JsonToBind(j["aimbot"]["magicbulletkey"], Config.aimbot.magicbulletkey);

    Config.aimbot.MaxDistance = j["aimbot"]["maxdistance"].get<float>();
    Config.aimbot.silentaim = j["aimbot"]["silentaim"].get<bool>();
    Config.aimbot.targetSelectionMode = j["aimbot"]["targetselectionmode"].get<int>();
    Config.aimbot.MovementFix = j["aimbot"]["MovementFix"].get<bool>();

    Config.antiaim.AAtype = j["antiaim"]["aatype"].get<int>();
    Config.antiaim.bAntiAim = j["antiaim"]["bAntiAim"].get<bool>();
    Config.antiaim.lowerjitter = j["antiaim"]["lowerjitter"].get<float>();
    Config.antiaim.upperjitter = j["antiaim"]["upperjitter"].get<float>();

    Config.colors.aimbotTargetcol = JsonToImVec4(j["colors"]["aimbotTargetcol"]);
    Config.colors.boxespcol = JsonToImVec4(j["colors"]["boxespcol"]);
    Config.colors.distancecolesp = JsonToImVec4(j["colors"]["distancecolesp"]);
    Config.colors.drawfovcol = JsonToImVec4(j["colors"]["drawfovcol"]);
    Config.colors.drawmonsterscol = JsonToImVec4(j["colors"]["drawmonsterscol"]);
    Config.colors.drawxpcol = JsonToImVec4(j["colors"]["drawxpcol"]);
    Config.colors.healthtextcolesp = JsonToImVec4(j["colors"]["healthtextcolesp"]);
    Config.colors.namecoloresp = JsonToImVec4(j["colors"]["namecoloresp"]);
    Config.colors.skeletoncol = JsonToImVec4(j["colors"]["skeletoncol"]);
    Config.colors.tracerscol = JsonToImVec4(j["colors"]["tracerscol"]);
    Config.colors.ChamsCol = JsonToImVec4(j["colors"]["ChamsCol"]);
    Config.colors.LocalChamsCol = JsonToImVec4(j["colors"]["LocalChamsCol"]);
    
    Config.esp.bEsp = j["esp"]["bEsp"].get<bool>();
    Config.esp.boneEsp = j["esp"]["boneEsp"].get<bool>();
    Config.esp.boxEsp = j["esp"]["boxEsp"].get<bool>();
    Config.esp.DistanceEsp = j["esp"]["DistanceEsp"].get<bool>();
    Config.esp.DrawAimbotPrediction = j["esp"]["DrawAimbotPrediction"].get<bool>();
    Config.esp.DrawAimbotTarget = j["esp"]["DrawAimbotTarget"].get<bool>();
    Config.esp.ShowKeyBindList = j["esp"]["ShowKeyBindList"].get<bool>();
    Config.esp.DrawFov = j["esp"]["DrawFov"].get<bool>();
    Config.esp.DrawMinions = j["esp"]["DrawMinions"].get<bool>();
    Config.esp.DrawMonsters = j["esp"]["DrawMonsters"].get<bool>();
    Config.esp.DrawXp = j["esp"]["DrawXp"].get<bool>();
    Config.esp.HealthBar = j["esp"]["HealthBar"].get<bool>();
    Config.esp.HealthEsp = j["esp"]["HealthEsp"].get<bool>();
    Config.esp.HealthText = j["esp"]["HealthText"].get<bool>();
    Config.esp.NameEsp = j["esp"]["NameEsp"].get<bool>();
    Config.esp.Tracers = j["esp"]["Tracers"].get<bool>();
    Config.esp.Chams = j["esp"]["Chams"].get<bool>();
    Config.esp.LocalChams = j["esp"]["LocalChams"].get<bool>();
    Config.esp.ModelChams = j["esp"]["ModelChams"].get<bool>();

    Config.misc.bNorecoil = j["misc"]["bNorecoil"].get<bool>();
    Config.misc.fovmodifier = j["misc"]["fovmodifier"].get<float>();
    Config.misc.SpeedBoost = j["misc"]["SpeedBoost"].get<bool>();
    JsonToBind(j["misc"]["SpeedBoostKey"], Config.misc.SpeedBoostKey);

    Config.shiv.AutoAimDagger = j["shiv"]["AutoAimDagger"].get<bool>();
    Config.shiv.AutoAimDash = j["shiv"]["AutoAimDash"].get<bool>();
    Config.shiv.AutoExecute = j["shiv"]["AutoExecute"].get<bool>();

    Config.vindicta.AutoAimCrow = j["vindicta"]["AutoAimCrow"].get<bool>();
    Config.vindicta.AutoAimStake = j["vindicta"]["AutoAimStake"].get<bool>();
    Config.vindicta.AutoSnipe = j["vindicta"]["AutoSnipe"].get<bool>();
    Config.vindicta.AutoUltHealthPercent = j["vindicta"]["AutoUltHealthPercent"].get<float>();

    Config.bebop.AimHook = j["bebop"]["AimHook"].get<bool>();
    Config.bebop.AutoBomb = j["bebop"]["AutoBomb"].get<bool>();
    Config.bebop.AutoUppercut = j["bebop"]["AutoUppercut"].get<bool>();

    JsonToBind(j["menu"]["MenuKey"], Config.MenuKey);

}

 void ConfigSettings::SaveConfig(const std::string& filename) {

     json j;

     j["aimbot"]["enabled"] = Config.aimbot.bAimbot;
     j["aimbot"]["AimKey"] = BindToJson(Config.aimbot.AimKey);
     j["aimbot"]["AimKeyMinions"] = BindToJson(Config.aimbot.AimKeyMinions);
     j["aimbot"]["AimKeyXp"] = BindToJson(Config.aimbot.AimKeyXp);
     j["aimbot"]["aimminions"] = Config.aimbot.AimMinions;
     j["aimbot"]["aimxp"] = Config.aimbot.AimXp;
     j["aimbot"]["fov"] = Config.aimbot.fov;
     j["aimbot"]["magicbullet"] = Config.aimbot.magicbullet;
     j["aimbot"]["magicbulletkey"] = BindToJson(Config.aimbot.magicbulletkey);
     j["aimbot"]["maxdistance"] = Config.aimbot.MaxDistance;
     j["aimbot"]["silentaim"] = Config.aimbot.silentaim;
     j["aimbot"]["targetselectionmode"] = Config.aimbot.targetSelectionMode;
     j["aimbot"]["MovementFix"] = Config.aimbot.MovementFix;

     j["antiaim"]["aatype"] = Config.antiaim.AAtype;
     j["antiaim"]["bAntiAim"] = Config.antiaim.bAntiAim;
     j["antiaim"]["lowerjitter"] = Config.antiaim.lowerjitter;
     j["antiaim"]["upperjitter"] = Config.antiaim.upperjitter;

     j["colors"]["aimbotTargetcol"] = ImVec4ToJson(Config.colors.aimbotTargetcol);
     j["colors"]["boxespcol"] = ImVec4ToJson(Config.colors.boxespcol);
     j["colors"]["distancecolesp"] = ImVec4ToJson(Config.colors.distancecolesp);
     j["colors"]["drawfovcol"] = ImVec4ToJson(Config.colors.drawfovcol);
     j["colors"]["drawmonsterscol"] = ImVec4ToJson(Config.colors.drawmonsterscol);
     j["colors"]["drawxpcol"] = ImVec4ToJson(Config.colors.drawxpcol);
     j["colors"]["healthtextcolesp"] = ImVec4ToJson(Config.colors.healthtextcolesp);
     j["colors"]["namecoloresp"] = ImVec4ToJson(Config.colors.namecoloresp);
     j["colors"]["skeletoncol"] = ImVec4ToJson(Config.colors.skeletoncol);
     j["colors"]["tracerscol"] = ImVec4ToJson(Config.colors.tracerscol);
     j["colors"]["ChamsCol"] = ImVec4ToJson(Config.colors.ChamsCol);
     j["colors"]["LocalChamsCol"] = ImVec4ToJson(Config.colors.LocalChamsCol);

     j["esp"]["bEsp"] = Config.esp.bEsp;
     j["esp"]["boneEsp"] = Config.esp.boneEsp;
     j["esp"]["boxEsp"] = Config.esp.boxEsp;
     j["esp"]["DistanceEsp"] = Config.esp.DistanceEsp;
     j["esp"]["DrawAimbotPrediction"] = Config.esp.DrawAimbotPrediction;
     j["esp"]["ShowKeyBindList"] = Config.esp.ShowKeyBindList;
     j["esp"]["DrawAimbotTarget"] = Config.esp.DrawAimbotTarget;
     j["esp"]["DrawFov"] = Config.esp.DrawFov;
     j["esp"]["DrawMinions"] = Config.esp.DrawMinions;
     j["esp"]["DrawMonsters"] = Config.esp.DrawMonsters;
     j["esp"]["DrawXp"] = Config.esp.DrawXp;
     j["esp"]["HealthBar"] = Config.esp.HealthBar;
     j["esp"]["HealthEsp"] = Config.esp.HealthEsp;
     j["esp"]["HealthText"] = Config.esp.HealthText;
     j["esp"]["NameEsp"] = Config.esp.NameEsp;
     j["esp"]["Tracers"] = Config.esp.Tracers;
     j["esp"]["Chams"] = Config.esp.Chams;
     j["esp"]["LocalChams"] = Config.esp.LocalChams;
     j["esp"]["ModelChams"] = Config.esp.ModelChams;

     j["misc"]["bNorecoil"] = Config.misc.bNorecoil;
     j["misc"]["fovmodifier"] = Config.misc.fovmodifier;
     j["misc"]["SpeedBoost"] = Config.misc.SpeedBoost;
     j["misc"]["SpeedBoostKey"] = BindToJson(Config.misc.SpeedBoostKey);

     j["shiv"]["AutoAimDagger"] = Config.shiv.AutoAimDagger;
     j["shiv"]["AutoAimDash"] = Config.shiv.AutoAimDash;
     j["shiv"]["AutoExecute"] = Config.shiv.AutoExecute;

     j["vindicta"]["AutoAimCrow"] = Config.vindicta.AutoAimCrow;
     j["vindicta"]["AutoAimStake"] = Config.vindicta.AutoAimStake;
     j["vindicta"]["AutoSnipe"] = Config.vindicta.AutoSnipe;
     j["vindicta"]["AutoUltHealthPercent"] = Config.vindicta.AutoUltHealthPercent;

     j["bebop"]["AimHook"] = Config.bebop.AimHook;
     j["bebop"]["AutoBomb"] = Config.bebop.AutoBomb;
     j["bebop"]["AutoUppercut"] = Config.bebop.AutoUppercut;

     j["menu"]["MenuKey"] = BindToJson(Config.MenuKey);



     const std::string path = "C:/LynchWare/";

     if (!std::filesystem::exists("C:/LynchWare")) {
         std::cerr << "Directory C:/LynchWare does not exist." << std::endl;
         return;
     }

     std::string finalpath = path + filename + ".json";

     if (!std::filesystem::exists(finalpath)) {
         std::cout << "Doesnt Exist" << std::endl;
         std::ofstream file(finalpath);
     }

     std::ofstream outputFile(finalpath);
     if (!outputFile.is_open()) {
         return;
     }

     outputFile << j.dump(4);
     outputFile.close();

}
 
 void ConfigSettings::RefreshConfigs() {
     const std::string filepath = "C:/LynchWare/";

     // Create the directory if it doesn't exist
     if (!std::filesystem::exists(filepath)) {
         std::filesystem::create_directory(filepath);
     }

     // Clear existing configs
     configs.clear();
     selectedconfig = 0;

     // Iterate over the directory and find .json files
     for (const auto& file : std::filesystem::directory_iterator(filepath)) {
         std::string filename = file.path().filename().string();

         // Check if the file has a .json extension
         if (file.path().extension() == ".json") {
             // Remove the .json extension
             filename.erase(filename.find_last_of('.'));  // Alternatively, you can use filename.replace() as well

             if (!filename.empty()) {
                 configs.push_back(filename);
             }

             std::cout << "Found JSON file: " << filename << std::endl;  // Print the found filename
         }
     }
 }

void ConfigSettings::DeleteConfig(const std::string& filename) {

    const std::string filepath = "C:/LynchWare/" + filename + ".json";

    // Check if the directory exists, if not, create it
    if (!std::filesystem::exists("C:/LynchWare/")) {
        std::filesystem::create_directory("C:/LynchWare/");
    }

    // Check if the file exists
    if (std::filesystem::exists(filepath)) {
        try {
            // Delete the file
            std::filesystem::remove(filepath);
            std::cout << "Deleted config file: " << filename << std::endl;
        }
        catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Error deleting file: " << e.what() << std::endl;
        }
    }
    else {
        std::cout << "File not found: " << filename << std::endl;
    }

    RefreshConfigs();

}

