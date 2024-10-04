// Generated using https://github.com/a2x/cs2-dumper
// 2024-09-27 00:32:11.333937500 UTC

#pragma once

#include <cstddef>

namespace cs2_dumper {
    namespace schemas {
        // Module: client.dll
        // Class count: 1828
        // Enum count: 10
        namespace client_dll {
            // Alignment: 4
            // Member count: 2
            enum class StartupBehavior_t : uint32_t {
                UNIT_STARTUP_BEHAVIOR_DEFAULT = 0x0,
                UNIT_STARTUP_BEHAVIOR_TAUNT = 0x1
            };
            // Alignment: 4
            // Member count: 6
            enum class PortraitScale_t : uint32_t {
                PORTRAIT_SCALE_INVALID = 0xFFFFFFFFFFFFFFFF,
                PORTRAIT_SCALE_LOADOUT = 0x0,
                PORTRAIT_SCALE_ALTERNATE_LOADOUT = 0x1,
                PORTRAIT_SCALE_WORLD = 0x2,
                PORTRAIT_SCALE_SPECTATOR_LOADOUT = 0x3,
                PORTRAIT_SCALE_VERSUS_LOADOUT = 0x4
            };
            // Alignment: 4
            // Member count: 102
            enum class EGCCitadelClientMessages : uint32_t {
                k_EMsgClientToGCStartMatchmaking = 0x2332,
                k_EMsgClientToGCStartMatchmakingResponse = 0x2333,
                k_EMsgClientToGCStopMatchmaking = 0x2334,
                k_EMsgClientToGCStopMatchmakingResponse = 0x2335,
                k_EMsgGCToClientMatchmakingStopped = 0x2336,
                k_EMsgClientToGCLeaveLobby = 0x2337,
                k_EMsgClientToGCLeaveLobbyResponse = 0x2338,
                k_EMsgClientToGCIsInMatchmaking = 0x2339,
                k_EMsgClientToGCIsInMatchmakingResponse = 0x233A,
                k_EMsgGCToClientDevPlaytestStatus = 0x233B,
                k_EMsgClientToGCDevSetMMBias = 0x233F,
                k_EMsgClientToGCGetProfileCard = 0x2340,
                k_EMsgClientToGCGetProfileCardResponse = 0x2341,
                k_EMsgClientToGCUpdateRoster = 0x2342,
                k_EMsgClientToGCUpdateRosterResponse = 0x2343,
                k_EMsgGCToClientProfileCardUpdated = 0x2344,
                k_EMsgGCToClientDevAnnouncements = 0x2345,
                k_EMsgClientToGCModifyDevAnnouncements = 0x2346,
                k_EMsgClientToGCModifyDevAnnouncementsResponse = 0x2347,
                k_EMsgGCToClientSDRTicket = 0x238C,
                k_EMsgClientToGCReplacementSDRTicket = 0x238D,
                k_EMsgClientToGCReplacementSDRTicketResponse = 0x238E,
                k_EMsgClientToGCSetServerConVar = 0x2393,
                k_EMsgClientToGCSetServerConVarResponse = 0x2394,
                k_EMsgClientToGCSpectateLobby = 0x2395,
                k_EMsgClientToGCSpectateLobbyResponse = 0x2396,
                k_EMsgClientToGCPostMatchSurveyResponse = 0x2397,
                k_EMsgClientToGCGetMatchHistory = 0x2398,
                k_EMsgClientToGCGetMatchHistoryResponse = 0x2399,
                k_EMsgClientToGCSpectateUser = 0x239C,
                k_EMsgClientToGCSpectateUserResponse = 0x239D,
                k_EMsgClientToGCPartyCreate = 0x23A3,
                k_EMsgClientToGCPartyCreateResponse = 0x23A4,
                k_EMsgClientToGCPartyLeave = 0x23A5,
                k_EMsgClientToGCPartyLeaveResponse = 0x23A6,
                k_EMsgClientToGCPartyJoin = 0x23A7,
                k_EMsgClientToGCPartyJoinResponse = 0x23A8,
                k_EMsgClientToGCPartyAction = 0x23A9,
                k_EMsgClientToGCPartyActionResponse = 0x23AA,
                k_EMsgClientToGCPartyStartMatch = 0x23AB,
                k_EMsgClientToGCPartyStartMatchResponse = 0x23AC,
                k_EMsgClientToGCPartyInviteUser = 0x23AD,
                k_EMsgClientToGCPartyInviteUserResponse = 0x23AE,
                k_EMsgGCToClientPartyEvent = 0x23AF,
                k_EMsgGCToClientCanRejoinParty = 0x23B1,
                k_EMsgClientToGCPartyJoinViaCode = 0x23B2,
                k_EMsgClientToGCPartyJoinViaCodeResponse = 0x23B3,
                k_EMsgClientToGCPartyUpdateRoster = 0x23B4,
                k_EMsgClientToGCPartyUpdateRosterResponse = 0x23B5,
                k_EMsgClientToGCPartySetReadyState = 0x23B6,
                k_EMsgClientToGCPartySetReadyStateResponse = 0x23B7,
                k_EMsgClientToGCGetAccountStats = 0x23CC,
                k_EMsgClientToGCGetAccountStatsResponse = 0x23CD,
                k_EMsgGCToClientAccountStatsUpdated = 0x23CE,
                k_EMsgClientToGCGetMatchMetaData = 0x23CF,
                k_EMsgClientToGCGetMatchMetaDataResponse = 0x23D0,
                k_EMsgClientToGCDevAction = 0x23D4,
                k_EMsgClientToGCDevActionResponse = 0x23D5,
                k_EMsgClientToGCRecordClientEvents = 0x23D6,
                k_EMsgClientToGCRecordClientEventsResponse = 0x23D7,
                k_EMsgClientToGCSetNewPlayerProgress = 0x23D8,
                k_EMsgClientToGCSetNewPlayerProgressResponse = 0x23D9,
                k_EMsgClientToGCUpdateAccountSync = 0x23DA,
                k_EMsgClientToGCUpdateAccountSyncResponse = 0x23DB,
                k_EMsgClientToGCGetHeroChoice = 0x23DC,
                k_EMsgClientToGCGetHeroChoiceResponse = 0x23DD,
                k_EMsgClientToGCUnlockHero = 0x23DE,
                k_EMsgClientToGCUnlockHeroResponse = 0x23DF,
                k_EMsgClientToGCBookUnlock = 0x23E0,
                k_EMsgClientToGCBookUnlockResponse = 0x23E1,
                k_EMsgClientToGCGetBook = 0x23E2,
                k_EMsgClientToGCGetBookResponse = 0x23E3,
                k_EMsgGCToClientBookUpdated = 0x23E4,
                k_EMsgClientToGCSubmitPlaytestUser = 0x23E5,
                k_EMsgClientToGCSubmitPlaytestUserResponse = 0x23E6,
                k_EMsgClientToGCUpdateHeroBuild = 0x23E9,
                k_EMsgClientToGCUpdateHeroBuildResponse = 0x23EA,
                k_EMsgClientToGCFindHeroBuilds = 0x23EB,
                k_EMsgClientToGCFindHeroBuildsResponse = 0x23EC,
                k_EMsgClientToGCReportPlayerFromMatch = 0x23ED,
                k_EMsgClientToGCReportPlayerFromMatchResponse = 0x23EE,
                k_EMsgClientToGCGetAccountMatchReports = 0x23EF,
                k_EMsgClientToGCGetAccountMatchReportsResponse = 0x23F0,
                k_EMsgClientToGCDeleteHeroBuild = 0x23F1,
                k_EMsgClientToGCDeleteHeroBuildResponse = 0x23F2,
                k_EMsgClientToGCGetActiveMatches = 0x23F3,
                k_EMsgClientToGCGetActiveMatchesResponse = 0x23F4,
                k_EMsgClientToGCGetDiscordLink = 0x23F5,
                k_EMsgClientToGCGetDiscordLinkResponse = 0x23F6,
                k_EMsgClientToGCPartySetMode = 0x23F7,
                k_EMsgClientToGCPartySetModeResponse = 0x23F8,
                k_EMsgClientToGCGrantForumAccess = 0x23F9,
                k_EMsgClientToGCGrantForumAccessResponse = 0x23FA,
                k_EMsgClientToGCModeratorRequest = 0x23FB,
                k_EMsgClientToGCModeratorRequestResponse = 0x23FC,
                k_EMsgClientToGCGetFriendGameStatus = 0x23FD,
                k_EMsgClientToGCGetFriendGameStatusResponse = 0x23FE,
                k_EMsgClientToGCUpdateHeroBuildPreference = 0x23FF,
                k_EMsgClientToGCUpdateHeroBuildPreferenceResponse = 0x2400,
                k_EMsgClientToGCGetOldHeroBuildData = 0x2401,
                k_EMsgClientToGCGetOldHeroBuildDataResponse = 0x2402,
                k_EMsgClientToGCUpdateSpectatorStatus = 0x2403
            };
            // Alignment: 4
            // Member count: 7
            enum class ECitadelPingWheelMessageType_t : uint32_t {
                CITADEL_PING_WHEEL_PREGAME = 0x0,
                CITADEL_PING_WHEEL_INPROGRESS = 0x1,
                CITADEL_PING_WHEEL_DISABLED_WHILE_DEAD = 0x2,
                CITADEL_PING_WHEEL_POSTGAME = 0x3,
                CITADEL_PING_WHEEL_CONTEXTUAL = 0x4,
                CITADEL_PING_WHEEL_SUBNAV = 0x5,
                CITADEL_PING_WHEEL_COUNT = 0x6
            };
            // Alignment: 4
            // Member count: 3
            enum class ECitadelNewPlayerProgressFlag : uint32_t {
                k_eNewPlayerProgress_GettingStarted = 0x1,
                k_eNewPlayerProgress_HeroTraining = 0x2,
                k_eNewPlayerProgress_LaneTraining = 0x3
            };
            // Alignment: 4
            // Member count: 55
            enum class ECitadelClientAccountEvent : uint32_t {
                k_eLaunchedHeroTest = 0x1,
                k_eViewedProfile = 0x2,
                k_eViewedSocial = 0x3,
                k_eViewedHeroes = 0x4,
                k_eViewedHeroDetails = 0x5,
                k_eViewedPatchNotes = 0x6,
                k_eViewedEvents = 0x7,
                k_eViewedGettingStarted = 0x8,
                k_eViewedGuidePage = 0x9,
                k_eLaunchedClient = 0xA,
                k_eEditRoster = 0xB,
                k_eViewedWatch = 0xC,
                k_eCreatedParty = 0xD,
                k_eCreatedPartyWithInvite = 0xE,
                k_eViewedSelfProfile = 0xF,
                k_eJoinedPartyCode = 0x10,
                k_eSentPartyInvite = 0x11,
                k_eAcceptPartyInvite = 0x12,
                k_eRejectPartyInvite = 0x13,
                k_eSpectateUser = 0x14,
                k_eSpectateMatch = 0x15,
                k_eEnteredMatchMaking = 0x16,
                k_eLeftMatchMaking = 0x17,
                k_eEnteredPartyMatchMaking = 0x18,
                k_eLeftPartyMatchMaking = 0x19,
                k_eDownloadedReplay = 0x1A,
                k_eWatchedReplay = 0x1B,
                k_eViewMatchDetails = 0x1C,
                k_eMatchDetailsTab = 0x1D,
                k_eDeleteReplay = 0x1E,
                k_eBotMatch_Guided = 0x1F,
                k_eBotMatch_Easy = 0x20,
                k_eBotMatch_Hard = 0x21,
                k_eLiveUpdatedRoster = 0x22,
                k_eMatchMakingIdle_Displayed = 0x23,
                k_eMatchMakingIdle_Stopped = 0x24,
                k_eConnectReacquireTicket = 0x25,
                k_eConnectAttemptReconnect = 0x26,
                k_eDisconnectPresentedPrompt = 0x27,
                k_eDisconnectConfirmed = 0x28,
                k_eViewedSettings_Options = 0x29,
                k_eViewedSettings_Video = 0x2A,
                k_eViewedSettings_Audio = 0x2B,
                k_eViewedSettings_HotKey = 0x2C,
                k_eViewedSettings_ChatWheel = 0x2D,
                k_eViewedSettings_About = 0x2E,
                k_eOpenedSubmitFeedback = 0x2F,
                k_eTutorialSkip_Pressed = 0x30,
                k_eTutorialSkip_Confirmed = 0x31,
                k_eViewedGuidePage_5s = 0x32,
                k_eViewedGuidePage_15s = 0x33,
                k_eViewedGuidePage_30s = 0x34,
                k_eViewedGuidePage_60s = 0x35,
                k_eOpenedBookTest = 0x36,
                k_eSandboxViaHeroPage = 0x37
            };
            // Alignment: 4
            // Member count: 3
            enum class EProfileCardSlotType : uint32_t {
                k_EProfileCardSlotType_Empty = 0x0,
                k_EProfileCardSlotType_Stat = 0x1,
                k_EProfileCardSlotType_Hero = 0x2
            };
            // Alignment: 4
            // Member count: 5
            enum class PortraitDisplayMode_t : uint32_t {
                PORTRAIT_DISPLAY_MODE_INVALID = 0xFFFFFFFFFFFFFFFF,
                PORTRAIT_DISPLAY_MODE_LOADOUT = 0x0,
                PORTRAIT_DISPLAY_MODE_LOADOUT_DIRE = 0x1,
                PORTRAIT_DISPLAY_MODE_LOADOUT_SMALL = 0x2,
                PORTRAIT_DISPLAY_MODE_TREASURE_SMALL = 0x3
            };
            // Alignment: 4
            // Member count: 3
            enum class ECitadelAccountPermissionFlag : uint32_t {
                k_eAccountPermission_PrivateBot = 0x1,
                k_eAccountPermission_CoopBot = 0x2,
                k_eAccountPermission_Unranked = 0x3
            };
            // Alignment: 4
            // Member count: 7
            enum class P2P_Messages : uint32_t {
                p2p_TextMessage = 0x100,
                p2p_Voice = 0x101,
                p2p_Ping = 0x102,
                p2p_VRAvatarPosition = 0x103,
                p2p_WatchSynchronization = 0x104,
                p2p_FightingGame_GameData = 0x105,
                p2p_FightingGame_Connection = 0x106
            };
            // Parent: C_PhysicsProp
            // Field count: 1
            //
            // Metadata:
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // NetworkVarNames: m_eLootType (int)
            namespace C_ItemCrate {
                constexpr std::ptrdiff_t m_eLootType = 0xCE0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CModifier_Synth_Grasp_BulletShield {
                constexpr std::ptrdiff_t m_fBulletShield = 0xC0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_RadianceVData {
                constexpr std::ptrdiff_t m_RadianceFxParticle = 0x608; // 
                constexpr std::ptrdiff_t m_RadianceDamageParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_ClientsideDamageParticle = 0x7C8; // 
                constexpr std::ptrdiff_t m_strDamageRecievedSound = 0x8A8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_StatStealBase {
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_TimeWall_Aura {
            }
            // Parent: CCitadelModifier
            // Field count: 3
            namespace CCitadel_Modifier_Rutger_ForceField_PushOut {
                constexpr std::ptrdiff_t m_vStart = 0xC0; // 
                constexpr std::ptrdiff_t m_vDest = 0xCC; // 
                constexpr std::ptrdiff_t m_vCenter = 0xD8; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 5
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_SiphonBullets_VData {
                constexpr std::ptrdiff_t m_StealWatcherModifier = 0x638; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_HealModifier = 0x648; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_TracerParticle = 0x658; // 
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x738; // 
                constexpr std::ptrdiff_t m_ExplodeSound = 0x818; // 
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_ArmorUpgrade_SpellShieldVData {
                constexpr std::ptrdiff_t m_SpellShieldBuffModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_LingeringAssist {
            }
            // Parent: C_BaseToggle
            // Field count: 0
            namespace C_FuncMover {
            }
            // Parent: C_PointClientUIWorldPanel
            // Field count: 2
            namespace CInWorldItemPanel {
                constexpr std::ptrdiff_t m_hTrackedEntity = 0xA90; // 
                constexpr std::ptrdiff_t m_nTrackedEntity = 0xA94; // 
            }
            // Parent: C_BaseTrigger
            // Field count: 0
            namespace C_TriggerLerpObject {
            }
            // Parent: CitadelAbilityVData
            // Field count: 7
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbility_Rutger_ForceField_VData {
                constexpr std::ptrdiff_t m_AuraModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_VictimPushModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_SlowModifier = 0x1568; // 
                constexpr std::ptrdiff_t m_strDomeCreated = 0x1578; // 
                constexpr std::ptrdiff_t m_strChargeUpSound = 0x1588; // 
                constexpr std::ptrdiff_t m_strPushAndDamage = 0x1598; // 
                constexpr std::ptrdiff_t m_ChronoSphereChargeParticle = 0x15A8; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 9
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Tokamak_CrimsonCannonVData {
                constexpr std::ptrdiff_t m_LaserShot = 0x1548; // 
                constexpr std::ptrdiff_t m_ChargeParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_CasterOnlyTargetParticle = 0x1708; // 
                constexpr std::ptrdiff_t m_EnemyTargetedParticle = 0x17E8; // 
                constexpr std::ptrdiff_t m_strEnemyBeenTargetedSound = 0x18C8; // 
                constexpr std::ptrdiff_t m_strCasterTargetSelectedSound = 0x18D8; // 
                constexpr std::ptrdiff_t m_strFireSound = 0x18E8; // 
                constexpr std::ptrdiff_t m_strImpactSound = 0x18F8; // 
                constexpr std::ptrdiff_t m_strBlockedSound = 0x1908; // 
            }
            // Parent: CCitadel_Modifier_Base
            // Field count: 0
            namespace CCitadel_Modifier_MagicCarpet_Shields {
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_HollowPoint_Proc {
                constexpr std::ptrdiff_t m_nStacksPerBullet = 0xC0; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_TechOverflowProcWatcherVData {
                constexpr std::ptrdiff_t m_BuildUpModifier = 0x638; // 
                constexpr std::ptrdiff_t m_ProcModifier = 0x648; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BuildupSuccessEffect = 0x658; // 
            }
            // Parent: None
            // Field count: 6
            //
            // Metadata:
            // NetworkVarNames: scale (int16)
            // NetworkVarNames: origin (Vector)
            // NetworkVarNames: bClip3DSkyBoxNearToWorldFar (bool)
            // NetworkVarNames: flClip3DSkyBoxNearToWorldFarOffset (float32)
            // NetworkVarNames: fog (fogparams_t)
            // NetworkVarNames: m_nWorldGroupID (WorldGroupId_t)
            namespace sky3dparams_t {
                constexpr std::ptrdiff_t scale = 0x8; // 
                constexpr std::ptrdiff_t origin = 0xC; // 
                constexpr std::ptrdiff_t bClip3DSkyBoxNearToWorldFar = 0x18; // 
                constexpr std::ptrdiff_t flClip3DSkyBoxNearToWorldFarOffset = 0x1C; // 
                constexpr std::ptrdiff_t fog = 0x20; // 
                constexpr std::ptrdiff_t m_nWorldGroupID = 0x88; // 
            }
            // Parent: C_BaseTrigger
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_iszSoundName (string_t)
            namespace C_TriggerItemShop {
                constexpr std::ptrdiff_t m_iszSoundName = 0x838; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Kobun {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Disruptive_Charge {
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_CloakingDevice_Active_Ambush_VData {
                constexpr std::ptrdiff_t m_InvisRevealedParticle = 0x608; // 
                constexpr std::ptrdiff_t m_AmbushParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_strActivateAmbushSound = 0x7C8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Tech_Defender_Shredders_Debuff {
            }
            // Parent: C_SoundEventEntity
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_vecCornerPairsNetworked (SoundeventPathCornerPairNetworked_t)
            namespace C_SoundEventPathCornerEntity {
                constexpr std::ptrdiff_t m_vecCornerPairsNetworked = 0x618; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Mirage_SandPhantom_ProcReady_VData {
                constexpr std::ptrdiff_t m_ProcReadyParticle = 0x608; // 
                constexpr std::ptrdiff_t m_strProcReadySound = 0x6E8; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbility_Synth_Blitz_VData {
                constexpr std::ptrdiff_t m_BlitzModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_TechAmpModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_SlowParticle = 0x1568; // 
                constexpr std::ptrdiff_t m_strProcSound = 0x1648; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Dust_Storm {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_ImmobilizeTrap {
            }
            // Parent: CCitadel_Modifier_BaseBulletPreRollProcVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ChainLightningVData {
                constexpr std::ptrdiff_t m_TracerParticle = 0x738; // 
                constexpr std::ptrdiff_t m_ChainModifier = 0x818; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_MagicShield_SpiritBuff {
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityMedicHealVData {
                constexpr std::ptrdiff_t m_HealBeamParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_HealTargetParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_strHealCastSound = 0x1708; // 
            }
            // Parent: C_BaseEntity
            // Field count: 0
            namespace CCitadelSpectateNode {
            }
            // Parent: CBaseAnimGraph
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_flTurnSolidTime (GameTime_t)
            namespace C_Citadel_Ice_Dome_Blocker {
                constexpr std::ptrdiff_t m_flTurnSolidTime = 0xB50; // 
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ItemPickupAuraVData {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Thumper_BulletWatcherVData {
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x608; // 
                constexpr std::ptrdiff_t m_ExplodeSound = 0x6E8; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Protection_RacketVData {
                constexpr std::ptrdiff_t m_CastOtherParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_ArmorModifier = 0x1628; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CBodyComponent
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_skeletonInstance (CSkeletonInstance)
            namespace CBodyComponentSkeletonInstance {
                constexpr std::ptrdiff_t m_skeletonInstance = 0x50; // 
            }
            // Parent: C_CitadelProjectile
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_flWidth (float)
            // NetworkVarNames: m_tDieTime (GameTime_t)
            namespace C_Projectile_Stomp_Projectile {
                constexpr std::ptrdiff_t m_flWidth = 0x8B8; // 
                constexpr std::ptrdiff_t m_tDieTime = 0x8BC; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_hAbilityToTrigger (CHandle<CCitadelBaseAbility>)
            // NetworkVarNames: m_SwappedToTime (GameTime_t)
            namespace CCitadelBaseTriggerAbility {
                constexpr std::ptrdiff_t m_hAbilityToTrigger = 0xC78; // 
                constexpr std::ptrdiff_t m_SwappedToTime = 0xC7C; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Chomp_Grapple {
                constexpr std::ptrdiff_t m_hMoveToTarget = 0xC0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Bull_Leap_Boosting_Crash {
            }
            // Parent: CitadelAbilityVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityPowerSurgeVData {
                constexpr std::ptrdiff_t m_ChainParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_CastHitParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_BuffModifier = 0x1708; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ChainModifier = 0x1718; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_AfterburnWatcherVData {
                constexpr std::ptrdiff_t m_AfterburnDotModifier = 0x638; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BuildUpModifier = 0x648; // 
                constexpr std::ptrdiff_t m_ExplodeSound = 0x658; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Item_Bleeding_Bullets_DamageOverTime {
                constexpr std::ptrdiff_t m_flLastTickTime = 0xC0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_PowerSurge {
            }
            // Parent: CCitadelModifierVData
            // Field count: 5
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_PowerSurgeVData {
                constexpr std::ptrdiff_t m_TracerParticle = 0x608; // 
                constexpr std::ptrdiff_t m_WeaponFxParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_strWeaponShootSound = 0x7C8; // 
                constexpr std::ptrdiff_t m_strBulletWhizSound = 0x7D8; // 
                constexpr std::ptrdiff_t m_DebuffModifier = 0x7E8; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 19
            //
            // Metadata:
            // NetworkVarNames: m_flTimeStartZipping (GameTime_t)
            // NetworkVarNames: m_flTimeForKnockdownProtection (GameTime_t)
            // NetworkVarNames: m_flTimeStopZipping (GameTime_t)
            // NetworkVarNames: m_flCasterSpeed (float)
            // NetworkVarNames: m_vecInitialVel (CNetworkVelocityVector)
            // NetworkVarNames: m_vecAttachPoint (Vector)
            // NetworkVarNames: m_pPrevNode (EHANDLE)
            // NetworkVarNames: m_pNextNode (EHANDLE)
            // NetworkVarNames: m_flTimeEnterState (GameTime_t)
            // NetworkVarNames: m_flLatchTime (GameTime_t)
            // NetworkVarNames: m_flDamagedTime (GameTime_t)
            // NetworkVarNames: m_eAttachState (EAttachState_t)
            // NetworkVarNames: m_iAttachedZipLineLane (int)
            // NetworkVarNames: m_bDroppedFromZipline (bool)
            // NetworkVarNames: m_vAttachZipLineOffset (Vector)
            namespace CCitadel_Ability_ZipLine {
                constexpr std::ptrdiff_t m_flActivatePressTime = 0x1070; // 
                constexpr std::ptrdiff_t m_bThinking = 0x1074; // 
                constexpr std::ptrdiff_t m_bMoveCollidedPushUp = 0x1075; // 
                constexpr std::ptrdiff_t m_flTimeStartZipping = 0x1084; // 
                constexpr std::ptrdiff_t m_flTimeForKnockdownProtection = 0x1088; // 
                constexpr std::ptrdiff_t m_flTimeStopZipping = 0x108C; // 
                constexpr std::ptrdiff_t m_flCasterSpeed = 0x1090; // 
                constexpr std::ptrdiff_t m_vecInitialVel = 0x1094; // 
                constexpr std::ptrdiff_t m_vecAttachPoint = 0x10C8; // 
                constexpr std::ptrdiff_t m_pPrevNode = 0x10D4; // 
                constexpr std::ptrdiff_t m_pNextNode = 0x10D8; // 
                constexpr std::ptrdiff_t m_flTimeEnterState = 0x10DC; // 
                constexpr std::ptrdiff_t m_flLatchTime = 0x10E0; // 
                constexpr std::ptrdiff_t m_flDamagedTime = 0x10E4; // 
                constexpr std::ptrdiff_t m_eAttachState = 0x10E8; // 
                constexpr std::ptrdiff_t m_iAttachedZipLineLane = 0x10EC; // 
                constexpr std::ptrdiff_t m_bDroppedFromZipline = 0x10F0; // 
                constexpr std::ptrdiff_t m_hAttachZipLine = 0x10F1; // 
                constexpr std::ptrdiff_t m_vAttachZipLineOffset = 0x10F4; // 
            }
            // Parent: CCitadelBaseAbilityServerOnly
            // Field count: 0
            namespace CCitadel_Ability_SuperNeutralIncendiary {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_TeamRelativeParticleVData {
                constexpr std::ptrdiff_t m_ParentViewParticle = 0x608; // 
                constexpr std::ptrdiff_t m_OtherPlayerViewParticle = 0x6E8; // 
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_FrenzyAuraVData {
                constexpr std::ptrdiff_t m_KillModifier = 0x648; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_Silenced
            // Field count: 0
            namespace CCitadel_Modifier_Targeted_Silence_Debuff {
            }
            // Parent: C_ParticleSystem
            // Field count: 4
            //
            // Metadata:
            // MNetworkExcludeByName
            // MNetworkIncludeByName
            // NetworkVarNames: m_iFriendlyEffectIndex (HParticleSystemDefinitionStrong)
            // NetworkVarNames: m_iEnemyEffectIndex (HParticleSystemDefinitionStrong)
            namespace C_TeamRelativeParticleSystem {
                constexpr std::ptrdiff_t m_iszFriendlyEffectName = 0xDF8; // 
                constexpr std::ptrdiff_t m_iszEnemyEffectName = 0xE00; // 
                constexpr std::ptrdiff_t m_iFriendlyEffectIndex = 0xE08; // 
                constexpr std::ptrdiff_t m_iEnemyEffectIndex = 0xE10; // 
            }
            // Parent: CCitadel_Modifier_PowerUp
            // Field count: 0
            namespace CCitadel_Modifier_BreakablePropCooldownReduction {
            }
            // Parent: C_BaseEntity
            // Field count: 35
            //
            // Metadata:
            // NetworkVarNames: m_CRenderComponent (CRenderComponent::Storage_t)
            // NetworkVarNames: m_CHitboxComponent (CHitboxComponent::Storage_t)
            // NetworkVarNames: m_nRenderMode (RenderMode_t)
            // NetworkVarNames: m_nRenderFX (RenderFx_t)
            // NetworkVarNames: m_clrRender (Color)
            // NetworkVarNames: m_vecRenderAttributes (EntityRenderAttribute_t)
            // NetworkVarNames: m_bRenderToCubemaps (bool)
            // NetworkVarNames: m_bNoInterpolate (bool)
            // NetworkVarNames: m_Collision (CCollisionProperty)
            // NetworkVarNames: m_Glow (CGlowProperty)
            // NetworkVarNames: m_flGlowBackfaceMult (float)
            // NetworkVarNames: m_fadeMinDist (float32)
            // NetworkVarNames: m_fadeMaxDist (float32)
            // NetworkVarNames: m_flFadeScale (float32)
            // NetworkVarNames: m_flShadowStrength (float32)
            // NetworkVarNames: m_nObjectCulling (uint8)
            // NetworkVarNames: m_nAddDecal (int)
            // NetworkVarNames: m_vDecalPosition (Vector)
            // NetworkVarNames: m_vDecalForwardAxis (Vector)
            // NetworkVarNames: m_flDecalHealBloodRate (float)
            // NetworkVarNames: m_flDecalHealHeightRate (float)
            // NetworkVarNames: m_ConfigEntitiesToPropagateMaterialDecalsTo (CHandle<C_BaseModelEntity>)
            namespace C_BaseModelEntity {
                constexpr std::ptrdiff_t m_CRenderComponent = 0x558; // 
                constexpr std::ptrdiff_t m_CHitboxComponent = 0x560; // 
                constexpr std::ptrdiff_t m_bInitModelEffects = 0x5A8; // 
                constexpr std::ptrdiff_t m_bIsStaticProp = 0x5A9; // 
                constexpr std::ptrdiff_t m_nLastAddDecal = 0x5AC; // 
                constexpr std::ptrdiff_t m_nDecalsAdded = 0x5B0; // 
                constexpr std::ptrdiff_t m_iOldHealth = 0x5B4; // 
                constexpr std::ptrdiff_t m_nRenderMode = 0x5B8; // 
                constexpr std::ptrdiff_t m_nRenderFX = 0x5B9; // 
                constexpr std::ptrdiff_t m_szAddModifier = 0x5C0; // 
                constexpr std::ptrdiff_t m_bAllowFadeInView = 0x5C8; // 
                constexpr std::ptrdiff_t m_bHasCollision = 0x5E8; // 
                constexpr std::ptrdiff_t m_vSupport = 0x5EC; // 
                constexpr std::ptrdiff_t m_clrRender = 0x5F8; // 
                constexpr std::ptrdiff_t m_vecRenderAttributes = 0x600; // 
                constexpr std::ptrdiff_t m_bRenderToCubemaps = 0x668; // 
                constexpr std::ptrdiff_t m_bNoInterpolate = 0x669; // 
                constexpr std::ptrdiff_t m_Collision = 0x670; // 
                constexpr std::ptrdiff_t m_Glow = 0x720; // 
                constexpr std::ptrdiff_t m_flGlowBackfaceMult = 0x778; // 
                constexpr std::ptrdiff_t m_fadeMinDist = 0x77C; // 
                constexpr std::ptrdiff_t m_fadeMaxDist = 0x780; // 
                constexpr std::ptrdiff_t m_flFadeScale = 0x784; // 
                constexpr std::ptrdiff_t m_flShadowStrength = 0x788; // 
                constexpr std::ptrdiff_t m_nObjectCulling = 0x78C; // 
                constexpr std::ptrdiff_t m_nAddDecal = 0x790; // 
                constexpr std::ptrdiff_t m_vDecalPosition = 0x794; // 
                constexpr std::ptrdiff_t m_vDecalForwardAxis = 0x7A0; // 
                constexpr std::ptrdiff_t m_flDecalHealBloodRate = 0x7AC; // 
                constexpr std::ptrdiff_t m_flDecalHealHeightRate = 0x7B0; // 
                constexpr std::ptrdiff_t m_ConfigEntitiesToPropagateMaterialDecalsTo = 0x7B8; // 
                constexpr std::ptrdiff_t m_vecViewOffset = 0x7D0; // 
                constexpr std::ptrdiff_t m_pClientAlphaProperty = 0x800; // 
                constexpr std::ptrdiff_t m_ClientOverrideTint = 0x808; // 
                constexpr std::ptrdiff_t m_bUseClientOverrideTint = 0x80C; // 
            }
            // Parent: C_BaseEntity
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_eType (EMiniMapMarkerType_t)
            namespace C_MiniMapMarker {
                constexpr std::ptrdiff_t m_eType = 0x558; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierRapidFireChannelVData {
                constexpr std::ptrdiff_t m_flAirDrag = 0x608; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_BulletFlurryVData {
                constexpr std::ptrdiff_t m_ChannelParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_BulletFlurryModifier = 0x1628; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CGameModifier_SetModelScale {
                constexpr std::ptrdiff_t m_flOldModelScale = 0xC0; // 
            }
            // Parent: C_BaseClientUIEntity
            // Field count: 13
            //
            // Metadata:
            // NetworkVarNames: m_bIgnoreInput (bool)
            // NetworkVarNames: m_flWidth (float)
            // NetworkVarNames: m_flHeight (float)
            // NetworkVarNames: m_flDPI (float)
            // NetworkVarNames: m_flInteractDistance (float)
            // NetworkVarNames: m_flDepthOffset (float)
            // NetworkVarNames: m_unOwnerContext (uint32)
            // NetworkVarNames: m_unHorizontalAlign (uint32)
            // NetworkVarNames: m_unVerticalAlign (uint32)
            // NetworkVarNames: m_unOrientation (uint32)
            // NetworkVarNames: m_bAllowInteractionFromAllSceneWorlds (bool)
            // NetworkVarNames: m_vecCSSClasses (string_t)
            namespace C_PointClientUIHUD {
                constexpr std::ptrdiff_t m_bCheckCSSClasses = 0x868; // 
                constexpr std::ptrdiff_t m_bIgnoreInput = 0x9E8; // 
                constexpr std::ptrdiff_t m_flWidth = 0x9EC; // 
                constexpr std::ptrdiff_t m_flHeight = 0x9F0; // 
                constexpr std::ptrdiff_t m_flDPI = 0x9F4; // 
                constexpr std::ptrdiff_t m_flInteractDistance = 0x9F8; // 
                constexpr std::ptrdiff_t m_flDepthOffset = 0x9FC; // 
                constexpr std::ptrdiff_t m_unOwnerContext = 0xA00; // 
                constexpr std::ptrdiff_t m_unHorizontalAlign = 0xA04; // 
                constexpr std::ptrdiff_t m_unVerticalAlign = 0xA08; // 
                constexpr std::ptrdiff_t m_unOrientation = 0xA0C; // 
                constexpr std::ptrdiff_t m_bAllowInteractionFromAllSceneWorlds = 0xA10; // 
                constexpr std::ptrdiff_t m_vecCSSClasses = 0xA18; // C_NetworkUtlVectorBase<CUtlSymbolLarge>
            }
            // Parent: CCitadelModifierVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Synth_Blitz_TechAmp_VData {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_WreckingBall_Debuff {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Puddle {
            }
            // Parent: CitadelItemVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Item_TechDamagePulseVData {
                constexpr std::ptrdiff_t m_PulseParticle = 0x1590; // 
                constexpr std::ptrdiff_t m_TargetParticle = 0x1670; // 
                constexpr std::ptrdiff_t m_strPulseTickSound = 0x1750; // 
                constexpr std::ptrdiff_t m_iMaxTargets = 0x1760; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_BulletArmorReduction {
            }
            // Parent: C_BaseModelEntity
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_flLightScale (float32)
            // NetworkVarNames: m_Radius (float32)
            namespace C_SpotlightEnd {
                constexpr std::ptrdiff_t m_flLightScale = 0x830; // 
                constexpr std::ptrdiff_t m_Radius = 0x834; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Bolo_Leech {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 7
            namespace CCitadel_Ability_BulletFlurry {
                constexpr std::ptrdiff_t m_vecShootTargets = 0xD90; // 
                constexpr std::ptrdiff_t m_nNumPlayersKilled = 0xDA8; // 
                constexpr std::ptrdiff_t m_nShootIndex = 0xDAC; // 
                constexpr std::ptrdiff_t m_nShootIndexNPC = 0xDB0; // 
                constexpr std::ptrdiff_t m_nBurstShots = 0xDB4; // 
                constexpr std::ptrdiff_t m_flNextAttackTime = 0xDB8; // 
                constexpr std::ptrdiff_t m_nSatVolumeIndex = 0xDBC; // 
            }
            // Parent: C_AI_CitadelNPC
            // Field count: 6
            //
            // Metadata:
            // NetworkVarNames: m_iLane (int)
            // NetworkVarNames: m_flFadeOutStart (GameTime_t)
            // NetworkVarNames: m_flFadeOutEnd (GameTime_t)
            // NetworkVarNames: m_hTargetedEnemy (EHANDLE)
            // NetworkVarNames: m_nElectricBeamCasts (int)
            namespace C_NPC_Boss_Tier2 {
                constexpr std::ptrdiff_t m_iLane = 0x14A8; // 
                constexpr std::ptrdiff_t m_flFadeOutStart = 0x14AC; // 
                constexpr std::ptrdiff_t m_flFadeOutEnd = 0x14B0; // 
                constexpr std::ptrdiff_t m_hTargetedEnemy = 0x14B4; // 
                constexpr std::ptrdiff_t m_vecElectricBeamLookTarget = 0x14B8; // 
                constexpr std::ptrdiff_t m_nElectricBeamCasts = 0x14D0; // 
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelModifierAirLiftExplodeAuraVData {
                constexpr std::ptrdiff_t m_empWaveParticle = 0x648; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_BreakablePropExtraGoldPickup {
            }
            // Parent: C_BaseEntity
            // Field count: 26
            //
            // Metadata:
            // NetworkVarNames: m_FOV (float)
            // NetworkVarNames: m_Resolution (float)
            // NetworkVarNames: m_bFogEnable (bool)
            // NetworkVarNames: m_FogColor (Color)
            // NetworkVarNames: m_flFogStart (float)
            // NetworkVarNames: m_flFogEnd (float)
            // NetworkVarNames: m_flFogMaxDensity (float)
            // NetworkVarNames: m_bActive (bool)
            // NetworkVarNames: m_bUseScreenAspectRatio (bool)
            // NetworkVarNames: m_flAspectRatio (float)
            // NetworkVarNames: m_bNoSky (bool)
            // NetworkVarNames: m_fBrightness (float)
            // NetworkVarNames: m_flZFar (float)
            // NetworkVarNames: m_flZNear (float)
            // NetworkVarNames: m_bCanHLTVUse (bool)
            // NetworkVarNames: m_bAlignWithParent (bool)
            // NetworkVarNames: m_bDofEnabled (bool)
            // NetworkVarNames: m_flDofNearBlurry (float)
            // NetworkVarNames: m_flDofNearCrisp (float)
            // NetworkVarNames: m_flDofFarCrisp (float)
            // NetworkVarNames: m_flDofFarBlurry (float)
            // NetworkVarNames: m_flDofTiltToGround (float)
            namespace C_PointCamera {
                constexpr std::ptrdiff_t m_FOV = 0x558; // 
                constexpr std::ptrdiff_t m_Resolution = 0x55C; // 
                constexpr std::ptrdiff_t m_bFogEnable = 0x560; // 
                constexpr std::ptrdiff_t m_FogColor = 0x561; // 
                constexpr std::ptrdiff_t m_flFogStart = 0x568; // 
                constexpr std::ptrdiff_t m_flFogEnd = 0x56C; // 
                constexpr std::ptrdiff_t m_flFogMaxDensity = 0x570; // 
                constexpr std::ptrdiff_t m_bActive = 0x574; // 
                constexpr std::ptrdiff_t m_bUseScreenAspectRatio = 0x575; // 
                constexpr std::ptrdiff_t m_flAspectRatio = 0x578; // 
                constexpr std::ptrdiff_t m_bNoSky = 0x57C; // 
                constexpr std::ptrdiff_t m_fBrightness = 0x580; // 
                constexpr std::ptrdiff_t m_flZFar = 0x584; // 
                constexpr std::ptrdiff_t m_flZNear = 0x588; // 
                constexpr std::ptrdiff_t m_bCanHLTVUse = 0x58C; // 
                constexpr std::ptrdiff_t m_bAlignWithParent = 0x58D; // 
                constexpr std::ptrdiff_t m_bDofEnabled = 0x58E; // 
                constexpr std::ptrdiff_t m_flDofNearBlurry = 0x590; // 
                constexpr std::ptrdiff_t m_flDofNearCrisp = 0x594; // 
                constexpr std::ptrdiff_t m_flDofFarCrisp = 0x598; // 
                constexpr std::ptrdiff_t m_flDofFarBlurry = 0x59C; // 
                constexpr std::ptrdiff_t m_flDofTiltToGround = 0x5A0; // 
                constexpr std::ptrdiff_t m_TargetFOV = 0x5A4; // 
                constexpr std::ptrdiff_t m_DegreesPerSecond = 0x5A8; // 
                constexpr std::ptrdiff_t m_bIsOn = 0x5AC; // 
                constexpr std::ptrdiff_t m_pNext = 0x5B0; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Rutger_Pulse {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelModifierAerialAssaultWatcherVData {
                constexpr std::ptrdiff_t m_AssaultModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Item_ColdFrontVData {
                constexpr std::ptrdiff_t m_AOEModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_PreventHealing {
            }
            // Parent: C_LightEntity
            // Field count: 0
            namespace C_LightSpotEntity {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_WeaponUpgrade_HeadshotBooster {
            }
            // Parent: CCitadelModifierVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Cadence_Crescendo_PostAOE_VData {
            }
            // Parent: CCitadelModifierVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierRapidFireAirJuggleVData {
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityCrowdControlVData {
                constexpr std::ptrdiff_t m_CastParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1628; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelAbilityVData
            // Field count: 14
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_ProximityRitual_VData {
                constexpr std::ptrdiff_t m_PredatoryStatueModel = 0x1548; // 
                constexpr std::ptrdiff_t m_CatReappearParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_CatDisappearParticle = 0x1708; // 
                constexpr std::ptrdiff_t m_CatEyesParticle = 0x17E8; // 
                constexpr std::ptrdiff_t m_CatSummonParticle = 0x18C8; // 
                constexpr std::ptrdiff_t m_CatRecallParticle = 0x19A8; // 
                constexpr std::ptrdiff_t m_RecallLineParticle = 0x1A88; // 
                constexpr std::ptrdiff_t m_strRecallSound = 0x1B68; // 
                constexpr std::ptrdiff_t m_strKilledSound = 0x1B78; // 
                constexpr std::ptrdiff_t m_PredatoryStatueModifier = 0x1B88; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_flHeavyMeleeDmg = 0x1B98; // 
                constexpr std::ptrdiff_t m_flLightMeleeDmg = 0x1B9C; // 
                constexpr std::ptrdiff_t m_flAbilityDamageScale = 0x1BA0; // 
                constexpr std::ptrdiff_t m_flNPCDamageScale = 0x1BA4; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_bAirRaiding (bool)
            namespace CCitadel_Ability_PowerJump {
                constexpr std::ptrdiff_t m_nTargetingParticleIndex = 0xC7C; // 
                constexpr std::ptrdiff_t m_bAirRaiding = 0xC80; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierTier3BossLaserBeamVData {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 12
            //
            // Metadata:
            // NetworkVarNames: m_vTop (CNetworkOriginQuantizedVector)
            // NetworkVarNames: m_vBottom (CNetworkOriginQuantizedVector)
            // NetworkVarNames: m_bRequestStopClimbing (bool)
            // NetworkVarNames: m_bRequestJumpToRoof (bool)
            // NetworkVarNames: m_flLastMoveTime (GameTime_t)
            // NetworkVarNames: m_flMoveDownStartTime (GameTime_t)
            // NetworkVarNames: m_eClimbState (EClimbRopeState_t)
            namespace CCitadel_Ability_Climb_Rope {
                constexpr std::ptrdiff_t m_vTop = 0xC78; // 
                constexpr std::ptrdiff_t m_vBottom = 0xCA8; // 
                constexpr std::ptrdiff_t m_flActivatePressTime = 0xCD8; // 
                constexpr std::ptrdiff_t m_flDisconnectTime = 0xCDC; // 
                constexpr std::ptrdiff_t m_flClimbStartTime = 0xCE0; // 
                constexpr std::ptrdiff_t m_vLastPos = 0xCE4; // 
                constexpr std::ptrdiff_t m_bRequestStopClimbing = 0xCF8; // 
                constexpr std::ptrdiff_t m_bRequestJumpToRoof = 0xCF9; // 
                constexpr std::ptrdiff_t m_flLastMoveTime = 0xCFC; // 
                constexpr std::ptrdiff_t m_flMoveDownStartTime = 0xD00; // 
                constexpr std::ptrdiff_t m_eClimbState = 0xD04; // 
                constexpr std::ptrdiff_t m_ClimbCount = 0xD0C; // 
            }
            // Parent: C_Team
            // Field count: 5
            //
            // Metadata:
            // NetworkVarNames: m_hPayload (EHANDLE)
            // NetworkVarNames: m_nBossesAlive (int)
            // NetworkVarNames: m_nBossesMax (int)
            // NetworkVarNames: m_nFlexSlotsUnlocked (EFlexSlotTypes_t)
            // NetworkVarNames: m_vecFOWEntities (STeamFOWEntity)
            namespace C_CitadelTeam {
                constexpr std::ptrdiff_t m_hPayload = 0x610; // 
                constexpr std::ptrdiff_t m_nBossesAlive = 0x614; // 
                constexpr std::ptrdiff_t m_nBossesMax = 0x618; // 
                constexpr std::ptrdiff_t m_nFlexSlotsUnlocked = 0x61C; // 
                constexpr std::ptrdiff_t m_vecFOWEntities = 0x620; // C_UtlVectorEmbeddedNetworkVar<STeamFOWEntity>
            }
            // Parent: C_BaseEntity
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_EnvWindShared (CEnvWindShared)
            namespace C_EnvWind {
                constexpr std::ptrdiff_t m_EnvWindShared = 0x558; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 2
            namespace CCitadel_Ability_Mirage_Teleport {
                constexpr std::ptrdiff_t m_vTargetPosition = 0xC80; // 
                constexpr std::ptrdiff_t m_vTargetAngles = 0xC8C; // 
            }
            // Parent: CCitadelModifier
            // Field count: 5
            namespace CCitadel_Modifier_Warden_RiotProtocol {
                constexpr std::ptrdiff_t m_mapEntToTimeHit = 0xC0; // 
                constexpr std::ptrdiff_t m_nNumPlayersAffected = 0xE8; // 
                constexpr std::ptrdiff_t m_nNumPlayersKilled = 0xEC; // 
                constexpr std::ptrdiff_t m_playerAngles = 0xF0; // 
                constexpr std::ptrdiff_t m_ConeParticle = 0xFC; // 
            }
            // Parent: CAbilityMeleeVData
            // Field count: 14
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityHoldMelee_VData {
                constexpr std::ptrdiff_t m_mapAttacks = 0x1560; // 
                constexpr std::ptrdiff_t m_flNextAttackOnParry = 0x1588; // 
                constexpr std::ptrdiff_t m_flParryWindow = 0x158C; // 
                constexpr std::ptrdiff_t m_flParryStunTime = 0x1590; // 
                constexpr std::ptrdiff_t m_flParryCooldown = 0x1594; // 
                constexpr std::ptrdiff_t m_AirMeleeUpScale = 0x1598; // 
                constexpr std::ptrdiff_t m_HoldBeginEffect = 0x15A8; // 
                constexpr std::ptrdiff_t m_SuccessfulParryParticle = 0x1688; // 
                constexpr std::ptrdiff_t m_ParryActivateParticle = 0x1768; // 
                constexpr std::ptrdiff_t m_cameraSequenceHoldStart = 0x1848; // CitadelCameraOperationsSequence_t
                constexpr std::ptrdiff_t m_cameraSequenceHitImpact = 0x18D0; // CitadelCameraOperationsSequence_t
                constexpr std::ptrdiff_t m_strHoldBegin = 0x1958; // 
                constexpr std::ptrdiff_t m_strSuccessfulParrySound = 0x1968; // 
                constexpr std::ptrdiff_t m_ParryVictimModifier = 0x1978; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_Intrinsic_BaseVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ReinforcingCasingsVData {
                constexpr std::ptrdiff_t m_BuffModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_SlowImmunity {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_VisibleDuration {
            }
            // Parent: CAI_CitadelNPCVData
            // Field count: 34
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAI_NPC_TrooperVData {
                constexpr std::ptrdiff_t m_TrooperType = 0xF60; // 
                constexpr std::ptrdiff_t m_flTrooperDamageResistPct = 0xF64; // 
                constexpr std::ptrdiff_t m_flT1BossDamageResistPct = 0xF68; // 
                constexpr std::ptrdiff_t m_flT2BossDamageResistPct = 0xF6C; // 
                constexpr std::ptrdiff_t m_flBarrackGuardianDamageResistPct = 0xF70; // 
                constexpr std::ptrdiff_t m_flNearDeathDuration = 0xF74; // 
                constexpr std::ptrdiff_t m_flFlySpeed = 0xF78; // 
                constexpr std::ptrdiff_t m_flFlyHeight = 0xF7C; // 
                constexpr std::ptrdiff_t m_flMeleeDamage = 0xF80; // 
                constexpr std::ptrdiff_t m_flMeleeDuration = 0xF84; // 
                constexpr std::ptrdiff_t m_flMeleeChargeRange = 0xF88; // 
                constexpr std::ptrdiff_t m_flAttackT1BossMaxRange = 0xF8C; // 
                constexpr std::ptrdiff_t m_flAttackTrooperMaxRange = 0xF90; // 
                constexpr std::ptrdiff_t m_flShieldDamageResistPct = 0xF94; // 
                constexpr std::ptrdiff_t m_flHealthBarOffsetDucking = 0xF98; // 
                constexpr std::ptrdiff_t m_flTrooperDPS = 0xF9C; // 
                constexpr std::ptrdiff_t m_flPlayerDPS = 0xFA0; // 
                constexpr std::ptrdiff_t m_flT1BossDPS = 0xFA4; // 
                constexpr std::ptrdiff_t m_flT2BossDPS = 0xFA8; // 
                constexpr std::ptrdiff_t m_flT3BossDPS = 0xFAC; // 
                constexpr std::ptrdiff_t m_flBarrackBossDPS = 0xFB0; // 
                constexpr std::ptrdiff_t m_flGeneratorBossDPS = 0xFB4; // 
                constexpr std::ptrdiff_t m_BossAttackParticle = 0xFB8; // 
                constexpr std::ptrdiff_t m_LastHitParticle = 0x1098; // 
                constexpr std::ptrdiff_t m_TargetingLaserParticle = 0x1178; // 
                constexpr std::ptrdiff_t m_TargetingEyeFlashParticle = 0x1258; // 
                constexpr std::ptrdiff_t m_sZiplineContainerBreakFromDamageParticle = 0x1338; // 
                constexpr std::ptrdiff_t m_sZiplineContainerBreakFromLandingParticle = 0x1418; // 
                constexpr std::ptrdiff_t m_MedicHealActiveParticle = 0x14F8; // 
                constexpr std::ptrdiff_t m_sPlayerLastHitSound = 0x15D8; // 
                constexpr std::ptrdiff_t m_sCelebrationSound = 0x15E8; // 
                constexpr std::ptrdiff_t m_sZiplineContainerBreakSound = 0x15F8; // 
                constexpr std::ptrdiff_t m_NearDeathModifier = 0x1608; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_TrooperBossInvulnModifier = 0x1618; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_Mirage_SandPhantom_WhirlwindEvasion {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_LifeDrain {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_StaticChargeVData {
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x608; // 
                constexpr std::ptrdiff_t m_ZapParticle = 0x6E8; // 
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CItemRefresherVData {
                constexpr std::ptrdiff_t m_RefreshParticle = 0x1590; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Hero_Testing_Damage_AuraDebuff {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_PowerUp {
            }
            // Parent: C_BaseEntity
            // Field count: 0
            namespace C_GameRulesProxy {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_AirLift_LandBuff {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ChargingGun {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CItemSmokeBombPreCastModifierVData {
                constexpr std::ptrdiff_t m_SmokeAreaParticle = 0x608; // 
                constexpr std::ptrdiff_t m_CasterParticle = 0x6E8; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_TechBurst_Proc {
            }
            // Parent: C_BaseFlex
            // Field count: 6
            //
            // Metadata:
            // MNetworkExcludeByUserGroup
            // NetworkVarNames: m_hMyWearables (CHandle<C_EconWearable>)
            namespace C_BaseCombatCharacter {
                constexpr std::ptrdiff_t m_hMyWearables = 0xCE8; // 
                constexpr std::ptrdiff_t m_leftFootAttachment = 0xD00; // 
                constexpr std::ptrdiff_t m_rightFootAttachment = 0xD01; // 
                constexpr std::ptrdiff_t m_nWaterWakeMode = 0xD04; // 
                constexpr std::ptrdiff_t m_flWaterWorldZ = 0xD08; // 
                constexpr std::ptrdiff_t m_flWaterNextTraceTime = 0xD0C; // 
            }
            // Parent: CCitadelBaseTriggerAbility
            // Field count: 0
            namespace CCitadel_Ability_WreckingBallThrow {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_BreakablePropFireRatePickupVData {
                constexpr std::ptrdiff_t m_flFireRate = 0x608; // 
            }
            // Parent: C_SoundEventEntity
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_flRadius (float)
            namespace C_SoundEventSphereEntity {
                constexpr std::ptrdiff_t m_flRadius = 0x618; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Cadence_Crescendo {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_SpilledBloodThinker {
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Upgrade_StabilizingTripodVData {
                constexpr std::ptrdiff_t m_SelfDebuffModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CEntitySubclassVDataBase
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelBulletTimeWarpVData {
                constexpr std::ptrdiff_t m_TimeWallHitParticle = 0x28; // 
                constexpr std::ptrdiff_t m_TimeWallHitTimerParticle = 0x108; // 
            }
            // Parent: C_DynamicProp
            // Field count: 0
            namespace C_DynamicPropAlias_cable_dynamic {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierItemPickupAuraTargetVData {
                constexpr std::ptrdiff_t m_PickupTimer = 0x608; // 
                constexpr std::ptrdiff_t m_PickupTimerModifier = 0x610; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_PointEntity
            // Field count: 12
            //
            // Metadata:
            // NetworkVarNames: m_bIsPlayingBack (bool)
            // NetworkVarNames: m_bPaused (bool)
            // NetworkVarNames: m_bMultiplayer (bool)
            // NetworkVarNames: m_bAutogenerated (bool)
            // NetworkVarNames: m_flForceClientTime (float32)
            // NetworkVarNames: m_nSceneStringIndex (uint16)
            // NetworkVarNames: m_hActorList (CHandle<C_BaseFlex>)
            namespace C_SceneEntity {
                constexpr std::ptrdiff_t m_bIsPlayingBack = 0x560; // 
                constexpr std::ptrdiff_t m_bPaused = 0x561; // 
                constexpr std::ptrdiff_t m_bMultiplayer = 0x562; // 
                constexpr std::ptrdiff_t m_bAutogenerated = 0x563; // 
                constexpr std::ptrdiff_t m_flForceClientTime = 0x564; // 
                constexpr std::ptrdiff_t m_nSceneStringIndex = 0x568; // 
                constexpr std::ptrdiff_t m_bClientOnly = 0x56A; // 
                constexpr std::ptrdiff_t m_hOwner = 0x56C; // 
                constexpr std::ptrdiff_t m_hActorList = 0x570; // C_NetworkUtlVectorBase<CHandle<C_BaseFlex>>
                constexpr std::ptrdiff_t m_bWasPlaying = 0x588; // 
                constexpr std::ptrdiff_t m_QueuedEvents = 0x598; // CUtlVector<C_SceneEntity::QueuedEvents_t>
                constexpr std::ptrdiff_t m_flCurrentTime = 0x5B0; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 5
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Tokamak_DyingStarVData {
                constexpr std::ptrdiff_t m_ExplosionParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_FlameAuraParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_strInFlightAnimGraphParam = 0x1708; // 
                constexpr std::ptrdiff_t m_strExplodeSound = 0x1710; // 
                constexpr std::ptrdiff_t m_InFlightModifier = 0x1720; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Ability_PrimaryWeaponVData
            // Field count: 7
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_PrimaryWeapon_BebopVData {
                constexpr std::ptrdiff_t m_strWindupSound = 0x1590; // 
                constexpr std::ptrdiff_t m_strBeamStartSound = 0x15A0; // 
                constexpr std::ptrdiff_t m_strBeamLoopSound1 = 0x15B0; // 
                constexpr std::ptrdiff_t m_strBeamLoopSound2 = 0x15C0; // 
                constexpr std::ptrdiff_t m_strBeamStopSound = 0x15D0; // 
                constexpr std::ptrdiff_t m_szWeaponBeamParticle = 0x15E0; // 
                constexpr std::ptrdiff_t m_flWindupRepeatCycle = 0x16C0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 5
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ProjectMindVData {
                constexpr std::ptrdiff_t m_TeleportStartParticle = 0x608; // 
                constexpr std::ptrdiff_t m_TeleportEndParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_TeleportTrailParticle = 0x7C8; // 
                constexpr std::ptrdiff_t m_TeleportModelParticle = 0x8A8; // 
                constexpr std::ptrdiff_t m_ShieldModifier = 0x988; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CModifier_SiphonBullets {
            }
            // Parent: CCitadel_Item_BubbleVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Item_Stasis_BombVData {
                constexpr std::ptrdiff_t m_AuraModifier = 0x1690; // 
            }
            // Parent: CPlayerPawnComponent
            // Field count: 21
            //
            // Metadata:
            // NetworkVarNames: m_nPunchAngleJoltTick (GameTick_t)
            // NetworkVarNames: m_PlayerFog (fogplayerparams_t)
            // NetworkVarNames: m_hColorCorrectionCtrl (CHandle<CColorCorrection>)
            // NetworkVarNames: m_hViewEntity (CHandle<CBaseEntity>)
            // NetworkVarNames: m_hTonemapController (CHandle<CTonemapController2>)
            // NetworkVarNames: m_audio (audioparams_t)
            // NetworkVarNames: m_PostProcessingVolumes (CHandle<C_PostProcessingVolume>)

            namespace CPlayer_CameraServices {
                constexpr std::ptrdiff_t m_vecPunchAngle = 0x40; // 
                constexpr std::ptrdiff_t m_vecPunchAngleVel = 0x58; // 
                constexpr std::ptrdiff_t m_nPunchAngleJoltTickClientSide = 0x70; // 
                constexpr std::ptrdiff_t m_nPunchAngleJoltTick = 0x74; // 
                constexpr std::ptrdiff_t m_PlayerFog = 0x78; // 
                constexpr std::ptrdiff_t m_hColorCorrectionCtrl = 0xB8; // 
                constexpr std::ptrdiff_t m_hViewEntity = 0xBC; // 
                constexpr std::ptrdiff_t m_hTonemapController = 0xC0; // 
                constexpr std::ptrdiff_t m_audio = 0xC8; // 
                constexpr std::ptrdiff_t m_PostProcessingVolumes = 0x140; // 
                constexpr std::ptrdiff_t m_flOldPlayerZ = 0x158; // 
                constexpr std::ptrdiff_t m_flOldPlayerViewOffsetZ = 0x15C; // 
                constexpr std::ptrdiff_t m_CurrentFog = 0x160; // 
                constexpr std::ptrdiff_t m_hOldFogController = 0x1C8; // 
                constexpr std::ptrdiff_t m_bOverrideFogColor = 0x1CC; // 
                constexpr std::ptrdiff_t m_OverrideFogColor = 0x1D1; // 
                constexpr std::ptrdiff_t m_bOverrideFogStartEnd = 0x1E5; // 
                constexpr std::ptrdiff_t m_fOverrideFogStart = 0x1EC; // 
                constexpr std::ptrdiff_t m_fOverrideFogEnd = 0x200; // 
                constexpr std::ptrdiff_t m_hActivePostProcessingVolume = 0x214; // CHandle<C_PostProcessingVolume>
                constexpr std::ptrdiff_t m_angDemoViewAngles = 0x218; // 
            }
            // Parent: C_FuncBrush
            // Field count: 8
            //
            // Metadata:
            // NetworkVarNames: m_targetCamera (CUtlString)
            // NetworkVarNames: m_nResolutionEnum (int)
            // NetworkVarNames: m_bRenderShadows (bool)
            // NetworkVarNames: m_bUseUniqueColorTarget (bool)
            // NetworkVarNames: m_brushModelName (CUtlString)
            // NetworkVarNames: m_hTargetCamera (EHANDLE)
            // NetworkVarNames: m_bEnabled (bool)
            // NetworkVarNames: m_bDraw3DSkybox (bool)
            namespace C_FuncMonitor {
                constexpr std::ptrdiff_t m_targetCamera = 0x830; // 
                constexpr std::ptrdiff_t m_nResolutionEnum = 0x838; // 
                constexpr std::ptrdiff_t m_bRenderShadows = 0x83C; // 
                constexpr std::ptrdiff_t m_bUseUniqueColorTarget = 0x83D; // 
                constexpr std::ptrdiff_t m_brushModelName = 0x840; // 
                constexpr std::ptrdiff_t m_hTargetCamera = 0x848; // 
                constexpr std::ptrdiff_t m_bEnabled = 0x84C; // 
                constexpr std::ptrdiff_t m_bDraw3DSkybox = 0x84D; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_PowerGenerator {
            }
            // Parent: C_BaseTrigger
            // Field count: 0
            namespace C_TriggerMultiple {
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Chrono_PulseGrenade_VData {
                constexpr std::ptrdiff_t m_PulseAreaModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_strHitSound = 0x1558; // 
                constexpr std::ptrdiff_t m_strDebuffStatName = 0x1568; // 
            }
            // Parent: CCitadelBaseAbilityServerOnly
            // Field count: 0
            namespace CCitadel_Ability_Tier2Boss_Stomp {
            }
            // Parent: None
            // Field count: 1
            namespace C_RopeKeyframe__CPhysicsDelegate {
                constexpr std::ptrdiff_t m_pKeyframe = 0x8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 5
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierVData_BaseAura {
                constexpr std::ptrdiff_t m_eAuraShapeType = 0x608; // 
                constexpr std::ptrdiff_t m_flAuraRadius = 0x60C; // 
                constexpr std::ptrdiff_t m_flAuraEntityBoundsScale = 0x61C; // 
                constexpr std::ptrdiff_t m_nAmbientParticleRadiusControlPoint = 0x62C; // 
                constexpr std::ptrdiff_t m_modifierProvidedByAura = 0x630; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Synth_Pulse_Escape_VData {
                constexpr std::ptrdiff_t m_SatchelParticle = 0x608; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 30
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelAbilityTangoTetherVData {
                constexpr std::ptrdiff_t m_flJumpFallSpeedMax = 0x1548; // 
                constexpr std::ptrdiff_t m_flJumpAirDrag = 0x154C; // 
                constexpr std::ptrdiff_t m_flJumpAirSpeedMax = 0x1550; // 
                constexpr std::ptrdiff_t m_flJumpSpeed = 0x1554; // 
                constexpr std::ptrdiff_t m_flJumpPitch = 0x1558; // 
                constexpr std::ptrdiff_t m_flDashSpeed = 0x155C; // 
                constexpr std::ptrdiff_t m_flDashCloseEnoughToTarget = 0x1560; // 
                constexpr std::ptrdiff_t m_flDashLockOntoTargetDist = 0x1564; // 
                constexpr std::ptrdiff_t m_flVelocityTurnSpringStrength = 0x1568; // 
                constexpr std::ptrdiff_t m_flAngleToSpeedScale = 0x156C; // 
                constexpr std::ptrdiff_t m_flBackswingDuration = 0x157C; // 
                constexpr std::ptrdiff_t m_flAnimToStrikePointTime = 0x1580; // 
                constexpr std::ptrdiff_t m_flGrappleShotFloatTime = 0x1584; // 
                constexpr std::ptrdiff_t m_flGrappleShotDelayToFlyOnHit = 0x1588; // 
                constexpr std::ptrdiff_t m_flGrappleSpeed = 0x158C; // 
                constexpr std::ptrdiff_t m_TetherModifier = 0x1590; // 
                constexpr std::ptrdiff_t m_GrappleTargetModifier = 0x15A0; // 
                constexpr std::ptrdiff_t m_LeapParticle = 0x15B0; // 
                constexpr std::ptrdiff_t m_ImpactParticle = 0x1690; // 
                constexpr std::ptrdiff_t m_SlashParticle = 0x1770; // 
                constexpr std::ptrdiff_t m_BulletGrappleTracerParticle = 0x1850; // 
                constexpr std::ptrdiff_t m_EnemyGrappleParticle = 0x1930; // 
                constexpr std::ptrdiff_t m_strDamageTarget = 0x1A10; // 
                constexpr std::ptrdiff_t m_strStartDash = 0x1A20; // 
                constexpr std::ptrdiff_t m_strStartAttack = 0x1A30; // 
                constexpr std::ptrdiff_t m_strGrappleHitTarget = 0x1A40; // 
                constexpr std::ptrdiff_t m_strGrappleHitWorld = 0x1A50; // 
                constexpr std::ptrdiff_t m_strGrappleHitNothing = 0x1A60; // 
                constexpr std::ptrdiff_t m_cameraSequenceFlying = 0x1A70; // CitadelCameraOperationsSequence_t
                constexpr std::ptrdiff_t m_cameraSequenceAttacking = 0x1AF8; // CitadelCameraOperationsSequence_t
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_WeaponUpgrade_BansheeSlugs_VData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_TechDefenderShreddersProcVData {
                constexpr std::ptrdiff_t m_TechDebuffModifier = 0x638; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_DivinersKevlarBuff_VData {
                constexpr std::ptrdiff_t m_KevlarChannelParticle = 0x608; // 
            }
            // Parent: CCitadel_Modifier_BaseShield
            // Field count: 0
            namespace CCitadel_Modifier_RegeneratingTechShield {
            }
            // Parent: CitadelItemVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CItem_Infuser_VData {
                constexpr std::ptrdiff_t m_BuffModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_CastParticle = 0x15A0; // 
            }
            // Parent: CEntityComponent
            // Field count: 2
            namespace CBodyComponent {
                constexpr std::ptrdiff_t m_pSceneNode = 0x8; // 
                constexpr std::ptrdiff_t __m_pChainEntity = 0x20; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Upgrade_OverdriveClip {
            }
            // Parent: C_BaseModelEntity
            // Field count: 0
            //
            // Metadata:
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            namespace CCitadelModelEntity {
            }
            // Parent: C_SoundAreaEntityBase
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_flRadius (float)
            namespace C_SoundAreaEntitySphere {
                constexpr std::ptrdiff_t m_flRadius = 0x580; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_VoidSphere_Buff {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_StunnedVData {
                constexpr std::ptrdiff_t m_StunnedParticle = 0x608; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_EscalatingExposure {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ItemPickupAuraTarget {
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_BreakablePropClipSizePickup {
                constexpr std::ptrdiff_t nClipRemaining = 0xC0; // 
            }
            // Parent: C_BaseModelEntity
            // Field count: 8
            //
            // Metadata:
            // MNetworkIncludeByUserGroup
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // NetworkVarNames: m_nHorizontalSize (uint32)
            // NetworkVarNames: m_nVerticalSize (uint32)
            // NetworkVarNames: m_nMinDist (uint32)
            // NetworkVarNames: m_nMaxDist (uint32)
            // NetworkVarNames: m_nOuterMaxDist (uint32)
            // NetworkVarNames: m_flGlowProxySize (float32)
            // NetworkVarNames: m_flHDRColorScale (float32)
            namespace C_LightGlow {
                constexpr std::ptrdiff_t m_nHorizontalSize = 0x830; // 
                constexpr std::ptrdiff_t m_nVerticalSize = 0x834; // 
                constexpr std::ptrdiff_t m_nMinDist = 0x838; // 
                constexpr std::ptrdiff_t m_nMaxDist = 0x83C; // 
                constexpr std::ptrdiff_t m_nOuterMaxDist = 0x840; // 
                constexpr std::ptrdiff_t m_flGlowProxySize = 0x844; // 
                constexpr std::ptrdiff_t m_flHDRColorScale = 0x848; // 
                constexpr std::ptrdiff_t m_GlowOverlay = 0x850; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Wrecker_Salvage {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Charged_Bomb {
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_SlowingTech_ProcVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x638; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 1
            namespace CCitadel_Modifier_CharmedWraps {
                constexpr std::ptrdiff_t m_fLastPrimingLightAttackTime = 0x168; // 
            }
            // Parent: CitadelItemVData
            // Field count: 8
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CItemPhantomStrike_VData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_CasterModifier = 0x15A0; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_strExplodeSound = 0x15B0; // 
                constexpr std::ptrdiff_t m_CastParticle = 0x15C0; // 
                constexpr std::ptrdiff_t m_ImpactParticle = 0x16A0; // 
                constexpr std::ptrdiff_t m_BuffParticle = 0x1780; // 
                constexpr std::ptrdiff_t m_flTeleportDistance = 0x1860; // 
                constexpr std::ptrdiff_t m_flVelocityScale = 0x1864; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityMantleVData {
                constexpr std::ptrdiff_t m_vecMantleTypes = 0x1548; // 
            }
            // Parent: CCitadelModifier
            // Field count: 5
            namespace CCitadel_Modifier_Basic_RangedArmorBonus {
                constexpr std::ptrdiff_t m_flBulletResistancePctMin = 0xC0; // 
                constexpr std::ptrdiff_t m_flBulletResistancePctMax = 0xC4; // 
                constexpr std::ptrdiff_t m_flRangeMin = 0xC8; // 
                constexpr std::ptrdiff_t m_flRangeMax = 0xCC; // 
                constexpr std::ptrdiff_t m_flInvulnRange = 0xD0; // 
            }
            // Parent: None
            // Field count: 4
            //
            // Metadata:
            // NetworkVarNames: m_duration (float32)
            // NetworkVarNames: m_timestamp (GameTime_t)
            // NetworkVarNames: m_timescale (float32)
            // NetworkVarNames: m_nWorldGroupId (WorldGroupId_t)
            namespace CountdownTimer {
                constexpr std::ptrdiff_t m_duration = 0x8; // 
                constexpr std::ptrdiff_t m_timestamp = 0xC; // 
                constexpr std::ptrdiff_t m_timescale = 0x10; // 
                constexpr std::ptrdiff_t m_nWorldGroupId = 0x14; // 
            }
            // Parent: None
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_hOwner (CEntityHandle)
            // NetworkVarNames: m_name (CUtlStringToken)
            namespace CGameSceneNodeHandle {
                constexpr std::ptrdiff_t m_hOwner = 0x8; // 
                constexpr std::ptrdiff_t m_name = 0xC; // 
            }
            // Parent: C_BaseModelEntity
            // Field count: 0
            namespace C_ConditionalCollidable {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 3
            namespace CCitadel_Ability_Thumper_1 {
                constexpr std::ptrdiff_t m_vecAimPos = 0xC78; // 
                constexpr std::ptrdiff_t m_vecAimNormal = 0xC84; // 
                constexpr std::ptrdiff_t m_flPushForce = 0xC90; // 
            }
            // Parent: CCitadel_Modifier_Sleep
            // Field count: 0
            namespace CCitadel_Modifier_Cadence_Sleeping {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Running_Decoy {
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_PoisonBullet_ShotWatcher {
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_PuddleVData {
                constexpr std::ptrdiff_t m_PuddleModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_IceDome_AuraModifierBase
            // Field count: 0
            namespace CCitadel_Modifier_IceDomeFriendly {
            }
            // Parent: CCitadel_Modifier_Intrinsic_Base
            // Field count: 3
            namespace CCitadel_Modifier_NapalmProjectile {
                constexpr std::ptrdiff_t m_vInitialCastPosition = 0x1A0; // 
                constexpr std::ptrdiff_t m_flProjectileSpeed = 0x1AC; // 
                constexpr std::ptrdiff_t m_iParticleEffect = 0x1B0; // 
            }
            // Parent: CitadelItemVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Item_DPS_Aura_VData {
                constexpr std::ptrdiff_t m_AOECastParticle = 0x1590; // 
                constexpr std::ptrdiff_t m_ActiveModifier = 0x1670; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Upgrade_OverdriveClip {
                constexpr std::ptrdiff_t m_nBonusMaxClipSize = 0xC0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Berserker {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_BerserkerDamageStackVData {
                constexpr std::ptrdiff_t m_BuffStatusParticle = 0x608; // 
                constexpr std::ptrdiff_t m_BuffStatusParticleEnemy = 0x6E8; // 
            }
            // Parent: CBaseAnimGraph
            // Field count: 14
            namespace C_ClientRagdoll {
                constexpr std::ptrdiff_t m_bFadeOut = 0xB50; // 
                constexpr std::ptrdiff_t m_bImportant = 0xB51; // 
                constexpr std::ptrdiff_t m_flEffectTime = 0xB54; // 
                constexpr std::ptrdiff_t m_gibDespawnTime = 0xB58; // 
                constexpr std::ptrdiff_t m_iCurrentFriction = 0xB5C; // 
                constexpr std::ptrdiff_t m_iMinFriction = 0xB60; // 
                constexpr std::ptrdiff_t m_iMaxFriction = 0xB64; // 
                constexpr std::ptrdiff_t m_iFrictionAnimState = 0xB68; // 
                constexpr std::ptrdiff_t m_bReleaseRagdoll = 0xB6C; // 
                constexpr std::ptrdiff_t m_iEyeAttachment = 0xB6D; // 
                constexpr std::ptrdiff_t m_bFadingOut = 0xB6E; // 
                constexpr std::ptrdiff_t m_flScaleEnd = 0xB70; // 
                constexpr std::ptrdiff_t m_flScaleTimeStart = 0xB98; // 
                constexpr std::ptrdiff_t m_flScaleTimeEnd = 0xBC0; // 
            }
            // Parent: CCitadel_Item_TrackingProjectileApplyModifier
            // Field count: 0
            namespace CCitadel_Item_Containment {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_flDomeStartTime (GameTime_t)
            // NetworkVarNames: m_flDomeEndTime (GameTime_t)
            namespace CCitadel_Ability_IceDome {
                constexpr std::ptrdiff_t m_flDomeStartTime = 0xCB0; // 
                constexpr std::ptrdiff_t m_flDomeEndTime = 0xCB4; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_DetentionAmmo {
            }
            // Parent: CGameSceneNode
            // Field count: 8
            //
            // Metadata:
            // NetworkVarNames: m_modelState (CModelState)
            // NetworkVarNames: m_bIsAnimationEnabled (bool)
            // NetworkVarNames: m_bUseParentRenderBounds (bool)
            // NetworkVarNames: m_materialGroup (CUtlStringToken)
            // NetworkVarNames: m_nHitboxSet (uint8)
            namespace CSkeletonInstance {
                constexpr std::ptrdiff_t m_modelState = 0x170; // 
                constexpr std::ptrdiff_t m_bIsAnimationEnabled = 0x3F0; // 
                constexpr std::ptrdiff_t m_bUseParentRenderBounds = 0x3F1; // 
                constexpr std::ptrdiff_t m_bDisableSolidCollisionsForHierarchy = 0x3F2; // 
                constexpr std::ptrdiff_t m_bDirtyMotionType = 0x0; // 
                constexpr std::ptrdiff_t m_bIsGeneratingLatchedParentSpaceState = 0x0; // 
                constexpr std::ptrdiff_t m_materialGroup = 0x3F4; // 
                constexpr std::ptrdiff_t m_nHitboxSet = 0x3F8; // 
            }
            // Parent: CCitadelAnimatingModelEntity
            // Field count: 0
            namespace C_Citadel_RestorativeGooCube {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_WeaponUpgrade_Ricochet {
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityKobunVData {
                constexpr std::ptrdiff_t m_vSummonFollowOffset = 0x1548; // 
                constexpr std::ptrdiff_t m_CloneModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Tengu_UrnVData {
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_AuraModifier = 0x1628; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ExplodeSound = 0x1638; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_ThrowSandVData {
                constexpr std::ptrdiff_t m_SandDebuff = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_SilenceDebuff = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelItemVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Item_RescueBeamVData {
                constexpr std::ptrdiff_t m_DispelAndHealModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_PullModifier = 0x15A0; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelAnimatingModelEntity
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_flProgress (float)
            // NetworkVarNames: m_nNumPushers (int)
            namespace C_CitadelPayload {
                constexpr std::ptrdiff_t m_flProgress = 0xB58; // 
                constexpr std::ptrdiff_t m_nNumPushers = 0xB5C; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_RapidFire_AirJuggle {
            }
            // Parent: CitadelItemVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CItem_FleetfootBoots_VData {
                constexpr std::ptrdiff_t m_FleetfootBootsModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_FleetfootBootsBonusClipModifier = 0x15A0; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Item_TrackingProjectileApplyModifier
            // Field count: 0
            namespace CItem_WitheringWhip {
            }
            // Parent: CCitadel_Modifier_PowerUp
            // Field count: 1
            namespace CCitadel_Modifier_BreakablePropExtraStamina {
                constexpr std::ptrdiff_t m_bFilled = 0xC0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Haze_StackingDamage {
                constexpr std::ptrdiff_t m_nTotalProcs = 0x168; // 
            }
            // Parent: CitadelItemVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Item_ModDisruptorVData {
                constexpr std::ptrdiff_t m_DetonateParticle = 0x1590; // 
                constexpr std::ptrdiff_t m_DisruptModifier = 0x1670; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_flWaveSpeed = 0x1680; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_UnstoppableVData {
                constexpr std::ptrdiff_t m_ShieldParticle = 0x608; // 
                constexpr std::ptrdiff_t m_PlayerShieldParticle = 0x6E8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_PreMatchWait {
                constexpr std::ptrdiff_t m_vSpawnPoint = 0xC0; // 
            }
            // Parent: CBodyComponentSkeletonInstance
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_animationController (CBaseAnimGraphController)
            namespace CBodyComponentBaseAnimGraph {
                constexpr std::ptrdiff_t m_animationController = 0x4E0; // 
            }
            // Parent: CBodyComponent
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_sceneNode (CGameSceneNode)
            namespace CBodyComponentPoint {
                constexpr std::ptrdiff_t m_sceneNode = 0x50; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Ability_Shield {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_Savior {
            }
            // Parent: C_SoundEventEntity
            // Field count: 0
            namespace C_SoundEventEntityAlias_snd_event_point {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Intimidate {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 2
            namespace CCitadel_Ability_ProximityRitual {
                constexpr std::ptrdiff_t m_vLaunchPosition = 0xC78; // 
                constexpr std::ptrdiff_t m_qLaunchAngle = 0xC84; // 
            }
            // Parent: CCitadel_Modifier_ChainLightning
            // Field count: 0
            namespace CCitadel_Modifier_Galvanic_Storm {
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_GalvanicStormTechShieldVData {
                constexpr std::ptrdiff_t m_BuffModifier = 0x608; // 
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x618; // 
                constexpr std::ptrdiff_t m_flExplodeSpeed = 0x6F8; // 
            }
            // Parent: CEntitySubclassVDataBase
            // Field count: 26
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierVData {
                constexpr std::ptrdiff_t m_flDuration = 0x28; // 
                constexpr std::ptrdiff_t m_bKeepMaximumDurationOnRefresh = 0x38; // 
                constexpr std::ptrdiff_t m_strParticleEffect = 0x40; // 
                constexpr std::ptrdiff_t m_strParticleEffectConfig = 0x120; // 
                constexpr std::ptrdiff_t m_strParticleStatusEffect = 0x128; // 
                constexpr std::ptrdiff_t m_strParticleStatusEffectConfig = 0x208; // 
                constexpr std::ptrdiff_t m_strScreenParticleEffect = 0x210; // 
                constexpr std::ptrdiff_t m_strScreenParticleEffectConfig = 0x2F0; // 
                constexpr std::ptrdiff_t m_nStatusEffectPriority = 0x2F8; // 
                constexpr std::ptrdiff_t m_vecRenderAttributes = 0x300; // CUtlVector<ModifierRenderAttribute_t>
                constexpr std::ptrdiff_t m_sStartSound = 0x318; // 
                constexpr std::ptrdiff_t m_sAmbientLoopingSound = 0x328; // 
                constexpr std::ptrdiff_t m_nAmbientLoopingSoundRecipients = 0x338; // 
                constexpr std::ptrdiff_t m_sEndSound = 0x340; // 
                constexpr std::ptrdiff_t m_nEnabledStateMask = 0x350; // 
                constexpr std::ptrdiff_t m_nDisabledStateMask = 0x368; // 
                constexpr std::ptrdiff_t m_nAttributes = 0x380; // 
                constexpr std::ptrdiff_t m_vecScriptValues = 0x388; // CUtlVector<ModifierScriptValue_t>
                constexpr std::ptrdiff_t m_vecScriptEventHandlers = 0x3A0; // 
                constexpr std::ptrdiff_t m_nDisableGroupsMask = 0x3B8; // 
                constexpr std::ptrdiff_t m_bPrivateAccess = 0x3BC; // 
                constexpr std::ptrdiff_t m_bIsHidden = 0x3BD; // 
                constexpr std::ptrdiff_t m_eHiddenType = 0x3C0; // 
                constexpr std::ptrdiff_t m_sLocalizationName = 0x3C8; // 
                constexpr std::ptrdiff_t m_eDebuffType = 0x3D0; // 
                constexpr std::ptrdiff_t m_bAutomaticallyDecayStacks = 0x3D4; // 
            }
            // Parent: C_NPC_FlyingDrone
            // Field count: 0
            namespace C_NPC_SurveillanceDrone {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Yamato_InfinitySlash_BuffTimer {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_LockDown {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Uppercutted {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 5
            //
            // Metadata:
            // NetworkVarNames: m_angFacing (QAngle)
            namespace CCitadel_Ability_Bounce_Pad {
                constexpr std::ptrdiff_t m_vForward = 0xC78; // 
                constexpr std::ptrdiff_t m_bShouldDeploy = 0xC84; // 
                constexpr std::ptrdiff_t m_bAnglesSet = 0xC85; // 
                constexpr std::ptrdiff_t m_bCanCancel = 0xC86; // 
                constexpr std::ptrdiff_t m_angFacing = 0xDA0; // 
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CItemPowerShardVData {
                constexpr std::ptrdiff_t m_RefreshParticle = 0x1590; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Tier2Boss_RocketBarrageVData {
                constexpr std::ptrdiff_t m_ExplosionParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_ExplosionSound = 0x1628; // 
                constexpr std::ptrdiff_t m_RocketFireSound = 0x1638; // 
                constexpr std::ptrdiff_t m_AuraModifier = 0x1648; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_AI_CitadelNPC
            // Field count: 0
            namespace CNPC_YakuzaGangster {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            namespace CAbility_Mirage_SandPhantom {
                constexpr std::ptrdiff_t m_vecVictimModifiers = 0xC78; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ThrowSandDebuffVData {
                constexpr std::ptrdiff_t m_DebuffParticle = 0x608; // 
            }
            // Parent: C_BasePlayerPawn
            // Field count: 0
            namespace CCitadelPlayerPawnBase {
            }
            // Parent: CBaseAnimGraph
            // Field count: 0
            namespace C_ItemFlare {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_ArmorUpgrade_ReturnFire {
            }
            // Parent: CCitadel_Modifier_Stunned
            // Field count: 7
            namespace CCitadel_Modifier_Knockdown {
                constexpr std::ptrdiff_t m_angStunAngles = 0xC8; // 
                constexpr std::ptrdiff_t m_ePreferredKnockdownType = 0xD4; // 
                constexpr std::ptrdiff_t m_bForceTakePreferred = 0xD8; // 
                constexpr std::ptrdiff_t m_flGetUpAnimTime = 0xDC; // 
                constexpr std::ptrdiff_t m_bGetUpCamSeqStarted = 0xE0; // 
                constexpr std::ptrdiff_t m_bOnGroundDuration = 0xE1; // 
                constexpr std::ptrdiff_t m_satIndex = 0xE4; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityLashVData {
                constexpr std::ptrdiff_t m_LashParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_BuffModifier = 0x1628; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_strVictimCastSound = 0x1638; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ChargedBombVData {
                constexpr std::ptrdiff_t m_ChargeParticle = 0x608; // 
                constexpr std::ptrdiff_t m_strBeepSound = 0x6E8; // 
            }
            // Parent: C_CitadelProjectile
            // Field count: 3
            namespace C_Citadel_Projectile_Viscous_GooGrenade {
                constexpr std::ptrdiff_t m_nBounces = 0x8B8; // 
                constexpr std::ptrdiff_t m_tNextDetonateTime = 0x8BC; // 
                constexpr std::ptrdiff_t m_vecProjectileHitTargets = 0x8C0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Thumper_EnemyPulled {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_RapidFire {
            }
            // Parent: CEntitySubclassVDataBase
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_CatAnimatingVData {
                constexpr std::ptrdiff_t m_sModelName = 0x28; // 
                constexpr std::ptrdiff_t m_cGlowColor = 0x108; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_flSelfCastEndTime (GameTime_t)
            namespace CCitadel_Ability_RestorativeGoo {
                constexpr std::ptrdiff_t m_flSelfCastEndTime = 0xC78; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Idol_Return {
            }
            // Parent: C_RagdollProp
            // Field count: 7
            //
            // Metadata:
            // NetworkVarNames: m_boneIndexAttached (uint32)
            // NetworkVarNames: m_ragdollAttachedObjectIndex (uint32)
            // NetworkVarNames: m_attachmentPointBoneSpace (Vector)
            // NetworkVarNames: m_attachmentPointRagdollSpace (Vector)
            namespace C_RagdollPropAttached {
                constexpr std::ptrdiff_t m_boneIndexAttached = 0xBC8; // 
                constexpr std::ptrdiff_t m_ragdollAttachedObjectIndex = 0xBCC; // 
                constexpr std::ptrdiff_t m_attachmentPointBoneSpace = 0xBD0; // 
                constexpr std::ptrdiff_t m_attachmentPointRagdollSpace = 0xBDC; // 
                constexpr std::ptrdiff_t m_vecOffset = 0xBE8; // 
                constexpr std::ptrdiff_t m_parentTime = 0xBF4; // 
                constexpr std::ptrdiff_t m_bHasParent = 0xBF8; // 
            }
            // Parent: C_BaseToggle
            // Field count: 2
            //
            // Metadata:
            // MNetworkIncludeByName
            // NetworkVarNames: m_bDisabled (bool)
            // NetworkVarNames: m_bClientSidePredicted (bool)
            namespace C_BaseTrigger {
                constexpr std::ptrdiff_t m_bDisabled = 0x830; // 
                constexpr std::ptrdiff_t m_bClientSidePredicted = 0x831; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityHighAlertVData {
                constexpr std::ptrdiff_t m_BuffModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_ZiplineBoost {
                constexpr std::ptrdiff_t m_bIsBoosting = 0xC0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_BreakablePropSpeedPickupVData {
                constexpr std::ptrdiff_t m_flSpeedBoost = 0x608; // 
                constexpr std::ptrdiff_t m_flSprintBoost = 0x60C; // 
            }
            // Parent: None
            // Field count: 3
            namespace C_EconEntity__AttachedParticleInfo_t {
                constexpr std::ptrdiff_t m_nAttachedParticleIndex = 0x0; // 
                constexpr std::ptrdiff_t m_customType = 0x4; // 
                constexpr std::ptrdiff_t m_bShouldDestroyImmediately = 0x8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_BoloVData {
                constexpr std::ptrdiff_t m_TrapModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ReverseLeechModifier = 0x618; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 6
            //
            // Metadata:
            // NetworkVarNames: m_bWantsSlow (bool)
            // NetworkVarNames: m_flLatchedTimeScaleFracChangeTime (GameTime_t)
            // NetworkVarNames: m_flLatchedTimeScaleFrac (float)
            // NetworkVarNames: m_flSpeedBoostEndTime (GameTime_t)
            // NetworkVarNames: m_flShotTimeScaleEndTime (GameTime_t)
            namespace CCitadel_Ability_Chrono_KineticCarbine {
                constexpr std::ptrdiff_t m_bWantsSlow = 0xC78; // 
                constexpr std::ptrdiff_t m_flLatchedTimeScaleFracChangeTime = 0xC7C; // 
                constexpr std::ptrdiff_t m_flLatchedTimeScaleFrac = 0xC80; // 
                constexpr std::ptrdiff_t m_flSpeedBoostEndTime = 0xC84; // 
                constexpr std::ptrdiff_t m_flShotTimeScaleEndTime = 0xC88; // 
                constexpr std::ptrdiff_t m_flStoredPowerPct = 0xC90; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_DeathTaxTechAmp {
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Item_BaseProjectileAOEModifierVData {
                constexpr std::ptrdiff_t m_AOEModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_ColossusActive {
                constexpr std::ptrdiff_t m_flOriginalModelScale = 0xC0; // 
            }
            // Parent: CCitadel_Item
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_iCurrentResistValue (int)
            namespace CCitadel_ArmorUpgrade_AblativeCoat {
                constexpr std::ptrdiff_t m_iCurrentResistValue = 0xC90; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_PermanentPickupVData {
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbility_Mirage_SandPhantom_VData {
                constexpr std::ptrdiff_t m_WhirlwindEvasionModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_SandPhantomModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Cadence_GrandFinale {
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_LockDown_Debuff {
                constexpr std::ptrdiff_t m_vEscapeTarget = 0x1D8; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 5
            //
            // Metadata:
            // NetworkVarNames: m_bAirCast (bool)
            // NetworkVarNames: m_vBeamAimPos (Vector)
            namespace CCitadel_Ability_Bebop_LaserBeam {
                constexpr std::ptrdiff_t m_bZoomed = 0xDC8; // 
                constexpr std::ptrdiff_t m_bAirCast = 0xDC9; // 
                constexpr std::ptrdiff_t m_vBeamAimPos = 0xDCC; // 
                constexpr std::ptrdiff_t m_angBeamAngles = 0xDD8; // 
                constexpr std::ptrdiff_t m_bNeedsBeamReset = 0xDF0; // 
            }
            // Parent: CCitadel_Modifier_Base_Buildup
            // Field count: 1
            namespace CCitadel_Modifier_IceBeam_Stacking_Slow {
                constexpr std::ptrdiff_t m_flCurrBuildup = 0x220; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Shield {
                constexpr std::ptrdiff_t m_hShieldEntity = 0xC0; // 
            }
            // Parent: CitadelItemVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_WeaponUpgrade_BurstFireVData {
                constexpr std::ptrdiff_t m_ActivationSound = 0x1590; // 
                constexpr std::ptrdiff_t m_BuffModifier = 0x15A0; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Basic_HealthRegen {
                constexpr std::ptrdiff_t m_flHealthRegen = 0xC0; // 
            }
            // Parent: None
            // Field count: 21
            //
            // Metadata:
            // NetworkVarNames: m_vOrigin (Vector)
            // NetworkVarNames: m_vStart (Vector)
            // NetworkVarNames: m_vNormal (Vector)
            // NetworkVarNames: m_vAngles (QAngle)
            // NetworkVarNames: m_hEntity (CEntityHandle)
            // NetworkVarNames: m_hOtherEntity (CEntityHandle)
            // NetworkVarNames: m_flScale (float32)
            // NetworkVarNames: m_flMagnitude (float32)
            // NetworkVarNames: m_flRadius (float32)
            // NetworkVarNames: m_nSurfaceProp (CUtlStringToken)
            // NetworkVarNames: m_nEffectIndex (HParticleSystemDefinition)
            // NetworkVarNames: m_nDamageType (uint32)
            // NetworkVarNames: m_nPenetrate (uint8)
            // NetworkVarNames: m_nMaterial (uint16)
            // NetworkVarNames: m_nHitBox (uint16)
            // NetworkVarNames: m_nColor (uint8)
            // NetworkVarNames: m_fFlags (uint8)
            // NetworkVarNames: m_nAttachmentIndex (AttachmentHandle_t)
            // NetworkVarNames: m_nAttachmentName (CUtlStringToken)
            // NetworkVarNames: m_iEffectName (uint16)
            // NetworkVarNames: m_nExplosionType (uint8)
            namespace CEffectData {
                constexpr std::ptrdiff_t m_vOrigin = 0x8; // 
                constexpr std::ptrdiff_t m_vStart = 0x14; // 
                constexpr std::ptrdiff_t m_vNormal = 0x20; // 
                constexpr std::ptrdiff_t m_vAngles = 0x2C; // 
                constexpr std::ptrdiff_t m_hEntity = 0x38; // 
                constexpr std::ptrdiff_t m_hOtherEntity = 0x3C; // 
                constexpr std::ptrdiff_t m_flScale = 0x40; // 
                constexpr std::ptrdiff_t m_flMagnitude = 0x44; // 
                constexpr std::ptrdiff_t m_flRadius = 0x48; // 
                constexpr std::ptrdiff_t m_nSurfaceProp = 0x4C; // 
                constexpr std::ptrdiff_t m_nEffectIndex = 0x50; // 
                constexpr std::ptrdiff_t m_nDamageType = 0x58; // 
                constexpr std::ptrdiff_t m_nPenetrate = 0x5C; // 
                constexpr std::ptrdiff_t m_nMaterial = 0x5E; // 
                constexpr std::ptrdiff_t m_nHitBox = 0x60; // 
                constexpr std::ptrdiff_t m_nColor = 0x62; // 
                constexpr std::ptrdiff_t m_fFlags = 0x63; // 
                constexpr std::ptrdiff_t m_nAttachmentIndex = 0x64; // 
                constexpr std::ptrdiff_t m_nAttachmentName = 0x68; // 
                constexpr std::ptrdiff_t m_iEffectName = 0x6C; // 
                constexpr std::ptrdiff_t m_nExplosionType = 0x6E; // 
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierSleepBombAuraVData {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Slork_Ambush {
            }
            // Parent: CCitadel_Modifier_Burning
            // Field count: 0
            namespace CCitadel_Modifier_Tokamak_HeatSinks_DOT {
            }
            // Parent: CitadelAbilityVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilitySummonGangsterVData {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_MagicCarpet_SummonVData {
                constexpr std::ptrdiff_t m_SummonParticle = 0x608; // 
            }
            // Parent: CCitadelBaseAbilityServerOnly
            // Field count: 0
            namespace CCitadel_Ability_SuperNeutralShield {
            }
            // Parent: CCitadelPlayerPawnBase
            // Field count: 0
            //
            // Metadata:
            // MNetworkIncludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByUserGroup
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkVarTypeOverride
            // MNetworkIncludeByName
            // MNetworkVarTypeOverride
            // MNetworkIncludeByName
            // MNetworkVarTypeOverride
            // MNetworkIncludeByName
            namespace C_CitadelObserverPawn {
            }
            // Parent: CitadelAbilityVData
            // Field count: 25
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_ZipLine_VData {
                constexpr std::ptrdiff_t m_flMinButtonHoldTimeToActivate = 0x1548; // 
                constexpr std::ptrdiff_t m_flCrouchDropSpeedFraction = 0x154C; // 
                constexpr std::ptrdiff_t m_flCrouchDropAirDragSuppressDuration = 0x1550; // 
                constexpr std::ptrdiff_t m_flDetachDisallowedTime = 0x1554; // 
                constexpr std::ptrdiff_t m_flCameraWobbleIntensity = 0x1558; // 
                constexpr std::ptrdiff_t m_DOFWhileZiplining = 0x155C; // 
                constexpr std::ptrdiff_t m_ZipLinePreviewParticle = 0x1570; // 
                constexpr std::ptrdiff_t m_ZipLineSpeedParticle = 0x1650; // 
                constexpr std::ptrdiff_t m_ZipLineTetherParticle = 0x1730; // 
                constexpr std::ptrdiff_t m_ZipLineTetherAttachParticle = 0x1810; // 
                constexpr std::ptrdiff_t m_ZipLineEnemyKnockdownProtectionParticle = 0x18F0; // 
                constexpr std::ptrdiff_t m_ZipLineSelfKnockdownProtectionParticle = 0x19D0; // 
                constexpr std::ptrdiff_t m_ZipLineKnockdownProtectionStatusParticle = 0x1AB0; // 
                constexpr std::ptrdiff_t m_strZipLineSummonSound = 0x1B90; // 
                constexpr std::ptrdiff_t m_strZipLineLatchedSound = 0x1BA0; // 
                constexpr std::ptrdiff_t m_strZipLineStartSound = 0x1BB0; // 
                constexpr std::ptrdiff_t m_RidingZipLineModifier = 0x1BC0; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_KnockedOffSlowModifier = 0x1BD0; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ZipLineIntroModifier = 0x1BE0; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ZipLineKnockdownImmuneModifier = 0x1BF0; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ZipLineSlowModifier = 0x1C00; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_cameraSequenceAwaitingTether = 0x1C10; // CitadelCameraOperationsSequence_t
                constexpr std::ptrdiff_t m_cameraSequenceLatched = 0x1C98; // CitadelCameraOperationsSequence_t
                constexpr std::ptrdiff_t m_cameraSequenceAttached = 0x1D20; // CitadelCameraOperationsSequence_t
                constexpr std::ptrdiff_t m_cameraSequenceClear = 0x1DA8; // CitadelCameraOperationsSequence_t
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_ArmorUpgrade_Colossus_VData {
                constexpr std::ptrdiff_t m_BuffModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Out_Of_Combat_Health_Regen {
                constexpr std::ptrdiff_t m_LastDamageTaken = 0xC0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierGlitchVData {
                constexpr std::ptrdiff_t m_DebuffParticle = 0x608; // 
            }
            // Parent: C_CitadelProjectile
            // Field count: 0
            namespace CItemExplosiveBarrel {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Stomp {
            }
            // Parent: CCitadelModifierVData
            // Field count: 6
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_FissureWallVData {
                constexpr std::ptrdiff_t m_DebrisParticle = 0x608; // 
                constexpr std::ptrdiff_t m_SpikeParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_WallSpawnSound = 0x7C8; // 
                constexpr std::ptrdiff_t m_DebuffModifier = 0x7D8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_EnemyVisionModifier = 0x7E8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_SlowModifier = 0x7F8; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 2
            namespace CCitadel_Modifier_Stunned {
                constexpr std::ptrdiff_t m_bEnabled = 0xC0; // 
                constexpr std::ptrdiff_t m_bWasEnabled = 0xC1; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_EscalatingExposureProcWatcherVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x638; // 
            }
            // Parent: CCitadelBaseAbilityServerOnly
            // Field count: 0
            namespace CCitadel_Ability_Tier2Boss_LaserBeam {
            }
            // Parent: C_NPC_Trooper
            // Field count: 0
            namespace C_NPC_SuperTrooper {
            }
            // Parent: CCitadel_Item
            // Field count: 1
            namespace CCitadel_Item_PowerShard {
                constexpr std::ptrdiff_t m_hLastSignatureToActivate = 0xC90; // 
            }
            // Parent: C_BaseToggle
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_glowEntity (CHandle<C_BaseModelEntity>)
            // NetworkVarNames: m_usable (bool)
            // NetworkVarNames: m_szDisplayText (string_t)
            namespace C_BaseButton {
                constexpr std::ptrdiff_t m_glowEntity = 0x830; // 
                constexpr std::ptrdiff_t m_usable = 0x834; // 
                constexpr std::ptrdiff_t m_szDisplayText = 0x838; // 
            }
            // Parent: CCitadel_Modifier_StatStealBase
            // Field count: 0
            namespace CCitadel_Modifier_Mirage_FireScarabs_Watcher {
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CModifier_Synth_Pulse_BulletShield {
                constexpr std::ptrdiff_t m_fBulletShield = 0xC0; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_bAirCast (bool)
            namespace CCitadel_Ability_Tokamak_CrimsonCannon {
                constexpr std::ptrdiff_t m_bAirCast = 0xC78; // 
                constexpr std::ptrdiff_t m_bIsZoomed = 0xE40; // 
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_Cadence_GrandFinaleAOE {
            }
            // Parent: C_CitadelProjectile
            // Field count: 0
            namespace C_Citadel_Projectile_Wrecker_Teleport {
            }
            // Parent: C_PointEntity
            // Field count: 0
            namespace CInfoParticleTarget {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_flCastStartTime (GameTime_t)
            namespace CCitadel_Ability_Mirage_FireBeetles {
                constexpr std::ptrdiff_t m_vLaunchPosition = 0xC78; // 
                constexpr std::ptrdiff_t m_qLaunchAngle = 0xC84; // 
                constexpr std::ptrdiff_t m_flCastStartTime = 0xC90; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_LightningBall {
                constexpr std::ptrdiff_t m_hProjectile = 0x168; // 
            }
            // Parent: CPlayer_MovementServices
            // Field count: 12
            //
            // Metadata:
            // NetworkVarNames: m_flFallVelocity (float32)
            // NetworkVarNames: m_bInCrouch (bool)
            // NetworkVarNames: m_nCrouchState (uint32)
            // NetworkVarNames: m_flCrouchTransitionStartTime (GameTime_t)
            // NetworkVarNames: m_bDucked (bool)
            // NetworkVarNames: m_bDucking (bool)
            // NetworkVarNames: m_bInDuckJump (bool)
            namespace CPlayer_MovementServices_Humanoid {
                constexpr std::ptrdiff_t m_flStepSoundTime = 0x1D8; // 
                constexpr std::ptrdiff_t m_flFallVelocity = 0x1DC; // 
                constexpr std::ptrdiff_t m_bInCrouch = 0x1E0; // 
                constexpr std::ptrdiff_t m_nCrouchState = 0x1E4; // 
                constexpr std::ptrdiff_t m_flCrouchTransitionStartTime = 0x1E8; // 
                constexpr std::ptrdiff_t m_bDucked = 0x1EC; // 
                constexpr std::ptrdiff_t m_bDucking = 0x1ED; // 
                constexpr std::ptrdiff_t m_bInDuckJump = 0x1EE; // 
                constexpr std::ptrdiff_t m_groundNormal = 0x1F0; // 
                constexpr std::ptrdiff_t m_flSurfaceFriction = 0x1FC; // 
                constexpr std::ptrdiff_t m_surfaceProps = 0x200; // 
                constexpr std::ptrdiff_t m_nStepside = 0x210; // 
            }
            // Parent: C_NPC_SimpleAnimatingAI
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_CCitadelAbilityComponent (CCitadelAbilityComponent::Storage_t)
            // NetworkVarNames: m_flAttackRange (float)
            // NetworkVarNames: m_flAimPitch (float)
            namespace C_NPC_ShieldedSentry {
                constexpr std::ptrdiff_t m_CCitadelAbilityComponent = 0xB58; // 
                constexpr std::ptrdiff_t m_flAttackRange = 0xCFC; // 
                constexpr std::ptrdiff_t m_flAimPitch = 0xD00; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_ColdFront {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_BaseHeldItem {
            }
            // Parent: C_BaseClientUIEntity
            // Field count: 28
            //
            // Metadata:
            // NetworkVarNames: m_bIgnoreInput (bool)
            // NetworkVarNames: m_bLit (bool)
            // NetworkVarNames: m_bFollowPlayerAcrossTeleport (bool)
            // NetworkVarNames: m_flWidth (float)
            // NetworkVarNames: m_flHeight (float)
            // NetworkVarNames: m_flDPI (float)
            // NetworkVarNames: m_flInteractDistance (float)
            // NetworkVarNames: m_flDepthOffset (float)
            // NetworkVarNames: m_unOwnerContext (uint32)
            // NetworkVarNames: m_unHorizontalAlign (uint32)
            // NetworkVarNames: m_unVerticalAlign (uint32)
            // NetworkVarNames: m_unOrientation (uint32)
            // NetworkVarNames: m_bAllowInteractionFromAllSceneWorlds (bool)
            // NetworkVarNames: m_vecCSSClasses (string_t)
            // NetworkVarNames: m_bOpaque (bool)
            // NetworkVarNames: m_bNoDepth (bool)
            // NetworkVarNames: m_bRenderBackface (bool)
            // NetworkVarNames: m_bUseOffScreenIndicator (bool)
            // NetworkVarNames: m_bExcludeFromSaveGames (bool)
            // NetworkVarNames: m_bGrabbable (bool)
            // NetworkVarNames: m_bOnlyRenderToTexture (bool)
            // NetworkVarNames: m_bDisableMipGen (bool)
            // NetworkVarNames: m_nExplicitImageLayout (int32)
            namespace C_PointClientUIWorldPanel {
                constexpr std::ptrdiff_t m_bForceRecreateNextUpdate = 0x868; // 
                constexpr std::ptrdiff_t m_bMoveViewToPlayerNextThink = 0x869; // 
                constexpr std::ptrdiff_t m_bCheckCSSClasses = 0x86A; // 
                constexpr std::ptrdiff_t m_anchorDeltaTransform = 0x870; // 
                constexpr std::ptrdiff_t m_pOffScreenIndicator = 0xA08; // 
                constexpr std::ptrdiff_t m_bIgnoreInput = 0xA30; // 
                constexpr std::ptrdiff_t m_bLit = 0xA31; // 
                constexpr std::ptrdiff_t m_bFollowPlayerAcrossTeleport = 0xA32; // 
                constexpr std::ptrdiff_t m_flWidth = 0xA34; // 
                constexpr std::ptrdiff_t m_flHeight = 0xA38; // 
                constexpr std::ptrdiff_t m_flDPI = 0xA3C; // 
                constexpr std::ptrdiff_t m_flInteractDistance = 0xA40; // 
                constexpr std::ptrdiff_t m_flDepthOffset = 0xA44; // 
                constexpr std::ptrdiff_t m_unOwnerContext = 0xA48; // 
                constexpr std::ptrdiff_t m_unHorizontalAlign = 0xA4C; // 
                constexpr std::ptrdiff_t m_unVerticalAlign = 0xA50; // 
                constexpr std::ptrdiff_t m_unOrientation = 0xA54; // 
                constexpr std::ptrdiff_t m_bAllowInteractionFromAllSceneWorlds = 0xA58; // 
                constexpr std::ptrdiff_t m_vecCSSClasses = 0xA60; // C_NetworkUtlVectorBase<CUtlSymbolLarge>
                constexpr std::ptrdiff_t m_bOpaque = 0xA78; // 
                constexpr std::ptrdiff_t m_bNoDepth = 0xA79; // 
                constexpr std::ptrdiff_t m_bRenderBackface = 0xA7A; // 
                constexpr std::ptrdiff_t m_bUseOffScreenIndicator = 0xA7B; // 
                constexpr std::ptrdiff_t m_bExcludeFromSaveGames = 0xA7C; // 
                constexpr std::ptrdiff_t m_bGrabbable = 0xA7D; // 
                constexpr std::ptrdiff_t m_bOnlyRenderToTexture = 0xA7E; // 
                constexpr std::ptrdiff_t m_bDisableMipGen = 0xA7F; // 
                constexpr std::ptrdiff_t m_nExplicitImageLayout = 0xA80; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 8
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbility_Synth_PlasmaFlux_VData {
                constexpr std::ptrdiff_t m_WeaponDamageBonusModifier = 0x1548; // 
                constexpr std::ptrdiff_t m_TeleportTrailParticle = 0x1558; // 
                constexpr std::ptrdiff_t m_ImpactParticle = 0x1638; // 
                constexpr std::ptrdiff_t m_strCasterLoopingSound = 0x1718; // 
                constexpr std::ptrdiff_t m_strProjectileExpireSound = 0x1728; // 
                constexpr std::ptrdiff_t m_strImpactSound = 0x1738; // 
                constexpr std::ptrdiff_t m_strTimerSound = 0x1748; // 
                constexpr std::ptrdiff_t m_cameraSequenceTeleport = 0x1758; // CitadelCameraOperationsSequence_t
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 10
            //
            // Metadata:
            // NetworkVarNames: m_bIsRolling (bool)
            // NetworkVarNames: m_hBall (CHandle<CCitadelViscousBall>)
            // NetworkVarNames: m_eRollingState (EViscousBowlingBallState_t)
            // NetworkVarNames: m_flNextStateTime (GameTime_t)
            // NetworkVarNames: m_flNextWallCheck (GameTime_t)
            // NetworkVarNames: m_flRollStartTime (GameTime_t)
            // NetworkVarNames: m_flWallExitTime (GameTime_t)
            // NetworkVarNames: m_vecWallExitVelocity (Vector)
            namespace CCitadel_Ability_GooBowlingBall {
                constexpr std::ptrdiff_t m_bHasAirJumped = 0xFC0; // 
                constexpr std::ptrdiff_t m_bIsRolling = 0xFC1; // 
                constexpr std::ptrdiff_t m_hBall = 0xFC4; // 
                constexpr std::ptrdiff_t m_eRollingState = 0xFC8; // 
                constexpr std::ptrdiff_t m_flNextStateTime = 0xFCC; // 
                constexpr std::ptrdiff_t m_flNextWallCheck = 0xFD0; // 
                constexpr std::ptrdiff_t m_flRollStartTime = 0xFD4; // 
                constexpr std::ptrdiff_t m_flWallExitTime = 0xFD8; // 
                constexpr std::ptrdiff_t m_vecWallExitVelocity = 0xFDC; // 
                constexpr std::ptrdiff_t m_nDirectionParticleIndex = 0xFF0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 7
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelModifierAerialAssaultVData {
                constexpr std::ptrdiff_t m_FireRateModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x618; // 
                constexpr std::ptrdiff_t m_TracerParticle = 0x6F8; // 
                constexpr std::ptrdiff_t m_ExplodeSound = 0x7D8; // 
                constexpr std::ptrdiff_t m_flAirDrag = 0x7E8; // 
                constexpr std::ptrdiff_t m_flAirSpeed = 0x7EC; // 
                constexpr std::ptrdiff_t m_flFallSpeed = 0x7F0; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_SlowingBullets_ProcVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x638; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ActiveDisarm_SpiritSteal_VData {
                constexpr std::ptrdiff_t m_SpiritStealParticle = 0x608; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ClimbRopeSpeed {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelModifierProjectilePitchingLoopSoundThinkerVData {
                constexpr std::ptrdiff_t m_speedToPitchRemap = 0x608; // 
            }
            // Parent: C_NPC_SimpleAnimatingAI
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_flAttackRange (float)
            // NetworkVarNames: m_flAimPitch (float)
            namespace C_NPC_FieldSentry {
                constexpr std::ptrdiff_t m_flAttackRange = 0xB5C; // 
                constexpr std::ptrdiff_t m_flAimPitch = 0xB60; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_ComboBreaker {
            }
            // Parent: CCitadelModifierVData
            // Field count: 8
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Mirage_SandPhantom_Passive_Victim_VData {
                constexpr std::ptrdiff_t m_SlowModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BuffStatusParticle = 0x618; // 
                constexpr std::ptrdiff_t m_BuffStatusVictimParticle = 0x6F8; // 
                constexpr std::ptrdiff_t m_StackDamageParticle = 0x7D8; // 
                constexpr std::ptrdiff_t m_StackReadyParticle = 0x8B8; // 
                constexpr std::ptrdiff_t m_ConsumeMaxStacksSound = 0x998; // 
                constexpr std::ptrdiff_t m_ConsumeMaxStacksNonHeroSound = 0x9A8; // 
                constexpr std::ptrdiff_t m_ApplyStackSound = 0x9B8; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Astro_Shotgun_Toggle {
            }
            // Parent: CCitadel_Modifier_Intrinsic_Base
            // Field count: 0
            namespace CCitadel_Modifier_WeaponEaterStack {
            }
            // Parent: C_SoundOpvarSetPointEntity
            // Field count: 0
            namespace C_SoundOpvarSetAABBEntity {
            }
            // Parent: None
            // Field count: 4
            //
            // Metadata:
            // NetworkVarNames: m_nTotalPausedTicks (int)
            // NetworkVarNames: m_nPauseStartTick (int)
            // NetworkVarNames: m_bGamePaused (bool)
            namespace C_GameRules {
                constexpr std::ptrdiff_t __m_pChainEntity = 0x8; // 
                constexpr std::ptrdiff_t m_nTotalPausedTicks = 0x30; // 
                constexpr std::ptrdiff_t m_nPauseStartTick = 0x34; // 
                constexpr std::ptrdiff_t m_bGamePaused = 0x38; // 
            }
            // Parent: C_BasePropDoor
            // Field count: 0
            namespace C_PropDoorRotating {
            }
            // Parent: C_BaseEntity
            // Field count: 4
            //
            // Metadata:
            // MNetworkIncludeByName
            // NetworkVarNames: m_aPlayerControllers (CHandle<CBasePlayerController>)
            // NetworkVarNames: m_aPlayers (CHandle<C_BasePlayerPawn>)
            // NetworkVarNames: m_iScore (int32)
            // NetworkVarNames: m_szTeamname (char)
            namespace C_Team {
                constexpr std::ptrdiff_t m_aPlayerControllers = 0x558; // 
                constexpr std::ptrdiff_t m_aPlayers = 0x570; // 
                constexpr std::ptrdiff_t m_iScore = 0x588; // 
                constexpr std::ptrdiff_t m_szTeamname = 0x58C; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 9
            //
            // Metadata:
            // NetworkVarNames: m_bPreparing (bool)
            // NetworkVarNames: m_bTackling (bool)
            // NetworkVarNames: m_flTackleStartTime (GameTime_t)
            // NetworkVarNames: m_flPrepareStartTime (GameTime_t)
            // NetworkVarNames: m_vecTackleDir (Vector)
            namespace CCitadel_Ability_ChargedTackle {
                constexpr std::ptrdiff_t m_bPreparing = 0xE70; // 
                constexpr std::ptrdiff_t m_bTackling = 0xE71; // 
                constexpr std::ptrdiff_t m_flTackleStartTime = 0xE74; // 
                constexpr std::ptrdiff_t m_flPrepareStartTime = 0xE78; // 
                constexpr std::ptrdiff_t m_vecTackleDir = 0xE7C; // 
                constexpr std::ptrdiff_t m_vecLastPosition = 0xE88; // 
                constexpr std::ptrdiff_t m_nStuckFramesCount = 0xE94; // 
                constexpr std::ptrdiff_t m_vecHitEnemies = 0xE98; // 
                constexpr std::ptrdiff_t m_nDistancePreview = 0xEB0; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 5
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelAbilityChargedBombVData {
                constexpr std::ptrdiff_t m_ChargeBombModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x1558; // 
                constexpr std::ptrdiff_t m_strExplodeSound = 0x1638; // 
                constexpr std::ptrdiff_t m_flChargeForMaxDamage = 0x1648; // 
                constexpr std::ptrdiff_t m_flMinDamagePercent = 0x164C; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Aerial_Assault_Watcher {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_GlowToTeammates {
            }
            // Parent: CCitadelModifierAura
            // Field count: 3
            namespace CCitadel_Modifier_AirLift_ExplodeAura {
                constexpr std::ptrdiff_t m_flStartRadius = 0xE0; // 
                constexpr std::ptrdiff_t m_flEndRadius = 0xE4; // 
                constexpr std::ptrdiff_t m_flSpreadDuration = 0xE8; // 
            }
            // Parent: CAI_CitadelNPCVData
            // Field count: 24
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CNPC_Boss_Tier2VData {
                constexpr std::ptrdiff_t m_flPlayerInitialSightRange = 0xF60; // 
                constexpr std::ptrdiff_t m_strWIPModelName = 0xF68; // 
                constexpr std::ptrdiff_t m_vecWeakPoints = 0x1048; // 
                constexpr std::ptrdiff_t m_BeamChargingEffect = 0x1060; // 
                constexpr std::ptrdiff_t m_BeamPreviewEffect = 0x1140; // 
                constexpr std::ptrdiff_t m_BeamActiveEffect = 0x1220; // 
                constexpr std::ptrdiff_t m_StompImpactEffect = 0x1300; // 
                constexpr std::ptrdiff_t m_flTossSpeed = 0x13E0; // 
                constexpr std::ptrdiff_t m_flStompDamage = 0x13E4; // 
                constexpr std::ptrdiff_t m_flStompTossUpMagnitude = 0x13E8; // 
                constexpr std::ptrdiff_t m_flStunDuration = 0x13EC; // 
                constexpr std::ptrdiff_t m_flStompImpactRadius = 0x13F0; // 
                constexpr std::ptrdiff_t m_flStompImpactHeight = 0x13F4; // 
                constexpr std::ptrdiff_t m_flSweepRadius = 0x13F8; // 
                constexpr std::ptrdiff_t m_flSweepSpeed = 0x13FC; // 
                constexpr std::ptrdiff_t m_flSweepZScale = 0x1400; // 
                constexpr std::ptrdiff_t m_flSweepMaxAngle = 0x1404; // 
                constexpr std::ptrdiff_t m_flSweepMaxRange = 0x1408; // 
                constexpr std::ptrdiff_t m_flSweepAdjustSpeed = 0x140C; // 
                constexpr std::ptrdiff_t m_flBurstDuration = 0x1410; // 
                constexpr std::ptrdiff_t m_flBurstCooldown = 0x1414; // 
                constexpr std::ptrdiff_t m_BackdoorProtectionModifier = 0x1418; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_InvulModifier = 0x1428; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_flInvulModifierRange = 0x1438; // 
            }
            // Parent: C_SoundAreaEntityBase
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_vMin (Vector)
            // NetworkVarNames: m_vMax (Vector)
            namespace C_SoundAreaEntityOrientedBox {
                constexpr std::ptrdiff_t m_vMin = 0x580; // 
                constexpr std::ptrdiff_t m_vMax = 0x58C; // 
            }
            // Parent: CCitadel_Ability_PrimaryWeapon_BeamWeapon
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_flStartWindUpTime (GameTime_t)
            // NetworkVarNames: m_flStartFiringTime (GameTime_t)
            // NetworkVarNames: m_bFiring (bool)
            namespace CCitadel_Ability_PrimaryWeapon_Bebop {
                constexpr std::ptrdiff_t m_flStartWindUpTime = 0x1000; // 
                constexpr std::ptrdiff_t m_flStartFiringTime = 0x1004; // 
                constexpr std::ptrdiff_t m_bFiring = 0x1008; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_SiphonBullets_HealthLoss {
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_LongRangeSlowingTech_ProcVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x638; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierDelayedStunVData {
                constexpr std::ptrdiff_t m_HitParticle = 0x608; // 
            }
            // Parent: CCitadelAnimatingModelEntity
            // Field count: 0
            namespace C_Citadel_CatAnimating {
            }
            // Parent: C_BaseModelEntity
            // Field count: 8
            //
            // Metadata:
            // NetworkVarNames: m_bLoop (bool)
            // NetworkVarNames: m_flFPS (float)
            // NetworkVarNames: m_hPositionKeys (HRenderTextureStrong)
            // NetworkVarNames: m_hRotationKeys (HRenderTextureStrong)
            // NetworkVarNames: m_vAnimationBoundsMin (Vector)
            // NetworkVarNames: m_vAnimationBoundsMax (Vector)
            // NetworkVarNames: m_flStartTime (float)
            // NetworkVarNames: m_flStartFrame (float)
            namespace C_TextureBasedAnimatable {
                constexpr std::ptrdiff_t m_bLoop = 0x830; // 
                constexpr std::ptrdiff_t m_flFPS = 0x834; // 
                constexpr std::ptrdiff_t m_hPositionKeys = 0x838; // 
                constexpr std::ptrdiff_t m_hRotationKeys = 0x840; // 
                constexpr std::ptrdiff_t m_vAnimationBoundsMin = 0x848; // 
                constexpr std::ptrdiff_t m_vAnimationBoundsMax = 0x854; // 
                constexpr std::ptrdiff_t m_flStartTime = 0x860; // 
                constexpr std::ptrdiff_t m_flStartFrame = 0x864; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_IdolReturnTimer {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Targetdummy_2 {
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierRiotProtocolBuffVData {
                constexpr std::ptrdiff_t m_LaserParticle = 0x608; // 
                constexpr std::ptrdiff_t m_PulseHitEnemyParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_EnemyDebuffModifier = 0x7C8; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierCrowdControlDebuffVData {
                constexpr std::ptrdiff_t m_DebuffParticle = 0x608; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_AirRaid {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelModifierIdolReturnTimerVData {
                constexpr std::ptrdiff_t m_ChannelParticle = 0x608; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_IcePath_TechPowerLinger {
                constexpr std::ptrdiff_t m_nBonusSpirit = 0xC0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_VeilWalkerWatcherVData {
                constexpr std::ptrdiff_t m_InvisModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_VeilWalkerTriggeredModifier = 0x618; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_VeilWalkerMovespeed = 0x628; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_flTraceLengthMin = 0x638; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_MeleeTarget {
            }
            // Parent: CNPC_TrooperNeutralVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CNPC_TrooperNeutralNodeMoverVData {
                constexpr std::ptrdiff_t m_bEnableMovementToNodes = 0x12C8; // 
                constexpr std::ptrdiff_t m_flExposedDuration = 0x12CC; // 
                constexpr std::ptrdiff_t m_flHideDuration = 0x12D4; // 
                constexpr std::ptrdiff_t m_HidingModifier = 0x12E0; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_SoundOpvarSetPointBase
            // Field count: 0
            namespace C_SoundOpvarSetPointEntity {
            }
            // Parent: C_NPC_TrooperNeutral
            // Field count: 0
            namespace C_NPC_MidBossHeroTest {
            }
            // Parent: C_LightEntity
            // Field count: 0
            namespace C_LightOrthoEntity {
            }
            // Parent: CCitadel_Modifier_PowerUp
            // Field count: 0
            namespace CCitadel_Modifier_PermanentPickup {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Slork_Raging_Current_CountdownVData {
                constexpr std::ptrdiff_t m_TorrentModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_WaterAuraParticle = 0x618; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Mirage_Tornado_Aura_Apply_VData {
                constexpr std::ptrdiff_t m_TossModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_LiftModifier = 0x618; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_strHitConfirmSound = 0x628; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityThumper3VData {
                constexpr std::ptrdiff_t m_DroneModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ShakedownPulseVData {
                constexpr std::ptrdiff_t m_strFireSound = 0x608; // 
                constexpr std::ptrdiff_t m_ShakeParticle = 0x618; // 
                constexpr std::ptrdiff_t m_ChainParticle = 0x6F8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_WreckerScrapBlastDebuff {
                constexpr std::ptrdiff_t m_flEnemyMoveSlow = 0xC0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_HealingPulse_Tracker {
            }
            // Parent: CitadelItemVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Item_TechCleaveVData {
                constexpr std::ptrdiff_t m_TechCleaveModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_sCleaveProcSound = 0x15A0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 2
            namespace CCitadel_Modifier_RescueBeam {
                constexpr std::ptrdiff_t m_flHealthPerTick = 0x1A0; // 
                constexpr std::ptrdiff_t m_nBeamIndex = 0x1A4; // 
            }
            // Parent: CCitadelItemPickupRejuvVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelItemPickupRejuvHeroTestVData {
            }
            // Parent: C_BaseEntity
            // Field count: 2
            namespace CSkyboxReference {
                constexpr std::ptrdiff_t m_worldGroupId = 0x558; // 
                constexpr std::ptrdiff_t m_hSkyCamera = 0x55C; // 
            }
            // Parent: C_TonemapController2
            // Field count: 0
            namespace C_TonemapController2Alias_env_tonemap_controller2 {
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelModifierAura_ConeVData {
                constexpr std::ptrdiff_t m_flAuraTargetingConeHalfWidth = 0x648; // 
                constexpr std::ptrdiff_t m_flAuraTargetingConeAngle = 0x64C; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ControlPointCapturerAuraTarget {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Dust_Storm_Thrown {
            }
            // Parent: CitadelItemVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_ArmorUpgrade_PersonalRejuvenatorVData {
                constexpr std::ptrdiff_t m_DeployParticle = 0x1590; // 
                constexpr std::ptrdiff_t m_RespawnParticle = 0x1670; // 
                constexpr std::ptrdiff_t m_sDeploySound = 0x1750; // 
                constexpr std::ptrdiff_t m_sRespawnSound = 0x1760; // 
            }
            // Parent: CCitadelModifier
            // Field count: 18
            namespace CCitadel_Modifier_Tier2Boss_LaserBeam {
                constexpr std::ptrdiff_t m_bPreview = 0x130; // 
                constexpr std::ptrdiff_t m_flSoundStartTime = 0x13C; // 
                constexpr std::ptrdiff_t m_vStart = 0x144; // 
                constexpr std::ptrdiff_t m_vEnd = 0x150; // 
                constexpr std::ptrdiff_t m_vPrevEnd = 0x15C; // 
                constexpr std::ptrdiff_t m_flAngleBetweenTrace = 0x168; // 
                constexpr std::ptrdiff_t m_flDamagePerTick = 0x16C; // 
                constexpr std::ptrdiff_t m_flCreepDamagePerTick = 0x170; // 
                constexpr std::ptrdiff_t m_flNextDamageTick = 0x174; // 
                constexpr std::ptrdiff_t m_vecEntitiesHit = 0x178; // 
                constexpr std::ptrdiff_t m_flDamageTickRate = 0x190; // 
                constexpr std::ptrdiff_t m_flLastShakeTime = 0x194; // 
                constexpr std::ptrdiff_t m_bSweepRightFirst = 0x198; // 
                constexpr std::ptrdiff_t m_angBeamAim = 0x19C; // 
                constexpr std::ptrdiff_t m_vecBeamTarget = 0x1A8; // 
                constexpr std::ptrdiff_t m_flLastBeamUpdateTime = 0x1B4; // 
                constexpr std::ptrdiff_t m_flTargetingTaskStartTime = 0x1D0; // 
                constexpr std::ptrdiff_t m_flTrackVel = 0x1D4; // 
            }
            // Parent: None
            // Field count: 30
            //
            // Metadata:
            // NetworkVarNames: m_hTargetEntity (CHandle<C_BaseEntity>)
            // NetworkVarNames: m_bState (bool)
            // NetworkVarNames: m_bAlwaysUpdate (bool)
            // NetworkVarNames: m_flLightFOV (float32)
            // NetworkVarNames: m_bEnableShadows (bool)
            // NetworkVarNames: m_bSimpleProjection (bool)
            // NetworkVarNames: m_bLightOnlyTarget (bool)
            // NetworkVarNames: m_bLightWorld (bool)
            // NetworkVarNames: m_bCameraSpace (bool)
            // NetworkVarNames: m_flBrightnessScale (float32)
            // NetworkVarNames: m_LightColor (Color)
            // NetworkVarNames: m_flIntensity (float32)
            // NetworkVarNames: m_flLinearAttenuation (float32)
            // NetworkVarNames: m_flQuadraticAttenuation (float32)
            // NetworkVarNames: m_bVolumetric (bool)
            // NetworkVarNames: m_flVolumetricIntensity (float32)
            // NetworkVarNames: m_flNoiseStrength (float32)
            // NetworkVarNames: m_flFlashlightTime (float32)
            // NetworkVarNames: m_nNumPlanes (uint32)
            // NetworkVarNames: m_flPlaneOffset (float32)
            // NetworkVarNames: m_flColorTransitionTime (float32)
            // NetworkVarNames: m_flAmbient (float32)
            // NetworkVarNames: m_SpotlightTextureName (char)
            // NetworkVarNames: m_nSpotlightTextureFrame (int32)
            // NetworkVarNames: m_nShadowQuality (uint32)
            // NetworkVarNames: m_flNearZ (float32)
            // NetworkVarNames: m_flFarZ (float32)
            // NetworkVarNames: m_flProjectionSize (float32)
            // NetworkVarNames: m_flRotation (float32)
            // NetworkVarNames: m_bFlipHorizontal (bool)
            namespace CProjectedTextureBase {
                constexpr std::ptrdiff_t m_hTargetEntity = 0xC; // 
                constexpr std::ptrdiff_t m_bState = 0x10; // 
                constexpr std::ptrdiff_t m_bAlwaysUpdate = 0x11; // 
                constexpr std::ptrdiff_t m_flLightFOV = 0x14; // 
                constexpr std::ptrdiff_t m_bEnableShadows = 0x18; // 
                constexpr std::ptrdiff_t m_bSimpleProjection = 0x19; // 
                constexpr std::ptrdiff_t m_bLightOnlyTarget = 0x1A; // 
                constexpr std::ptrdiff_t m_bLightWorld = 0x1B; // 
                constexpr std::ptrdiff_t m_bCameraSpace = 0x1C; // 
                constexpr std::ptrdiff_t m_flBrightnessScale = 0x20; // 
                constexpr std::ptrdiff_t m_LightColor = 0x24; // 
                constexpr std::ptrdiff_t m_flIntensity = 0x28; // 
                constexpr std::ptrdiff_t m_flLinearAttenuation = 0x2C; // 
                constexpr std::ptrdiff_t m_flQuadraticAttenuation = 0x30; // 
                constexpr std::ptrdiff_t m_bVolumetric = 0x34; // 
                constexpr std::ptrdiff_t m_flVolumetricIntensity = 0x38; // 
                constexpr std::ptrdiff_t m_flNoiseStrength = 0x3C; // 
                constexpr std::ptrdiff_t m_flFlashlightTime = 0x40; // 
                constexpr std::ptrdiff_t m_nNumPlanes = 0x44; // 
                constexpr std::ptrdiff_t m_flPlaneOffset = 0x48; // 
                constexpr std::ptrdiff_t m_flColorTransitionTime = 0x4C; // 
                constexpr std::ptrdiff_t m_flAmbient = 0x50; // 
                constexpr std::ptrdiff_t m_SpotlightTextureName = 0x54; // 
                constexpr std::ptrdiff_t m_nSpotlightTextureFrame = 0x254; // 
                constexpr std::ptrdiff_t m_nShadowQuality = 0x258; // 
                constexpr std::ptrdiff_t m_flNearZ = 0x25C; // 
                constexpr std::ptrdiff_t m_flFarZ = 0x260; // 
                constexpr std::ptrdiff_t m_flProjectionSize = 0x264; // 
                constexpr std::ptrdiff_t m_flRotation = 0x268; // 
                constexpr std::ptrdiff_t m_bFlipHorizontal = 0x26C; // 
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_Cadence_SleepAOE {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_WeaponUpgrade_FireRateAura {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_AirLiftExplodingAllyVData {
                constexpr std::ptrdiff_t m_strExplodeEffect = 0x608; // 
                constexpr std::ptrdiff_t m_AOEModifier = 0x6E8; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Bebop_LaserBeamVData {
                constexpr std::ptrdiff_t m_LaserModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ChargeParticle = 0x1558; // 
            }
            // Parent: CCitadel_Modifier_Invis
            // Field count: 1
            namespace CCitadel_Modifier_Camouflage_Invis {
                constexpr std::ptrdiff_t m_vCastPosition = 0x268; // 
            }
            // Parent: CCitadelBaseAbilityServerOnly
            // Field count: 0
            namespace CCitadel_Ability_TrooperGrenade {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_BaseShield {
            }
            // Parent: C_NPC_TrooperNeutral
            // Field count: 0
            namespace C_NPC_TrooperNeutralNodeMover {
            }
            // Parent: CAttributeManager
            // Field count: 1
            //
            // Metadata:
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // NetworkVarNames: m_Item (CEconItemView)
            namespace CAttributeContainer {
                constexpr std::ptrdiff_t m_Item = 0x68; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Lash_Flog_Debuff {
            }
            // Parent: CCitadelModifierVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_FlameDashVData {
                constexpr std::ptrdiff_t m_GroundAuraModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ProgressModifier = 0x618; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_FlameDashParticle = 0x628; // 
                constexpr std::ptrdiff_t m_FlameAuraParticle = 0x708; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Stabilizing_Tripod {
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_ArmorUpgrade_VexBarrierVData {
                constexpr std::ptrdiff_t m_ShieldModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_HollowPoint_Stack {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_ArmorUpgrade_SlowImmunity {
            }
            // Parent: C_PathParticleRope
            // Field count: 0
            namespace C_PathParticleRopeAlias_path_particle_rope_clientside {
            }
            // Parent: CCitadel_Modifier_Intrinsic_Base
            // Field count: 0
            namespace CCitadel_Modifier_MagicStormWatcher {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_DiscordVData {
                constexpr std::ptrdiff_t m_ImpactParticle = 0x608; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_TechRangeClamp {
            }
            // Parent: CPlayerPawnComponent
            // Field count: 0
            namespace CPlayer_UseServices {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Synth_Grasp_Caster_VData {
                constexpr std::ptrdiff_t m_CastParticle = 0x608; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityRestorativeGooVData {
                constexpr std::ptrdiff_t m_RestorativeGooParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_RestorativeGooModifier = 0x1628; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 3
            namespace CCitadel_Ability_Teleport {
                constexpr std::ptrdiff_t m_bTeleportingToTarget = 0xC78; // 
                constexpr std::ptrdiff_t m_vTargetPosition = 0xC7C; // 
                constexpr std::ptrdiff_t m_vTargetAngles = 0xC88; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_BulletArmorReductionVData {
            }
            // Parent: CEntityComponent
            // Field count: 1
            namespace CScriptComponent {
                constexpr std::ptrdiff_t m_scriptClassName = 0x30; // 
            }
            // Parent: C_BaseEntity
            // Field count: 17
            //
            // Metadata:
            // NetworkVarNames: m_Entity_hLightProbeTexture (HRenderTextureStrong)
            // NetworkVarNames: m_Entity_hLightProbeDirectLightIndicesTexture (HRenderTextureStrong)
            // NetworkVarNames: m_Entity_hLightProbeDirectLightScalarsTexture (HRenderTextureStrong)
            // NetworkVarNames: m_Entity_hLightProbeDirectLightShadowsTexture (HRenderTextureStrong)
            // NetworkVarNames: m_Entity_vBoxMins (Vector)
            // NetworkVarNames: m_Entity_vBoxMaxs (Vector)
            // NetworkVarNames: m_Entity_bMoveable (bool)
            // NetworkVarNames: m_Entity_nHandshake (int)
            // NetworkVarNames: m_Entity_nPriority (int)
            // NetworkVarNames: m_Entity_bStartDisabled (bool)
            // NetworkVarNames: m_Entity_nLightProbeSizeX (int)
            // NetworkVarNames: m_Entity_nLightProbeSizeY (int)
            // NetworkVarNames: m_Entity_nLightProbeSizeZ (int)
            // NetworkVarNames: m_Entity_nLightProbeAtlasX (int)
            // NetworkVarNames: m_Entity_nLightProbeAtlasY (int)
            // NetworkVarNames: m_Entity_nLightProbeAtlasZ (int)
            // NetworkVarNames: m_Entity_bEnabled (bool)
            namespace C_EnvLightProbeVolume {
                constexpr std::ptrdiff_t m_Entity_hLightProbeTexture = 0x1538; // 
                constexpr std::ptrdiff_t m_Entity_hLightProbeDirectLightIndicesTexture = 0x1540; // 
                constexpr std::ptrdiff_t m_Entity_hLightProbeDirectLightScalarsTexture = 0x1548; // 
                constexpr std::ptrdiff_t m_Entity_hLightProbeDirectLightShadowsTexture = 0x1550; // 
                constexpr std::ptrdiff_t m_Entity_vBoxMins = 0x1558; // 
                constexpr std::ptrdiff_t m_Entity_vBoxMaxs = 0x1564; // 
                constexpr std::ptrdiff_t m_Entity_bMoveable = 0x1570; // 
                constexpr std::ptrdiff_t m_Entity_nHandshake = 0x1574; // 
                constexpr std::ptrdiff_t m_Entity_nPriority = 0x1578; // 
                constexpr std::ptrdiff_t m_Entity_bStartDisabled = 0x157C; // 
                constexpr std::ptrdiff_t m_Entity_nLightProbeSizeX = 0x1580; // 
                constexpr std::ptrdiff_t m_Entity_nLightProbeSizeY = 0x1584; // 
                constexpr std::ptrdiff_t m_Entity_nLightProbeSizeZ = 0x1588; // 
                constexpr std::ptrdiff_t m_Entity_nLightProbeAtlasX = 0x158C; // 
                constexpr std::ptrdiff_t m_Entity_nLightProbeAtlasY = 0x1590; // 
                constexpr std::ptrdiff_t m_Entity_nLightProbeAtlasZ = 0x1594; // 
                constexpr std::ptrdiff_t m_Entity_bEnabled = 0x15A1; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityGenericPerson4VData {
            }
            // Parent: CCitadel_Modifier_Sleep
            // Field count: 0
            namespace CCitadel_Modifier_SleepDagger_Asleep {
            }
            // Parent: CCitadelModifier
            // Field count: 4
            namespace CCitadel_Modifier_Chrono_KineticCarbine {
                constexpr std::ptrdiff_t m_nBulletCount = 0xC0; // 
                constexpr std::ptrdiff_t m_flElapsedPct = 0xC4; // 
                constexpr std::ptrdiff_t m_hTimeWarp = 0xC8; // CHandle<CCitadelBulletTimeWarp>
                constexpr std::ptrdiff_t m_nFullyChargedParticle = 0xCC; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_HealthSwapPrecastVData {
                constexpr std::ptrdiff_t m_strTargetParticleEffect = 0x608; // 
                constexpr std::ptrdiff_t m_strTargetEnemyParticleEffect = 0x6E8; // 
                constexpr std::ptrdiff_t m_strTargetScreenParticleEffect = 0x7C8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_LifeDrainVData {
                constexpr std::ptrdiff_t m_SilenceModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DrainParticle = 0x618; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_BeltFed_MagazineVData {
                constexpr std::ptrdiff_t m_SpinUpSound = 0x608; // 
                constexpr std::ptrdiff_t m_SpinDownSound = 0x618; // 
                constexpr std::ptrdiff_t m_SpinLoopSound = 0x628; // 
            }
            // Parent: CitadelItemVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CItemStimPakVData {
                constexpr std::ptrdiff_t m_StimPakModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_CastParticle = 0x15A0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_TriggerPush {
                constexpr std::ptrdiff_t m_vPush = 0xC0; // 
            }
            // Parent: None
            // Field count: 12
            //
            // Metadata:
            // NetworkVarNames: m_nEntIndex (CEntityIndex)
            // NetworkVarNames: m_nTeam (int)
            // NetworkVarNames: m_eClass (Class_T)
            // NetworkVarNames: m_iLane (int)
            // NetworkVarNames: m_eHeight (EMinimapHeight)
            // NetworkVarNames: m_bVisibleOnMap (bool)
            // NetworkVarNames: m_bBackdoorProtectionActive (bool)
            // NetworkVarNames: m_nTickHidden (GameTick_t)
            // NetworkVarNames: m_strEntityName (CUtlString)
            // NetworkVarNames: m_nHealthPercent (uint8)
            // NetworkVarNames: m_nPositionX (uint8)
            // NetworkVarNames: m_nPositionY (uint8)
            namespace STeamFOWEntity {
                constexpr std::ptrdiff_t m_nEntIndex = 0x30; // 
                constexpr std::ptrdiff_t m_nTeam = 0x34; // 
                constexpr std::ptrdiff_t m_eClass = 0x38; // 
                constexpr std::ptrdiff_t m_iLane = 0x3C; // 
                constexpr std::ptrdiff_t m_eHeight = 0x40; // 
                constexpr std::ptrdiff_t m_bVisibleOnMap = 0x41; // 
                constexpr std::ptrdiff_t m_bBackdoorProtectionActive = 0x42; // 
                constexpr std::ptrdiff_t m_nTickHidden = 0x44; // 
                constexpr std::ptrdiff_t m_strEntityName = 0x48; // 
                constexpr std::ptrdiff_t m_nHealthPercent = 0x50; // 
                constexpr std::ptrdiff_t m_nPositionX = 0x51; // 
                constexpr std::ptrdiff_t m_nPositionY = 0x52; // 
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ThermalDetonator_ThinkerVData {
                constexpr std::ptrdiff_t m_GroundParticle = 0x648; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Hook_Shield {
            }
            // Parent: CCitadelModifier
            // Field count: 3
            namespace CCitadel_Modifier_FireBomb {
                constexpr std::ptrdiff_t m_flSideMoveSpeed = 0x130; // 
                constexpr std::ptrdiff_t m_vReturnPosition = 0x134; // 
                constexpr std::ptrdiff_t m_vReturnAngles = 0x140; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Item_AOESilence_Target {
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_TechBurst_ProcVData {
                constexpr std::ptrdiff_t m_ProcParticle = 0x638; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_RespawnCredit {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_HealthRegenAura {
            }
            // Parent: C_CitadelProjectile
            // Field count: 0
            namespace C_CitadelTrackedProjectile {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Cadence_Crescendo_InAOE_VData {
                constexpr std::ptrdiff_t m_PostAOEModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_VeilWalkerMovespeed {
            }
            // Parent: CCitadel_Modifier_Intrinsic_Base
            // Field count: 1
            namespace CCitadel_Modifier_ReinforcingCasings {
                constexpr std::ptrdiff_t m_LastHitShotID = 0xC0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Upgrade_OverdriveClip_VData {
                constexpr std::ptrdiff_t m_BuffEffect = 0x608; // 
                constexpr std::ptrdiff_t m_TracerParticle = 0x6E8; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_DisarmProcWatcherVData {
                constexpr std::ptrdiff_t m_BuildUpModifier = 0x638; // 
                constexpr std::ptrdiff_t m_DisarmProcModifier = 0x648; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ImmunityModifier = 0x658; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_TracerParticle = 0x668; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_DiminishingSlow {
                constexpr std::ptrdiff_t m_flSlowPercent = 0xC0; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_UtilityUpgrade_DebuffImmunity {
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbility_Rutger_CheatDeath_VData {
                constexpr std::ptrdiff_t m_ModifierCheatDeathActivated = 0x1548; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierFealtyTargetVData {
                constexpr std::ptrdiff_t m_CastParticle = 0x608; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_Arcane_Eater_Proc {
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CItemMetalSkinVData {
                constexpr std::ptrdiff_t m_MetalSkinModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Upgrade_AmmoScavenger_VData {
                constexpr std::ptrdiff_t m_BuffModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 7
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ShieldTracker_BaseVData {
                constexpr std::ptrdiff_t m_flShieldImpactEffectDuration = 0x608; // 
                constexpr std::ptrdiff_t m_ShieldImpactParticle = 0x610; // 
                constexpr std::ptrdiff_t m_ShieldImpactModifier = 0x6F0; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t eShieldType = 0x700; // 
                constexpr std::ptrdiff_t flCooldownOnDamage = 0x704; // 
                constexpr std::ptrdiff_t flCooldownOnBreak = 0x708; // 
                constexpr std::ptrdiff_t flRegenDuration = 0x70C; // 
            }
            // Parent: C_BaseEntity
            // Field count: 30
            //
            // Metadata:
            // NetworkVarNames: m_bTimerPaused (bool)
            // NetworkVarNames: m_flTimeRemaining (float)
            // NetworkVarNames: m_flTimerEndTime (GameTime_t)
            // NetworkVarNames: m_bIsDisabled (bool)
            // NetworkVarNames: m_bShowInHUD (bool)
            // NetworkVarNames: m_nTimerLength (int)
            // NetworkVarNames: m_nTimerInitialLength (int)
            // NetworkVarNames: m_nTimerMaxLength (int)
            // NetworkVarNames: m_bAutoCountdown (bool)
            // NetworkVarNames: m_nSetupTimeLength (int)
            // NetworkVarNames: m_nState (int)
            // NetworkVarNames: m_bStartPaused (bool)
            // NetworkVarNames: m_bInCaptureWatchState (bool)
            // NetworkVarNames: m_flTotalTime (float)
            // NetworkVarNames: m_bStopWatchTimer (bool)
            namespace C_TeamRoundTimer {
                constexpr std::ptrdiff_t m_bTimerPaused = 0x558; // 
                constexpr std::ptrdiff_t m_flTimeRemaining = 0x55C; // 
                constexpr std::ptrdiff_t m_flTimerEndTime = 0x560; // 
                constexpr std::ptrdiff_t m_bIsDisabled = 0x564; // 
                constexpr std::ptrdiff_t m_bShowInHUD = 0x565; // 
                constexpr std::ptrdiff_t m_nTimerLength = 0x568; // 
                constexpr std::ptrdiff_t m_nTimerInitialLength = 0x56C; // 
                constexpr std::ptrdiff_t m_nTimerMaxLength = 0x570; // 
                constexpr std::ptrdiff_t m_bAutoCountdown = 0x574; // 
                constexpr std::ptrdiff_t m_nSetupTimeLength = 0x578; // 
                constexpr std::ptrdiff_t m_nState = 0x57C; // 
                constexpr std::ptrdiff_t m_bStartPaused = 0x580; // 
                constexpr std::ptrdiff_t m_bInCaptureWatchState = 0x581; // 
                constexpr std::ptrdiff_t m_flTotalTime = 0x584; // 
                constexpr std::ptrdiff_t m_bStopWatchTimer = 0x588; // 
                constexpr std::ptrdiff_t m_bFireFinished = 0x589; // 
                constexpr std::ptrdiff_t m_bFire5MinRemain = 0x58A; // 
                constexpr std::ptrdiff_t m_bFire4MinRemain = 0x58B; // 
                constexpr std::ptrdiff_t m_bFire3MinRemain = 0x58C; // 
                constexpr std::ptrdiff_t m_bFire2MinRemain = 0x58D; // 
                constexpr std::ptrdiff_t m_bFire1MinRemain = 0x58E; // 
                constexpr std::ptrdiff_t m_bFire30SecRemain = 0x58F; // 
                constexpr std::ptrdiff_t m_bFire10SecRemain = 0x590; // 
                constexpr std::ptrdiff_t m_bFire5SecRemain = 0x591; // 
                constexpr std::ptrdiff_t m_bFire4SecRemain = 0x592; // 
                constexpr std::ptrdiff_t m_bFire3SecRemain = 0x593; // 
                constexpr std::ptrdiff_t m_bFire2SecRemain = 0x594; // 
                constexpr std::ptrdiff_t m_bFire1SecRemain = 0x595; // 
                constexpr std::ptrdiff_t m_nOldTimerLength = 0x598; // 
                constexpr std::ptrdiff_t m_nOldTimerState = 0x59C; // 
            }
            // Parent: CCitadelModelEntity
            // Field count: 1
            namespace C_LaneNode {
                constexpr std::ptrdiff_t m_nPlayerTeamEventIndex = 0x868; // 
            }
            // Parent: CCitadelModelEntity
            // Field count: 1
            namespace C_CitadelViscousBall {
                constexpr std::ptrdiff_t m_hAbility = 0x838; // 
            }
            // Parent: CCitadel_Modifier_StunnedVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_RagingCurrentVData {
                constexpr std::ptrdiff_t m_TorrentParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_TorrentModifier = 0x7C8; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelAbilityVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityThumper2VData {
                constexpr std::ptrdiff_t m_StompParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_strStompExplosionSound = 0x1628; // 
                constexpr std::ptrdiff_t m_BuffModifier = 0x1638; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BarbedWireAuraModifier = 0x1648; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_ExplosiveBarrel {
            }
            // Parent: CitadelAbilityVData
            // Field count: 5
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityVacuumVData {
                constexpr std::ptrdiff_t m_VacuumAuraModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_flAirSpeedMax = 0x1558; // 
                constexpr std::ptrdiff_t m_flFallSpeedMax = 0x155C; // 
                constexpr std::ptrdiff_t m_flAirDrag = 0x1560; // 
                constexpr std::ptrdiff_t m_flMaxMovespeed = 0x1564; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierBullChargingVData {
                constexpr std::ptrdiff_t m_ChargeParticle = 0x608; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilitySprintVData {
                constexpr std::ptrdiff_t m_SprintParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_strSprintSound = 0x1628; // 
                constexpr std::ptrdiff_t m_flInCombatDuration = 0x1638; // 
                constexpr std::ptrdiff_t m_flSprintAccMS = 0x163C; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_ZiplineSpeed {
                constexpr std::ptrdiff_t m_iLane = 0xC0; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            namespace CAbility_Synth_Affliction {
                constexpr std::ptrdiff_t m_hAOEParticle = 0xCE8; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Tenacity {
            }
            // Parent: CCitadelYamatoBaseVData
            // Field count: 12
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_InfinitySlashVData {
                constexpr std::ptrdiff_t m_flRiseSpeed = 0x1550; // 
                constexpr std::ptrdiff_t m_flRiseDuration = 0x1554; // 
                constexpr std::ptrdiff_t m_flSpeedDecayScale = 0x1558; // 
                constexpr std::ptrdiff_t m_flExplodeHoldTime = 0x155C; // 
                constexpr std::ptrdiff_t m_flExplosionShakeAmplitude = 0x1560; // 
                constexpr std::ptrdiff_t m_flExplosionShakeFrequency = 0x1564; // 
                constexpr std::ptrdiff_t m_flExplosionShakeDuration = 0x1568; // 
                constexpr std::ptrdiff_t m_AOERangeEffect = 0x1570; // 
                constexpr std::ptrdiff_t m_AnimCastEffect = 0x1650; // 
                constexpr std::ptrdiff_t m_cameraSequenceExplosion = 0x1730; // CitadelCameraOperationsSequence_t
                constexpr std::ptrdiff_t m_BuffModifier = 0x17B8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BuffTimerModifier = 0x17C8; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 16
            //
            // Metadata:
            // NetworkVarNames: m_vecCastStartPos (Vector)
            // NetworkVarNames: m_vecDashStartPos (Vector)
            // NetworkVarNames: m_vecDashEndPos (Vector)
            // NetworkVarNames: m_angDashStartAng (QAngle)
            // NetworkVarNames: m_flDashStartTime (GameTime_t)
            // NetworkVarNames: m_flGrappleStartTime (GameTime_t)
            // NetworkVarNames: m_flGrappleArriveTime (GameTime_t)
            // NetworkVarNames: m_hTarget (EHANDLE)
            // NetworkVarNames: m_flGrappleShotAttackTime (GameTime_t)
            // NetworkVarNames: m_rgTargetPos (Vector)
            // NetworkVarNames: m_rgTargetPosTime (GameTime_t)
            namespace CCitadel_Ability_TangoTether {
                constexpr std::ptrdiff_t m_desatVolIdx = 0xC78; // 
                constexpr std::ptrdiff_t m_vecCastStartPos = 0xC7C; // 
                constexpr std::ptrdiff_t m_vecDashStartPos = 0xC88; // 
                constexpr std::ptrdiff_t m_vecDashEndPos = 0xC94; // 
                constexpr std::ptrdiff_t m_angDashStartAng = 0xCA0; // 
                constexpr std::ptrdiff_t m_flDashStartTime = 0xCAC; // 
                constexpr std::ptrdiff_t m_flGrappleStartTime = 0xCB0; // 
                constexpr std::ptrdiff_t m_flGrappleArriveTime = 0xCB4; // 
                constexpr std::ptrdiff_t m_hTarget = 0xCB8; // 
                constexpr std::ptrdiff_t m_flVelSpring = 0xCBC; // 
                constexpr std::ptrdiff_t m_flGrappleShotAttackTime = 0xCC0; // 
                constexpr std::ptrdiff_t m_nTicksNotMoving = 0xCC4; // 
                constexpr std::ptrdiff_t m_vecPrevPos = 0xCC8; // 
                constexpr std::ptrdiff_t m_rgTargetPos = 0xCD4; // 
                constexpr std::ptrdiff_t m_rgTargetPosTime = 0xDC4; // 
                constexpr std::ptrdiff_t m_nGrappleTravelEffect = 0xE14; // 
            }
            // Parent: CCitadelBaseShivAbility
            // Field count: 1
            namespace CCitadel_Ability_ShivDagger {
                constexpr std::ptrdiff_t m_bIsInRicochet = 0xC78; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Puddle {
            }
            // Parent: CitadelAbilityVData
            // Field count: 21
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Bull_LeapVData {
                constexpr std::ptrdiff_t m_CrashSpeedScaleCurve = 0x1548; // 
                constexpr std::ptrdiff_t m_BoostModifier = 0x1588; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_CrashModifier = 0x1598; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ImmunityModifier = 0x15A8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_LandingBonusesModifier = 0x15B8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_TakeOffParticle = 0x15C8; // 
                constexpr std::ptrdiff_t m_ImpactParticle = 0x16A8; // 
                constexpr std::ptrdiff_t m_AoEPreviewParticle = 0x1788; // 
                constexpr std::ptrdiff_t m_nHoverParticle = 0x1868; // 
                constexpr std::ptrdiff_t m_strCrashingSound = 0x1948; // 
                constexpr std::ptrdiff_t m_strImpactSound = 0x1958; // 
                constexpr std::ptrdiff_t m_flStartupTime = 0x1968; // 
                constexpr std::ptrdiff_t m_flForwardBoostSpeed = 0x196C; // 
                constexpr std::ptrdiff_t m_flUpBoostSpeed = 0x1970; // 
                constexpr std::ptrdiff_t m_flBoostTurnRate = 0x1974; // 
                constexpr std::ptrdiff_t m_flHoverTime = 0x1978; // 
                constexpr std::ptrdiff_t m_flMinAimAngle = 0x197C; // 
                constexpr std::ptrdiff_t m_flBoostGain = 0x1980; // 
                constexpr std::ptrdiff_t m_flBoostTime = 0x1984; // 
                constexpr std::ptrdiff_t m_flLandingTime = 0x1988; // 
                constexpr std::ptrdiff_t m_flCrashSpeed = 0x198C; // 
            }
            // Parent: C_BaseEntity
            // Field count: 31
            //
            // Metadata:
            // MNetworkIncludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByUserGroup
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByUserGroup
            // MNetworkOverride
            // NetworkVarNames: m_bChanneling (bool)
            // NetworkVarNames: m_bInCastDelay (bool)
            // NetworkVarNames: m_bSelected (bool)
            // NetworkVarNames: m_vecImbuedByAbilitiyIDs (EntitySubclassID_t)
            // NetworkVarNames: m_nUpgradeBits (int)
            // NetworkVarNames: m_iBucketID (int)
            // NetworkVarNames: m_bToggleState (bool)
            // NetworkVarNames: m_flToggledTime (GameTime_t)
            // NetworkVarNames: m_flCooldownStart (GameTime_t)
            // NetworkVarNames: m_flCooldownEnd (GameTime_t)
            // NetworkVarNames: m_flCastCompletedTime (GameTime_t)
            // NetworkVarNames: m_flChannelStartTime (GameTime_t)
            // NetworkVarNames: m_flCastDelayStartTime (GameTime_t)
            // NetworkVarNames: m_eAbilitySlot (EAbilitySlots_t)
            // NetworkVarNames: m_flPostCastDelayEndTime (GameTime_t)
            // NetworkVarNames: m_iRemainingCharges (int)
            // NetworkVarNames: m_flChargeRechargeStart (GameTime_t)
            // NetworkVarNames: m_flChargeRechargeEnd (GameTime_t)
            // NetworkVarNames: m_flMovementControlActiveTime (GameTime_t)
            // NetworkVarNames: m_flSelectedChangedTime (GameTime_t)
            // NetworkVarNames: m_flAltCastHoldStartTime (GameTime_t)
            // NetworkVarNames: m_flAltCastDoubleTapStartTime (GameTime_t)
            // NetworkVarNames: m_nImbuedAbilityID (AbilityID_t)
            // NetworkVarNames: m_bSelectionModeIsAltMode (bool)
            namespace C_CitadelBaseAbility {
                constexpr std::ptrdiff_t m_vecIntrinsicModifiers = 0x620; // 
                constexpr std::ptrdiff_t m_pCastDelayAutoModifier = 0x638; // 
                constexpr std::ptrdiff_t m_pChannelAutoModifier = 0x650; // 
                constexpr std::ptrdiff_t m_strUsedCastGraphParam = 0x668; // 
                constexpr std::ptrdiff_t m_nCastParamNeedsResetTick = 0x670; // 
                constexpr std::ptrdiff_t m_bIsCoolingDownInternal = 0x674; // 
                constexpr std::ptrdiff_t m_flCancelLockoutTime = 0x678; // 
                constexpr std::ptrdiff_t m_bChanneling = 0x698; // 
                constexpr std::ptrdiff_t m_bInCastDelay = 0x699; // 
                constexpr std::ptrdiff_t m_bSelected = 0x69A; // 
                constexpr std::ptrdiff_t m_vecImbuedByAbilitiyIDs = 0x6A0; // C_NetworkUtlVectorBase<CUtlStringToken>
                constexpr std::ptrdiff_t m_nUpgradeBits = 0x6B8; // 
                constexpr std::ptrdiff_t m_iBucketID = 0x6BC; // 
                constexpr std::ptrdiff_t m_bToggleState = 0x6C0; // 
                constexpr std::ptrdiff_t m_flToggledTime = 0x6C4; // 
                constexpr std::ptrdiff_t m_flCooldownStart = 0x6C8; // 
                constexpr std::ptrdiff_t m_flCooldownEnd = 0x6CC; // 
                constexpr std::ptrdiff_t m_flCastCompletedTime = 0x6D0; // 
                constexpr std::ptrdiff_t m_flChannelStartTime = 0x6D4; // 
                constexpr std::ptrdiff_t m_flCastDelayStartTime = 0x6D8; // 
                constexpr std::ptrdiff_t m_eAbilitySlot = 0x6DC; // 
                constexpr std::ptrdiff_t m_flPostCastDelayEndTime = 0x6E0; // 
                constexpr std::ptrdiff_t m_iRemainingCharges = 0x6E4; // 
                constexpr std::ptrdiff_t m_flChargeRechargeStart = 0x6E8; // 
                constexpr std::ptrdiff_t m_flChargeRechargeEnd = 0x6EC; // 
                constexpr std::ptrdiff_t m_flMovementControlActiveTime = 0x6F0; // 
                constexpr std::ptrdiff_t m_flSelectedChangedTime = 0x6F4; // 
                constexpr std::ptrdiff_t m_flAltCastHoldStartTime = 0x6F8; // 
                constexpr std::ptrdiff_t m_flAltCastDoubleTapStartTime = 0x6FC; // 
                constexpr std::ptrdiff_t m_nImbuedAbilityID = 0x700; // 
                constexpr std::ptrdiff_t m_bSelectionModeIsAltMode = 0x704; // 
            }
            // Parent: C_NPC_SimpleAnimatingAI
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_CCitadelAbilityComponent (CCitadelAbilityComponent::Storage_t)
            namespace C_NPC_TeslaCoil {
                constexpr std::ptrdiff_t m_CCitadelAbilityComponent = 0xB58; // 
            }
            // Parent: C_ModelPointEntity
            // Field count: 0
            namespace C_EnvProjectedTexture {
            }
            // Parent: C_BaseEntity
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_pathString (CUtlString)
            namespace CPathSimple {
                constexpr std::ptrdiff_t m_pathString = 0x5B0; // 
            }
            // Parent: CCitadel_Modifier_Stunned
            // Field count: 1
            namespace CCitadel_Modifier_UltCombo_Target {
                constexpr std::ptrdiff_t m_angles = 0xC8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_WreckingBall_AutoThrow {
            }
            // Parent: CCitadelModifier
            // Field count: 7
            namespace CCitadel_Modifier_Bebop_LaserBeam {
                constexpr std::ptrdiff_t m_flSoundStartTime = 0x330; // 
                constexpr std::ptrdiff_t m_vStart = 0x338; // 
                constexpr std::ptrdiff_t m_vEnd = 0x344; // 
                constexpr std::ptrdiff_t m_vPrevEnd = 0x350; // 
                constexpr std::ptrdiff_t m_flAngleBetweenTrace = 0x35C; // 
                constexpr std::ptrdiff_t m_flDamagePerTick = 0x360; // 
                constexpr std::ptrdiff_t m_flNextDamageTick = 0x364; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Astro_Rifle_SelfVData {
                constexpr std::ptrdiff_t m_WeaponFxParticle = 0x608; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Kelvin_Frozen {
            }
            // Parent: CitadelAbilityVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Chrono_KineticCarbineVData {
                constexpr std::ptrdiff_t m_flShotTimeScaleLingerDuration = 0x1548; // 
                constexpr std::ptrdiff_t m_ChargingModifier = 0x1550; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1560; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_cameraKineticCarbineShotFired = 0x1570; // CitadelCameraOperationsSequence_t
            }
            // Parent: CitadelItemVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Item_DivinersKevlar_VData {
                constexpr std::ptrdiff_t m_BuffModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_PrecastSpiritBuffModifier = 0x15A0; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Item
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_bFlying (bool)
            // NetworkVarNames: m_bSummoning (bool)
            namespace CCitadel_Upgrade_MagicCarpet {
                constexpr std::ptrdiff_t m_flFlyingStartTime = 0xC90; // 
                constexpr std::ptrdiff_t m_bFlying = 0xD40; // 
                constexpr std::ptrdiff_t m_bSummoning = 0xD41; // 
            }
            // Parent: C_PointClientUIWorldPanel
            // Field count: 4
            namespace CPointOffScreenIndicatorUi {
                constexpr std::ptrdiff_t m_bBeenEnabled = 0xA90; // 
                constexpr std::ptrdiff_t m_bHide = 0xA91; // 
                constexpr std::ptrdiff_t m_flSeenTargetTime = 0xA94; // 
                constexpr std::ptrdiff_t m_pTargetPanel = 0xA98; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 2
            namespace CCitadel_Ability_Shakedown_Target {
                constexpr std::ptrdiff_t m_hShadowdownAbility = 0xC78; // CHandle<CCitadel_Ability_Yakuza_Shakedown>
                constexpr std::ptrdiff_t m_AimPos = 0xC7C; // 
            }
            // Parent: CEntitySubclassVDataBase
            // Field count: 8
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Bounce_PadVData {
                constexpr std::ptrdiff_t m_sModelName = 0x28; // 
                constexpr std::ptrdiff_t m_IdleParticle = 0x108; // 
                constexpr std::ptrdiff_t m_BounceParticle = 0x1E8; // 
                constexpr std::ptrdiff_t m_DestroyParticle = 0x2C8; // 
                constexpr std::ptrdiff_t m_strCasterBounceSound = 0x3A8; // 
                constexpr std::ptrdiff_t m_strOtherHeroBounceSound = 0x3B8; // 
                constexpr std::ptrdiff_t m_strBarrelBounceSound = 0x3C8; // 
                constexpr std::ptrdiff_t m_strExpiredSound = 0x3D8; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_SmokeBombVData {
                constexpr std::ptrdiff_t m_InvisModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BuffModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_PurgeParticle = 0x1568; // 
            }
            // Parent: CCitadelModifier
            // Field count: 12
            namespace CCitadel_Modifier_BurstFire_Actuator {
                constexpr std::ptrdiff_t m_bLastShotInFlight = 0xC0; // 
                constexpr std::ptrdiff_t m_bBonusTracked = 0xC1; // 
                constexpr std::ptrdiff_t m_nHitCounter = 0xC4; // 
                constexpr std::ptrdiff_t m_nTotalBurstFireShots = 0xC8; // 
                constexpr std::ptrdiff_t m_nInitialzedClipSize = 0xCC; // 
                constexpr std::ptrdiff_t m_nBonusPitch = 0xD0; // 
                constexpr std::ptrdiff_t m_bInitialized = 0xD4; // 
                constexpr std::ptrdiff_t m_nIncreasedBurstShotCount = 0xD8; // 
                constexpr std::ptrdiff_t m_flIntraBurstCycleTime = 0xDC; // 
                constexpr std::ptrdiff_t m_flCycleTimePct = 0xE0; // 
                constexpr std::ptrdiff_t m_flMaxCycleTimeOverride = 0xE4; // 
                constexpr std::ptrdiff_t m_flMaxBurstFireCooldownOverride = 0xE8; // 
            }
            // Parent: CCitadel_Modifier_StatStealBaseVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Siphon_Bullets_WatcherVData {
                constexpr std::ptrdiff_t m_HealModifier = 0x628; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Upgrade_Magic_Storm {
            }
            // Parent: CPlayer_MovementServices
            // Field count: 2
            namespace CCitadelObserver_MovementServices {
                constexpr std::ptrdiff_t m_flRoamingSpeed = 0x1D8; // 
                constexpr std::ptrdiff_t m_bHasFreeCursor = 0x1DC; // 
            }
            // Parent: CBodyComponentSkeletonInstance
            // Field count: 0
            namespace CBodyComponentBaseModelEntity {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_IceDome_AuraModifierBase {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_TechCleave {
            }
            // Parent: None
            // Field count: 77
            //
            // Metadata:
            // MGetKV3ClassDefaults
            // MVDataAssociatedFile
            // MVDataOverlayType
            namespace CitadelHeroData_t {
                constexpr std::ptrdiff_t m_vecAnimGraphDefaultValueOverrides = 0x8; // 
                constexpr std::ptrdiff_t m_HeroID = 0x28; // 
                constexpr std::ptrdiff_t m_hDamageTakenParticle = 0x30; // 
                constexpr std::ptrdiff_t m_hGroundDamageTakenParticle = 0x110; // 
                constexpr std::ptrdiff_t m_hDeathParticle = 0x1F0; // 
                constexpr std::ptrdiff_t m_hLowHealthParticle = 0x2D0; // 
                constexpr std::ptrdiff_t m_strSelectionImage = 0x3B0; // 
                constexpr std::ptrdiff_t m_strIconImageSmall = 0x3C0; // 
                constexpr std::ptrdiff_t m_strIconHeroCard = 0x3D0; // 
                constexpr std::ptrdiff_t m_strMinimapImage = 0x3E0; // 
                constexpr std::ptrdiff_t m_strTopBarImage = 0x3F0; // 
                constexpr std::ptrdiff_t m_strTopBarVertical = 0x400; // 
                constexpr std::ptrdiff_t m_hRespawnParticle = 0x410; // 
                constexpr std::ptrdiff_t m_colorUI = 0x4F0; // 
                constexpr std::ptrdiff_t m_hAmbientParticle = 0x4F8; // 
                constexpr std::ptrdiff_t m_vecAmbientParticleSettings = 0x5D8; // 
                constexpr std::ptrdiff_t m_colorGlowFriendly = 0x5F0; // 
                constexpr std::ptrdiff_t m_colorGlowEnemy = 0x5F4; // 
                constexpr std::ptrdiff_t m_colorGlowTeam1 = 0x5F8; // 
                constexpr std::ptrdiff_t m_colorGlowTeam2 = 0x5FC; // 
                constexpr std::ptrdiff_t m_strModelName = 0x600; // 
                constexpr std::ptrdiff_t m_nModelSkin = 0x6E0; // 
                constexpr std::ptrdiff_t m_strPublicModelName = 0x6E8; // 
                constexpr std::ptrdiff_t m_strWIPModelName = 0x7C8; // 
                constexpr std::ptrdiff_t m_strUIAnimGraph = 0x8A8; // CResourceNameTyped<CWeakHandle<InfoForResourceTypeIAnimGraphModelBinding>>
                constexpr std::ptrdiff_t m_strUIShopAnimGraph = 0x988; // CResourceNameTyped<CWeakHandle<InfoForResourceTypeIAnimGraphModelBinding>>
                constexpr std::ptrdiff_t m_strUIPortraitMap = 0xA68; // 
                constexpr std::ptrdiff_t m_strUIShoppingMap = 0xA70; // 
                constexpr std::ptrdiff_t m_heroStatsUI = 0xA78; // 
                constexpr std::ptrdiff_t m_heroStatsDisplay = 0xAA8; // 
                constexpr std::ptrdiff_t m_ShopStatDisplay = 0xB38; // 
                constexpr std::ptrdiff_t m_strDeathSound = 0xBE0; // 
                constexpr std::ptrdiff_t m_strLastHitSound = 0xBF0; // 
                constexpr std::ptrdiff_t m_strRosterSelectedSound = 0xC00; // 
                constexpr std::ptrdiff_t m_strRosterRemovedSound = 0xC10; // 
                constexpr std::ptrdiff_t m_strFootstepSoundEventDefault = 0xC20; // 
                constexpr std::ptrdiff_t m_strLowHealthSound = 0xC30; // 
                constexpr std::ptrdiff_t m_strHeroSpecificLowHealthSound = 0xC40; // 
                constexpr std::ptrdiff_t m_strMovementLoop = 0xC50; // 
                constexpr std::ptrdiff_t m_hFootstepSounds = 0xC60; // 
                constexpr std::ptrdiff_t m_hGameSoundEventScript = 0xC68; // CResourceNameTyped<CWeakHandle<InfoForResourceTypeCVSoundEventScriptList>>
                constexpr std::ptrdiff_t m_hGeneratedVOEventScript = 0xD48; // CResourceNameTyped<CWeakHandle<InfoForResourceTypeCVSoundEventScriptList>>
                constexpr std::ptrdiff_t m_flFootstepSoundTravelDistanceMeters = 0xE28; // 
                constexpr std::ptrdiff_t m_flStealthSpeedMetersPerSecond = 0xE2C; // 
                constexpr std::ptrdiff_t m_flStepSoundTime = 0xE30; // 
                constexpr std::ptrdiff_t m_flStepSoundTimeSprinting = 0xE34; // 
                constexpr std::ptrdiff_t m_flCollisionRadius = 0xE38; // 
                constexpr std::ptrdiff_t m_flCollisionHeight = 0xE3C; // 
                constexpr std::ptrdiff_t m_flStepHeight = 0xE40; // 
                constexpr std::ptrdiff_t m_bInDevelopment = 0xE44; // 
                constexpr std::ptrdiff_t m_bAssignedPlayersOnly = 0xE45; // 
                constexpr std::ptrdiff_t m_bBotSelectable = 0xE46; // 
                constexpr std::ptrdiff_t m_bNewPlayerRecommended = 0xE47; // 
                constexpr std::ptrdiff_t m_bLaneTestingRecommended = 0xE48; // 
                constexpr std::ptrdiff_t m_bNeedsTesting = 0xE49; // 
                constexpr std::ptrdiff_t m_bLimitedTesting = 0xE4A; // 
                constexpr std::ptrdiff_t m_bDisabled = 0xE4B; // 
                constexpr std::ptrdiff_t m_bPlayerSelectable = 0xE4C; // 
                constexpr std::ptrdiff_t m_nComplexity = 0xE50; // 
                constexpr std::ptrdiff_t m_nReadability = 0xE54; // 
                constexpr std::ptrdiff_t m_flMinLowHealthPercentage = 0xE58; // 
                constexpr std::ptrdiff_t m_flMaxLowHealthPercentage = 0xE5C; // 
                constexpr std::ptrdiff_t m_flMinMidHealthPercentage = 0xE60; // 
                constexpr std::ptrdiff_t m_flMaxMidHealthPercentage = 0xE64; // 
                constexpr std::ptrdiff_t m_flMinHealthForThreshold = 0xE68; // 
                constexpr std::ptrdiff_t m_flMaxHealthForThreshold = 0xE6C; // 
                constexpr std::ptrdiff_t m_mapStartingStats = 0xE70; // CUtlOrderedMap<EStatsType,float32>
                constexpr std::ptrdiff_t m_mapScalingStats = 0xE98; // CUtlOrderedMap<EStatsType,HeroScalingStat_t>
                constexpr std::ptrdiff_t m_mapBoundAbilities = 0xED8; // 
                constexpr std::ptrdiff_t m_mapWIPAbilities = 0xF00; // 
                constexpr std::ptrdiff_t m_mapItemSlotInfo = 0xF28; // 
                constexpr std::ptrdiff_t m_RecommendedUpgrades = 0xF50; // 
                constexpr std::ptrdiff_t m_RecommendedAbilityOrder = 0xFD8; // 
                constexpr std::ptrdiff_t m_eAbilityResourceType = 0x1008; // 
                constexpr std::ptrdiff_t m_mapStandardLevelUpUpgrades = 0x1028; // CUtlOrderedMap<EModifierValue,float32>
                constexpr std::ptrdiff_t m_mapLevelInfo = 0x1050; // CUtlOrderedMap<int32,HeroLevel_t>
                constexpr std::ptrdiff_t m_mapPurchaseBonuses = 0x1078; // CUtlOrderedMap<EItemSlotTypes_t,CUtlVector<HeroPurchaseBonus_t>>
            }
            // Parent: C_BaseEntity
            // Field count: 4
            //
            // Metadata:
            // NetworkVarNames: m_skyboxData (sky3dparams_t)
            // NetworkVarNames: m_skyboxSlotToken (CUtlStringToken)
            namespace C_SkyCamera {
                constexpr std::ptrdiff_t m_skyboxData = 0x558; // 
                constexpr std::ptrdiff_t m_skyboxSlotToken = 0x5E8; // 
                constexpr std::ptrdiff_t m_bUseAngles = 0x5EC; // 
                constexpr std::ptrdiff_t m_pNext = 0x5F0; // 
            }
            // Parent: C_BaseModelEntity
            // Field count: 0
            namespace C_World {
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierVacuumAuraVData {
                constexpr std::ptrdiff_t m_FinishParticle = 0x648; // 
                constexpr std::ptrdiff_t m_AlliedParticle = 0x728; // 
                constexpr std::ptrdiff_t m_EnemyParticle = 0x808; // 
                constexpr std::ptrdiff_t m_strAmbientLoopingLocalPlayerSound = 0x8E8; // 
            }
            // Parent: C_CitadelProjectile
            // Field count: 1
            namespace C_CitadelProjectile_ImmobilizeTrap {
                constexpr std::ptrdiff_t m_bShouldDraw = 0x8B8; // 
            }
            // Parent: C_BaseModelEntity
            // Field count: 13
            //
            // Metadata:
            // NetworkVarNames: m_flStartTime (GameTime_t)
            // NetworkVarNames: m_flFadeInStart (float32)
            // NetworkVarNames: m_flFadeInLength (float32)
            // NetworkVarNames: m_flFadeOutModelStart (float32)
            // NetworkVarNames: m_flFadeOutModelLength (float32)
            // NetworkVarNames: m_flFadeOutStart (float32)
            // NetworkVarNames: m_flFadeOutLength (float32)
            // NetworkVarNames: m_nDissolveType (EntityDisolveType_t)
            // NetworkVarNames: m_vDissolverOrigin (Vector)
            // NetworkVarNames: m_nMagnitude (uint32)
            namespace C_EntityDissolve {
                constexpr std::ptrdiff_t m_flStartTime = 0x838; // 
                constexpr std::ptrdiff_t m_flFadeInStart = 0x83C; // 
                constexpr std::ptrdiff_t m_flFadeInLength = 0x840; // 
                constexpr std::ptrdiff_t m_flFadeOutModelStart = 0x844; // 
                constexpr std::ptrdiff_t m_flFadeOutModelLength = 0x848; // 
                constexpr std::ptrdiff_t m_flFadeOutStart = 0x84C; // 
                constexpr std::ptrdiff_t m_flFadeOutLength = 0x850; // 
                constexpr std::ptrdiff_t m_flNextSparkTime = 0x854; // 
                constexpr std::ptrdiff_t m_nDissolveType = 0x858; // 
                constexpr std::ptrdiff_t m_vDissolverOrigin = 0x85C; // 
                constexpr std::ptrdiff_t m_nMagnitude = 0x868; // 
                constexpr std::ptrdiff_t m_bCoreExplode = 0x86C; // 
                constexpr std::ptrdiff_t m_bLinkedToServerEnt = 0x86D; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_hActiveProjectile (CHandle<CCitadelProjectile>)
            namespace CAbility_Mirage_Tornado {
                constexpr std::ptrdiff_t m_vLastValidMovementPosition = 0xC78; // 
                constexpr std::ptrdiff_t m_hActiveProjectile = 0xC84; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierRiotProtocolEnemyDebuffVData {
                constexpr std::ptrdiff_t m_DebuffParticle = 0x608; // 
            }
            // Parent: CCitadel_Modifier_StunnedVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Wrecker_UltimateThrowEnemyVData {
                constexpr std::ptrdiff_t m_EnemyHeroStasisEffect = 0x6E8; // 
                constexpr std::ptrdiff_t m_EnemyHeroGrabEffect = 0x7C8; // 
            }
            // Parent: CCitadel_Modifier_BaseBulletPreRollProcVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ExplosiveBulletsVData {
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x738; // 
                constexpr std::ptrdiff_t m_ExplodeSound = 0x818; // 
            }
            // Parent: None
            // Field count: 14
            //
            // Metadata:
            // NetworkVarNames: m_hCtrl (CHandle<CFogController>)
            namespace C_fogplayerparams_t {
                constexpr std::ptrdiff_t m_hCtrl = 0x8; // 
                constexpr std::ptrdiff_t m_flTransitionTime = 0xC; // 
                constexpr std::ptrdiff_t m_OldColor = 0x10; // 
                constexpr std::ptrdiff_t m_flOldStart = 0x14; // 
                constexpr std::ptrdiff_t m_flOldEnd = 0x18; // 
                constexpr std::ptrdiff_t m_flOldMaxDensity = 0x1C; // 
                constexpr std::ptrdiff_t m_flOldHDRColorScale = 0x20; // 
                constexpr std::ptrdiff_t m_flOldFarZ = 0x24; // 
                constexpr std::ptrdiff_t m_NewColor = 0x28; // 
                constexpr std::ptrdiff_t m_flNewStart = 0x2C; // 
                constexpr std::ptrdiff_t m_flNewEnd = 0x30; // 
                constexpr std::ptrdiff_t m_flNewMaxDensity = 0x34; // 
                constexpr std::ptrdiff_t m_flNewHDRColorScale = 0x38; // 
                constexpr std::ptrdiff_t m_flNewFarZ = 0x3C; // 
            }
            // Parent: C_BaseTrigger
            // Field count: 0
            namespace C_CitadelIdolReturnTrigger {
            }
            // Parent: C_BaseTrigger
            // Field count: 0
            namespace C_CitadelClimbRopeTrigger {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_Refresher {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_KnockbackAura {
            }
            // Parent: CEntitySubclassVDataBase
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelItemPickupRejuvVData {
                constexpr std::ptrdiff_t m_AbilityProjectile = 0x28; // 
                constexpr std::ptrdiff_t m_RejuvModifier = 0x38; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_PunchPickupModifier = 0x48; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_IsFrozenParticle = 0x58; // 
            }
            // Parent: None
            // Field count: 29
            //
            // Metadata:
            // NetworkVarNames: m_flStartTime (GameTime_t)
            // NetworkVarNames: m_iWindSeed (uint32)
            // NetworkVarNames: m_iMinWind (uint16)
            // NetworkVarNames: m_iMaxWind (uint16)
            // NetworkVarNames: m_windRadius (int32)
            // NetworkVarNames: m_iMinGust (uint16)
            // NetworkVarNames: m_iMaxGust (uint16)
            // NetworkVarNames: m_flMinGustDelay (float32)
            // NetworkVarNames: m_flMaxGustDelay (float32)
            // NetworkVarNames: m_flGustDuration (float32)
            // NetworkVarNames: m_iGustDirChange (uint16)
            // NetworkVarNames: m_location (Vector)
            // NetworkVarNames: m_iInitialWindDir (uint16)
            // NetworkVarNames: m_flInitialWindSpeed (float32)
            namespace C_EnvWindShared {
                constexpr std::ptrdiff_t m_flStartTime = 0x8; // 
                constexpr std::ptrdiff_t m_iWindSeed = 0xC; // 
                constexpr std::ptrdiff_t m_iMinWind = 0x10; // 
                constexpr std::ptrdiff_t m_iMaxWind = 0x12; // 
                constexpr std::ptrdiff_t m_windRadius = 0x14; // 
                constexpr std::ptrdiff_t m_iMinGust = 0x18; // 
                constexpr std::ptrdiff_t m_iMaxGust = 0x1A; // 
                constexpr std::ptrdiff_t m_flMinGustDelay = 0x1C; // 
                constexpr std::ptrdiff_t m_flMaxGustDelay = 0x20; // 
                constexpr std::ptrdiff_t m_flGustDuration = 0x24; // 
                constexpr std::ptrdiff_t m_iGustDirChange = 0x28; // 
                constexpr std::ptrdiff_t m_location = 0x2C; // 
                constexpr std::ptrdiff_t m_iszGustSound = 0x38; // 
                constexpr std::ptrdiff_t m_iWindDir = 0x3C; // 
                constexpr std::ptrdiff_t m_flWindSpeed = 0x40; // 
                constexpr std::ptrdiff_t m_currentWindVector = 0x44; // 
                constexpr std::ptrdiff_t m_CurrentSwayVector = 0x50; // 
                constexpr std::ptrdiff_t m_PrevSwayVector = 0x5C; // 
                constexpr std::ptrdiff_t m_iInitialWindDir = 0x68; // 
                constexpr std::ptrdiff_t m_flInitialWindSpeed = 0x6C; // 
                constexpr std::ptrdiff_t m_flVariationTime = 0x70; // 
                constexpr std::ptrdiff_t m_flSwayTime = 0x74; // 
                constexpr std::ptrdiff_t m_flSimTime = 0x78; // 
                constexpr std::ptrdiff_t m_flSwitchTime = 0x7C; // 
                constexpr std::ptrdiff_t m_flAveWindSpeed = 0x80; // 
                constexpr std::ptrdiff_t m_bGusting = 0x84; // 
                constexpr std::ptrdiff_t m_flWindAngleVariation = 0x88; // 
                constexpr std::ptrdiff_t m_flWindSpeedVariation = 0x8C; // 
                constexpr std::ptrdiff_t m_hEntOwner = 0x90; // 
            }
            // Parent: C_NPC_HeroCloneTrooper
            // Field count: 0
            namespace C_NPC_HeroDecoy {
            }
            // Parent: C_BaseTrigger
            // Field count: 12
            //
            // Metadata:
            // NetworkVarNames: m_hPostSettings (HPostProcessingStrong)
            // NetworkVarNames: m_flFadeDuration (float)
            // NetworkVarNames: m_flMinLogExposure (float)
            // NetworkVarNames: m_flMaxLogExposure (float)
            // NetworkVarNames: m_flMinExposure (float)
            // NetworkVarNames: m_flMaxExposure (float)
            // NetworkVarNames: m_flExposureCompensation (float)
            // NetworkVarNames: m_flExposureFadeSpeedUp (float)
            // NetworkVarNames: m_flExposureFadeSpeedDown (float)
            // NetworkVarNames: m_flTonemapEVSmoothingRange (float)
            // NetworkVarNames: m_bMaster (bool)
            // NetworkVarNames: m_bExposureControl (bool)
            namespace C_PostProcessingVolume {
                constexpr std::ptrdiff_t m_hPostSettings = 0x848; // 
                constexpr std::ptrdiff_t m_flFadeDuration = 0x850; // 
                constexpr std::ptrdiff_t m_flMinLogExposure = 0x854; // 
                constexpr std::ptrdiff_t m_flMaxLogExposure = 0x858; // 
                constexpr std::ptrdiff_t m_flMinExposure = 0x85C; // 
                constexpr std::ptrdiff_t m_flMaxExposure = 0x860; // 
                constexpr std::ptrdiff_t m_flExposureCompensation = 0x864; // 
                constexpr std::ptrdiff_t m_flExposureFadeSpeedUp = 0x868; // 
                constexpr std::ptrdiff_t m_flExposureFadeSpeedDown = 0x86C; // 
                constexpr std::ptrdiff_t m_flTonemapEVSmoothingRange = 0x870; // 
                constexpr std::ptrdiff_t m_bMaster = 0x874; // 
                constexpr std::ptrdiff_t m_bExposureControl = 0x875; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_BullCharging {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_LightningBall {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Passive_CloakVData {
                constexpr std::ptrdiff_t m_InvisModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 4
            namespace CCitadel_Modifier_UIHudMessage {
                constexpr std::ptrdiff_t m_strHudMessage = 0xC0; // 
                constexpr std::ptrdiff_t m_bIncludeDecimal = 0xC8; // 
                constexpr std::ptrdiff_t m_eModifierValue = 0xCC; // 
                constexpr std::ptrdiff_t m_flValue = 0xD0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_InShopTunnel {
            }
            // Parent: CPlayerPawnComponent
            // Field count: 0
            namespace CPlayer_FlashlightServices {
            }
            // Parent: CCitadelItemPickupRejuv
            // Field count: 0
            namespace CCitadelItemPickupRejuvHeroTest {
            }
            // Parent: C_BaseModelEntity
            // Field count: 0
            namespace CServerOnlyModelEntity {
            }
            // Parent: CCitadelModifier
            // Field count: 3
            namespace CCitadel_Modifier_IcePath {
                constexpr std::ptrdiff_t m_iShardCount = 0x2F0; // 
                constexpr std::ptrdiff_t m_vLastShardPosition = 0x2F4; // 
                constexpr std::ptrdiff_t m_hSurfShard = 0x300; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            namespace CCitadel_Ability_ChronoSwap {
                constexpr std::ptrdiff_t m_bHitTarget = 0xC78; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 8
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityCardTossVData {
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_SummonedCard = 0x1628; // 
                constexpr std::ptrdiff_t m_strCardTossSound = 0x1708; // 
                constexpr std::ptrdiff_t m_strCardSummonSound = 0x1718; // 
                constexpr std::ptrdiff_t m_flSummonedCardStartSideOffset = 0x1728; // 
                constexpr std::ptrdiff_t m_flSummonedCardSideOffsetStep = 0x172C; // 
                constexpr std::ptrdiff_t m_flSummonedCardForwardOffset = 0x1730; // 
                constexpr std::ptrdiff_t m_flSummonedCardVerticalOffset = 0x1734; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_TriggerTower {
            }
            // Parent: C_PhysicsProp
            // Field count: 0
            namespace C_ItemParachute {
            }
            // Parent: C_BaseModelEntity
            // Field count: 0
            //
            // Metadata:
            // MNetworkOverride
            // MNetworkOverride
            namespace C_FuncRotating {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_Mirage_Tornado_Aura_Apply {
            }
            // Parent: CCitadel_Modifier_Base
            // Field count: 0
            namespace CModifier_Synth_Blitz_TechAmp {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierFlyingStrikeTargetVData {
                constexpr std::ptrdiff_t m_GrappleRopeParticle = 0x608; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 10
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Nano_PredatoryStatueVData {
                constexpr std::ptrdiff_t m_AOEParticle = 0x608; // 
                constexpr std::ptrdiff_t m_EnabledParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_DrainParticle = 0x7C8; // 
                constexpr std::ptrdiff_t m_strEnabledSound = 0x8A8; // 
                constexpr std::ptrdiff_t m_strEnabledLoopSound = 0x8B8; // 
                constexpr std::ptrdiff_t m_strDisabledSound = 0x8C8; // 
                constexpr std::ptrdiff_t m_strLaserHitSound = 0x8D8; // 
                constexpr std::ptrdiff_t m_strLaserStartSound = 0x8E8; // 
                constexpr std::ptrdiff_t m_strLaserLoopSound = 0x8F8; // 
                constexpr std::ptrdiff_t m_TargetModifier = 0x908; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_SleepBomb {
                constexpr std::ptrdiff_t m_vecOrigin = 0x210; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierStackingDamageVData {
                constexpr std::ptrdiff_t m_SlowModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_BloodBomb {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierStimPakVData {
                constexpr std::ptrdiff_t m_BuffParticle = 0x608; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_MagicShock_Proc {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 6
            //
            // Metadata:
            // NetworkVarNames: m_bSprinting (bool)
            // NetworkVarNames: m_flInCombatStartTime (GameTime_t)
            // NetworkVarNames: m_flInCombatEndTime (GameTime_t)
            // NetworkVarNames: m_flSprintStartTime (GameTime_t)
            namespace CCitadel_Ability_Sprint {
                constexpr std::ptrdiff_t m_nSprintParticle = 0xC78; // 
                constexpr std::ptrdiff_t m_bSprinting = 0xC7C; // 
                constexpr std::ptrdiff_t m_flInCombatStartTime = 0xC80; // 
                constexpr std::ptrdiff_t m_flInCombatEndTime = 0xC84; // 
                constexpr std::ptrdiff_t m_flSprintStartTime = 0xC88; // 
                constexpr std::ptrdiff_t m_bInCombat = 0xC8C; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_DamageResistance {
                constexpr std::ptrdiff_t m_flShieldHealth = 0xC0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Healing_Disabled {
            }
            // Parent: C_BaseEntity
            // Field count: 4
            //
            // Metadata:
            // NetworkVarNames: m_flScale (float32)
            // NetworkVarNames: m_flStartScale (float32)
            // NetworkVarNames: m_flScaleTime (float)
            // NetworkVarNames: m_nFlags (uint32)
            namespace C_BaseFire {
                constexpr std::ptrdiff_t m_flScale = 0x558; // 
                constexpr std::ptrdiff_t m_flStartScale = 0x55C; // 
                constexpr std::ptrdiff_t m_flScaleTime = 0x560; // 
                constexpr std::ptrdiff_t m_nFlags = 0x564; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_ArmorUpgrade_DebuffReducer {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Empty {
            }
            // Parent: C_CitadelTrackedProjectile
            // Field count: 1
            namespace C_CitadelPositionHomingProjectile {
                constexpr std::ptrdiff_t m_vecHomingPosition = 0x8B8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CGameModifier_FireUserEntityIO {
            }
            // Parent: C_BaseEntity
            // Field count: 16
            //
            // Metadata:
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkUserGroupProxy
            // MNetworkUserGroupProxy
            // MNetworkIncludeByUserGroup
            // NetworkVarNames: m_nTickBase (uint32)
            // NetworkVarNames: m_hPawn (CHandle<CBasePlayerPawn>)
            // NetworkVarNames: m_bKnownTeamMismatch (bool)
            // NetworkVarNames: m_iConnected (PlayerConnectedState)
            // NetworkVarNames: m_iszPlayerName (char)
            // NetworkVarNames: m_steamID (uint64)
            // NetworkVarNames: m_iDesiredFOV (uint32)
            // MNetworkReplayCompatField
            namespace CBasePlayerController {
                constexpr std::ptrdiff_t m_nFinalPredictedTick = 0x560; // 
                constexpr std::ptrdiff_t m_CommandContext = 0x568; // 
                constexpr std::ptrdiff_t m_nInButtonsWhichAreToggles = 0x600; // 
                constexpr std::ptrdiff_t m_nTickBase = 0x608; // 
                constexpr std::ptrdiff_t m_hPawn = 0x60C; // 
                constexpr std::ptrdiff_t m_bKnownTeamMismatch = 0x610; // 
                constexpr std::ptrdiff_t m_hPredictedPawn = 0x614; // 
                constexpr std::ptrdiff_t m_nSplitScreenSlot = 0x618; // 
                constexpr std::ptrdiff_t m_hSplitOwner = 0x61C; // 
                constexpr std::ptrdiff_t m_hSplitScreenPlayers = 0x620; // 
                constexpr std::ptrdiff_t m_bIsHLTV = 0x638; // 
                constexpr std::ptrdiff_t m_iConnected = 0x63C; // 
                constexpr std::ptrdiff_t m_iszPlayerName = 0x640; // 
                constexpr std::ptrdiff_t m_steamID = 0x6C8; // 
                constexpr std::ptrdiff_t m_bIsLocalPlayerController = 0x6D0; // 
                constexpr std::ptrdiff_t m_iDesiredFOV = 0x6D4; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_GenericPerson_3 {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_HealthSwapVData {
                constexpr std::ptrdiff_t m_BloodExchangeParticle = 0x608; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Muted {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Silenced {
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_TechBleed_Proc {
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ApplyDebuff_ProcVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x638; // 
            }
            // Parent: CBaseModifier
            // Field count: 0
            namespace CCitadelModifier {
            }
            // Parent: None
            // Field count: 0
            //
            // Metadata:
            // MPulseProvideFeatureTag
            // MPulseLibraryBindings
            namespace CPointTemplateAPI {
            }
            // Parent: CBaseAnimGraph
            // Field count: 0
            namespace C_WaterBullet {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_Synth_Affliction_Debuff {
            }
            // Parent: CCitadelModifierVData
            // Field count: 6
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierGangActivityAbilitySwapVData {
                constexpr std::ptrdiff_t m_SummonGangster = 0x608; // 
                constexpr std::ptrdiff_t m_TeleportToGangster = 0x618; // 
                constexpr std::ptrdiff_t m_Cancel = 0x628; // 
                constexpr std::ptrdiff_t m_ReplaceWithSummonGangster = 0x638; // 
                constexpr std::ptrdiff_t m_ReplaceWithTeleportToGangster = 0x648; // 
                constexpr std::ptrdiff_t m_ReplaceWithCancel = 0x658; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 10
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierRestorativeGooVData {
                constexpr std::ptrdiff_t m_RestorativeGooEndParticle = 0x608; // 
                constexpr std::ptrdiff_t m_flDistanceCameraOffsetLerpTime = 0x6E8; // 
                constexpr std::ptrdiff_t m_flDistanceCameraOffsetBias = 0x6EC; // 
                constexpr std::ptrdiff_t m_flDistanceCameraOffset = 0x6F0; // 
                constexpr std::ptrdiff_t m_BreakoutProgressBarModifier = 0x6F8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_PostCubeBuffModifier = 0x708; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_NonTargetLoopingSound = 0x718; // 
                constexpr std::ptrdiff_t m_TargetLoopingSound = 0x728; // 
                constexpr std::ptrdiff_t m_LightMeleeImpact = 0x738; // 
                constexpr std::ptrdiff_t m_HeavyMeleeImpact = 0x748; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Chrono_PulseGrenade_Debuff {
            }
            // Parent: CCitadelModifier
            // Field count: 5
            namespace CCitadel_Modifier_BeltFed_Magazine {
                constexpr std::ptrdiff_t m_bInitialized = 0xC0; // 
                constexpr std::ptrdiff_t m_flSpinUpRateOverride = 0xC4; // 
                constexpr std::ptrdiff_t m_flSpinUpDecayOverride = 0xC8; // 
                constexpr std::ptrdiff_t m_flMaxCycleTimeOverride = 0xCC; // 
                constexpr std::ptrdiff_t m_flMaxBurstFireCooldownOverride = 0xD0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ItemWalkBack {
            }
            // Parent: CSkeletonAnimationController
            // Field count: 14
            //
            // Metadata:
            // NetworkVarNames: m_animGraphNetworkedVars (CAnimGraphNetworkedVariables)
            // NetworkVarNames: m_hSequence (HSequence)
            // NetworkVarNames: m_flSeqStartTime (GameTime_t)
            // NetworkVarNames: m_flSeqFixedCycle (float)
            // NetworkVarNames: m_nAnimLoopMode (AnimLoopMode_t)
            namespace CBaseAnimGraphController {
                constexpr std::ptrdiff_t m_animGraphNetworkedVars = 0x18; // 
                constexpr std::ptrdiff_t m_bSequenceFinished = 0x14A8; // 
                constexpr std::ptrdiff_t m_flSoundSyncTime = 0x14AC; // 
                constexpr std::ptrdiff_t m_nActiveIKChainMask = 0x14B0; // 
                constexpr std::ptrdiff_t m_hSequence = 0x14B4; // 
                constexpr std::ptrdiff_t m_flSeqStartTime = 0x14B8; // 
                constexpr std::ptrdiff_t m_flSeqFixedCycle = 0x14BC; // 
                constexpr std::ptrdiff_t m_nAnimLoopMode = 0x14C0; // 
                constexpr std::ptrdiff_t m_flPlaybackRate = 0x14C4; // 
                constexpr std::ptrdiff_t m_nNotifyState = 0x14D0; // 
                constexpr std::ptrdiff_t m_bNetworkedAnimationInputsChanged = 0x14D2; // 
                constexpr std::ptrdiff_t m_bNetworkedSequenceChanged = 0x14D3; // 
                constexpr std::ptrdiff_t m_bLastUpdateSkipped = 0x14D4; // 
                constexpr std::ptrdiff_t m_flPrevAnimUpdateTime = 0x14D8; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 4
            //
            // Metadata:
            // NetworkVarNames: m_flPostCastHoldEndTime (GameTime_t)
            namespace CCitadel_Ability_HealthSwap {
                constexpr std::ptrdiff_t m_nFXIndex = 0xC78; // 
                constexpr std::ptrdiff_t m_flHealthToCaster = 0xC7C; // 
                constexpr std::ptrdiff_t m_flTargetHealthLost = 0xC80; // 
                constexpr std::ptrdiff_t m_flPostCastHoldEndTime = 0xDA0; // 
            }
            // Parent: CCitadel_Modifier_ChainLightningVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Galvanic_Storm_VData {
                constexpr std::ptrdiff_t m_TechShieldModifier = 0x828; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 3
            namespace CCitadel_Modifier_Push {
                constexpr std::ptrdiff_t m_vPushForce = 0xC0; // 
                constexpr std::ptrdiff_t m_flDecayRate = 0xCC; // 
                constexpr std::ptrdiff_t m_TimeDestroy = 0xD0; // 
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_Hero_Testing_Damage_Aura {
            }
            // Parent: CModifierVData_BaseAura
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelModifierAuraVData {
                constexpr std::ptrdiff_t m_iAuraSearchType = 0x640; // 
                constexpr std::ptrdiff_t m_iAuraSearchFlags = 0x644; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 8
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbility_Synth_Barrage_VData {
                constexpr std::ptrdiff_t m_BarrageCasterModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_AmpModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1568; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ShootParticle = 0x1578; // 
                constexpr std::ptrdiff_t m_ImpactParticle = 0x1658; // 
                constexpr std::ptrdiff_t m_ChannelParticle = 0x1738; // 
                constexpr std::ptrdiff_t m_strProjectileLaunchSound = 0x1818; // 
                constexpr std::ptrdiff_t m_flAttackInterval = 0x1828; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierUppercuttedVData {
                constexpr std::ptrdiff_t m_StunParticle = 0x608; // 
                constexpr std::ptrdiff_t m_strStunSound = 0x6E8; // 
                constexpr std::ptrdiff_t m_NoExplodeModifier = 0x6F8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_flEnemyNoAirDashDuration = 0x708; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_PsychicDagger {
            }
            // Parent: C_BaseModelEntity
            // Field count: 15
            //
            // Metadata:
            // MNetworkIncludeByName
            // NetworkVarNames: m_bInitiallyPopulateInterpHistory (bool)
            // NetworkVarNames: m_bAnimGraphUpdateEnabled (bool)
            // NetworkVarNames: m_vecForce (Vector)
            // NetworkVarNames: m_nForceBone (int32)
            // NetworkVarNames: m_RagdollPose (PhysicsRagdollPose_t)
            // NetworkVarNames: m_bRagdollClientSide (bool)
            // NetworkVarNames: m_animGraph2SerializeData (uint8)
            // NetworkVarNames: m_nAnimGraph2SerializeDataSizeBytes (int)
            namespace CBaseAnimGraph {
                constexpr std::ptrdiff_t m_bInitiallyPopulateInterpHistory = 0x8B0; // 
                constexpr std::ptrdiff_t m_bSuppressAnimEventSounds = 0x8B2; // 
                constexpr std::ptrdiff_t m_bAnimGraphUpdateEnabled = 0x8C0; // 
                constexpr std::ptrdiff_t m_flMaxSlopeDistance = 0x8C4; // 
                constexpr std::ptrdiff_t m_vLastSlopeCheckPos = 0x8C8; // 
                constexpr std::ptrdiff_t m_bAnimationUpdateScheduled = 0x8D4; // 
                constexpr std::ptrdiff_t m_vecForce = 0x8D8; // 
                constexpr std::ptrdiff_t m_nForceBone = 0x8E4; // 
                constexpr std::ptrdiff_t m_pClientsideRagdoll = 0x8E8; // 
                constexpr std::ptrdiff_t m_bBuiltRagdoll = 0x8F0; // 
                constexpr std::ptrdiff_t m_RagdollPose = 0x908; // 
                constexpr std::ptrdiff_t m_bRagdollClientSide = 0x950; // 
                constexpr std::ptrdiff_t m_bHasAnimatedMaterialAttributes = 0x960; // 
                constexpr std::ptrdiff_t m_animGraph2SerializeData = 0xAA8; // 
                constexpr std::ptrdiff_t m_nAnimGraph2SerializeDataSizeBytes = 0xAC0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Tokamak_HeatSinks_DOT_VData {
                constexpr std::ptrdiff_t m_sAfterburnParticle = 0x608; // 
                constexpr std::ptrdiff_t m_sAfterburnExplodeParticle = 0x6E8; // 
            }
            // Parent: CAbilityMeleeVData
            // Field count: 5
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityUppercutVData {
                constexpr std::ptrdiff_t m_UppercutAttackData = 0x1560; // AttackData_t
                constexpr std::ptrdiff_t m_UppercutModifier = 0x1A88; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BuffModifier = 0x1A98; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ClipModifier = 0x1AA8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_flMaxPitchUp = 0x1AB8; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Gravity_Lasso {
            }
            // Parent: CCitadelModifierVData
            // Field count: 6
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_IceDomeVData {
                constexpr std::ptrdiff_t m_BlockerModel = 0x608; // 
                constexpr std::ptrdiff_t m_DomeParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_FriendlyAuraModifier = 0x7C8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_EnemyAuraModifier = 0x7D8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_strDomeEndSound = 0x7E8; // 
                constexpr std::ptrdiff_t m_strTargetLoopingSound = 0x7F8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ImmobilizeTrapDOT_Thinker {
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_HealthSwapPrecast {
                constexpr std::ptrdiff_t m_hTarget = 0xC0; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_StaticChargeVData {
                constexpr std::ptrdiff_t m_CastParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_StaticChargeModifier = 0x1628; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_MeleeDamageOnly {
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CModifier_Mirage_Tornado_Aura {
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_MobileResupplyAura {
            }
            // Parent: C_CitadelProjectile
            // Field count: 0
            namespace C_Citadel_Projectile_Guided_Arrow {
            }
            // Parent: C_BaseEntity
            // Field count: 0
            namespace C_PointEntity {
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_IceDomeVData {
                constexpr std::ptrdiff_t m_IceDomeModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierLashFlogDebuffVData {
                constexpr std::ptrdiff_t m_FlogDebuffParticle = 0x608; // 
            }
            // Parent: C_GameRules
            // Field count: 0
            namespace C_MultiplayRules {
            }
            // Parent: None
            // Field count: 0
            //
            // Metadata:
            // MPulseProvideFeatureTag
            // MPulseLibraryBindings
            namespace CBasePlayerControllerAPI {
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_ControlPointBlockerAura {
            }
            // Parent: CCitadel_Item
            // Field count: 1
            namespace CCitadel_Item_WarpStone {
                constexpr std::ptrdiff_t m_nCastDelayParticleIndex = 0xC90; // 
            }
            // Parent: CCitadel_Item
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_iStacks (int)
            namespace CCitadel_WeaponUpgrade_SiphonBullets {
                constexpr std::ptrdiff_t m_iStacks = 0xC90; // 
            }
            // Parent: C_BaseEntity
            // Field count: 16
            //
            // Metadata:
            // NetworkVarNames: m_flParticleSpacing (float)
            // NetworkVarNames: m_flSlack (float)
            // NetworkVarNames: m_flRadius (float)
            // NetworkVarNames: m_ColorTint (Color)
            // NetworkVarNames: m_nEffectState (int)
            // NetworkVarNames: m_iEffectIndex (HParticleSystemDefinitionStrong)
            // NetworkVarNames: m_PathNodes_Position (Vector)
            // NetworkVarNames: m_PathNodes_TangentIn (Vector)
            // NetworkVarNames: m_PathNodes_TangentOut (Vector)
            // NetworkVarNames: m_PathNodes_Color (Vector)
            // NetworkVarNames: m_PathNodes_PinEnabled (bool)
            // NetworkVarNames: m_PathNodes_RadiusScale (float)
            namespace C_PathParticleRope {
                constexpr std::ptrdiff_t m_bStartActive = 0x560; // 
                constexpr std::ptrdiff_t m_flMaxSimulationTime = 0x564; // 
                constexpr std::ptrdiff_t m_iszEffectName = 0x568; // 
                constexpr std::ptrdiff_t m_PathNodes_Name = 0x570; // 
                constexpr std::ptrdiff_t m_flParticleSpacing = 0x588; // 
                constexpr std::ptrdiff_t m_flSlack = 0x58C; // 
                constexpr std::ptrdiff_t m_flRadius = 0x590; // 
                constexpr std::ptrdiff_t m_ColorTint = 0x594; // 
                constexpr std::ptrdiff_t m_nEffectState = 0x598; // 
                constexpr std::ptrdiff_t m_iEffectIndex = 0x5A0; // 
                constexpr std::ptrdiff_t m_PathNodes_Position = 0x5A8; // 
                constexpr std::ptrdiff_t m_PathNodes_TangentIn = 0x5C0; // 
                constexpr std::ptrdiff_t m_PathNodes_TangentOut = 0x5D8; // 
                constexpr std::ptrdiff_t m_PathNodes_Color = 0x5F0; // 
                constexpr std::ptrdiff_t m_PathNodes_PinEnabled = 0x608; // 
                constexpr std::ptrdiff_t m_PathNodes_RadiusScale = 0x620; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_RapidFire {
                constexpr std::ptrdiff_t m_flNextAttackTime = 0x210; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ThrownShiv_Slow_Debuff {
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_SilencedVData {
                constexpr std::ptrdiff_t m_EmpParticle = 0x608; // 
                constexpr std::ptrdiff_t m_EmpPlayerParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_EmpStatusParticle = 0x7C8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_BulletShieldImpact {
                constexpr std::ptrdiff_t m_AmbientEffect = 0xC0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Backdoor_Protection {
            }
            // Parent: CAI_CitadelNPCVData
            // Field count: 32
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CNPC_TrooperNeutralVData {
                constexpr std::ptrdiff_t m_eTrooperType = 0xF60; // 
                constexpr std::ptrdiff_t m_flGoldReward = 0xF64; // 
                constexpr std::ptrdiff_t m_flGoldRewardBonusPercentPerMinute = 0xF68; // 
                constexpr std::ptrdiff_t m_bGiveGoldOnHit = 0xF6C; // 
                constexpr std::ptrdiff_t m_bOrbDropper = 0xF6D; // 
                constexpr std::ptrdiff_t m_bCapSimultanousAttackers = 0xF6E; // 
                constexpr std::ptrdiff_t m_flShieldReactivateDelay = 0xF70; // 
                constexpr std::ptrdiff_t m_flDyingDuration = 0xF74; // 
                constexpr std::ptrdiff_t m_bDamagedByBullets = 0xF78; // 
                constexpr std::ptrdiff_t m_bDamagedByMelee = 0xF79; // 
                constexpr std::ptrdiff_t m_bDamagedByAbilities = 0xF7A; // 
                constexpr std::ptrdiff_t m_bFixedMeleeDamage = 0xF7B; // 
                constexpr std::ptrdiff_t m_ShieldParticle = 0xF80; // 
                constexpr std::ptrdiff_t m_flRetaliateDamage = 0x1060; // 
                constexpr std::ptrdiff_t m_flRetaliateCooldown = 0x1064; // 
                constexpr std::ptrdiff_t m_retaliateParticle = 0x1068; // 
                constexpr std::ptrdiff_t m_bHasAOEAttack = 0x1148; // 
                constexpr std::ptrdiff_t m_flAOERadius = 0x114C; // 
                constexpr std::ptrdiff_t m_flAOEDamage = 0x1150; // 
                constexpr std::ptrdiff_t m_flAOEAttackCooldown = 0x1154; // 
                constexpr std::ptrdiff_t m_AOEParticle = 0x1158; // 
                constexpr std::ptrdiff_t m_AOEDebuffToApply = 0x1238; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_AOEInitiateSound = 0x1248; // 
                constexpr std::ptrdiff_t m_AOESound = 0x1258; // 
                constexpr std::ptrdiff_t m_AOEDebuffDuration = 0x1268; // 
                constexpr std::ptrdiff_t m_vecRandomBodyGroup = 0x1270; // 
                constexpr std::ptrdiff_t m_vecRandomSkin = 0x1288; // 
                constexpr std::ptrdiff_t m_flHullCapsuleRadius = 0x12A0; // 
                constexpr std::ptrdiff_t m_flHullCapsuleHeight = 0x12A4; // 
                constexpr std::ptrdiff_t m_bFaceEnemyWhileIdle = 0x12A8; // 
                constexpr std::ptrdiff_t m_IdleLoopSound = 0x12B0; // 
                constexpr std::ptrdiff_t m_MoveType = 0x12C0; // 
            }
            // Parent: C_CitadelProjectile
            // Field count: 0
            namespace CCitadel_Projectile_RocketLauncher_Rocket {
            }
            // Parent: CCitadel_Ability_BaseHeldItem
            // Field count: 0
            namespace CCitadel_Ability_GoldenIdol {
            }
            // Parent: C_BaseModelEntity
            // Field count: 17
            //
            // Metadata:
            // MNetworkIncludeByName
            // MNetworkOverride
            // MNetworkOverride
            // NetworkVarNames: m_vInitialVelocity (Vector)
            // NetworkVarNames: m_vInitialPosition (Vector)
            // NetworkVarNames: m_abilityID (AbilityID_t)
            // NetworkVarNames: m_hThrower (EHANDLE)
            // NetworkVarNames: m_sParticleName (string_t)
            // NetworkVarNames: m_vecSpawnPosition (Vector)
            // NetworkVarNames: m_flProjectileSpeed (float)
            // NetworkVarNames: m_flMaxLifetime (float)
            namespace C_CitadelProjectile {
                constexpr std::ptrdiff_t m_hTarget = 0x83C; // 
                constexpr std::ptrdiff_t m_flMaxDistance = 0x840; // 
                constexpr std::ptrdiff_t m_flArmingTime = 0x844; // 
                constexpr std::ptrdiff_t m_flChargeAmount = 0x848; // 
                constexpr std::ptrdiff_t m_bCollideWithThrower = 0x84C; // 
                constexpr std::ptrdiff_t m_bNewCollideWithThrower = 0x84D; // 
                constexpr std::ptrdiff_t m_flTickSoundInterval = 0x858; // 
                constexpr std::ptrdiff_t m_vInitialVelocity = 0x860; // 
                constexpr std::ptrdiff_t m_vInitialPosition = 0x86C; // 
                constexpr std::ptrdiff_t m_abilityID = 0x878; // 
                constexpr std::ptrdiff_t m_hThrower = 0x87C; // 
                constexpr std::ptrdiff_t m_sParticleName = 0x880; // 
                constexpr std::ptrdiff_t m_vecSpawnPosition = 0x888; // 
                constexpr std::ptrdiff_t m_flProjectileSpeed = 0x894; // 
                constexpr std::ptrdiff_t m_flMaxLifetime = 0x898; // 
                constexpr std::ptrdiff_t m_flParticleRadius = 0x8A0; // 
                constexpr std::ptrdiff_t m_flPreviousTimeScale = 0x8B0; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Targetdummy_3 {
            }
            // Parent: CCitadelModifier
            // Field count: 2
            namespace CCitadel_Modifier_StaticCharge {
                constexpr std::ptrdiff_t m_hRingEffect = 0xC0; // 
                constexpr std::ptrdiff_t m_flRadius = 0x138; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_Upgrade_KineticSash {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_ArmorUpgrade_CloakingDevice {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_ArmorUpgrade_RegenerativeArmor {
            }
            // Parent: C_SoundEventEntity
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_vMins (Vector)
            // NetworkVarNames: m_vMaxs (Vector)
            namespace C_SoundEventAABBEntity {
                constexpr std::ptrdiff_t m_vMins = 0x618; // 
                constexpr std::ptrdiff_t m_vMaxs = 0x624; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Citadel_Bull_Leap_LandingBonuses_VData {
                constexpr std::ptrdiff_t m_BuffParticle = 0x608; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 23
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityDashVData {
                constexpr std::ptrdiff_t m_DashParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_DownDashParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_strArriveSound = 0x1708; // 
                constexpr std::ptrdiff_t m_strStaminaDrainedSound = 0x1718; // 
                constexpr std::ptrdiff_t m_cameraSequenceGroundDashActivate = 0x1728; // CitadelCameraOperationsSequence_t
                constexpr std::ptrdiff_t m_cameraSequenceAirDashActivate = 0x17B0; // CitadelCameraOperationsSequence_t
                constexpr std::ptrdiff_t m_flMaxAngDiff = 0x1838; // 
                constexpr std::ptrdiff_t m_flDurationScaleForSpeed = 0x183C; // 
                constexpr std::ptrdiff_t m_flSlideEarlyOutWindow = 0x1840; // 
                constexpr std::ptrdiff_t m_flSlideLockoutTime = 0x1844; // 
                constexpr std::ptrdiff_t m_flGroundDashAirbornDrag = 0x1848; // 
                constexpr std::ptrdiff_t m_flGroundDashAirbornSpeedClamp = 0x184C; // 
                constexpr std::ptrdiff_t m_strGroundDashActivate = 0x1850; // 
                constexpr std::ptrdiff_t m_curvePosition = 0x1860; // 
                constexpr std::ptrdiff_t m_flGroundDashDuration = 0x18A0; // 
                constexpr std::ptrdiff_t m_flGroundDashDistanceInMeters = 0x18A4; // 
                constexpr std::ptrdiff_t m_flAirDashEndVelocityScale = 0x18A8; // 
                constexpr std::ptrdiff_t m_flAirDashAccPct = 0x18AC; // 
                constexpr std::ptrdiff_t m_flDuringDrag = 0x18B0; // 
                constexpr std::ptrdiff_t m_flPostDrag = 0x18B4; // 
                constexpr std::ptrdiff_t m_flPostDragDuration = 0x18B8; // 
                constexpr std::ptrdiff_t m_flDownwardAirDashSpeed = 0x18BC; // 
                constexpr std::ptrdiff_t m_strDashActivate = 0x18C0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_DebuffImmunity {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ConsumedProtectionRacketVData {
                constexpr std::ptrdiff_t m_strShieldBreakSound = 0x608; // 
            }
            // Parent: CCitadel_Modifier_Stunned
            // Field count: 1
            namespace CCitadel_Modifier_Wrecker_Ultimate_ThrowEnemy {
                constexpr std::ptrdiff_t m_vThrowVelocity = 0xC8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_WreckerSalvage_Buff {
                constexpr std::ptrdiff_t m_nBuffParticle = 0xC0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 3
            namespace CCitadel_Modifier_StickyBombAttached {
                constexpr std::ptrdiff_t m_bDetonateSoundStarted = 0xC0; // 
                constexpr std::ptrdiff_t m_flDamage = 0xCC; // 
                constexpr std::ptrdiff_t m_nParticleIndex = 0xD0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ViscousBallVData {
                constexpr std::ptrdiff_t m_TrailParticle = 0x608; // 
                constexpr std::ptrdiff_t m_DirectionParticle = 0x6E8; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityNikumanVData {
                constexpr std::ptrdiff_t m_NikumanModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_SelfBuffModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelItemVData
            // Field count: 6
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CItem_ActiveReload_VData {
                constexpr std::ptrdiff_t m_SuccessModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_strSuccessSound = 0x15A0; // 
                constexpr std::ptrdiff_t m_strFailureSound = 0x15B0; // 
                constexpr std::ptrdiff_t m_SuccessParticle = 0x15C0; // 
                constexpr std::ptrdiff_t m_FailureParticle = 0x16A0; // 
                constexpr std::ptrdiff_t m_flGraceTime = 0x1780; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 10
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CitadelItemVData {
                constexpr std::ptrdiff_t m_iItemTier = 0x154C; // 
                constexpr std::ptrdiff_t m_nUpgradeSlotCost = 0x154D; // 
                constexpr std::ptrdiff_t m_bWarnIfNoAffectedAbilities = 0x154E; // 
                constexpr std::ptrdiff_t m_bRequiresChargedAbility = 0x154F; // 
                constexpr std::ptrdiff_t m_bRequiresChanelledAbility = 0x1550; // 
                constexpr std::ptrdiff_t m_vecComponentItems = 0x1558; // 
                constexpr std::ptrdiff_t m_bShowTextDescription = 0x1570; // 
                constexpr std::ptrdiff_t m_bIsDefensiveItem = 0x1571; // 
                constexpr std::ptrdiff_t m_eShopFilters = 0x1572; // 
                constexpr std::ptrdiff_t m_vecTooltipSectionInfo = 0x1578; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Near_Climbable_RopeVData {
                constexpr std::ptrdiff_t m_flEnableStateTime = 0x608; // 
            }
            // Parent: C_BaseModelEntity
            // Field count: 8
            //
            // Metadata:
            // NetworkVarNames: m_hLocalPortalLink (EHANDLE)
            // NetworkVarNames: m_hRemotePortalLink (EHANDLE)
            // NetworkVarNames: m_brushModelName (CUtlString)
            // NetworkVarNames: m_flFadeStartDist (float)
            // NetworkVarNames: m_flFadeEndDist (float)
            // NetworkVarNames: m_flFadeStartAngle (float)
            // NetworkVarNames: m_flFadeEndAngle (float)
            // NetworkVarNames: m_fadeToColor (Color)
            namespace C_RenderPortal {
                constexpr std::ptrdiff_t m_hLocalPortalLink = 0x830; // 
                constexpr std::ptrdiff_t m_hRemotePortalLink = 0x834; // 
                constexpr std::ptrdiff_t m_brushModelName = 0x838; // 
                constexpr std::ptrdiff_t m_flFadeStartDist = 0x840; // 
                constexpr std::ptrdiff_t m_flFadeEndDist = 0x844; // 
                constexpr std::ptrdiff_t m_flFadeStartAngle = 0x848; // 
                constexpr std::ptrdiff_t m_flFadeEndAngle = 0x84C; // 
                constexpr std::ptrdiff_t m_fadeToColor = 0x850; // 
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_FlameDashGroundAuraVData {
                constexpr std::ptrdiff_t m_GroundParticle = 0x648; // 
                constexpr std::ptrdiff_t m_flHeight = 0x728; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_QuickSilver {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_AOE_Tech_Shield {
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CGameModifier_SetMoveType {
                constexpr std::ptrdiff_t m_nMoveType = 0xC0; // 
            }
            // Parent: CCitadel_Modifier_Base
            // Field count: 0
            namespace CCitadel_Modifier_TangoTetherTarget {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_PristineEmblem {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Objective_Bullet_Resist {
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_Tokamak_AllySmokeAOE {
            }
            // Parent: CCitadel_Item_TrackingProjectileApplyModifier
            // Field count: 0
            namespace CCitadel_Item_Disarm {
            }
            // Parent: CCitadelModifierVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Synth_Barrage_Caster_VData {
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityGangActivityCancelVData {
                constexpr std::ptrdiff_t m_AbilitySwap = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 5
            namespace CCitadel_Modifier_HookTarget {
                constexpr std::ptrdiff_t m_flCurrentVerticalSpeed = 0xC4; // 
                constexpr std::ptrdiff_t m_bSuccess = 0xC8; // 
                constexpr std::ptrdiff_t m_bSameTeam = 0xC9; // 
                constexpr std::ptrdiff_t m_bPlayedApproachingWhoosh = 0xCA; // 
                constexpr std::ptrdiff_t m_flInitialTravelDistance = 0xCC; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilitySleepDaggerVData {
                constexpr std::ptrdiff_t m_ImpactParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_SleepModifier = 0x1628; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DrowsyModifier = 0x1638; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_SleepBombModifier = 0x1648; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityLashFlogVData {
                constexpr std::ptrdiff_t m_FlogParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_FlogLifeLeachParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_FlogDebuffModifier = 0x1708; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_BoxingGlove {
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Inhibitor_ProcVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x638; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_BaseBulletPreRollProc
            // Field count: 1
            namespace CCitadel_Modifier_ChainLightning {
                constexpr std::ptrdiff_t m_flNextProcTime = 0x1C0; // 
            }
            // Parent: CBaseAnimGraph
            // Field count: 7
            //
            // Metadata:
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkIncludeByName
            // MNetworkExcludeByUserGroup
            // MNetworkExcludeByUserGroup
            // MNetworkExcludeByUserGroup
            // MNetworkUserGroupProxy
            // NetworkVarNames: m_nNextPrimaryAttackTick (GameTick_t)
            // NetworkVarNames: m_flNextPrimaryAttackTickRatio (float32)
            // NetworkVarNames: m_nNextSecondaryAttackTick (GameTick_t)
            // NetworkVarNames: m_flNextSecondaryAttackTickRatio (float32)
            // NetworkVarNames: m_iClip1 (int32)
            // NetworkVarNames: m_iClip2 (int32)
            // NetworkVarNames: m_pReserveAmmo (int)
            namespace C_BasePlayerWeapon {
                constexpr std::ptrdiff_t m_nNextPrimaryAttackTick = 0xB50; // 
                constexpr std::ptrdiff_t m_flNextPrimaryAttackTickRatio = 0xB54; // 
                constexpr std::ptrdiff_t m_nNextSecondaryAttackTick = 0xB58; // 
                constexpr std::ptrdiff_t m_flNextSecondaryAttackTickRatio = 0xB5C; // 
                constexpr std::ptrdiff_t m_iClip1 = 0xB60; // 
                constexpr std::ptrdiff_t m_iClip2 = 0xB64; // 
                constexpr std::ptrdiff_t m_pReserveAmmo = 0xB68; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_UtilityUpgrade_HealthNova {
            }
            // Parent: CCitadelYamatoBaseVData
            // Field count: 9
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelAbilityHealingSlashVData {
                constexpr std::ptrdiff_t m_flEffectSize = 0x1550; // 
                constexpr std::ptrdiff_t m_flMaxAttackAngle = 0x1554; // 
                constexpr std::ptrdiff_t m_remapAngleToTime = 0x1558; // 
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1568; // 
                constexpr std::ptrdiff_t m_ImpactParticle = 0x1578; // 
                constexpr std::ptrdiff_t m_HealingSlashParticle = 0x1658; // 
                constexpr std::ptrdiff_t m_HealingSlashSwordGlow = 0x1738; // 
                constexpr std::ptrdiff_t m_CastParticle = 0x1818; // 
                constexpr std::ptrdiff_t m_strDamageTarget = 0x18F8; // 
            }
            // Parent: None
            // Field count: 24
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CBasePlayerWeaponVData {
                constexpr std::ptrdiff_t m_szClassName = 0x10; // 
                constexpr std::ptrdiff_t m_szWorldModel = 0x18; // 
                constexpr std::ptrdiff_t m_sToolsOnlyOwnerModelName = 0xF8; // 
                constexpr std::ptrdiff_t m_bBuiltRightHanded = 0x1D8; // 
                constexpr std::ptrdiff_t m_bAllowFlipping = 0x1D9; // 
                constexpr std::ptrdiff_t m_sMuzzleAttachment = 0x1E0; // CAttachmentNameSymbolWithStorage
                constexpr std::ptrdiff_t m_szMuzzleFlashParticle = 0x200; // 
                constexpr std::ptrdiff_t m_bLinkedCooldowns = 0x2E0; // 
                constexpr std::ptrdiff_t m_vecIntrinsicModifiers = 0x2E8; // 
                constexpr std::ptrdiff_t m_iFlags = 0x300; // 
                constexpr std::ptrdiff_t m_nPrimaryAmmoType = 0x301; // 
                constexpr std::ptrdiff_t m_nSecondaryAmmoType = 0x302; // 
                constexpr std::ptrdiff_t m_iMaxClip1 = 0x304; // 
                constexpr std::ptrdiff_t m_iMaxClip2 = 0x308; // 
                constexpr std::ptrdiff_t m_iDefaultClip1 = 0x30C; // 
                constexpr std::ptrdiff_t m_iDefaultClip2 = 0x310; // 
                constexpr std::ptrdiff_t m_bReserveAmmoAsClips = 0x314; // 
                constexpr std::ptrdiff_t m_iWeight = 0x318; // 
                constexpr std::ptrdiff_t m_bAutoSwitchTo = 0x31C; // 
                constexpr std::ptrdiff_t m_bAutoSwitchFrom = 0x31D; // 
                constexpr std::ptrdiff_t m_iRumbleEffect = 0x320; // 
                constexpr std::ptrdiff_t m_iSlot = 0x324; // 
                constexpr std::ptrdiff_t m_iPosition = 0x328; // 
                constexpr std::ptrdiff_t m_aShootSounds = 0x330; // 
            }
            // Parent: CBaseAnimGraph
            // Field count: 23
            //
            // Metadata:
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // NetworkVarNames: m_poolOrigin (Vector)
            // NetworkVarNames: m_waterLevel (float32)
            // NetworkVarNames: m_x (float32)
            // NetworkVarNames: m_y (float32)
            // NetworkVarNames: m_z (float32)
            // NetworkVarNames: m_angle (float32)
            namespace C_Fish {
                constexpr std::ptrdiff_t m_pos = 0xB50; // 
                constexpr std::ptrdiff_t m_vel = 0xB5C; // 
                constexpr std::ptrdiff_t m_angles = 0xB68; // 
                constexpr std::ptrdiff_t m_localLifeState = 0xB74; // 
                constexpr std::ptrdiff_t m_deathDepth = 0xB78; // 
                constexpr std::ptrdiff_t m_deathAngle = 0xB7C; // 
                constexpr std::ptrdiff_t m_buoyancy = 0xB80; // 
                constexpr std::ptrdiff_t m_wiggleTimer = 0xB88; // 
                constexpr std::ptrdiff_t m_wigglePhase = 0xBA0; // 
                constexpr std::ptrdiff_t m_wiggleRate = 0xBA4; // 
                constexpr std::ptrdiff_t m_actualPos = 0xBA8; // 
                constexpr std::ptrdiff_t m_actualAngles = 0xBB4; // 
                constexpr std::ptrdiff_t m_poolOrigin = 0xBC0; // 
                constexpr std::ptrdiff_t m_waterLevel = 0xBCC; // 
                constexpr std::ptrdiff_t m_gotUpdate = 0xBD0; // 
                constexpr std::ptrdiff_t m_x = 0xBD4; // 
                constexpr std::ptrdiff_t m_y = 0xBD8; // 
                constexpr std::ptrdiff_t m_z = 0xBDC; // 
                constexpr std::ptrdiff_t m_angle = 0xBE0; // 
                constexpr std::ptrdiff_t m_errorHistory = 0xBE4; // 
                constexpr std::ptrdiff_t m_errorHistoryIndex = 0xC34; // 
                constexpr std::ptrdiff_t m_errorHistoryCount = 0xC38; // 
                constexpr std::ptrdiff_t m_averageError = 0xC3C; // 
            }
            // Parent: C_CitadelProjectile
            // Field count: 0
            namespace C_Citadel_Projectile_Archer_ChargedShot {
            }
            // Parent: CCitadelModifierAura
            // Field count: 3
            namespace CCitadel_Modifier_Item_AOESilence {
                constexpr std::ptrdiff_t m_flStartRadius = 0xE0; // 
                constexpr std::ptrdiff_t m_flEndRadius = 0xE4; // 
                constexpr std::ptrdiff_t m_flSpreadDuration = 0xE8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Shiv_KillingBlow_Leap {
            }
            // Parent: CitadelAbilityVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityLightningBallVData {
                constexpr std::ptrdiff_t m_ZapModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_strHitSound = 0x1558; // 
                constexpr std::ptrdiff_t m_strProjectileLoopingSound = 0x1568; // 
                constexpr std::ptrdiff_t m_ZapParticle = 0x1578; // 
            }
            // Parent: CScaleFunctionVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CScaleFunctionAbilityPropertySingleStatVData {
            }
            // Parent: IntervalTimer
            // Field count: 7
            //
            // Metadata:
            // NetworkVarNames: m_flValues (float)
            // NetworkVarNames: m_nValueCounts (int)
            // NetworkVarNames: m_nBucketCount (int)
            // NetworkVarNames: m_flInterval (float)
            // NetworkVarNames: m_flFinalValue (float)
            // NetworkVarNames: m_nCompressionType (TimelineCompression_t)
            // NetworkVarNames: m_bStopped (bool)
            namespace CTimeline {
                constexpr std::ptrdiff_t m_flValues = 0x10; // 
                constexpr std::ptrdiff_t m_nValueCounts = 0x110; // 
                constexpr std::ptrdiff_t m_nBucketCount = 0x210; // 
                constexpr std::ptrdiff_t m_flInterval = 0x214; // 
                constexpr std::ptrdiff_t m_flFinalValue = 0x218; // 
                constexpr std::ptrdiff_t m_nCompressionType = 0x21C; // 
                constexpr std::ptrdiff_t m_bStopped = 0x220; // 
            }
            // Parent: CBaseAnimGraph
            // Field count: 0
            namespace C_Citadel_DeployablePreview {
            }
            // Parent: CCitadelModifierAura
            // Field count: 1
            namespace CCitadel_Item_StasisBomb_Aura {
                constexpr std::ptrdiff_t m_AuraRadius = 0xE0; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Targetdummy_1 {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_SettingSunThinker {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierHighAlertBuffVData {
                constexpr std::ptrdiff_t m_BuffParticle = 0x608; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityTrappersBoloVData {
                constexpr std::ptrdiff_t m_ImpactParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_TrapModifier = 0x1628; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1638; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_DisarmProcWatcher {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_RevealTarget {
            }
            // Parent: C_BaseEntity
            // Field count: 1
            namespace CPathAccompany {
                constexpr std::ptrdiff_t m_vecNodes = 0x558; // CUtlVector<PathAccompanyNode_t>
            }
            // Parent: C_BaseCombatCharacter
            // Field count: 28
            //
            // Metadata:
            // MNetworkUserGroupProxy
            // MNetworkUserGroupProxy
            // MNetworkExcludeByUserGroup
            // MNetworkIncludeByUserGroup
            // MNetworkIncludeByUserGroup
            // MNetworkIncludeByUserGroup
            // MNetworkOverride
            // MNetworkOverride
            // MNetworkOverride
            // MNetworkOverride
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // NetworkVarNames: m_pWeaponServices (CPlayer_WeaponServices*)
            // NetworkVarNames: m_pItemServices (CPlayer_ItemServices*)
            // NetworkVarNames: m_pAutoaimServices (CPlayer_AutoaimServices*)
            // NetworkVarNames: m_pObserverServices (CPlayer_ObserverServices*)
            // NetworkVarNames: m_pWaterServices (CPlayer_WaterServices*)
            // NetworkVarNames: m_pUseServices (CPlayer_UseServices*)
            // NetworkVarNames: m_pFlashlightServices (CPlayer_FlashlightServices*)
            // NetworkVarNames: m_pCameraServices (CPlayer_CameraServices*)
            // NetworkVarNames: m_pMovementServices (CPlayer_MovementServices*)
            // NetworkVarNames: m_ServerViewAngleChanges (ViewAngleServerChange_t)
            // NetworkVarNames: m_iHideHUD (uint32)
            // NetworkVarNames: m_skybox3d (sky3dparams_t)
            // NetworkVarNames: m_flDeathTime (GameTime_t)
            // NetworkVarNames: m_hController (CHandle<CBasePlayerController>)
            namespace C_BasePlayerPawn {
                constexpr std::ptrdiff_t m_pWeaponServices = 0xD70; // 
                constexpr std::ptrdiff_t m_pItemServices = 0xD78; // 
                constexpr std::ptrdiff_t m_pAutoaimServices = 0xD80; // 
                constexpr std::ptrdiff_t m_pObserverServices = 0xD88; // 
                constexpr std::ptrdiff_t m_pWaterServices = 0xD90; // 
                constexpr std::ptrdiff_t m_pUseServices = 0xD98; // 
                constexpr std::ptrdiff_t m_pFlashlightServices = 0xDA0; // 
                constexpr std::ptrdiff_t m_pCameraServices = 0xDA8; // 
                constexpr std::ptrdiff_t m_pMovementServices = 0xDB0; // 
                constexpr std::ptrdiff_t m_ServerViewAngleChanges = 0xDC0; // 
                constexpr std::ptrdiff_t m_nHighestConsumedServerViewAngleChangeIndex = 0xE10; // 
                constexpr std::ptrdiff_t v_angle = 0xE14; // 
                constexpr std::ptrdiff_t v_anglePrevious = 0xE20; // 
                constexpr std::ptrdiff_t m_iHideHUD = 0xE2C; // 
                constexpr std::ptrdiff_t m_skybox3d = 0xE30; // 
                constexpr std::ptrdiff_t m_flDeathTime = 0xEC0; // 
                constexpr std::ptrdiff_t m_vecPredictionError = 0xEC4; // 
                constexpr std::ptrdiff_t m_flPredictionErrorTime = 0xED0; // 
                constexpr std::ptrdiff_t m_vecLastCameraSetupLocalOrigin = 0xED4; // 
                constexpr std::ptrdiff_t m_flLastCameraSetupTime = 0xEE0; // 
                constexpr std::ptrdiff_t m_flFOVSensitivityAdjust = 0xEE4; // 
                constexpr std::ptrdiff_t m_flMouseSensitivity = 0xEE8; // 
                constexpr std::ptrdiff_t m_vOldOrigin = 0xEEC; // 
                constexpr std::ptrdiff_t m_flOldSimulationTime = 0xEF8; // 
                constexpr std::ptrdiff_t m_nLastExecutedCommandNumber = 0xEFC; // 
                constexpr std::ptrdiff_t m_nLastExecutedCommandTick = 0xF00; // 
                constexpr std::ptrdiff_t m_hController = 0xF04; // 
                constexpr std::ptrdiff_t m_bIsSwappingToPredictableController = 0xF08; // 
            }
            // Parent: None
            // Field count: 7
            //
            // Metadata:
            // NetworkVarNames: m_iReapplyProvisionParity (int)
            // NetworkVarNames: m_hOuter (EHANDLE)
            // NetworkVarNames: m_ProviderType (attributeprovidertypes_t)
            namespace CAttributeManager {
                constexpr std::ptrdiff_t m_Providers = 0x8; // 
                constexpr std::ptrdiff_t m_Receivers = 0x20; // 
                constexpr std::ptrdiff_t m_iReapplyProvisionParity = 0x38; // 
                constexpr std::ptrdiff_t m_hOuter = 0x3C; // 
                constexpr std::ptrdiff_t m_bPreventLoopback = 0x40; // 
                constexpr std::ptrdiff_t m_ProviderType = 0x44; // 
                constexpr std::ptrdiff_t m_CachedResults = 0x48; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityDistruptiveChargeVData {
                constexpr std::ptrdiff_t m_Particle = 0x1548; // 
                constexpr std::ptrdiff_t m_BuffModifier = 0x1628; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_HornetSting {
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_MutedVData {
                constexpr std::ptrdiff_t m_MutedParticle = 0x608; // 
                constexpr std::ptrdiff_t m_MutedPlayerParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_MutedStatusParticle = 0x7C8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_TurnCameraToTarget {
                constexpr std::ptrdiff_t m_hTarget = 0xC0; // 
            }
            // Parent: C_BaseEntity
            // Field count: 0
            namespace CLogicalEntity {
            }
            // Parent: None
            // Field count: 24
            //
            // Metadata:
            // NetworkVarNames: m_PredNetBoolVariables (uint32)
            // NetworkVarNames: m_PredNetByteVariables (byte)
            // NetworkVarNames: m_PredNetUInt16Variables (uint16)
            // NetworkVarNames: m_PredNetIntVariables (int32)
            // NetworkVarNames: m_PredNetUInt32Variables (uint32)
            // NetworkVarNames: m_PredNetUInt64Variables (uint64)
            // NetworkVarNames: m_PredNetFloatVariables (float)
            // NetworkVarNames: m_PredNetVectorVariables (Vector)
            // NetworkVarNames: m_PredNetQuaternionVariables (Quaternion)
            // NetworkVarNames: m_PredNetGlobalSymbolVariables (CGlobalSymbol)
            // NetworkVarNames: m_OwnerOnlyPredNetBoolVariables (uint32)
            // NetworkVarNames: m_OwnerOnlyPredNetByteVariables (byte)
            // NetworkVarNames: m_OwnerOnlyPredNetUInt16Variables (uint16)
            // NetworkVarNames: m_OwnerOnlyPredNetIntVariables (int32)
            // NetworkVarNames: m_OwnerOnlyPredNetUInt32Variables (uint32)
            // NetworkVarNames: m_OwnerOnlyPredNetUInt64Variables (uint64)
            // NetworkVarNames: m_OwnerOnlyPredNetFloatVariables (float)
            // NetworkVarNames: m_OwnerOnlyPredNetVectorVariables (Vector)
            // NetworkVarNames: m_OwnerOnlyPredNetQuaternionVariables (Quaternion)
            // NetworkVarNames: m_OwnerOnlyPredNetGlobalSymbolVariables (CGlobalSymbol)
            // NetworkVarNames: m_nBoolVariablesCount (int)
            // NetworkVarNames: m_nOwnerOnlyBoolVariablesCount (int)
            // NetworkVarNames: m_nRandomSeedOffset (int)
            // NetworkVarNames: m_flLastTeleportTime (float)
            namespace CAnimGraphNetworkedVariables {
                constexpr std::ptrdiff_t m_PredNetBoolVariables = 0x8; // C_NetworkUtlVectorBase<uint32>
                constexpr std::ptrdiff_t m_PredNetByteVariables = 0x20; // 
                constexpr std::ptrdiff_t m_PredNetUInt16Variables = 0x38; // C_NetworkUtlVectorBase<uint16>
                constexpr std::ptrdiff_t m_PredNetIntVariables = 0x50; // 
                constexpr std::ptrdiff_t m_PredNetUInt32Variables = 0x68; // C_NetworkUtlVectorBase<uint32>
                constexpr std::ptrdiff_t m_PredNetUInt64Variables = 0x80; // C_NetworkUtlVectorBase<uint64>
                constexpr std::ptrdiff_t m_PredNetFloatVariables = 0x98; // C_NetworkUtlVectorBase<float32>
                constexpr std::ptrdiff_t m_PredNetVectorVariables = 0xB0; // C_NetworkUtlVectorBase<Vector>
                constexpr std::ptrdiff_t m_PredNetQuaternionVariables = 0xC8; // C_NetworkUtlVectorBase<Quaternion>
                constexpr std::ptrdiff_t m_PredNetGlobalSymbolVariables = 0xE0; // C_NetworkUtlVectorBase<CGlobalSymbol>
                constexpr std::ptrdiff_t m_OwnerOnlyPredNetBoolVariables = 0xF8; // C_NetworkUtlVectorBase<uint32>
                constexpr std::ptrdiff_t m_OwnerOnlyPredNetByteVariables = 0x110; // 
                constexpr std::ptrdiff_t m_OwnerOnlyPredNetUInt16Variables = 0x128; // C_NetworkUtlVectorBase<uint16>
                constexpr std::ptrdiff_t m_OwnerOnlyPredNetIntVariables = 0x140; // 
                constexpr std::ptrdiff_t m_OwnerOnlyPredNetUInt32Variables = 0x158; // C_NetworkUtlVectorBase<uint32>
                constexpr std::ptrdiff_t m_OwnerOnlyPredNetUInt64Variables = 0x170; // C_NetworkUtlVectorBase<uint64>
                constexpr std::ptrdiff_t m_OwnerOnlyPredNetFloatVariables = 0x188; // C_NetworkUtlVectorBase<float32>
                constexpr std::ptrdiff_t m_OwnerOnlyPredNetVectorVariables = 0x1A0; // C_NetworkUtlVectorBase<Vector>
                constexpr std::ptrdiff_t m_OwnerOnlyPredNetQuaternionVariables = 0x1B8; // C_NetworkUtlVectorBase<Quaternion>
                constexpr std::ptrdiff_t m_OwnerOnlyPredNetGlobalSymbolVariables = 0x1D0; // C_NetworkUtlVectorBase<CGlobalSymbol>
                constexpr std::ptrdiff_t m_nBoolVariablesCount = 0x1E8; // 
                constexpr std::ptrdiff_t m_nOwnerOnlyBoolVariablesCount = 0x1EC; // 
                constexpr std::ptrdiff_t m_nRandomSeedOffset = 0x1F0; // 
                constexpr std::ptrdiff_t m_flLastTeleportTime = 0x1F4; // 
            }
            // Parent: C_BaseModelEntity
            // Field count: 41
            //
            // Metadata:
            // MNetworkIncludeByUserGroup
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // NetworkVarNames: m_flScrollSpeed (float32)
            // NetworkVarNames: m_RopeFlags (uint16)
            // NetworkVarNames: m_iRopeMaterialModelIndex (HMaterialStrong)
            // NetworkVarNames: m_nSegments (uint8)
            // NetworkVarNames: m_hStartPoint (CHandle<C_BaseEntity>)
            // NetworkVarNames: m_hEndPoint (CHandle<C_BaseEntity>)
            // NetworkVarNames: m_iStartAttachment (AttachmentHandle_t)
            // NetworkVarNames: m_iEndAttachment (AttachmentHandle_t)
            // NetworkVarNames: m_Subdiv (uint8)
            // NetworkVarNames: m_RopeLength (int16)
            // NetworkVarNames: m_Slack (int16)
            // NetworkVarNames: m_TextureScale (float32)
            // NetworkVarNames: m_fLockedPoints (uint8)
            // NetworkVarNames: m_nChangeCount (uint8)
            // NetworkVarNames: m_Width (float32)
            // NetworkVarNames: m_bConstrainBetweenEndpoints (bool)
            namespace C_RopeKeyframe {
                constexpr std::ptrdiff_t m_LinksTouchingSomething = 0x838; // 
                constexpr std::ptrdiff_t m_nLinksTouchingSomething = 0x83C; // 
                constexpr std::ptrdiff_t m_bApplyWind = 0x840; // 
                constexpr std::ptrdiff_t m_fPrevLockedPoints = 0x844; // 
                constexpr std::ptrdiff_t m_iForcePointMoveCounter = 0x848; // 
                constexpr std::ptrdiff_t m_bPrevEndPointPos = 0x84C; // 
                constexpr std::ptrdiff_t m_vPrevEndPointPos = 0x850; // 
                constexpr std::ptrdiff_t m_flCurScroll = 0x868; // 
                constexpr std::ptrdiff_t m_flScrollSpeed = 0x86C; // 
                constexpr std::ptrdiff_t m_RopeFlags = 0x870; // 
                constexpr std::ptrdiff_t m_iRopeMaterialModelIndex = 0x878; // CStrongHandle<InfoForResourceTypeIMaterial2>
                constexpr std::ptrdiff_t m_LightValues = 0xAF0; // 
                constexpr std::ptrdiff_t m_nSegments = 0xB68; // 
                constexpr std::ptrdiff_t m_hStartPoint = 0xB6C; // 
                constexpr std::ptrdiff_t m_hEndPoint = 0xB70; // 
                constexpr std::ptrdiff_t m_iStartAttachment = 0xB74; // 
                constexpr std::ptrdiff_t m_iEndAttachment = 0xB75; // 
                constexpr std::ptrdiff_t m_Subdiv = 0xB76; // 
                constexpr std::ptrdiff_t m_RopeLength = 0xB78; // 
                constexpr std::ptrdiff_t m_Slack = 0xB7A; // 
                constexpr std::ptrdiff_t m_TextureScale = 0xB7C; // 
                constexpr std::ptrdiff_t m_fLockedPoints = 0xB80; // 
                constexpr std::ptrdiff_t m_nChangeCount = 0xB81; // 
                constexpr std::ptrdiff_t m_Width = 0xB84; // 
                constexpr std::ptrdiff_t m_PhysicsDelegate = 0xB88; // 
                constexpr std::ptrdiff_t m_hMaterial = 0xB98; // CStrongHandle<InfoForResourceTypeIMaterial2>
                constexpr std::ptrdiff_t m_TextureHeight = 0xBA0; // 
                constexpr std::ptrdiff_t m_vecImpulse = 0xBA4; // 
                constexpr std::ptrdiff_t m_vecPreviousImpulse = 0xBB0; // 
                constexpr std::ptrdiff_t m_flCurrentGustTimer = 0xBBC; // 
                constexpr std::ptrdiff_t m_flCurrentGustLifetime = 0xBC0; // 
                constexpr std::ptrdiff_t m_flTimeToNextGust = 0xBC4; // 
                constexpr std::ptrdiff_t m_vWindDir = 0xBC8; // 
                constexpr std::ptrdiff_t m_vColorMod = 0xBD4; // 
                constexpr std::ptrdiff_t m_vCachedEndPointAttachmentPos = 0xBE0; // 
                constexpr std::ptrdiff_t m_vCachedEndPointAttachmentAngle = 0xBF8; // 
                constexpr std::ptrdiff_t m_bConstrainBetweenEndpoints = 0xC10; // 
                constexpr std::ptrdiff_t m_bEndPointAttachmentPositionsDirty = 0x0; // 
                constexpr std::ptrdiff_t m_bEndPointAttachmentAnglesDirty = 0x0; // 
                constexpr std::ptrdiff_t m_bNewDataThisFrame = 0x0; // 
                constexpr std::ptrdiff_t m_bPhysicsInitted = 0x0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Cadence_SilenceContraptionsDebuffVData {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Trappers_Bolo {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Nano_PredatoryStatueTarget {
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_SlowingBullets_Proc {
            }
            // Parent: C_BaseEntity
            // Field count: 16
            //
            // Metadata:
            // NetworkVarNames: m_hGradientFogTexture (HRenderTextureStrong)
            // NetworkVarNames: m_flFogStartDistance (float)
            // NetworkVarNames: m_flFogEndDistance (float)
            // NetworkVarNames: m_bHeightFogEnabled (bool)
            // NetworkVarNames: m_flFogStartHeight (float)
            // NetworkVarNames: m_flFogEndHeight (float)
            // NetworkVarNames: m_flFarZ (float)
            // NetworkVarNames: m_flFogMaxOpacity (float)
            // NetworkVarNames: m_flFogFalloffExponent (float)
            // NetworkVarNames: m_flFogVerticalExponent (float)
            // NetworkVarNames: m_fogColor (Color)
            // NetworkVarNames: m_flFogStrength (float)
            // NetworkVarNames: m_flFadeTime (float)
            // NetworkVarNames: m_bStartDisabled (bool)
            // NetworkVarNames: m_bIsEnabled (bool)
            namespace C_GradientFog {
                constexpr std::ptrdiff_t m_hGradientFogTexture = 0x558; // 
                constexpr std::ptrdiff_t m_flFogStartDistance = 0x560; // 
                constexpr std::ptrdiff_t m_flFogEndDistance = 0x564; // 
                constexpr std::ptrdiff_t m_bHeightFogEnabled = 0x568; // 
                constexpr std::ptrdiff_t m_flFogStartHeight = 0x56C; // 
                constexpr std::ptrdiff_t m_flFogEndHeight = 0x570; // 
                constexpr std::ptrdiff_t m_flFarZ = 0x574; // 
                constexpr std::ptrdiff_t m_flFogMaxOpacity = 0x578; // 
                constexpr std::ptrdiff_t m_flFogFalloffExponent = 0x57C; // 
                constexpr std::ptrdiff_t m_flFogVerticalExponent = 0x580; // 
                constexpr std::ptrdiff_t m_fogColor = 0x584; // 
                constexpr std::ptrdiff_t m_flFogStrength = 0x588; // 
                constexpr std::ptrdiff_t m_flFadeTime = 0x58C; // 
                constexpr std::ptrdiff_t m_bStartDisabled = 0x590; // 
                constexpr std::ptrdiff_t m_bIsEnabled = 0x591; // 
                constexpr std::ptrdiff_t m_bGradientFogNeedsTextures = 0x592; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Slork_Gun_Poison {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Mirage_FireBeetles_Buff_VData {
                constexpr std::ptrdiff_t m_CasterBuffParticle = 0x608; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_GenericPerson_4 {
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityWreckerScrapBlastVData {
                constexpr std::ptrdiff_t m_SprayParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_ChannelStartParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1708; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Item_Bleeding_Bullets_ActiveVData {
                constexpr std::ptrdiff_t m_BleedModifier = 0x638; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BuildUpModifier = 0x648; // 
                constexpr std::ptrdiff_t m_BulletImpactParticle = 0x658; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Stimpak_regen {
            }
            // Parent: CCitadelModifier
            // Field count: 4
            namespace CCitadel_Modifier_BlastPush {
                constexpr std::ptrdiff_t m_vPush = 0xC0; // 
                constexpr std::ptrdiff_t m_flPushVelocity = 0xCC; // 
                constexpr std::ptrdiff_t m_flMaxPushVelocity = 0xD0; // 
                constexpr std::ptrdiff_t m_flMaxPushVelocitySqr = 0xD4; // 
            }
            // Parent: CScaleFunctionBase
            // Field count: 0
            namespace CScaleFunctionAbilityProperty_WeaponDamage {
            }
            // Parent: CEntityComponent
            // Field count: 0
            namespace CCitadelPlayerClipComponent {
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CItemAOESilenceAuraVData {
                constexpr std::ptrdiff_t m_empWaveParticle = 0x648; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Disruptive_Charge {
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_TargetPracticeDebuffVData {
                constexpr std::ptrdiff_t m_SlowModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BulletResistModifier = 0x618; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_EMPModifier = 0x628; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 10
            //
            // Metadata:
            // NetworkVarNames: m_vecStartPos (Vector)
            // NetworkVarNames: m_vecPosition (Vector)
            // NetworkVarNames: m_vecInitialPosition (Vector)
            // NetworkVarNames: m_CastTime (GameTime_t)
            // NetworkVarNames: m_vecDirection (Vector)
            // NetworkVarNames: m_vecLeft (Vector)
            // NetworkVarNames: m_Length (float)
            // NetworkVarNames: m_bTraveling (bool)
            // NetworkVarNames: m_bPreview (bool)
            namespace CCitadel_Ability_FissureWall {
                constexpr std::ptrdiff_t m_vecWallPreviewParticles = 0xC88; // 
                constexpr std::ptrdiff_t m_vecStartPos = 0xD48; // 
                constexpr std::ptrdiff_t m_vecPosition = 0xD54; // 
                constexpr std::ptrdiff_t m_vecInitialPosition = 0xD60; // 
                constexpr std::ptrdiff_t m_CastTime = 0xD6C; // 
                constexpr std::ptrdiff_t m_vecDirection = 0xD70; // 
                constexpr std::ptrdiff_t m_vecLeft = 0xD7C; // 
                constexpr std::ptrdiff_t m_Length = 0xD88; // 
                constexpr std::ptrdiff_t m_bTraveling = 0xD8C; // 
                constexpr std::ptrdiff_t m_bPreview = 0xD8D; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_LifestrikeGauntlets {
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_CheatDeathImmunityVData {
                constexpr std::ptrdiff_t m_BuffParticle = 0x608; // 
                constexpr std::ptrdiff_t m_BuffPlayerParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_StatusEffect = 0x7C8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_StatStealBaseVData {
                constexpr std::ptrdiff_t m_StatStolenDebuffModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_StatStolenBuffModifier = 0x618; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelBaseShivAbility
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_flTotalPendingDamage (float)
            namespace CCitadel_Ability_Shiv_Defer_Damage {
                constexpr std::ptrdiff_t m_flTotalPendingDamage = 0xD58; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 10
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_IceBeamVData {
                constexpr std::ptrdiff_t m_BeamParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_HitParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_SlowModifier = 0x1708; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BuildupModifier = 0x1718; // 
                constexpr std::ptrdiff_t m_BuildupProcModifier = 0x1728; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BeamStartSound = 0x1738; // 
                constexpr std::ptrdiff_t m_BeamStopSound = 0x1748; // 
                constexpr std::ptrdiff_t m_BeamPointStartLoopSound = 0x1758; // 
                constexpr std::ptrdiff_t m_BeamPointEndLoopSound = 0x1768; // 
                constexpr std::ptrdiff_t m_BeamPointClosestLoopSound = 0x1778; // 
            }
            // Parent: C_NPC_TrooperBoss
            // Field count: 0
            namespace C_NPC_TrooperBarrackBoss {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 6
            //
            // Metadata:
            // NetworkVarNames: m_ChargeState (EViscousChargedGunState)
            // NetworkVarNames: m_nClipConsumed (float)
            // NetworkVarNames: m_bIsCharging (bool)
            // NetworkVarNames: m_bIsToggled (bool)
            namespace CCitadel_Ability_ViscousWeapon_Alt {
                constexpr std::ptrdiff_t m_ChargeState = 0xC78; // 
                constexpr std::ptrdiff_t m_nClipConsumed = 0xC7C; // 
                constexpr std::ptrdiff_t m_bIsCharging = 0xC80; // 
                constexpr std::ptrdiff_t m_bIsToggled = 0xC81; // 
                constexpr std::ptrdiff_t m_fxChargingParticle = 0xC84; // 
                constexpr std::ptrdiff_t m_flLastBulletConsumedTime = 0xC90; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_ColdFrontAOE {
                constexpr std::ptrdiff_t m_hAOEEffect = 0x1A0; // 
            }
            // Parent: C_BaseCombatCharacter
            // Field count: 20
            namespace C_PortraitWorldUnit {
                constexpr std::ptrdiff_t m_bSuppressIntroEffects = 0xD70; // 
                constexpr std::ptrdiff_t m_bIsAlternateLoadout = 0xD71; // 
                constexpr std::ptrdiff_t m_bSpawnBackgroundModels = 0xD72; // 
                constexpr std::ptrdiff_t m_bDeferredPortrait = 0xD73; // 
                constexpr std::ptrdiff_t m_bShowParticleAssetModifiers = 0xD74; // 
                constexpr std::ptrdiff_t m_bIgnorePortraitInfo = 0xD75; // 
                constexpr std::ptrdiff_t m_bFlyingCourier = 0xD76; // 
                constexpr std::ptrdiff_t m_nEffigyStatusEffect = 0xD78; // 
                constexpr std::ptrdiff_t m_effigySequenceName = 0xD80; // 
                constexpr std::ptrdiff_t m_flStartingAnimationCycle = 0xD88; // 
                constexpr std::ptrdiff_t m_flRareLoadoutAnimChance = 0xD8C; // 
                constexpr std::ptrdiff_t m_environment = 0xDA0; // CitadelPortraitEnvironmentType_t
                constexpr std::ptrdiff_t m_nStartupBehavior = 0xDA4; // 
                constexpr std::ptrdiff_t m_cameraName = 0xF18; // 
                constexpr std::ptrdiff_t m_nPortraitParticle = 0xF50; // 
                constexpr std::ptrdiff_t m_nAmbientParticle = 0xF54; // 
                constexpr std::ptrdiff_t m_nCourierType = 0xF58; // 
                constexpr std::ptrdiff_t m_heroID = 0xF5C; // 
                constexpr std::ptrdiff_t m_heroAnimGraphEnumName = 0xF60; // 
                constexpr std::ptrdiff_t m_heroShopAnimGraphEnumName = 0xF68; // 
            }
            // Parent: C_EconEntity
            // Field count: 0
            namespace C_EconWearable {
            }
            // Parent: C_BaseModelEntity
            // Field count: 4
            //
            // Metadata:
            // NetworkVarNames: m_flBulletTimeScale (float)
            // NetworkVarNames: m_flProjectileTimeScale (float)
            // NetworkVarNames: m_flExpireTime (GameTime_t)
            // NetworkVarNames: m_flStopDuration (float)
            namespace CCitadelBulletTimeWarp {
                constexpr std::ptrdiff_t m_flBulletTimeScale = 0x830; // 
                constexpr std::ptrdiff_t m_flProjectileTimeScale = 0x834; // 
                constexpr std::ptrdiff_t m_flExpireTime = 0x838; // 
                constexpr std::ptrdiff_t m_flStopDuration = 0x83C; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityRiptideVData {
                constexpr std::ptrdiff_t m_TossModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Slork_Invis {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierChargedTackleActiveVData {
                constexpr std::ptrdiff_t m_TackleParticle = 0x608; // 
                constexpr std::ptrdiff_t m_PullEnemiesParticle = 0x6E8; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_AfterburnWatcher {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_TriggerTowerRegen {
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Item_HealthNova {
                constexpr std::ptrdiff_t m_flAmountPerSecond = 0xC0; // 
            }
            // Parent: CCitadel_Modifier_Intrinsic_BaseVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_MagicClarityWatcherVData {
                constexpr std::ptrdiff_t m_BuffModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 4
            namespace CCitadel_Modifier_TossUp {
                constexpr std::ptrdiff_t m_bForceApplied = 0xC0; // 
                constexpr std::ptrdiff_t m_bLandedOnGround = 0xC1; // 
                constexpr std::ptrdiff_t m_vTossUpForce = 0xC4; // 
                constexpr std::ptrdiff_t m_flCurrentVelocityScale = 0xD0; // 
            }
            // Parent: C_CitadelProjectile
            // Field count: 0
            namespace C_Citadel_ProjectileRiptide {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_ArmorUpgrade_AbilityLifeSteal {
            }
            // Parent: CCitadel_Item_TrackingProjectileApplyModifier
            // Field count: 0
            namespace CCitadel_Item_RejuvTrackingProjectile {
            }
            // Parent: CCitadelModifierVData
            // Field count: 5
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ItemPickupPunchableVData {
                constexpr std::ptrdiff_t m_flPhysicsRadius = 0x608; // 
                constexpr std::ptrdiff_t m_IsDroppingParticle = 0x610; // 
                constexpr std::ptrdiff_t m_IsPunchableParticle = 0x6F0; // 
                constexpr std::ptrdiff_t m_IsFrozenParticle = 0x7D0; // 
                constexpr std::ptrdiff_t m_NearRejuvAuraModifier = 0x8B0; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_BaseModelEntity
            // Field count: 0
            namespace C_BaseToggle {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Astro_Rifle_Debuff {
            }
            // Parent: CCitadel_Modifier_Stunned
            // Field count: 4
            namespace CCitadel_Modifier_LashGrappleEnemy_Debuff {
                constexpr std::ptrdiff_t m_vCrashDir = 0xC8; // 
                constexpr std::ptrdiff_t m_vLiftTarget = 0xD4; // 
                constexpr std::ptrdiff_t m_flStartTime = 0xE0; // 
                constexpr std::ptrdiff_t m_bCrashingDown = 0xE4; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_Healbane_Debuff {
            }
            // Parent: CCitadelModifierVData
            // Field count: 8
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_RespawnCreditVData {
                constexpr std::ptrdiff_t m_eRespawnMechanic = 0x608; // 
                constexpr std::ptrdiff_t m_flRespawnDelay = 0x60C; // 
                constexpr std::ptrdiff_t m_flPercentOfNormalRespawn = 0x610; // 
                constexpr std::ptrdiff_t m_flBonusClipSize = 0x614; // 
                constexpr std::ptrdiff_t m_flBonusFirerate = 0x618; // 
                constexpr std::ptrdiff_t m_flBonusHealth = 0x61C; // 
                constexpr std::ptrdiff_t m_flBonusMoveSpeedMeterPerSecond = 0x620; // 
                constexpr std::ptrdiff_t m_sExpireSound = 0x628; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CItem_FleetfootBoots {
            }
            // Parent: CCitadel_Modifier_Silenced
            // Field count: 2
            namespace CCitadel_Modifier_Bubble {
                constexpr std::ptrdiff_t m_flDampingFactor = 0xC0; // 
                constexpr std::ptrdiff_t m_ParticleIndex = 0x1E0; // 
            }
            // Parent: C_BaseEntity
            // Field count: 16
            //
            // Metadata:
            // NetworkVarNames: m_bActive (bool)
            // NetworkVarNames: m_vBoxMins (Vector)
            // NetworkVarNames: m_vBoxMaxs (Vector)
            // NetworkVarNames: m_bStartDisabled (bool)
            // NetworkVarNames: m_flStrength (float)
            // NetworkVarNames: m_nFalloffShape (int)
            // NetworkVarNames: m_flFalloffExponent (float)
            // NetworkVarNames: m_flHeightFogDepth (float)
            // NetworkVarNames: m_fHeightFogEdgeWidth (float)
            // NetworkVarNames: m_fIndirectLightStrength (float)
            // NetworkVarNames: m_fSunLightStrength (float)
            // NetworkVarNames: m_fNoiseStrength (float)
            // NetworkVarNames: m_bOverrideIndirectLightStrength (bool)
            // NetworkVarNames: m_bOverrideSunLightStrength (bool)
            // NetworkVarNames: m_bOverrideNoiseStrength (bool)
            // NetworkVarNames: m_bAllowLPVIndirect (bool)
            namespace C_EnvVolumetricFogVolume {
                constexpr std::ptrdiff_t m_bActive = 0x558; // 
                constexpr std::ptrdiff_t m_vBoxMins = 0x55C; // 
                constexpr std::ptrdiff_t m_vBoxMaxs = 0x568; // 
                constexpr std::ptrdiff_t m_bStartDisabled = 0x574; // 
                constexpr std::ptrdiff_t m_flStrength = 0x578; // 
                constexpr std::ptrdiff_t m_nFalloffShape = 0x57C; // 
                constexpr std::ptrdiff_t m_flFalloffExponent = 0x580; // 
                constexpr std::ptrdiff_t m_flHeightFogDepth = 0x584; // 
                constexpr std::ptrdiff_t m_fHeightFogEdgeWidth = 0x588; // 
                constexpr std::ptrdiff_t m_fIndirectLightStrength = 0x58C; // 
                constexpr std::ptrdiff_t m_fSunLightStrength = 0x590; // 
                constexpr std::ptrdiff_t m_fNoiseStrength = 0x594; // 
                constexpr std::ptrdiff_t m_bOverrideIndirectLightStrength = 0x598; // 
                constexpr std::ptrdiff_t m_bOverrideSunLightStrength = 0x599; // 
                constexpr std::ptrdiff_t m_bOverrideNoiseStrength = 0x59A; // 
                constexpr std::ptrdiff_t m_bAllowLPVIndirect = 0x59B; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_WreckerSalvage {
            }
            // Parent: CCitadelModifierVData
            // Field count: 9
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_TargetPracticeEnemyVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BuildupCompleteModifier = 0x618; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BuildupModifier = 0x628; // 
                constexpr std::ptrdiff_t m_TargetParticle = 0x638; // 
                constexpr std::ptrdiff_t m_HitParticle = 0x718; // 
                constexpr std::ptrdiff_t m_HeadParticle = 0x7F8; // 
                constexpr std::ptrdiff_t m_strTargetHitSound = 0x8D8; // 
                constexpr std::ptrdiff_t m_strTargetHeadShotHitSound = 0x8E8; // 
                constexpr std::ptrdiff_t m_strTargetCompleteSound = 0x8F8; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            namespace CCitadel_Ability_Lash_Flog {
                constexpr std::ptrdiff_t m_SandEffect = 0xD90; // 
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_WeaponUpgrade_SiphonBulletsVData {
                constexpr std::ptrdiff_t m_PermanentHealthLoss = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_ChainLightningEffectVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Galvanic_Storm_EffectVData {
                constexpr std::ptrdiff_t m_BuffChainParticle = 0x708; // 
            }
            // Parent: C_BaseModelEntity
            // Field count: 0
            namespace C_ModelPointEntity {
            }
            // Parent: CCitadel_Modifier_InvisVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Nano_ShadowVData {
                constexpr std::ptrdiff_t m_SilenceModifier = 0x8C0; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ArmorDebuff = 0x8D0; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_RevealedEffect = 0x8E0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_WarpStone_Caster {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Succor_MoveVData {
                constexpr std::ptrdiff_t m_PullSound = 0x608; // 
            }
            // Parent: CCitadelPlayerPawnBase
            // Field count: 45
            //
            // Metadata:
            // MNetworkVarTypeOverride
            // MNetworkIncludeByName
            // MNetworkVarTypeOverride
            // MNetworkIncludeByName
            // NetworkVarNames: m_angClientCamera (QAngle)
            // NetworkVarNames: m_eZipLineLaneColor (CMsgLaneColor)
            // NetworkVarNames: m_nLevel (int32)
            // NetworkVarNames: m_nCurrencies (int32)
            // NetworkVarNames: m_nSpentCurrencies (int32)
            // NetworkVarNames: m_flLastSpawnTime (GameTime_t)
            // NetworkVarNames: m_flRespawnTime (GameTime_t)
            // NetworkVarNames: m_bInRegenerationZone (bool)
            // NetworkVarNames: m_bInItemShopZone (bool)
            // NetworkVarNames: m_timeRevealedOnMinimapByNPC (GameTime_t)
            // NetworkVarNames: m_vecFullSellPriceItems (EntitySubclassID_t)
            // NetworkVarNames: m_vecFullSellPriceAbilityUpgrades (FullSellPriceAbilityUpgrades_t)
            // NetworkVarNames: m_bNetworkDisconnected (bool)
            // NetworkVarNames: m_bHasIncomingThreats (bool)
            // NetworkVarNames: m_bLearningAbility (bool)
            // NetworkVarNames: m_nFlashStartTick (int)
            // NetworkVarNames: m_nFlashMaxStartTick (int)
            // NetworkVarNames: m_nFlashFadeStartTick (int)
            // NetworkVarNames: m_nFlashEndTick (int)
            // NetworkVarNames: m_nFlashMaxAlpha (int8)
            // NetworkVarNames: m_nDeducedLane (int32)
            // NetworkVarNames: m_nSuccessiveDucks (int8)
            // NetworkVarNames: m_flLastDuckTime (GameTime_t)
            // NetworkVarNames: m_bDismissedReportCard (bool)
            // NetworkVarNames: m_flCurrentHealingAmount (float)
            // NetworkVarNames: m_angLockedEyeAngles (QAngle)
            // NetworkVarNames: m_CCitadelAbilityComponent (CCitadelAbilityComponent::Storage_t)
            // NetworkVarNames: m_CCitadelHeroComponent (CCitadelHeroComponent::Storage_t)
            // NetworkVarNames: m_bAnimGraphMovementClipped (bool)
            // NetworkVarNames: m_bAnimGraphMovementDisableGravity (bool)
            // NetworkVarNames: m_bAnimGraphMovementDirectAirControl (bool)
            // NetworkVarNames: m_flPredTimeSlowedStart (GameTime_t)
            // NetworkVarNames: m_flPredTimeSlowedEnd (GameTime_t)
            // NetworkVarNames: m_flPredSlowSpeed (float32)
            // NetworkVarNames: m_flTimeSlowedStart (GameTime_t)
            // NetworkVarNames: m_flTimeSlowedEnd (GameTime_t)
            // NetworkVarNames: m_flSlowSpeed (float32)
            // NetworkVarNames: m_flSprintAnimSuppressEndTime (GameTime_t)
            namespace C_CitadelPlayerPawn {
                constexpr std::ptrdiff_t m_angEyeAngles = 0xF88; // 
                constexpr std::ptrdiff_t m_angClientCamera = 0xFA0; // 
                constexpr std::ptrdiff_t m_eZipLineLaneColor = 0xFAC; // 
                constexpr std::ptrdiff_t m_nLevel = 0xFB0; // 
                constexpr std::ptrdiff_t m_nCurrencies = 0xFB4; // 
                constexpr std::ptrdiff_t m_nSpentCurrencies = 0xFC4; // 
                constexpr std::ptrdiff_t m_flLastSpawnTime = 0xFD4; // 
                constexpr std::ptrdiff_t m_flRespawnTime = 0xFD8; // 
                constexpr std::ptrdiff_t m_bInRegenerationZone = 0xFDC; // 
                constexpr std::ptrdiff_t m_bInItemShopZone = 0xFDD; // 
                constexpr std::ptrdiff_t m_timeRevealedOnMinimapByNPC = 0xFE0; // 
                constexpr std::ptrdiff_t m_vecFullSellPriceItems = 0xFE8; // C_NetworkUtlVectorBase<CUtlStringToken>
                constexpr std::ptrdiff_t m_vecFullSellPriceAbilityUpgrades = 0x1000; // 
                constexpr std::ptrdiff_t m_bNetworkDisconnected = 0x1018; // 
                constexpr std::ptrdiff_t m_bHasIncomingThreats = 0x1019; // 
                constexpr std::ptrdiff_t m_bLearningAbility = 0x101A; // 
                constexpr std::ptrdiff_t m_nFlashStartTick = 0x101C; // 
                constexpr std::ptrdiff_t m_nFlashMaxStartTick = 0x1020; // 
                constexpr std::ptrdiff_t m_nFlashFadeStartTick = 0x1024; // 
                constexpr std::ptrdiff_t m_nFlashEndTick = 0x1028; // 
                constexpr std::ptrdiff_t m_nFlashMaxAlpha = 0x102C; // 
                constexpr std::ptrdiff_t m_nDeducedLane = 0x1030; // 
                constexpr std::ptrdiff_t m_nSuccessiveDucks = 0x1034; // 
                constexpr std::ptrdiff_t m_flLastDuckTime = 0x1038; // 
                constexpr std::ptrdiff_t m_bDismissedReportCard = 0x103C; // 
                constexpr std::ptrdiff_t m_flCurrentHealingAmount = 0x1040; // 
                constexpr std::ptrdiff_t m_angLockedEyeAngles = 0x1044; // 
                constexpr std::ptrdiff_t m_CCitadelAbilityComponent = 0x1050; // 
                constexpr std::ptrdiff_t m_CCitadelHeroComponent = 0x11F0; // 
                constexpr std::ptrdiff_t m_flRichPresenceUpdateInterval = 0x12B8; // 
                constexpr std::ptrdiff_t m_bAnimGraphMovementClipped = 0x13B0; // 
                constexpr std::ptrdiff_t m_bAnimGraphMovementDisableGravity = 0x13B1; // 
                constexpr std::ptrdiff_t m_bAnimGraphMovementDirectAirControl = 0x13B2; // 
                constexpr std::ptrdiff_t m_bLastMoveWasAnimGraph = 0x13B3; // 
                constexpr std::ptrdiff_t m_flPredTimeSlowedStart = 0x13B4; // 
                constexpr std::ptrdiff_t m_flPredTimeSlowedEnd = 0x13B8; // 
                constexpr std::ptrdiff_t m_flPredSlowSpeed = 0x13BC; // 
                constexpr std::ptrdiff_t m_flTimeSlowedStart = 0x13C0; // 
                constexpr std::ptrdiff_t m_flTimeSlowedEnd = 0x13D0; // 
                constexpr std::ptrdiff_t m_flSlowSpeed = 0x13E0; // 
                constexpr std::ptrdiff_t m_flSprintAnimSuppressEndTime = 0x13F0; // 
                constexpr std::ptrdiff_t m_iCurSlowSlot = 0x13F4; // 
                constexpr std::ptrdiff_t m_vShootTestOffsetStanding = 0x13F8; // 
                constexpr std::ptrdiff_t m_vShootTestOffsetCrouching = 0x1404; // 
                constexpr std::ptrdiff_t m_leanStartTime = 0x1410; // 
            }
            // Parent: CCitadel_Ability_ZipLine
            // Field count: 0
            namespace CCitadel_Ability_TrooperZipLine {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Upgrade_Headhunter_HeadshotBuff {
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_DetentionAmmoVData {
                constexpr std::ptrdiff_t m_BuildUpModifier = 0x638; // 
                constexpr std::ptrdiff_t m_DebuffModifier = 0x648; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ImmunityModifier = 0x658; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_TracerParticle = 0x668; // 
            }
            // Parent: CScaleFunctionBase
            // Field count: 0
            namespace CScaleFunctionAbilityPropertySingleStat {
            }
            // Parent: C_BaseFire
            // Field count: 13
            //
            // Metadata:
            // MNetworkOverride
            // MNetworkOverride
            // NetworkVarNames: m_nFlameModelIndex (int32)
            // NetworkVarNames: m_nFlameFromAboveModelIndex (int32)
            namespace C_FireSmoke {
                constexpr std::ptrdiff_t m_nFlameModelIndex = 0x568; // 
                constexpr std::ptrdiff_t m_nFlameFromAboveModelIndex = 0x56C; // 
                constexpr std::ptrdiff_t m_flScaleRegister = 0x570; // 
                constexpr std::ptrdiff_t m_flScaleStart = 0x574; // 
                constexpr std::ptrdiff_t m_flScaleEnd = 0x578; // 
                constexpr std::ptrdiff_t m_flScaleTimeStart = 0x57C; // 
                constexpr std::ptrdiff_t m_flScaleTimeEnd = 0x580; // 
                constexpr std::ptrdiff_t m_flChildFlameSpread = 0x584; // 
                constexpr std::ptrdiff_t m_flClipPerc = 0x598; // 
                constexpr std::ptrdiff_t m_bClipTested = 0x59C; // 
                constexpr std::ptrdiff_t m_bFadingOut = 0x59D; // 
                constexpr std::ptrdiff_t m_tParticleSpawn = 0x5A0; // 
                constexpr std::ptrdiff_t m_pFireOverlay = 0x5A8; // 
            }
            // Parent: C_Sprite
            // Field count: 0
            namespace C_FireFromAboveSprite {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_UtilityUpgrade_AOESmokeBomb {
            }
            // Parent: C_BaseEntity
            // Field count: 24
            //
            // Metadata:
            // NetworkVarNames: m_Entity_Color (Color)
            // NetworkVarNames: m_Entity_flBrightness (float)
            // NetworkVarNames: m_Entity_hCubemapTexture (HRenderTextureStrong)
            // NetworkVarNames: m_Entity_bCustomCubemapTexture (bool)
            // NetworkVarNames: m_Entity_hLightProbeTexture (HRenderTextureStrong)
            // NetworkVarNames: m_Entity_hLightProbeDirectLightIndicesTexture (HRenderTextureStrong)
            // NetworkVarNames: m_Entity_hLightProbeDirectLightScalarsTexture (HRenderTextureStrong)
            // NetworkVarNames: m_Entity_hLightProbeDirectLightShadowsTexture (HRenderTextureStrong)
            // NetworkVarNames: m_Entity_vBoxMins (Vector)
            // NetworkVarNames: m_Entity_vBoxMaxs (Vector)
            // NetworkVarNames: m_Entity_bMoveable (bool)
            // NetworkVarNames: m_Entity_nHandshake (int)
            // NetworkVarNames: m_Entity_nEnvCubeMapArrayIndex (int)
            // NetworkVarNames: m_Entity_nPriority (int)
            // NetworkVarNames: m_Entity_bStartDisabled (bool)
            // NetworkVarNames: m_Entity_flEdgeFadeDist (float)
            // NetworkVarNames: m_Entity_vEdgeFadeDists (Vector)
            // NetworkVarNames: m_Entity_nLightProbeSizeX (int)
            // NetworkVarNames: m_Entity_nLightProbeSizeY (int)
            // NetworkVarNames: m_Entity_nLightProbeSizeZ (int)
            // NetworkVarNames: m_Entity_nLightProbeAtlasX (int)
            // NetworkVarNames: m_Entity_nLightProbeAtlasY (int)
            // NetworkVarNames: m_Entity_nLightProbeAtlasZ (int)
            // NetworkVarNames: m_Entity_bEnabled (bool)
            namespace C_EnvCombinedLightProbeVolume {
                constexpr std::ptrdiff_t m_Entity_Color = 0x15B8; // 
                constexpr std::ptrdiff_t m_Entity_flBrightness = 0x15BC; // 
                constexpr std::ptrdiff_t m_Entity_hCubemapTexture = 0x15C0; // 
                constexpr std::ptrdiff_t m_Entity_bCustomCubemapTexture = 0x15C8; // 
                constexpr std::ptrdiff_t m_Entity_hLightProbeTexture = 0x15D0; // 
                constexpr std::ptrdiff_t m_Entity_hLightProbeDirectLightIndicesTexture = 0x15D8; // 
                constexpr std::ptrdiff_t m_Entity_hLightProbeDirectLightScalarsTexture = 0x15E0; // 
                constexpr std::ptrdiff_t m_Entity_hLightProbeDirectLightShadowsTexture = 0x15E8; // 
                constexpr std::ptrdiff_t m_Entity_vBoxMins = 0x15F0; // 
                constexpr std::ptrdiff_t m_Entity_vBoxMaxs = 0x15FC; // 
                constexpr std::ptrdiff_t m_Entity_bMoveable = 0x1608; // 
                constexpr std::ptrdiff_t m_Entity_nHandshake = 0x160C; // 
                constexpr std::ptrdiff_t m_Entity_nEnvCubeMapArrayIndex = 0x1610; // 
                constexpr std::ptrdiff_t m_Entity_nPriority = 0x1614; // 
                constexpr std::ptrdiff_t m_Entity_bStartDisabled = 0x1618; // 
                constexpr std::ptrdiff_t m_Entity_flEdgeFadeDist = 0x161C; // 
                constexpr std::ptrdiff_t m_Entity_vEdgeFadeDists = 0x1620; // 
                constexpr std::ptrdiff_t m_Entity_nLightProbeSizeX = 0x162C; // 
                constexpr std::ptrdiff_t m_Entity_nLightProbeSizeY = 0x1630; // 
                constexpr std::ptrdiff_t m_Entity_nLightProbeSizeZ = 0x1634; // 
                constexpr std::ptrdiff_t m_Entity_nLightProbeAtlasX = 0x1638; // 
                constexpr std::ptrdiff_t m_Entity_nLightProbeAtlasY = 0x163C; // 
                constexpr std::ptrdiff_t m_Entity_nLightProbeAtlasZ = 0x1640; // 
                constexpr std::ptrdiff_t m_Entity_bEnabled = 0x1659; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_SleepDagger {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_FlameDash {
            }
            // Parent: CScaleFunctionBase
            // Field count: 0
            namespace CScaleFunctionAbilityProperty_KineticCarbine {
            }
            // Parent: C_SoundOpvarSetPointBase
            // Field count: 0
            namespace C_SoundOpvarSetOBBWindEntity {
            }
            // Parent: None
            // Field count: 4
            //
            // Metadata:
            // NetworkVarNames: m_Handle (ModelConfigHandle_t)
            // NetworkVarNames: m_Name (string_t)
            // NetworkVarNames: m_AssociatedEntities (CHandle<C_BaseModelEntity>)
            // NetworkVarNames: m_AssociatedEntityNames (string_t)
            namespace ActiveModelConfig_t {
                constexpr std::ptrdiff_t m_Handle = 0x28; // 
                constexpr std::ptrdiff_t m_Name = 0x30; // 
                constexpr std::ptrdiff_t m_AssociatedEntities = 0x38; // 
                constexpr std::ptrdiff_t m_AssociatedEntityNames = 0x50; // C_NetworkUtlVectorBase<CUtlSymbolLarge>
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Mirage_Tornado_Lift_VData {
                constexpr std::ptrdiff_t m_HoldInPlaceModifier = 0x608; // 
                constexpr std::ptrdiff_t m_LiftParticle = 0x618; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            namespace CCitadel_Ability_Fealty {
                constexpr std::ptrdiff_t m_hTarget = 0xC78; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_SummonGangster {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Bull_Leap_Boosting {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_ZipLine_Boost {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_CheaterCurse {
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_Thumper_2_Aura {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierIntimidatedVData {
                constexpr std::ptrdiff_t m_EffectParticle = 0x608; // 
            }
            // Parent: CitadelItemVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Upgrade_AerialAssualtVData {
                constexpr std::ptrdiff_t m_WatcherModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_LaunchParticle = 0x15A0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Unstoppable {
                constexpr std::ptrdiff_t m_vecCheckedModifiers = 0xC0; // 
            }
            // Parent: C_DynamicProp
            // Field count: 0
            namespace C_DynamicPropAlias_dynamic_prop {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierVData_SetMoveType {
                constexpr std::ptrdiff_t m_nMoveType = 0x608; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_nPlayersHit (int)
            namespace CCitadel_Ability_StickyBomb {
                constexpr std::ptrdiff_t m_nPlayersHit = 0xC80; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_LightningBullet {
            }
            // Parent: CCitadel_UtilityUpgrade_RocketBootsVData
            // Field count: 7
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_UtilityUpgrade_RocketBoosterVData {
                constexpr std::ptrdiff_t m_LandingParticle = 0x1680; // 
                constexpr std::ptrdiff_t m_AoEPreviewParticle = 0x1760; // 
                constexpr std::ptrdiff_t m_DropDownStartParticle = 0x1840; // 
                constexpr std::ptrdiff_t m_DropDownStartSound = 0x1920; // 
                constexpr std::ptrdiff_t m_LandingSound = 0x1930; // 
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1940; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_flSlamEnabledTime = 0x1950; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Magic_Clarity_BuffVData {
                constexpr std::ptrdiff_t m_VisualModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_AcolytesGlove_VData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x638; // 
                constexpr std::ptrdiff_t m_SwingParticle = 0x648; // 
                constexpr std::ptrdiff_t m_HitParticle = 0x728; // 
            }
            // Parent: None
            // Field count: 41
            //
            // Metadata:
            // NetworkVarNames: m_iLevel (int32)
            // NetworkVarNames: m_iMaxAmmo (int32)
            // NetworkVarNames: m_iHealthMax (int32)
            // NetworkVarNames: m_flHealthRegen (float)
            // NetworkVarNames: m_flRespawnTime (GameTime_t)
            // NetworkVarNames: m_nHeroID (HeroID_t)
            // NetworkVarNames: m_iGoldNetWorth (int32)
            // NetworkVarNames: m_iAPNetWorth (int32)
            // NetworkVarNames: m_iCreepGold (int32)
            // NetworkVarNames: m_iCreepGoldSoloBonus (int32)
            // NetworkVarNames: m_iCreepGoldKill (int32)
            // NetworkVarNames: m_iCreepGoldAirOrb (int32)
            // NetworkVarNames: m_iCreepGoldGroundOrb (int32)
            // NetworkVarNames: m_iCreepGoldDeny (int32)
            // NetworkVarNames: m_iCreepGoldNeutral (int32)
            // NetworkVarNames: m_iFarmBaseline (int32)
            // NetworkVarNames: m_iHealth (int32)
            // NetworkVarNames: m_iPlayerKills (int32)
            // NetworkVarNames: m_iPlayerAssists (int32)
            // NetworkVarNames: m_iDeaths (int32)
            // NetworkVarNames: m_iDenies (int32)
            // NetworkVarNames: m_iLastHits (int32)
            // NetworkVarNames: m_bAlive (bool)
            // NetworkVarNames: m_nHeroDraftPosition (int32)
            // NetworkVarNames: m_bUltimateTrained (bool)
            // NetworkVarNames: m_flUltimateCooldownStart (GameTime_t)
            // NetworkVarNames: m_flUltimateCooldownEnd (GameTime_t)
            // NetworkVarNames: m_bHasRejuvenator (bool)
            // NetworkVarNames: m_bHasRebirth (bool)
            // NetworkVarNames: m_iHeroDamage (int32)
            // NetworkVarNames: m_iHeroHealing (int32)
            // NetworkVarNames: m_iSelfHealing (int32)
            // NetworkVarNames: m_iObjectiveDamage (int32)
            // NetworkVarNames: m_nHeroAbilityUpgradeBits (int32)
            // NetworkVarNames: m_vecUpgrades (EntitySubclassID_t)
            // NetworkVarNames: m_vecBonusCounterAbilities (EntitySubclassID_t)
            // NetworkVarNames: m_vecBonusCounterValues (int32)
            // NetworkVarNames: m_tHeldItem (AbilityID_t)
            // NetworkVarNames: m_vecImbuements (ItemImbuementPair_t)
            // NetworkVarNames: m_vecDynamicAbilityValues (DynamicAbilityValues_t)
            // NetworkVarNames: m_vecStatViewerModifierValues (StatViewerModifierValues_t)
            namespace PlayerDataGlobal_t {
                constexpr std::ptrdiff_t m_iLevel = 0x8; // 
                constexpr std::ptrdiff_t m_iMaxAmmo = 0xC; // 
                constexpr std::ptrdiff_t m_iHealthMax = 0x10; // 
                constexpr std::ptrdiff_t m_flHealthRegen = 0x14; // 
                constexpr std::ptrdiff_t m_flRespawnTime = 0x18; // 
                constexpr std::ptrdiff_t m_nHeroID = 0x1C; // 
                constexpr std::ptrdiff_t m_iGoldNetWorth = 0x20; // 
                constexpr std::ptrdiff_t m_iAPNetWorth = 0x24; // 
                constexpr std::ptrdiff_t m_iCreepGold = 0x28; // 
                constexpr std::ptrdiff_t m_iCreepGoldSoloBonus = 0x2C; // 
                constexpr std::ptrdiff_t m_iCreepGoldKill = 0x30; // 
                constexpr std::ptrdiff_t m_iCreepGoldAirOrb = 0x34; // 
                constexpr std::ptrdiff_t m_iCreepGoldGroundOrb = 0x38; // 
                constexpr std::ptrdiff_t m_iCreepGoldDeny = 0x3C; // 
                constexpr std::ptrdiff_t m_iCreepGoldNeutral = 0x40; // 
                constexpr std::ptrdiff_t m_iFarmBaseline = 0x44; // 
                constexpr std::ptrdiff_t m_iHealth = 0x48; // 
                constexpr std::ptrdiff_t m_iPlayerKills = 0x4C; // 
                constexpr std::ptrdiff_t m_iPlayerAssists = 0x50; // 
                constexpr std::ptrdiff_t m_iDeaths = 0x54; // 
                constexpr std::ptrdiff_t m_iDenies = 0x58; // 
                constexpr std::ptrdiff_t m_iLastHits = 0x5C; // 
                constexpr std::ptrdiff_t m_bAlive = 0x60; // 
                constexpr std::ptrdiff_t m_nHeroDraftPosition = 0x64; // 
                constexpr std::ptrdiff_t m_bUltimateTrained = 0x68; // 
                constexpr std::ptrdiff_t m_flUltimateCooldownStart = 0x6C; // 
                constexpr std::ptrdiff_t m_flUltimateCooldownEnd = 0x70; // 
                constexpr std::ptrdiff_t m_bHasRejuvenator = 0x74; // 
                constexpr std::ptrdiff_t m_bHasRebirth = 0x75; // 
                constexpr std::ptrdiff_t m_iHeroDamage = 0x78; // 
                constexpr std::ptrdiff_t m_iHeroHealing = 0x7C; // 
                constexpr std::ptrdiff_t m_iSelfHealing = 0x80; // 
                constexpr std::ptrdiff_t m_iObjectiveDamage = 0x84; // 
                constexpr std::ptrdiff_t m_nHeroAbilityUpgradeBits = 0x88; // 
                constexpr std::ptrdiff_t m_vecUpgrades = 0x98; // 
                constexpr std::ptrdiff_t m_vecBonusCounterAbilities = 0xB0; // 
                constexpr std::ptrdiff_t m_vecBonusCounterValues = 0xC8; // 
                constexpr std::ptrdiff_t m_tHeldItem = 0xE0; // 
                constexpr std::ptrdiff_t m_vecImbuements = 0xE8; // 
                constexpr std::ptrdiff_t m_vecDynamicAbilityValues = 0x138; // 
                constexpr std::ptrdiff_t m_vecStatViewerModifierValues = 0x188; // 
            }
            // Parent: CLogicalEntity
            // Field count: 7
            namespace CLogicRelay {
                constexpr std::ptrdiff_t m_OnTrigger = 0x558; // 
                constexpr std::ptrdiff_t m_OnSpawn = 0x580; // 
                constexpr std::ptrdiff_t m_bDisabled = 0x5A8; // 
                constexpr std::ptrdiff_t m_bWaitForRefire = 0x5A9; // 
                constexpr std::ptrdiff_t m_bTriggerOnce = 0x5AA; // 
                constexpr std::ptrdiff_t m_bFastRetrigger = 0x5AB; // 
                constexpr std::ptrdiff_t m_bPassthoughCaller = 0x5AC; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 6
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbility_Mirage_Tornado_VData {
                constexpr std::ptrdiff_t m_TornadoCastParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_CasterModifier = 0x1628; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_WhirlwindEvasionModifier = 0x1638; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_TornadoAura = 0x1648; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_GrenadeTrailModifier = 0x1658; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_cameraSequenceTravelingInTornado = 0x1668; // CitadelCameraOperationsSequence_t
            }
            // Parent: CCitadelBaseYamatoAbility
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_nPowerLevel (int)
            namespace CCitadel_Ability_PowerSlash {
                constexpr std::ptrdiff_t m_nPowerLevel = 0xC8C; // 
                constexpr std::ptrdiff_t m_nCastParticle = 0xC90; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Bomber_Ability02 {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_HealthSwap {
            }
            // Parent: CCitadelBaseAbilityServerOnly
            // Field count: 0
            namespace CTier3BossAbility {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Base {
            }
            // Parent: CCitadel_Item
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_nFastFireEndTime (GameTime_t)
            namespace CCitadel_WeaponUpgrade_BurstFire {
                constexpr std::ptrdiff_t m_nFastFireEndTime = 0xC90; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_ArmorUpgrade_HealOnLevel {
            }
            // Parent: C_PointCamera
            // Field count: 1
            namespace C_PointCameraVFOV {
                constexpr std::ptrdiff_t m_flVerticalFOV = 0x5B8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_Synth_Barrage_Caster {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CAbility_Synth_Pulse {
            }
            // Parent: CCitadel_Modifier_StunnedVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_VacuumAuraTargetModifierVData {
                constexpr std::ptrdiff_t m_flOuterSpeedScale = 0x6E8; // 
                constexpr std::ptrdiff_t m_flSpeedScaleBias = 0x6EC; // 
                constexpr std::ptrdiff_t m_TargetLoopingSound = 0x6F0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Chrono_KineticCarbine_Slow {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_PowerJump {
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CModifier_Upgrade_ArcaneMedallion {
            }
            // Parent: C_BaseTrigger
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_vExitOrigin (Vector)
            namespace C_CitadelTeleportTrigger {
                constexpr std::ptrdiff_t m_vExitOrigin = 0x838; // 
            }
            // Parent: C_BaseModelEntity
            // Field count: 73
            //
            // Metadata:
            // NetworkVarNames: m_bEnabled (bool)
            // NetworkVarNames: m_nColorMode (int)
            // NetworkVarNames: m_Color (Color)
            // NetworkVarNames: m_flColorTemperature (float)
            // NetworkVarNames: m_flBrightness (float)
            // NetworkVarNames: m_flBrightnessScale (float)
            // NetworkVarNames: m_nDirectLight (int)
            // NetworkVarNames: m_nBakedShadowIndex (int)
            // NetworkVarNames: m_nLuminaireShape (int)
            // NetworkVarNames: m_flLuminaireSize (float)
            // NetworkVarNames: m_flLuminaireAnisotropy (float)
            // NetworkVarNames: m_LightStyleString (CUtlString)
            // NetworkVarNames: m_flLightStyleStartTime (GameTime_t)
            // NetworkVarNames: m_QueuedLightStyleStrings (CUtlString)
            // NetworkVarNames: m_LightStyleEvents (CUtlString)
            // NetworkVarNames: m_LightStyleTargets (CHandle<C_BaseModelEntity>)
            // NetworkVarNames: m_hLightCookie (HRenderTextureStrong)
            // NetworkVarNames: m_flShape (float)
            // NetworkVarNames: m_flSoftX (float)
            // NetworkVarNames: m_flSoftY (float)
            // NetworkVarNames: m_flSkirt (float)
            // NetworkVarNames: m_flSkirtNear (float)
            // NetworkVarNames: m_vSizeParams (Vector)
            // NetworkVarNames: m_flRange (float)
            // NetworkVarNames: m_vShear (Vector)
            // NetworkVarNames: m_nBakeSpecularToCubemaps (int)
            // NetworkVarNames: m_vBakeSpecularToCubemapsSize (Vector)
            // NetworkVarNames: m_nCastShadows (int)
            // NetworkVarNames: m_nShadowMapSize (int)
            // NetworkVarNames: m_nShadowPriority (int)
            // NetworkVarNames: m_bContactShadow (bool)
            // NetworkVarNames: m_nBounceLight (int)
            // NetworkVarNames: m_flBounceScale (float)
            // NetworkVarNames: m_flMinRoughness (float)
            // NetworkVarNames: m_vAlternateColor (Vector)
            // NetworkVarNames: m_fAlternateColorBrightness (float)
            // NetworkVarNames: m_nFog (int)
            // NetworkVarNames: m_flFogStrength (float)
            // NetworkVarNames: m_nFogShadows (int)
            // NetworkVarNames: m_flFogScale (float)
            // NetworkVarNames: m_bFogMixedShadows (bool)
            // NetworkVarNames: m_flFadeSizeStart (float)
            // NetworkVarNames: m_flFadeSizeEnd (float)
            // NetworkVarNames: m_flShadowFadeSizeStart (float)
            // NetworkVarNames: m_flShadowFadeSizeEnd (float)
            // NetworkVarNames: m_bPrecomputedFieldsValid (bool)
            // NetworkVarNames: m_vPrecomputedBoundsMins (Vector)
            // NetworkVarNames: m_vPrecomputedBoundsMaxs (Vector)
            // NetworkVarNames: m_vPrecomputedOBBOrigin (Vector)
            // NetworkVarNames: m_vPrecomputedOBBAngles (QAngle)
            // NetworkVarNames: m_vPrecomputedOBBExtent (Vector)
            // NetworkVarNames: m_nPrecomputedSubFrusta (int)
            // NetworkVarNames: m_vPrecomputedOBBOrigin0 (Vector)
            // NetworkVarNames: m_vPrecomputedOBBAngles0 (QAngle)
            // NetworkVarNames: m_vPrecomputedOBBExtent0 (Vector)
            // NetworkVarNames: m_vPrecomputedOBBOrigin1 (Vector)
            // NetworkVarNames: m_vPrecomputedOBBAngles1 (QAngle)
            // NetworkVarNames: m_vPrecomputedOBBExtent1 (Vector)
            // NetworkVarNames: m_vPrecomputedOBBOrigin2 (Vector)
            // NetworkVarNames: m_vPrecomputedOBBAngles2 (QAngle)
            // NetworkVarNames: m_vPrecomputedOBBExtent2 (Vector)
            // NetworkVarNames: m_vPrecomputedOBBOrigin3 (Vector)
            // NetworkVarNames: m_vPrecomputedOBBAngles3 (QAngle)
            // NetworkVarNames: m_vPrecomputedOBBExtent3 (Vector)
            // NetworkVarNames: m_vPrecomputedOBBOrigin4 (Vector)
            // NetworkVarNames: m_vPrecomputedOBBAngles4 (QAngle)
            // NetworkVarNames: m_vPrecomputedOBBExtent4 (Vector)
            // NetworkVarNames: m_vPrecomputedOBBOrigin5 (Vector)
            // NetworkVarNames: m_vPrecomputedOBBAngles5 (QAngle)
            // NetworkVarNames: m_vPrecomputedOBBExtent5 (Vector)
            // NetworkVarNames: m_VisClusters (uint16)
            namespace C_BarnLight {
                constexpr std::ptrdiff_t m_bEnabled = 0x830; // 
                constexpr std::ptrdiff_t m_nColorMode = 0x834; // 
                constexpr std::ptrdiff_t m_Color = 0x838; // 
                constexpr std::ptrdiff_t m_flColorTemperature = 0x83C; // 
                constexpr std::ptrdiff_t m_flBrightness = 0x840; // 
                constexpr std::ptrdiff_t m_flBrightnessScale = 0x844; // 
                constexpr std::ptrdiff_t m_nDirectLight = 0x848; // 
                constexpr std::ptrdiff_t m_nBakedShadowIndex = 0x84C; // 
                constexpr std::ptrdiff_t m_nLuminaireShape = 0x850; // 
                constexpr std::ptrdiff_t m_flLuminaireSize = 0x854; // 
                constexpr std::ptrdiff_t m_flLuminaireAnisotropy = 0x858; // 
                constexpr std::ptrdiff_t m_LightStyleString = 0x860; // 
                constexpr std::ptrdiff_t m_flLightStyleStartTime = 0x868; // 
                constexpr std::ptrdiff_t m_QueuedLightStyleStrings = 0x870; // C_NetworkUtlVectorBase<CUtlString>
                constexpr std::ptrdiff_t m_LightStyleEvents = 0x888; // C_NetworkUtlVectorBase<CUtlString>
                constexpr std::ptrdiff_t m_LightStyleTargets = 0x8A0; // 
                constexpr std::ptrdiff_t m_StyleEvent = 0x8B8; // 
                constexpr std::ptrdiff_t m_hLightCookie = 0x958; // 
                constexpr std::ptrdiff_t m_flShape = 0x960; // 
                constexpr std::ptrdiff_t m_flSoftX = 0x964; // 
                constexpr std::ptrdiff_t m_flSoftY = 0x968; // 
                constexpr std::ptrdiff_t m_flSkirt = 0x96C; // 
                constexpr std::ptrdiff_t m_flSkirtNear = 0x970; // 
                constexpr std::ptrdiff_t m_vSizeParams = 0x974; // 
                constexpr std::ptrdiff_t m_flRange = 0x980; // 
                constexpr std::ptrdiff_t m_vShear = 0x984; // 
                constexpr std::ptrdiff_t m_nBakeSpecularToCubemaps = 0x990; // 
                constexpr std::ptrdiff_t m_vBakeSpecularToCubemapsSize = 0x994; // 
                constexpr std::ptrdiff_t m_nCastShadows = 0x9A0; // 
                constexpr std::ptrdiff_t m_nShadowMapSize = 0x9A4; // 
                constexpr std::ptrdiff_t m_nShadowPriority = 0x9A8; // 
                constexpr std::ptrdiff_t m_bContactShadow = 0x9AC; // 
                constexpr std::ptrdiff_t m_nBounceLight = 0x9B0; // 
                constexpr std::ptrdiff_t m_flBounceScale = 0x9B4; // 
                constexpr std::ptrdiff_t m_flMinRoughness = 0x9B8; // 
                constexpr std::ptrdiff_t m_vAlternateColor = 0x9BC; // 
                constexpr std::ptrdiff_t m_fAlternateColorBrightness = 0x9C8; // 
                constexpr std::ptrdiff_t m_nFog = 0x9CC; // 
                constexpr std::ptrdiff_t m_flFogStrength = 0x9D0; // 
                constexpr std::ptrdiff_t m_nFogShadows = 0x9D4; // 
                constexpr std::ptrdiff_t m_flFogScale = 0x9D8; // 
                constexpr std::ptrdiff_t m_bFogMixedShadows = 0x9DC; // 
                constexpr std::ptrdiff_t m_flFadeSizeStart = 0x9E0; // 
                constexpr std::ptrdiff_t m_flFadeSizeEnd = 0x9E4; // 
                constexpr std::ptrdiff_t m_flShadowFadeSizeStart = 0x9E8; // 
                constexpr std::ptrdiff_t m_flShadowFadeSizeEnd = 0x9EC; // 
                constexpr std::ptrdiff_t m_bPrecomputedFieldsValid = 0x9F0; // 
                constexpr std::ptrdiff_t m_vPrecomputedBoundsMins = 0x9F4; // 
                constexpr std::ptrdiff_t m_vPrecomputedBoundsMaxs = 0xA00; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBOrigin = 0xA0C; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBAngles = 0xA18; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBExtent = 0xA24; // 
                constexpr std::ptrdiff_t m_nPrecomputedSubFrusta = 0xA30; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBOrigin0 = 0xA34; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBAngles0 = 0xA40; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBExtent0 = 0xA4C; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBOrigin1 = 0xA58; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBAngles1 = 0xA64; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBExtent1 = 0xA70; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBOrigin2 = 0xA7C; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBAngles2 = 0xA88; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBExtent2 = 0xA94; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBOrigin3 = 0xAA0; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBAngles3 = 0xAAC; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBExtent3 = 0xAB8; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBOrigin4 = 0xAC4; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBAngles4 = 0xAD0; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBExtent4 = 0xADC; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBOrigin5 = 0xAE8; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBAngles5 = 0xAF4; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBExtent5 = 0xB00; // 
                constexpr std::ptrdiff_t m_bInitialBoneSetup = 0xB50; // 
                constexpr std::ptrdiff_t m_VisClusters = 0xB58; // C_NetworkUtlVectorBase<uint16>
            }
            // Parent: C_BaseEntity
            // Field count: 8
            //
            // Metadata:
            // NetworkVarNames: m_flAutoExposureMin (float)
            // NetworkVarNames: m_flAutoExposureMax (float)
            // NetworkVarNames: m_flTonemapPercentTarget (float)
            // NetworkVarNames: m_flTonemapPercentBrightPixels (float)
            // NetworkVarNames: m_flTonemapMinAvgLum (float)
            // NetworkVarNames: m_flExposureAdaptationSpeedUp (float)
            // NetworkVarNames: m_flExposureAdaptationSpeedDown (float)
            // NetworkVarNames: m_flTonemapEVSmoothingRange (float)
            namespace C_TonemapController2 {
                constexpr std::ptrdiff_t m_flAutoExposureMin = 0x558; // 
                constexpr std::ptrdiff_t m_flAutoExposureMax = 0x55C; // 
                constexpr std::ptrdiff_t m_flTonemapPercentTarget = 0x560; // 
                constexpr std::ptrdiff_t m_flTonemapPercentBrightPixels = 0x564; // 
                constexpr std::ptrdiff_t m_flTonemapMinAvgLum = 0x568; // 
                constexpr std::ptrdiff_t m_flExposureAdaptationSpeedUp = 0x56C; // 
                constexpr std::ptrdiff_t m_flExposureAdaptationSpeedDown = 0x570; // 
                constexpr std::ptrdiff_t m_flTonemapEVSmoothingRange = 0x574; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_SpinVData {
                constexpr std::ptrdiff_t m_AoEParticle = 0x608; // 
                constexpr std::ptrdiff_t m_SlowModifier = 0x6E8; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelAbilityVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityIntimidateVData {
                constexpr std::ptrdiff_t m_EnemyModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_AoEPlayerParticle = 0x1568; // 
                constexpr std::ptrdiff_t m_AoEParticle = 0x1648; // 
            }
            // Parent: CCitadelAnimatingModelEntity
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_hAbility (CHandle<CCitadelBaseAbility>)
            // NetworkVarNames: m_bFloating (bool)
            namespace CCitadel_MobileResupply {
                constexpr std::ptrdiff_t m_hAbility = 0xB58; // 
                constexpr std::ptrdiff_t m_bFloating = 0xB5C; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Wraith_RapidFireVData {
                constexpr std::ptrdiff_t m_RapidFireParticle = 0x608; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_HornetLeap {
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 6
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_SilenceProcWatcherVData {
                constexpr std::ptrdiff_t m_BuildUpModifier = 0x638; // 
                constexpr std::ptrdiff_t m_SilenceProcModifier = 0x648; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_SilenceActiveModifier = 0x658; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ImmunityModifier = 0x668; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_sInstantProcIfCasterHasModifier = 0x678; // 
                constexpr std::ptrdiff_t m_TracerParticle = 0x680; // 
            }
            // Parent: CEntitySubclassVDataBase
            // Field count: 78
            //
            // Metadata:
            // MGetKV3ClassDefaults
            // MVDataOverlayType
            namespace CitadelAbilityVData {
                constexpr std::ptrdiff_t m_eAbilityType = 0x28; // 
                constexpr std::ptrdiff_t m_eItemSlotType = 0x29; // 
                constexpr std::ptrdiff_t m_bDisabled = 0x2A; // 
                constexpr std::ptrdiff_t m_bInDevelopment = 0x2B; // 
                constexpr std::ptrdiff_t m_bStartTrained = 0x2C; // 
                constexpr std::ptrdiff_t m_iMaxLevel = 0x30; // 
                constexpr std::ptrdiff_t m_nAbilityPointsCost = 0x34; // 
                constexpr std::ptrdiff_t m_nAbillityUnlocksCost = 0x38; // 
                constexpr std::ptrdiff_t m_iUpdateTime = 0x40; // 
                constexpr std::ptrdiff_t m_AbilityBehaviorsBits = 0x4C; // CBitVecEnum<EAbilityBehavior_t>
                constexpr std::ptrdiff_t m_eAbilityTargetingLocation = 0x54; // 
                constexpr std::ptrdiff_t m_eAbilityTargetingShape = 0x58; // 
                constexpr std::ptrdiff_t m_flTargetingConeAngle = 0x5C; // 
                constexpr std::ptrdiff_t m_flTargetingConeHalfWidth = 0x60; // 
                constexpr std::ptrdiff_t m_bIncludeExtra2DCone = 0x64; // 
                constexpr std::ptrdiff_t m_eAbilityActivation = 0x68; // 
                constexpr std::ptrdiff_t m_TriggerButtonPreReqButton = 0x70; // 
                constexpr std::ptrdiff_t m_TriggerButtonOverride = 0x78; // 
                constexpr std::ptrdiff_t m_eAbilitySpectatePriority = 0x80; // 
                constexpr std::ptrdiff_t m_bitsInterruptingStates = 0x84; // 
                constexpr std::ptrdiff_t m_IncompatibleFilter = 0x9C; // 
                constexpr std::ptrdiff_t m_nAbilityTargetTypes = 0xAC; // 
                constexpr std::ptrdiff_t m_nAbilityTargetFlags = 0xB0; // 
                constexpr std::ptrdiff_t m_bitsPostCastEnabledStateMask = 0xB4; // 
                constexpr std::ptrdiff_t m_TargetAbilityEffectsToApply = 0xCC; // 
                constexpr std::ptrdiff_t m_bShowTargetingPreviewWhileChanneling = 0xD0; // 
                constexpr std::ptrdiff_t m_bShowTargetingPreviewWhileCasting = 0xD1; // 
                constexpr std::ptrdiff_t m_WeaponInfo = 0xD8; // 
                constexpr std::ptrdiff_t m_projectileInfo = 0x750; // 
                constexpr std::ptrdiff_t m_deploymentInfo = 0xAD0; // 
                constexpr std::ptrdiff_t m_mapAbilityProperties = 0xCB0; // 
                constexpr std::ptrdiff_t m_vecDependentAbilities = 0xCD8; // 
                constexpr std::ptrdiff_t m_vecAbilityUpgrades = 0xCF0; // 
                constexpr std::ptrdiff_t m_strCastAnimGraphParam = 0xD28; // 
                constexpr std::ptrdiff_t m_strSelectionNameOverride = 0xD30; // 
                constexpr std::ptrdiff_t m_strCastAnimSequenceName = 0xD38; // 
                constexpr std::ptrdiff_t m_AbilityTooltipDetails = 0xD40; // 
                constexpr std::ptrdiff_t m_strCSSClass = 0xD70; // 
                constexpr std::ptrdiff_t m_strAbilityImage = 0xD78; // 
                constexpr std::ptrdiff_t m_strMoviePreviewPath = 0xD88; // 
                constexpr std::ptrdiff_t m_HUDPanel = 0xD90; // 
                constexpr std::ptrdiff_t m_bShowInPassiveItemsArea = 0xDC8; // 
                constexpr std::ptrdiff_t m_bForceShowHUDPanel = 0xDC9; // 
                constexpr std::ptrdiff_t m_additionalAbilities = 0xDD0; // 
                constexpr std::ptrdiff_t m_strCancelAbilityKey = 0xDF0; // 
                constexpr std::ptrdiff_t m_strSecondaryStatName = 0xDF8; // 
                constexpr std::ptrdiff_t m_strCastButtonLocToken = 0xE00; // 
                constexpr std::ptrdiff_t m_strAltCastButtonLocToken = 0xE08; // 
                constexpr std::ptrdiff_t m_cameraSequenceCastStart = 0xE10; // CitadelCameraOperationsSequence_t
                constexpr std::ptrdiff_t m_bEndCastStartSequenceOnCastComplete = 0xE98; // 
                constexpr std::ptrdiff_t m_cameraSequenceCastComplete = 0xEA0; // CitadelCameraOperationsSequence_t
                constexpr std::ptrdiff_t m_cameraSequenceChannelStart = 0xF28; // CitadelCameraOperationsSequence_t
                constexpr std::ptrdiff_t m_bEndChannelStartSequenceOnChannelComplete = 0xFB0; // 
                constexpr std::ptrdiff_t m_flCameraPreviewOffset = 0xFB4; // 
                constexpr std::ptrdiff_t m_flCameraPreviewDistance = 0xFB8; // 
                constexpr std::ptrdiff_t m_flCameraPreviewSpeed = 0xFBC; // 
                constexpr std::ptrdiff_t m_previewParticle = 0xFC0; // 
                constexpr std::ptrdiff_t m_PreviewPathParticle = 0x10A0; // 
                constexpr std::ptrdiff_t m_mapCastEventParticles = 0x1180; // 
                constexpr std::ptrdiff_t m_skillshotHitParticle = 0x11A8; // 
                constexpr std::ptrdiff_t m_skillshotMissParticle = 0x1288; // 
                constexpr std::ptrdiff_t m_TargetingPreviewParticle = 0x1368; // 
                constexpr std::ptrdiff_t m_strSelectedSound = 0x1448; // 
                constexpr std::ptrdiff_t m_strUnselectedSound = 0x1458; // 
                constexpr std::ptrdiff_t m_strSelectedLoopSound = 0x1468; // 
                constexpr std::ptrdiff_t m_strCastSound = 0x1478; // 
                constexpr std::ptrdiff_t m_strChannelSound = 0x1488; // 
                constexpr std::ptrdiff_t m_strChannelLoopSound = 0x1498; // 
                constexpr std::ptrdiff_t m_strCastDelaySound = 0x14A8; // 
                constexpr std::ptrdiff_t m_strCastDelayLoopSound = 0x14B8; // 
                constexpr std::ptrdiff_t m_strHitConfirmationSound = 0x14C8; // 
                constexpr std::ptrdiff_t m_strDamageTakenSound = 0x14D8; // 
                constexpr std::ptrdiff_t m_strAbilityOffCooldownSound = 0x14E8; // 
                constexpr std::ptrdiff_t m_strAbilityChargeReadySound = 0x14F8; // 
                constexpr std::ptrdiff_t m_bPlayMeepMop = 0x1508; // 
                constexpr std::ptrdiff_t m_AutoChannelModifier = 0x1510; // 
                constexpr std::ptrdiff_t m_AutoCastDelayModifier = 0x1520; // 
                constexpr std::ptrdiff_t m_AutoIntrinsicModifiers = 0x1530; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_TrooperDisabledInvulnerabilityFX {
            }
            // Parent: C_SoundOpvarSetPointEntity
            // Field count: 0
            namespace C_SoundOpvarSetAutoRoomEntity {
            }
            // Parent: CCitadel_UtilityUpgrade_RocketBoots
            // Field count: 6
            //
            // Metadata:
            // NetworkVarNames: m_flCastTime (GameTime_t)
            // NetworkVarNames: m_bCrashingDown (bool)
            // NetworkVarNames: m_bImpulseApplied (bool)
            // NetworkVarNames: m_vecCrashPosition (Vector)
            // NetworkVarNames: m_vecCrashDirection (Vector)
            namespace CCitadel_UtilityUpgrade_RocketBooster {
                constexpr std::ptrdiff_t m_nTargetingParticleIndex = 0xD04; // 
                constexpr std::ptrdiff_t m_flCastTime = 0xD08; // 
                constexpr std::ptrdiff_t m_bCrashingDown = 0xD0C; // 
                constexpr std::ptrdiff_t m_bImpulseApplied = 0xD0D; // 
                constexpr std::ptrdiff_t m_vecCrashPosition = 0xD10; // 
                constexpr std::ptrdiff_t m_vecCrashDirection = 0xD1C; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_SelfBuffModifier {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Cadence_Anthem {
            }
            // Parent: CCitadelYamatoBaseVData
            // Field count: 21
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityPowerSlashVData {
                constexpr std::ptrdiff_t m_flAirDrag = 0x1550; // 
                constexpr std::ptrdiff_t m_flMaxPowerPadding = 0x1554; // 
                constexpr std::ptrdiff_t m_flEffectGroundTrace = 0x1558; // 
                constexpr std::ptrdiff_t m_flWhizbyMaxRange = 0x155C; // 
                constexpr std::ptrdiff_t m_flStartPosTestCapsuleLength = 0x1560; // 
                constexpr std::ptrdiff_t m_vecLongEffectOffset = 0x1564; // 
                constexpr std::ptrdiff_t m_PowerSlashParticle = 0x1570; // 
                constexpr std::ptrdiff_t m_PowerSlashFullParticle = 0x1650; // 
                constexpr std::ptrdiff_t m_ImpactParticle = 0x1730; // 
                constexpr std::ptrdiff_t m_CastParticle = 0x1810; // 
                constexpr std::ptrdiff_t m_PowerUpParticle = 0x18F0; // 
                constexpr std::ptrdiff_t m_strStartSound = 0x19D0; // 
                constexpr std::ptrdiff_t m_strDamageImpactSound = 0x19E0; // 
                constexpr std::ptrdiff_t m_strDamageImpactVictimSound = 0x19F0; // 
                constexpr std::ptrdiff_t m_strPowerUp1Sounds = 0x1A00; // 
                constexpr std::ptrdiff_t m_strPowerUp2Sounds = 0x1A10; // 
                constexpr std::ptrdiff_t m_strPowerUp3Sounds = 0x1A20; // 
                constexpr std::ptrdiff_t m_strWhizbySound = 0x1A30; // 
                constexpr std::ptrdiff_t m_strSlashSound = 0x1A40; // 
                constexpr std::ptrdiff_t m_strSlashFullSound = 0x1A50; // 
                constexpr std::ptrdiff_t m_SlowModifier = 0x1A60; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_IceGrenadeVData {
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_IceGrenadeSlowModifier = 0x1628; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ExplosionSound = 0x1638; // 
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_ArmorUpgrade_ReturnFireVData {
                constexpr std::ptrdiff_t m_ReactiveArmorModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_TechShieldImpact {
                constexpr std::ptrdiff_t m_AmbientEffect = 0xC0; // 
            }
            // Parent: C_AI_CitadelNPC
            // Field count: 0
            namespace C_NPC_PestilenceDrone {
            }
            // Parent: C_BaseFlex
            // Field count: 12
            //
            // Metadata:
            // NetworkVarNames: m_AttributeManager (CAttributeContainer)
            namespace C_EconEntity {
                constexpr std::ptrdiff_t m_AttributeManager = 0xCF8; // 
                constexpr std::ptrdiff_t m_bClientside = 0xE38; // 
                constexpr std::ptrdiff_t m_nDisableMode = 0xE3C; // 
                constexpr std::ptrdiff_t m_bParticleSystemsCreated = 0xE40; // 
                constexpr std::ptrdiff_t m_bForceDestroyAttachedParticlesImmediately = 0xE41; // 
                constexpr std::ptrdiff_t m_vecAttachedParticles = 0xE48; // 
                constexpr std::ptrdiff_t m_hViewmodelAttachment = 0xE60; // 
                constexpr std::ptrdiff_t m_iOldTeam = 0xE64; // 
                constexpr std::ptrdiff_t m_bAttachmentDirty = 0xE68; // 
                constexpr std::ptrdiff_t m_iOldStyle = 0xE69; // 
                constexpr std::ptrdiff_t m_hOldProvidee = 0xE6C; // 
                constexpr std::ptrdiff_t m_vecAttachedModels = 0xE70; // 
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Tokamak_EnemySmokeAOE_VData {
            }
            // Parent: C_CitadelProjectile
            // Field count: 0
            namespace C_Citadel_Projectile_DustStorm {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_WeaponUpgrade_SurgingPower {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_SmokeBomb {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            namespace CCitadel_Ability_ChargedShot {
                constexpr std::ptrdiff_t m_ChannelParticle = 0xC78; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Tier2Boss_RocketDamage_AuraDebuff {
            }
            // Parent: C_BarnLight
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_bShowLight (bool)
            namespace C_RectLight {
                constexpr std::ptrdiff_t m_bShowLight = 0xB78; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityCadenceAnthemVData {
                constexpr std::ptrdiff_t m_AnthemAOEModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CModifier_FleetfootBoots_BonusClip {
                constexpr std::ptrdiff_t m_nBonusClip = 0xC0; // 
            }
            // Parent: CCitadel_Modifier_StatStealBase
            // Field count: 0
            namespace CCitadel_Modifier_Siphon_Bullets_Watcher {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Glitch {
            }
            // Parent: CCitadel_Modifier_Disarmed
            // Field count: 0
            namespace CCitadel_Modifier_DisarmProc {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_ArmorUpgrade_VexBarrier {
            }
            // Parent: C_BaseModelEntity
            // Field count: 24
            //
            // Metadata:
            // MNetworkIncludeByUserGroup
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // NetworkVarNames: m_szSnapshotFileName (char)
            // NetworkVarNames: m_bActive (bool)
            // NetworkVarNames: m_bFrozen (bool)
            // NetworkVarNames: m_flFreezeTransitionDuration (float)
            // NetworkVarNames: m_nStopType (int)
            // NetworkVarNames: m_bAnimateDuringGameplayPause (bool)
            // NetworkVarNames: m_iEffectIndex (HParticleSystemDefinitionStrong)
            // NetworkVarNames: m_flStartTime (GameTime_t)
            // NetworkVarNames: m_flPreSimTime (float32)
            // NetworkVarNames: m_vServerControlPoints (Vector)
            // NetworkVarNames: m_iServerControlPointAssignments (uint8)
            // NetworkVarNames: m_hControlPointEnts (CHandle<CBaseEntity>)
            // NetworkVarNames: m_bNoSave (bool)
            // NetworkVarNames: m_bNoFreeze (bool)
            // NetworkVarNames: m_bNoRamp (bool)
            namespace C_ParticleSystem {
                constexpr std::ptrdiff_t m_szSnapshotFileName = 0x830; // 
                constexpr std::ptrdiff_t m_bActive = 0xA30; // 
                constexpr std::ptrdiff_t m_bFrozen = 0xA31; // 
                constexpr std::ptrdiff_t m_flFreezeTransitionDuration = 0xA34; // 
                constexpr std::ptrdiff_t m_nStopType = 0xA38; // 
                constexpr std::ptrdiff_t m_bAnimateDuringGameplayPause = 0xA3C; // 
                constexpr std::ptrdiff_t m_iEffectIndex = 0xA40; // 
                constexpr std::ptrdiff_t m_flStartTime = 0xA48; // 
                constexpr std::ptrdiff_t m_flPreSimTime = 0xA4C; // 
                constexpr std::ptrdiff_t m_vServerControlPoints = 0xA50; // 
                constexpr std::ptrdiff_t m_iServerControlPointAssignments = 0xA80; // 
                constexpr std::ptrdiff_t m_hControlPointEnts = 0xA84; // 
                constexpr std::ptrdiff_t m_bNoSave = 0xB84; // 
                constexpr std::ptrdiff_t m_bNoFreeze = 0xB85; // 
                constexpr std::ptrdiff_t m_bNoRamp = 0xB86; // 
                constexpr std::ptrdiff_t m_bStartActive = 0xB87; // 
                constexpr std::ptrdiff_t m_iszEffectName = 0xB88; // 
                constexpr std::ptrdiff_t m_iszControlPointNames = 0xB90; // 
                constexpr std::ptrdiff_t m_nDataCP = 0xD90; // 
                constexpr std::ptrdiff_t m_vecDataCPValue = 0xD94; // 
                constexpr std::ptrdiff_t m_nTintCP = 0xDA0; // 
                constexpr std::ptrdiff_t m_clrTint = 0xDA4; // 
                constexpr std::ptrdiff_t m_bOldActive = 0xDC8; // 
                constexpr std::ptrdiff_t m_bOldFrozen = 0xDC9; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 8
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Wrecker_UltimateVData {
                constexpr std::ptrdiff_t m_EnemyGrabModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_EnemyThrowModifier = 0x618; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_EnemyDamageModifier = 0x628; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_InvincibleModifier = 0x638; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_StartSound = 0x648; // 
                constexpr std::ptrdiff_t m_AmbientLoopingSound = 0x658; // 
                constexpr std::ptrdiff_t m_GrabSound = 0x668; // 
                constexpr std::ptrdiff_t m_ThrowSound = 0x678; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Low_Health_Glow {
                constexpr std::ptrdiff_t m_nFXIndex = 0xC0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Magic_Clarity_Buff {
                constexpr std::ptrdiff_t m_bAbilityLocked = 0xF8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_BreakablePropExtraStaminaVData {
                constexpr std::ptrdiff_t m_nExtraStamina = 0x608; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Thumper_3 {
            }
            // Parent: CCitadelModifierVData
            // Field count: 9
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_StickyBombAttachedVData {
                constexpr std::ptrdiff_t m_BombAttachedParticle = 0x608; // 
                constexpr std::ptrdiff_t m_StunAttachedParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x7C8; // 
                constexpr std::ptrdiff_t m_BombAttachedVictimTeamParticle = 0x8A8; // 
                constexpr std::ptrdiff_t m_strExplodeSound = 0x988; // 
                constexpr std::ptrdiff_t m_strTickTockSound = 0x998; // 
                constexpr std::ptrdiff_t m_strTickTockFastSound = 0x9A8; // 
                constexpr std::ptrdiff_t m_DebuffModifier = 0x9B8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DetonateWarningTime = 0x9C8; // 
            }
            // Parent: CCitadel_Modifier_StunnedVData
            // Field count: 6
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierLashGrappleEnemyDebuffVData {
                constexpr std::ptrdiff_t m_GrappleParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_LaunchParticle = 0x7C8; // 
                constexpr std::ptrdiff_t m_ImpactParticle = 0x8A8; // 
                constexpr std::ptrdiff_t m_RopeParticle = 0x988; // 
                constexpr std::ptrdiff_t m_ImpactSound = 0xA68; // 
                constexpr std::ptrdiff_t m_DebuffModifier = 0xA78; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_SpeedBoost {
            }
            // Parent: CBaseLockonAbilityVData
            // Field count: 14
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityLashUltimateVData {
                constexpr std::ptrdiff_t m_TargetPreviewParticle = 0x1568; // 
                constexpr std::ptrdiff_t m_LaunchParticle = 0x1648; // 
                constexpr std::ptrdiff_t m_UltimateCastParticle = 0x1728; // 
                constexpr std::ptrdiff_t m_UltimateCastEnemyParticle = 0x1808; // 
                constexpr std::ptrdiff_t m_strThrowEnemyAnimGraphParam = 0x18E8; // 
                constexpr std::ptrdiff_t m_GrappleEnemyModifier = 0x18F0; // 
                constexpr std::ptrdiff_t m_GrabSound = 0x1900; // 
                constexpr std::ptrdiff_t m_MissSound = 0x1910; // 
                constexpr std::ptrdiff_t m_ThrowSound = 0x1920; // 
                constexpr std::ptrdiff_t m_flAirSpeedMax = 0x1930; // 
                constexpr std::ptrdiff_t m_flFallSpeedMax = 0x1934; // 
                constexpr std::ptrdiff_t m_flAirDrag = 0x1938; // 
                constexpr std::ptrdiff_t m_flMaxPitchRangeScale = 0x193C; // 
                constexpr std::ptrdiff_t m_flThrowAnimTossPoint = 0x1940; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_LastBreath {
                constexpr std::ptrdiff_t m_flDamageToAbsorb = 0x168; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Bomber_Ability03 {
            }
            // Parent: CScaleFunctionBase
            // Field count: 0
            namespace CScaleFunctionAbilityProperty_NanoTechRoundsDamage {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_ArmorUpgrade_Stimpak {
            }
            // Parent: CCitadel_Modifier_Stunned
            // Field count: 2
            namespace CCitadel_Modifier_Knockback {
                constexpr std::ptrdiff_t m_flForce = 0xC8; // 
                constexpr std::ptrdiff_t m_bKnockedBack = 0xCC; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            namespace CAbility_Synth_Grasp {
                constexpr std::ptrdiff_t m_vecTetheredEnemies = 0xC78; // 
            }
            // Parent: CPlayerPawnComponent
            // Field count: 6
            //
            // Metadata:
            // NetworkVarNames: m_iObserverMode (uint8)
            // NetworkVarNames: m_hObserverTarget (CHandle<CBaseEntity>)
            namespace CPlayer_ObserverServices {
                constexpr std::ptrdiff_t m_iObserverMode = 0x40; // 
                constexpr std::ptrdiff_t m_hObserverTarget = 0x44; // 
                constexpr std::ptrdiff_t m_iObserverLastMode = 0x48; // 
                constexpr std::ptrdiff_t m_bForcedObserverMode = 0x4C; // 
                constexpr std::ptrdiff_t m_flObserverChaseDistance = 0x50; // 
                constexpr std::ptrdiff_t m_flObserverChaseDistanceCalcTime = 0x54; // 
            }
            // Parent: CCitadelBaseTriggerAbility
            // Field count: 1
            namespace CCitadel_Ability_TangoTether_Trigger {
                constexpr std::ptrdiff_t m_hBaseAbility = 0xC8C; // 
            }
            // Parent: C_BaseModelEntity
            // Field count: 1
            //
            // Metadata:
            // MNetworkIncludeByName
            // NetworkVarNames: m_iLane (int)
            namespace C_AssignedLaneParticle {
                constexpr std::ptrdiff_t m_iLane = 0x850; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityThumper4VData {
                constexpr std::ptrdiff_t m_PullAOEModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Bounce_Pad_Stomp {
                constexpr std::ptrdiff_t m_bStomped = 0x2F0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ChargedBomb {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_IncendiaryThinker {
            }
            // Parent: CPlayerPawnComponent
            // Field count: 0
            namespace CPlayer_WaterServices {
            }
            // Parent: CCitadelAnimatingModelEntity
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_hAbility (CHandle<CCitadelBaseAbility>)
            namespace C_Citadel_Nano_Predatory_Statue {
                constexpr std::ptrdiff_t m_hAbility = 0xB60; // 
                constexpr std::ptrdiff_t m_flLifetime = 0xB64; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadelBaseYamatoAbility {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_SleepDagger_Drowsy {
            }
            // Parent: CCitadel_Modifier_ShieldTracker_Base
            // Field count: 0
            namespace CCitadel_Modifier_ShieldTracker_Magic {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_CanDamageTier3Phase2 {
            }
            // Parent: CCitadelBaseDashCastAbility
            // Field count: 0
            namespace CCitadel_Ability_Cadence_SilenceContraptions {
            }
            // Parent: CitadelAbilityVData
            // Field count: 26
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityLashDownStrikeVData {
                constexpr std::ptrdiff_t m_TargetPreviewParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_strGroundCastAnimGraphParam = 0x1628; // 
                constexpr std::ptrdiff_t m_strAirCastAnimGraphParam = 0x1630; // 
                constexpr std::ptrdiff_t m_StompParticle = 0x1638; // 
                constexpr std::ptrdiff_t m_StompLineParticle = 0x1718; // 
                constexpr std::ptrdiff_t m_StompLineObstructedParticle = 0x17F8; // 
                constexpr std::ptrdiff_t m_StompImpactParticle = 0x18D8; // 
                constexpr std::ptrdiff_t m_StompExplosionSound = 0x19B8; // 
                constexpr std::ptrdiff_t m_StompEnemyImpactSound = 0x19C8; // 
                constexpr std::ptrdiff_t m_DownStrikeModifier = 0x19D8; // 
                constexpr std::ptrdiff_t m_ImpactModifier = 0x19E8; // 
                constexpr std::ptrdiff_t m_flHeightUILingerTime = 0x19F8; // 
                constexpr std::ptrdiff_t m_flDamageFrustumHalfWidth = 0x19FC; // 
                constexpr std::ptrdiff_t m_flDamageFrustumAngle = 0x1A00; // 
                constexpr std::ptrdiff_t m_flDamageWaveSpeed = 0x1A04; // 
                constexpr std::ptrdiff_t m_flDamageTraceProbeDamageRadius = 0x1A08; // 
                constexpr std::ptrdiff_t m_flDamageTraceProbeWorldRadius = 0x1A0C; // 
                constexpr std::ptrdiff_t m_flDamageTraceProbeStepUpHeight = 0x1A10; // 
                constexpr std::ptrdiff_t m_flDamageTraceProbeStepDownHeight = 0x1A14; // 
                constexpr std::ptrdiff_t m_flDamageTraceProbeDropDownRate = 0x1A18; // 
                constexpr std::ptrdiff_t m_flInitialDamageRadiusInMeters = 0x1A1C; // 
                constexpr std::ptrdiff_t m_nGroundCrackGap = 0x1A20; // 
                constexpr std::ptrdiff_t m_flGroupLengthTolerance = 0x1A24; // 
                constexpr std::ptrdiff_t m_flDamageEffectScaleMin = 0x1A28; // 
                constexpr std::ptrdiff_t m_flDamageEffectScaleMax = 0x1A2C; // 
                constexpr std::ptrdiff_t m_flTrackAmount = 0x1A30; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_ProjectMindVData {
                constexpr std::ptrdiff_t m_ProjectMindModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_AcolytesGlove {
            }
            // Parent: CitadelItemVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Item_BubbleVData {
                constexpr std::ptrdiff_t m_CastParticle = 0x1590; // 
                constexpr std::ptrdiff_t m_CastTargetSound = 0x1670; // 
                constexpr std::ptrdiff_t m_BubbleModifier = 0x1680; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierHoldingGoldenIdolVData {
                constexpr std::ptrdiff_t m_IdolParticle = 0x608; // 
            }
            // Parent: None
            // Field count: 6
            namespace SequenceHistory_t {
                constexpr std::ptrdiff_t m_hSequence = 0x0; // 
                constexpr std::ptrdiff_t m_flSeqStartTime = 0x4; // 
                constexpr std::ptrdiff_t m_flSeqFixedCycle = 0x8; // 
                constexpr std::ptrdiff_t m_nSeqLoopMode = 0xC; // 
                constexpr std::ptrdiff_t m_flPlaybackRate = 0x10; // 
                constexpr std::ptrdiff_t m_flCyclesPerSecond = 0x14; // 
            }
            // Parent: C_PathParticleRope
            // Field count: 1
            namespace C_CitadelZiplinePath {
                constexpr std::ptrdiff_t m_iLaneNumber = 0x668; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_BaseHeldItemVData {
                constexpr std::ptrdiff_t m_ItemModel = 0x1548; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_Mirage_Traveler_FireRate {
            }
            // Parent: CitadelAbilityVData
            // Field count: 6
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityCadenceGrandFinaleVData {
                constexpr std::ptrdiff_t m_StageModel = 0x1548; // 
                constexpr std::ptrdiff_t m_flStageModelHeight = 0x1628; // 
                constexpr std::ptrdiff_t m_flStageModelWidth = 0x162C; // 
                constexpr std::ptrdiff_t m_flStageModelLength = 0x1630; // 
                constexpr std::ptrdiff_t m_flStageModelScale = 0x1634; // 
                constexpr std::ptrdiff_t m_GrandFinaleAOEModifier = 0x1638; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_Stunned
            // Field count: 1
            namespace CCitadel_Modifier_Gravity_Lasso_Enemy {
                constexpr std::ptrdiff_t m_eHoldPosition = 0xC8; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 8
            //
            // Metadata:
            // NetworkVarNames: m_flBoostYaw (float)
            // NetworkVarNames: m_vecCrashPosition (Vector)
            // NetworkVarNames: m_vecCrashDirection (Vector)
            // NetworkVarNames: m_eLeapState (ELeapState_t)
            // NetworkVarNames: m_flStateEnterTime (GameTime_t)
            // NetworkVarNames: m_flNextStateTime (CCitadelAutoScaledTime)
            // NetworkVarNames: m_flBoostEndTime (CCitadelAutoScaledTime)
            namespace CCitadel_Ability_Bull_Leap {
                constexpr std::ptrdiff_t m_flBoostYaw = 0xC78; // 
                constexpr std::ptrdiff_t m_vecCrashPosition = 0xC7C; // 
                constexpr std::ptrdiff_t m_vecCrashDirection = 0xC88; // 
                constexpr std::ptrdiff_t m_eLeapState = 0xC94; // 
                constexpr std::ptrdiff_t m_flStateEnterTime = 0xC98; // 
                constexpr std::ptrdiff_t m_flNextStateTime = 0xCA0; // 
                constexpr std::ptrdiff_t m_flBoostEndTime = 0xCB8; // 
                constexpr std::ptrdiff_t m_vecLastVel = 0xE28; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Infuser {
            }
            // Parent: CCitadelBaseAbilityServerOnly
            // Field count: 1
            namespace CCitadel_Ability_Tier2Boss_RocketBarrage {
                constexpr std::ptrdiff_t m_nGrenadesLeft = 0xC78; // 
            }
            // Parent: C_BaseEntity
            // Field count: 2
            namespace CPointModifierThinker {
                constexpr std::ptrdiff_t m_hModifier = 0x558; // 
                constexpr std::ptrdiff_t m_bSendToClients = 0x570; // 
            }
            // Parent: C_BaseModelEntity
            // Field count: 9
            //
            // Metadata:
            // NetworkVarNames: m_hDecalMaterial (HMaterialStrong)
            // NetworkVarNames: m_flWidth (float)
            // NetworkVarNames: m_flHeight (float)
            // NetworkVarNames: m_flDepth (float)
            // NetworkVarNames: m_nRenderOrder (uint32)
            // NetworkVarNames: m_bProjectOnWorld (bool)
            // NetworkVarNames: m_bProjectOnCharacters (bool)
            // NetworkVarNames: m_bProjectOnWater (bool)
            // NetworkVarNames: m_flDepthSortBias (float)
            namespace C_EnvDecal {
                constexpr std::ptrdiff_t m_hDecalMaterial = 0x830; // CStrongHandle<InfoForResourceTypeIMaterial2>
                constexpr std::ptrdiff_t m_flWidth = 0x838; // 
                constexpr std::ptrdiff_t m_flHeight = 0x83C; // 
                constexpr std::ptrdiff_t m_flDepth = 0x840; // 
                constexpr std::ptrdiff_t m_nRenderOrder = 0x844; // 
                constexpr std::ptrdiff_t m_bProjectOnWorld = 0x848; // 
                constexpr std::ptrdiff_t m_bProjectOnCharacters = 0x849; // 
                constexpr std::ptrdiff_t m_bProjectOnWater = 0x84A; // 
                constexpr std::ptrdiff_t m_flDepthSortBias = 0x84C; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_Mirage_Tornado_HoldInPlace {
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityLockDownVData {
                constexpr std::ptrdiff_t m_CastParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1628; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_NearbyEnemyBoostVData {
                constexpr std::ptrdiff_t m_BerserkerSound = 0x608; // 
                constexpr std::ptrdiff_t m_BuffModifier = 0x618; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_BaseEntity
            // Field count: 18
            //
            // Metadata:
            // MNetworkIncludeByUserGroup
            // NetworkVarNames: m_MinFalloff (float32)
            // NetworkVarNames: m_MaxFalloff (float32)
            // NetworkVarNames: m_flFadeInDuration (float32)
            // NetworkVarNames: m_flFadeOutDuration (float32)
            // NetworkVarNames: m_flMaxWeight (float32)
            // NetworkVarNames: m_flCurWeight (float32)
            // NetworkVarNames: m_netlookupFilename (char)
            // NetworkVarNames: m_bEnabled (bool)
            // NetworkVarNames: m_bMaster (bool)
            // NetworkVarNames: m_bClientSide (bool)
            // NetworkVarNames: m_bExclusive (bool)
            namespace C_ColorCorrection {
                constexpr std::ptrdiff_t m_vecOrigin = 0x558; // 
                constexpr std::ptrdiff_t m_MinFalloff = 0x564; // 
                constexpr std::ptrdiff_t m_MaxFalloff = 0x568; // 
                constexpr std::ptrdiff_t m_flFadeInDuration = 0x56C; // 
                constexpr std::ptrdiff_t m_flFadeOutDuration = 0x570; // 
                constexpr std::ptrdiff_t m_flMaxWeight = 0x574; // 
                constexpr std::ptrdiff_t m_flCurWeight = 0x578; // 
                constexpr std::ptrdiff_t m_netlookupFilename = 0x57C; // 
                constexpr std::ptrdiff_t m_bEnabled = 0x77C; // 
                constexpr std::ptrdiff_t m_bMaster = 0x77D; // 
                constexpr std::ptrdiff_t m_bClientSide = 0x77E; // 
                constexpr std::ptrdiff_t m_bExclusive = 0x77F; // 
                constexpr std::ptrdiff_t m_bEnabledOnClient = 0x780; // 
                constexpr std::ptrdiff_t m_flCurWeightOnClient = 0x784; // 
                constexpr std::ptrdiff_t m_bFadingIn = 0x788; // 
                constexpr std::ptrdiff_t m_flFadeStartWeight = 0x78C; // 
                constexpr std::ptrdiff_t m_flFadeStartTime = 0x790; // 
                constexpr std::ptrdiff_t m_flFadeDuration = 0x794; // 
            }
            // Parent: C_BaseCombatCharacter
            // Field count: 3
            //
            // Metadata:
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // NetworkVarNames: m_NPCState (NPC_STATE)
            // NetworkVarNames: m_bFadeCorpse (bool)
            // NetworkVarNames: m_bImportantRagdoll (bool)
            namespace C_AI_BaseNPC {
                constexpr std::ptrdiff_t m_NPCState = 0xD70; // 
                constexpr std::ptrdiff_t m_bFadeCorpse = 0xD74; // 
                constexpr std::ptrdiff_t m_bImportantRagdoll = 0xD75; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Warden_RiotProtocol_EnemyDebuff {
                constexpr std::ptrdiff_t m_flEnemyMoveSlow = 0xC0; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_ProjectMind {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Bomber_ULT {
            }
            // Parent: CitadelItemVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Upgrade_OverdriveClip_VData {
                constexpr std::ptrdiff_t m_OverdriveClipModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ReloadModifier = 0x15A0; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ChainLightningEffectVData {
                constexpr std::ptrdiff_t m_ChainParticle = 0x608; // 
                constexpr std::ptrdiff_t m_ChainSound = 0x6E8; // 
                constexpr std::ptrdiff_t m_VictimSound = 0x6F8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 2
            namespace CCitadel_Modifier_Passive_Camouflage {
                constexpr std::ptrdiff_t m_flRate = 0xC0; // 
                constexpr std::ptrdiff_t m_vLastPosition = 0xC4; // 
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_ThermalDetonator_Thinker {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_flNextShootTime (GameTime_t)
            namespace CAbility_Synth_Barrage {
                constexpr std::ptrdiff_t m_nProjectilesScheduled = 0xEE0; // 
                constexpr std::ptrdiff_t m_ChannelParticle = 0xEE4; // 
                constexpr std::ptrdiff_t m_flNextShootTime = 0xEE8; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityWreckerUltimateVData {
                constexpr std::ptrdiff_t m_BeamParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_ChargeParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_ActiveModifier = 0x1708; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_BaseBulletPreRollProc
            // Field count: 0
            namespace CCitadel_Modifier_MedicBullets {
            }
            // Parent: CCitadelModifierVData
            // Field count: 8
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_BaseEventProcVData {
                constexpr std::ptrdiff_t m_bProcChanceAffectedByEffectiveness = 0x608; // 
                constexpr std::ptrdiff_t m_bShouldApplyAbilityCooldown = 0x609; // 
                constexpr std::ptrdiff_t m_bCanProcMultipleTimesOnOneTarget = 0x60A; // 
                constexpr std::ptrdiff_t m_bCanProcByOtherObjects = 0x60B; // 
                constexpr std::ptrdiff_t m_nAbilityTargetTypes = 0x60C; // 
                constexpr std::ptrdiff_t m_nAbilityTargetFlags = 0x610; // 
                constexpr std::ptrdiff_t m_vecProcDamageTypes = 0x618; // CUtlVector<ECitadelDamageType>
                constexpr std::ptrdiff_t m_nRequiredDamageFlags = 0x630; // 
            }
            // Parent: CScaleFunctionVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CScaleFunctionAbilityPropertyMultiStatsVData {
                constexpr std::ptrdiff_t m_vecScalingStats = 0x40; // 
            }
            // Parent: None
            // Field count: 8
            //
            // Metadata:
            // NetworkVarNames: m_hModel (HModelStrong)
            // NetworkVarNames: m_bClientClothCreationSuppressed (bool)
            // NetworkVarNames: m_MeshGroupMask (MeshGroupMask_t)
            // NetworkVarNames: m_nBodyGroupChoices (int32)
            // NetworkVarNames: m_nIdealMotionType (int8)
            namespace CModelState {
                constexpr std::ptrdiff_t m_hModel = 0xD0; // CStrongHandle<InfoForResourceTypeCModel>
                constexpr std::ptrdiff_t m_ModelName = 0xD8; // 
                constexpr std::ptrdiff_t m_bClientClothCreationSuppressed = 0x118; // 
                constexpr std::ptrdiff_t m_MeshGroupMask = 0x1D0; // 
                constexpr std::ptrdiff_t m_nBodyGroupChoices = 0x220; // 
                constexpr std::ptrdiff_t m_nIdealMotionType = 0x26A; // 
                constexpr std::ptrdiff_t m_nForceLOD = 0x26B; // 
                constexpr std::ptrdiff_t m_nClothUpdateFlags = 0x26C; // 
            }
            // Parent: CBaseModifierAura
            // Field count: 0
            namespace CCitadelModifierAura {
            }
            // Parent: C_FuncBrush
            // Field count: 0
            namespace C_CitadelSpawnBlocker {
            }
            // Parent: None
            // Field count: 1
            namespace C_EconEntity__AttachedModelData_t {
                constexpr std::ptrdiff_t m_iModelDisplayFlags = 0x0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_Mirage_FireBeetles_Debuff {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierThumper_3VData {
                constexpr std::ptrdiff_t m_DroneParticle = 0x608; // 
                constexpr std::ptrdiff_t m_LoopSound = 0x6E8; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityCadenceCrescendoVData {
                constexpr std::ptrdiff_t m_CrescendoAOEModifier = 0x1548; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_SleepBomb {
            }
            // Parent: CCitadelModifierVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Thumper_EnemyPulled_VData {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 4
            //
            // Metadata:
            // NetworkVarNames: m_iBonusHealth (int)
            // NetworkVarNames: m_hTarget (CHandle<CBaseEntity>)
            namespace CCitadel_Ability_UltCombo {
                constexpr std::ptrdiff_t m_flLastAttackTime = 0xC78; // 
                constexpr std::ptrdiff_t m_nAttackNum = 0xC7C; // 
                constexpr std::ptrdiff_t m_iBonusHealth = 0xD28; // 
                constexpr std::ptrdiff_t m_hTarget = 0xD2C; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Forge_MiniTurret_InnateModifier {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_PowerSurge {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_DivinersKevlarBuff {
            }
            // Parent: CTier3BossAbility
            // Field count: 0
            namespace CCitadel_Ability_Tier3Boss_LaserBeam {
            }
            // Parent: CCitadelModifierVData
            // Field count: 7
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_InvisVData {
                constexpr std::ptrdiff_t m_InvisLoopParticle = 0x608; // 
                constexpr std::ptrdiff_t m_InvisDetectRadiusParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_InvisRevealedParticle = 0x7C8; // 
                constexpr std::ptrdiff_t m_strInvisRevealedSound = 0x8A8; // 
                constexpr std::ptrdiff_t m_bFadeInsteadOfRemoveOnBulletFire = 0x8B8; // 
                constexpr std::ptrdiff_t m_bFadeInsteadOfRemoveOnAbilityUse = 0x8B9; // 
                constexpr std::ptrdiff_t m_bFadeToVisibleAtEndOfDuration = 0x8BA; // 
            }
            // Parent: CEntitySubclassVDataBase
            // Field count: 27
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_BreakablePropVData {
                constexpr std::ptrdiff_t m_bBreakOnDodgeTouch = 0x28; // 
                constexpr std::ptrdiff_t m_bRenderAfterDeath = 0x29; // 
                constexpr std::ptrdiff_t m_bSolidAfterDeath = 0x2A; // 
                constexpr std::ptrdiff_t m_bIsPermanent = 0x2B; // 
                constexpr std::ptrdiff_t m_bDamagedByBullets = 0x2C; // 
                constexpr std::ptrdiff_t m_bDamagedByMelee = 0x2D; // 
                constexpr std::ptrdiff_t m_bDamagedByAbilities = 0x2E; // 
                constexpr std::ptrdiff_t m_hModel = 0x30; // 
                constexpr std::ptrdiff_t m_sAnimgraphParamDamageReceived = 0x110; // 
                constexpr std::ptrdiff_t m_sAnimgraphParamOnHit = 0x118; // 
                constexpr std::ptrdiff_t m_sAnimgraphParamOnRespawn = 0x120; // 
                constexpr std::ptrdiff_t m_sBreakSound = 0x128; // 
                constexpr std::ptrdiff_t m_sDamageSound = 0x138; // 
                constexpr std::ptrdiff_t m_sHeavyDamageSound = 0x148; // 
                constexpr std::ptrdiff_t m_sHitIndicatorSound = 0x158; // 
                constexpr std::ptrdiff_t m_iHealth = 0x168; // 
                constexpr std::ptrdiff_t m_flInitialSpawnTime = 0x16C; // 
                constexpr std::ptrdiff_t m_flRespawnTime = 0x170; // 
                constexpr std::ptrdiff_t m_flInitialSpawnTimeTest = 0x174; // 
                constexpr std::ptrdiff_t m_flRespawnTimeTest = 0x178; // 
                constexpr std::ptrdiff_t m_bIsMantleable = 0x17C; // 
                constexpr std::ptrdiff_t m_flPrimaryDropChance = 0x180; // 
                constexpr std::ptrdiff_t m_eRollType = 0x184; // 
                constexpr std::ptrdiff_t m_vecPrimaryPickups = 0x188; // 
                constexpr std::ptrdiff_t m_iMatchTimeMinsForLevel2Pickups = 0x1A0; // 
                constexpr std::ptrdiff_t m_vecPickups_lv2 = 0x1A8; // 
                constexpr std::ptrdiff_t m_iLootListDeckSize = 0x1C0; // 
            }
            // Parent: None
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_Attributes (C_EconItemAttribute)
            namespace CAttributeList {
                constexpr std::ptrdiff_t m_Attributes = 0x8; // 
                constexpr std::ptrdiff_t m_pManager = 0x58; // 
            }
            // Parent: CCitadel_Ability_PrimaryWeaponVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityCadencePrimaryWeaponVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_CrowdControl {
            }
            // Parent: CCitadelModifier
            // Field count: 3
            namespace CCitadel_Modifier_RestorativeGoo {
                constexpr std::ptrdiff_t m_flEarliestBreakoutTime = 0xC0; // 
                constexpr std::ptrdiff_t m_hGooCube = 0x3A0; // 
                constexpr std::ptrdiff_t m_flBreakoutPercentage = 0x3A4; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Upgrade_KineticSashTriggered_VData {
                constexpr std::ptrdiff_t m_TriggeredSound = 0x608; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Tech_BleedVData {
                constexpr std::ptrdiff_t m_DamageParticle = 0x608; // 
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Item_SelfBuffModifierVData {
                constexpr std::ptrdiff_t m_BuffModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_MultiplayRules
            // Field count: 0
            namespace C_TeamplayRules {
            }
            // Parent: C_CitadelProjectile
            // Field count: 1
            namespace C_CitadelBoomerangProjectile {
                constexpr std::ptrdiff_t m_bReturning = 0x8B8; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Upgrade_StabilizingTripod {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_ArmorUpgrade_RegeneratingBulletShield {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ItemPickupTimer {
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Mirage_SandPhantom_Passive_Victim {
                constexpr std::ptrdiff_t m_flLastProcTime = 0xCC; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CModifier_Upgrade_KineticSashTriggered {
                constexpr std::ptrdiff_t m_nBonusClip = 0xC0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_DamageResistanceVData {
                constexpr std::ptrdiff_t m_flDamageResistancePerSecond = 0x608; // 
                constexpr std::ptrdiff_t m_flTickInterval = 0x60C; // 
                constexpr std::ptrdiff_t m_flDamageResistanceBonusPerGameMinute = 0x610; // 
            }
            // Parent: C_BaseToggle
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_bIsUsable (bool)
            namespace C_BaseDoor {
                constexpr std::ptrdiff_t m_bIsUsable = 0x830; // 
            }
            // Parent: CCitadelBaseTriggerAbility
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_flActiveRadius (float)
            namespace CCitadelNanoPredatoryStatueTrigger {
                constexpr std::ptrdiff_t m_flActiveRadius = 0xC88; // 
            }
            // Parent: C_CitadelProjectile
            // Field count: 1
            namespace C_Citadel_Projectile_Bebop_Hook {
                constexpr std::ptrdiff_t m_iChainEffect = 0x8B8; // 
            }
            // Parent: CCitadel_Item
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_nKillsEarned (int)
            namespace CCitadel_WeaponUpgrade_GlassCannon {
                constexpr std::ptrdiff_t m_nKillsEarned = 0xC90; // 
            }
            // Parent: C_BaseClientUIEntity
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_hActivator (EHANDLE)
            namespace C_PointClientUIDialog {
                constexpr std::ptrdiff_t m_hActivator = 0x860; // 
                constexpr std::ptrdiff_t m_bStartEnabled = 0x864; // 
            }
            // Parent: CCitadel_Modifier_StatStealBaseVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Mirage_FireScarabs_WatcherVData {
                constexpr std::ptrdiff_t m_HealModifier = 0x628; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelAbilityVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityTargetdummy1VData {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_hHookVictim (EHANDLE)
            // NetworkVarNames: m_hProjectile (EHANDLE)
            // NetworkVarNames: m_vecHookTargetStartPos (Vector)
            namespace CCitadel_Ability_Hook {
                constexpr std::ptrdiff_t m_hHookVictim = 0xC78; // 
                constexpr std::ptrdiff_t m_hProjectile = 0xC7C; // 
                constexpr std::ptrdiff_t m_vecHookTargetStartPos = 0xC80; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_VoidSphere {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Bull_Heal {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_WeaponPowerForHealthVData {
                constexpr std::ptrdiff_t m_ActiveBuff = 0x608; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_SuperNeutralChargeActive {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_InvisFading {
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Rutger_Pulse_Aura_VData {
                constexpr std::ptrdiff_t m_empWaveParticle = 0x648; // 
            }
            // Parent: C_CitadelProjectile
            // Field count: 0
            namespace C_CProjectile_Rutger_Rocket {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ControlPointBlockerAuraTarget {
            }
            // Parent: C_PointEntity
            // Field count: 1
            namespace CPointChildModifier {
                constexpr std::ptrdiff_t m_bOrphanInsteadOfDeletingChildrenOnRemove = 0x558; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Synth_PlasmaFlux_WeaponDamage_VData {
                constexpr std::ptrdiff_t m_BuffParticle = 0x608; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_ShieldedSentry {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_AblativeCoatResistBuffVData {
                constexpr std::ptrdiff_t m_ResistBuffParticle = 0x608; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_ReloadSpeed {
                constexpr std::ptrdiff_t m_flReloadSpeed = 0xC0; // 
            }
            // Parent: C_BaseEntity
            // Field count: 0
            namespace C_InfoLadderDismount {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_TechCleave {
            }
            // Parent: C_BaseModelEntity
            // Field count: 13
            //
            // Metadata:
            // NetworkVarNames: m_vecConnections (CHandle<CCitadelZipLineNode>)
            // NetworkVarNames: m_eCaptureState (int16)
            // NetworkVarNames: m_iPrimaryLane (int16)
            // NetworkVarNames: m_nRopesParity (int16)
            // NetworkVarNames: m_bCornerNode (bool)
            // NetworkVarNames: m_bCapturable (bool)
            // NetworkVarNames: m_bAlwaysUsable (bool)
            // NetworkVarNames: m_bOneWay (bool)
            // NetworkVarNames: m_bDisableZippingToByPlayers (bool)
            // NetworkVarNames: m_bUseForMinimapDrawing (bool)
            // NetworkVarNames: m_hGuardingBoss (EHANDLE)
            // NetworkVarNames: m_flRopeRadius (float)
            // NetworkVarNames: m_bEnabled (bool)
            namespace CCitadelZipLineNode {
                constexpr std::ptrdiff_t m_vecConnections = 0x870; // 
                constexpr std::ptrdiff_t m_eCaptureState = 0x888; // 
                constexpr std::ptrdiff_t m_iPrimaryLane = 0x88A; // 
                constexpr std::ptrdiff_t m_nRopesParity = 0x88C; // 
                constexpr std::ptrdiff_t m_bCornerNode = 0x88E; // 
                constexpr std::ptrdiff_t m_bCapturable = 0x88F; // 
                constexpr std::ptrdiff_t m_bAlwaysUsable = 0x890; // 
                constexpr std::ptrdiff_t m_bOneWay = 0x891; // 
                constexpr std::ptrdiff_t m_bDisableZippingToByPlayers = 0x892; // 
                constexpr std::ptrdiff_t m_bUseForMinimapDrawing = 0x893; // 
                constexpr std::ptrdiff_t m_hGuardingBoss = 0x894; // 
                constexpr std::ptrdiff_t m_flRopeRadius = 0x898; // 
                constexpr std::ptrdiff_t m_bEnabled = 0x89C; // 
            }
            // Parent: CCitadelModifier
            // Field count: 3
            namespace CBaseModifierAura {
                constexpr std::ptrdiff_t m_hAuraUnits = 0xC0; // 
                constexpr std::ptrdiff_t m_hAmbientEffect = 0xD8; // 
                constexpr std::ptrdiff_t m_flOverrideRadius = 0xDC; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierChompHobbledVData {
                constexpr std::ptrdiff_t m_LassoEffect = 0x608; // 
                constexpr std::ptrdiff_t m_ConsumeSound = 0x6E8; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbility_Synth_Affliction_VData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_AoEParticle = 0x1558; // 
                constexpr std::ptrdiff_t m_CastParticle = 0x1638; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 7
            //
            // Metadata:
            // NetworkVarNames: m_flDissipationRate (float)
            // NetworkVarNames: m_flDissipationTime (GameTime_t)
            // NetworkVarNames: m_flHeatTime (GameTime_t)
            // NetworkVarNames: m_flOverheatSoundTime (GameTime_t)
            // NetworkVarNames: m_bOverheating (bool)
            namespace CCitadel_Ability_Tokamak_HeatSinks_Inherent {
                constexpr std::ptrdiff_t m_nIntervalsElapsed = 0xC78; // 
                constexpr std::ptrdiff_t m_NextShotTime = 0xC7C; // 
                constexpr std::ptrdiff_t m_flDissipationRate = 0xC80; // 
                constexpr std::ptrdiff_t m_flDissipationTime = 0xC84; // 
                constexpr std::ptrdiff_t m_flHeatTime = 0xC88; // 
                constexpr std::ptrdiff_t m_flOverheatSoundTime = 0xC8C; // 
                constexpr std::ptrdiff_t m_bOverheating = 0xC90; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_VoidSphereBuffVData {
                constexpr std::ptrdiff_t m_RapidFireParticle = 0x608; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Surging_Power {
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_CQC_ProcVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x638; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 6
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Tier3_DamagePulseVData {
                constexpr std::ptrdiff_t m_TargetParticle = 0x608; // 
                constexpr std::ptrdiff_t m_strPulseTickSound = 0x6E8; // 
                constexpr std::ptrdiff_t m_iMaxTargets = 0x6F8; // 
                constexpr std::ptrdiff_t m_flRadius = 0x6FC; // 
                constexpr std::ptrdiff_t m_flDamagePerPulse = 0x700; // 
                constexpr std::ptrdiff_t m_flTickRate = 0x704; // 
            }
            // Parent: CEntityComponent
            // Field count: 5
            namespace CRenderComponent {
                constexpr std::ptrdiff_t __m_pChainEntity = 0x10; // 
                constexpr std::ptrdiff_t m_bIsRenderingWithViewModels = 0x50; // 
                constexpr std::ptrdiff_t m_nSplitscreenFlags = 0x54; // 
                constexpr std::ptrdiff_t m_bEnableRendering = 0x60; // 
                constexpr std::ptrdiff_t m_bInterpolationReadyToDraw = 0xB0; // 
            }
            // Parent: C_SoundEventEntity
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_vMins (Vector)
            // NetworkVarNames: m_vMaxs (Vector)
            namespace C_SoundEventOBBEntity {
                constexpr std::ptrdiff_t m_vMins = 0x618; // 
                constexpr std::ptrdiff_t m_vMaxs = 0x624; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 7
            namespace CCitadel_Ability_Tokamak_HotShot {
                constexpr std::ptrdiff_t m_flDPS = 0xDF0; // 
                constexpr std::ptrdiff_t m_flNextDamageTick = 0xDF4; // 
                constexpr std::ptrdiff_t m_vStart = 0xDF8; // 
                constexpr std::ptrdiff_t m_vEnd = 0xE04; // 
                constexpr std::ptrdiff_t m_vecEntitiesHit = 0xE10; // 
                constexpr std::ptrdiff_t m_angBeamAngles = 0xE28; // 
                constexpr std::ptrdiff_t m_bNeedsBeamReset = 0xE40; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_WreckerScrapBlastDebuffVData {
                constexpr std::ptrdiff_t m_DebuffParticle = 0x608; // 
            }
            // Parent: CCitadelModifier
            // Field count: 6
            namespace CCitadel_Modifier_IceDome {
                constexpr std::ptrdiff_t m_hBlocker = 0xC0; // 
                constexpr std::ptrdiff_t m_hFriendlyAura = 0xC4; // 
                constexpr std::ptrdiff_t m_hEnemyAura = 0xC8; // 
                constexpr std::ptrdiff_t m_nParticleIndex = 0xCC; // 
                constexpr std::ptrdiff_t m_flStartTime = 0xD0; // 
                constexpr std::ptrdiff_t m_vOrigin = 0x1B8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Parry {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CItemAOESilenceModifierVData {
                constexpr std::ptrdiff_t m_strSilenceTargetSound = 0x608; // 
                constexpr std::ptrdiff_t m_SilenceModifier = 0x618; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelItemVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_UtilityUpgrade_AOESmokeBombVData {
                constexpr std::ptrdiff_t m_CastCompleteParticle = 0x1590; // 
                constexpr std::ptrdiff_t m_strBuffGainedSound = 0x1670; // 
                constexpr std::ptrdiff_t m_InvisModifier = 0x1680; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelItemVData
            // Field count: 10
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CItem_WarpStone_VData {
                constexpr std::ptrdiff_t m_CasterModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_CasterDebuffModifier = 0x15A0; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_strExplodeSound = 0x15B0; // 
                constexpr std::ptrdiff_t m_CastDelayParticle = 0x15C0; // 
                constexpr std::ptrdiff_t m_TeleportTrailParticle = 0x16A0; // 
                constexpr std::ptrdiff_t m_flGroundProbeSpeed = 0x1780; // 
                constexpr std::ptrdiff_t m_flGroundStepDown = 0x1784; // 
                constexpr std::ptrdiff_t m_flGroundStepUp = 0x1788; // 
                constexpr std::ptrdiff_t m_iMaxGroundIterations = 0x178C; // 
                constexpr std::ptrdiff_t m_flVelocityScale = 0x1790; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_SuperAcolytesGlove {
            }
            // Parent: None
            // Field count: 8
            //
            // Metadata:
            // NetworkVarNames: m_flLatchedValue (float)
            // NetworkVarNames: m_flLatchedTime (GameTime_t)
            // NetworkVarNames: m_eLockonState (ELockonState)
            // NetworkVarNames: m_hTarget (EHANDLE)
            namespace LockonTarget_t {
                constexpr std::ptrdiff_t m_flGainRate = 0x30; // 
                constexpr std::ptrdiff_t m_flDrainRate = 0x34; // 
                constexpr std::ptrdiff_t m_flMaxValue = 0x38; // 
                constexpr std::ptrdiff_t m_nPrevFullStacks = 0x3C; // 
                constexpr std::ptrdiff_t m_flLatchedValue = 0x40; // 
                constexpr std::ptrdiff_t m_flLatchedTime = 0x44; // 
                constexpr std::ptrdiff_t m_eLockonState = 0x48; // 
                constexpr std::ptrdiff_t m_hTarget = 0x4C; // 
            }
            // Parent: CEntityComponent
            // Field count: 66
            //
            // Metadata:
            // NetworkVarNames: m_Color (Color)
            // NetworkVarNames: m_SecondaryColor (Color)
            // NetworkVarNames: m_flBrightness (float)
            // NetworkVarNames: m_flBrightnessScale (float)
            // NetworkVarNames: m_flBrightnessMult (float)
            // NetworkVarNames: m_flRange (float)
            // NetworkVarNames: m_flFalloff (float)
            // NetworkVarNames: m_flAttenuation0 (float)
            // NetworkVarNames: m_flAttenuation1 (float)
            // NetworkVarNames: m_flAttenuation2 (float)
            // NetworkVarNames: m_flTheta (float)
            // NetworkVarNames: m_flPhi (float)
            // NetworkVarNames: m_hLightCookie (HRenderTextureStrong)
            // NetworkVarNames: m_nCascades (int)
            // NetworkVarNames: m_nCastShadows (int)
            // NetworkVarNames: m_nShadowWidth (int)
            // NetworkVarNames: m_nShadowHeight (int)
            // NetworkVarNames: m_bRenderDiffuse (bool)
            // NetworkVarNames: m_nRenderSpecular (int)
            // NetworkVarNames: m_bRenderTransmissive (bool)
            // NetworkVarNames: m_flOrthoLightWidth (float)
            // NetworkVarNames: m_flOrthoLightHeight (float)
            // NetworkVarNames: m_nStyle (int)
            // NetworkVarNames: m_Pattern (CUtlString)
            // NetworkVarNames: m_nCascadeRenderStaticObjects (int)
            // NetworkVarNames: m_flShadowCascadeCrossFade (float)
            // NetworkVarNames: m_flShadowCascadeDistanceFade (float)
            // NetworkVarNames: m_flShadowCascadeDistance0 (float)
            // NetworkVarNames: m_flShadowCascadeDistance1 (float)
            // NetworkVarNames: m_flShadowCascadeDistance2 (float)
            // NetworkVarNames: m_flShadowCascadeDistance3 (float)
            // NetworkVarNames: m_nShadowCascadeResolution0 (int)
            // NetworkVarNames: m_nShadowCascadeResolution1 (int)
            // NetworkVarNames: m_nShadowCascadeResolution2 (int)
            // NetworkVarNames: m_nShadowCascadeResolution3 (int)
            // NetworkVarNames: m_bUsesBakedShadowing (bool)
            // NetworkVarNames: m_nShadowPriority (int)
            // NetworkVarNames: m_nBakedShadowIndex (int)
            // NetworkVarNames: m_bRenderToCubemaps (bool)
            // NetworkVarNames: m_nDirectLight (int)
            // NetworkVarNames: m_nIndirectLight (int)
            // NetworkVarNames: m_flFadeMinDist (float)
            // NetworkVarNames: m_flFadeMaxDist (float)
            // NetworkVarNames: m_flShadowFadeMinDist (float)
            // NetworkVarNames: m_flShadowFadeMaxDist (float)
            // NetworkVarNames: m_bEnabled (bool)
            // NetworkVarNames: m_bFlicker (bool)
            // NetworkVarNames: m_bPrecomputedFieldsValid (bool)
            // NetworkVarNames: m_vPrecomputedBoundsMins (Vector)
            // NetworkVarNames: m_vPrecomputedBoundsMaxs (Vector)
            // NetworkVarNames: m_vPrecomputedOBBOrigin (Vector)
            // NetworkVarNames: m_vPrecomputedOBBAngles (QAngle)
            // NetworkVarNames: m_vPrecomputedOBBExtent (Vector)
            // NetworkVarNames: m_flPrecomputedMaxRange (float)
            // NetworkVarNames: m_nFogLightingMode (int)
            // NetworkVarNames: m_flFogContributionStength (float)
            // NetworkVarNames: m_flNearClipPlane (float)
            // NetworkVarNames: m_SkyColor (Color)
            // NetworkVarNames: m_flSkyIntensity (float)
            // NetworkVarNames: m_SkyAmbientBounce (Color)
            // NetworkVarNames: m_bUseSecondaryColor (bool)
            // NetworkVarNames: m_bMixedShadows (bool)
            // NetworkVarNames: m_flLightStyleStartTime (GameTime_t)
            // NetworkVarNames: m_flCapsuleLength (float)
            // NetworkVarNames: m_flMinRoughness (float)
            namespace CLightComponent {
                constexpr std::ptrdiff_t __m_pChainEntity = 0x38; // 
                constexpr std::ptrdiff_t m_Color = 0x75; // 
                constexpr std::ptrdiff_t m_SecondaryColor = 0x79; // 
                constexpr std::ptrdiff_t m_flBrightness = 0x80; // 
                constexpr std::ptrdiff_t m_flBrightnessScale = 0x84; // 
                constexpr std::ptrdiff_t m_flBrightnessMult = 0x88; // 
                constexpr std::ptrdiff_t m_flRange = 0x8C; // 
                constexpr std::ptrdiff_t m_flFalloff = 0x90; // 
                constexpr std::ptrdiff_t m_flAttenuation0 = 0x94; // 
                constexpr std::ptrdiff_t m_flAttenuation1 = 0x98; // 
                constexpr std::ptrdiff_t m_flAttenuation2 = 0x9C; // 
                constexpr std::ptrdiff_t m_flTheta = 0xA0; // 
                constexpr std::ptrdiff_t m_flPhi = 0xA4; // 
                constexpr std::ptrdiff_t m_hLightCookie = 0xA8; // 
                constexpr std::ptrdiff_t m_nCascades = 0xB0; // 
                constexpr std::ptrdiff_t m_nCastShadows = 0xB4; // 
                constexpr std::ptrdiff_t m_nShadowWidth = 0xB8; // 
                constexpr std::ptrdiff_t m_nShadowHeight = 0xBC; // 
                constexpr std::ptrdiff_t m_bRenderDiffuse = 0xC0; // 
                constexpr std::ptrdiff_t m_nRenderSpecular = 0xC4; // 
                constexpr std::ptrdiff_t m_bRenderTransmissive = 0xC8; // 
                constexpr std::ptrdiff_t m_flOrthoLightWidth = 0xCC; // 
                constexpr std::ptrdiff_t m_flOrthoLightHeight = 0xD0; // 
                constexpr std::ptrdiff_t m_nStyle = 0xD4; // 
                constexpr std::ptrdiff_t m_Pattern = 0xD8; // 
                constexpr std::ptrdiff_t m_nCascadeRenderStaticObjects = 0xE0; // 
                constexpr std::ptrdiff_t m_flShadowCascadeCrossFade = 0xE4; // 
                constexpr std::ptrdiff_t m_flShadowCascadeDistanceFade = 0xE8; // 
                constexpr std::ptrdiff_t m_flShadowCascadeDistance0 = 0xEC; // 
                constexpr std::ptrdiff_t m_flShadowCascadeDistance1 = 0xF0; // 
                constexpr std::ptrdiff_t m_flShadowCascadeDistance2 = 0xF4; // 
                constexpr std::ptrdiff_t m_flShadowCascadeDistance3 = 0xF8; // 
                constexpr std::ptrdiff_t m_nShadowCascadeResolution0 = 0xFC; // 
                constexpr std::ptrdiff_t m_nShadowCascadeResolution1 = 0x100; // 
                constexpr std::ptrdiff_t m_nShadowCascadeResolution2 = 0x104; // 
                constexpr std::ptrdiff_t m_nShadowCascadeResolution3 = 0x108; // 
                constexpr std::ptrdiff_t m_bUsesBakedShadowing = 0x10C; // 
                constexpr std::ptrdiff_t m_nShadowPriority = 0x110; // 
                constexpr std::ptrdiff_t m_nBakedShadowIndex = 0x114; // 
                constexpr std::ptrdiff_t m_bRenderToCubemaps = 0x118; // 
                constexpr std::ptrdiff_t m_nDirectLight = 0x11C; // 
                constexpr std::ptrdiff_t m_nIndirectLight = 0x120; // 
                constexpr std::ptrdiff_t m_flFadeMinDist = 0x124; // 
                constexpr std::ptrdiff_t m_flFadeMaxDist = 0x128; // 
                constexpr std::ptrdiff_t m_flShadowFadeMinDist = 0x12C; // 
                constexpr std::ptrdiff_t m_flShadowFadeMaxDist = 0x130; // 
                constexpr std::ptrdiff_t m_bEnabled = 0x134; // 
                constexpr std::ptrdiff_t m_bFlicker = 0x135; // 
                constexpr std::ptrdiff_t m_bPrecomputedFieldsValid = 0x136; // 
                constexpr std::ptrdiff_t m_vPrecomputedBoundsMins = 0x138; // 
                constexpr std::ptrdiff_t m_vPrecomputedBoundsMaxs = 0x144; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBOrigin = 0x150; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBAngles = 0x15C; // 
                constexpr std::ptrdiff_t m_vPrecomputedOBBExtent = 0x168; // 
                constexpr std::ptrdiff_t m_flPrecomputedMaxRange = 0x174; // 
                constexpr std::ptrdiff_t m_nFogLightingMode = 0x178; // 
                constexpr std::ptrdiff_t m_flFogContributionStength = 0x17C; // 
                constexpr std::ptrdiff_t m_flNearClipPlane = 0x180; // 
                constexpr std::ptrdiff_t m_SkyColor = 0x184; // 
                constexpr std::ptrdiff_t m_flSkyIntensity = 0x188; // 
                constexpr std::ptrdiff_t m_SkyAmbientBounce = 0x18C; // 
                constexpr std::ptrdiff_t m_bUseSecondaryColor = 0x190; // 
                constexpr std::ptrdiff_t m_bMixedShadows = 0x191; // 
                constexpr std::ptrdiff_t m_flLightStyleStartTime = 0x194; // 
                constexpr std::ptrdiff_t m_flCapsuleLength = 0x198; // 
                constexpr std::ptrdiff_t m_flMinRoughness = 0x19C; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_GooGrenade {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_IcePath_Buff {
            }
            // Parent: CCitadelModifier
            // Field count: 7
            namespace CCitadel_Modifier_ProjectMind {
                constexpr std::ptrdiff_t m_particleStart = 0xC0; // 
                constexpr std::ptrdiff_t m_particleEnd = 0xC4; // 
                constexpr std::ptrdiff_t m_particleTrail = 0xC8; // 
                constexpr std::ptrdiff_t m_vecEndLocation = 0xCC; // 
                constexpr std::ptrdiff_t m_vecStartPosition = 0xD8; // 
                constexpr std::ptrdiff_t m_flStartDelay = 0xE4; // 
                constexpr std::ptrdiff_t m_vecApplyOffset = 0xE8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_MetalSkinVData {
                constexpr std::ptrdiff_t m_BuffStartParticle = 0x608; // 
                constexpr std::ptrdiff_t m_BuffEndParticle = 0x6E8; // 
            }
            // Parent: CTier3BossAbility
            // Field count: 0
            namespace CCitadel_Ability_Tier3Boss_DamagePulse {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Core_PushTarget {
            }
            // Parent: None
            // Field count: 0
            namespace CEntityComponent {
            }
            // Parent: IEconItemInterface
            // Field count: 16
            //
            // Metadata:
            // NetworkVarNames: m_iItemDefinitionIndex (item_definition_index_t)
            // NetworkVarNames: m_iEntityQuality (int)
            // NetworkVarNames: m_iEntityLevel (uint32)
            // NetworkVarNames: m_iItemID (itemid_t)
            // NetworkVarNames: m_iAccountID (uint32)
            // NetworkVarNames: m_iInventoryPosition (uint32)
            // NetworkVarNames: m_bInitialized (bool)
            // NetworkVarNames: m_nOverrideStyle (style_index_t)
            // NetworkVarNames: m_AttributeList (CAttributeList)
            namespace C_EconItemView {
                constexpr std::ptrdiff_t m_iItemDefinitionIndex = 0x8; // 
                constexpr std::ptrdiff_t m_iEntityQuality = 0xC; // 
                constexpr std::ptrdiff_t m_iEntityLevel = 0x10; // 
                constexpr std::ptrdiff_t m_iItemID = 0x18; // 
                constexpr std::ptrdiff_t m_iAccountID = 0x20; // 
                constexpr std::ptrdiff_t m_iInventoryPosition = 0x24; // 
                constexpr std::ptrdiff_t m_bInitialized = 0x30; // 
                constexpr std::ptrdiff_t m_nOverrideStyle = 0x31; // 
                constexpr std::ptrdiff_t m_bIsStoreItem = 0x32; // 
                constexpr std::ptrdiff_t m_bIsTradeItem = 0x33; // 
                constexpr std::ptrdiff_t m_bHasComputedAttachedParticles = 0x34; // 
                constexpr std::ptrdiff_t m_bHasAttachedParticles = 0x35; // 
                constexpr std::ptrdiff_t m_iEntityQuantity = 0x38; // 
                constexpr std::ptrdiff_t m_unClientFlags = 0x3C; // 
                constexpr std::ptrdiff_t m_unOverrideOrigin = 0x40; // 
                constexpr std::ptrdiff_t m_AttributeList = 0x58; // 
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelModifer_Viscous_Goo_Aura_VData {
            }
            // Parent: C_BaseEntity
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_Handle (CHandle<CBaseEntity>)
            // NetworkVarNames: m_bSendHandle (bool)
            namespace C_HandleTest {
                constexpr std::ptrdiff_t m_Handle = 0x558; // 
                constexpr std::ptrdiff_t m_bSendHandle = 0x55C; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 9
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityTokamakHotShotVData {
                constexpr std::ptrdiff_t m_LaserModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_strLaserStartSound = 0x1558; // 
                constexpr std::ptrdiff_t m_strLaserEndSound = 0x1568; // 
                constexpr std::ptrdiff_t m_strLaserLoopSound = 0x1578; // 
                constexpr std::ptrdiff_t m_strLaserHitSound = 0x1588; // 
                constexpr std::ptrdiff_t m_ChargeParticle = 0x1598; // 
                constexpr std::ptrdiff_t m_BeamParticle = 0x1678; // 
                constexpr std::ptrdiff_t m_HitParticle = 0x1758; // 
                constexpr std::ptrdiff_t m_GroundParticle = 0x1838; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_tDrainLifeStopTime (GameTime_t)
            namespace CCitadel_Ability_LifeDrain {
                constexpr std::ptrdiff_t m_tDrainLifeStopTime = 0xC78; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            namespace CCitadel_Ability_StormCloud {
                constexpr std::ptrdiff_t m_bApplyingVerticalAirDrag = 0xC78; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_SuperAcolytesGlove_VData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x638; // 
                constexpr std::ptrdiff_t m_SwingParticle = 0x648; // 
                constexpr std::ptrdiff_t m_HitParticle = 0x728; // 
                constexpr std::ptrdiff_t m_FistReadyEffect = 0x808; // 
            }
            // Parent: C_BaseEntity
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_EnvWindShared (CEnvWindShared)
            namespace C_EnvWindClientside {
                constexpr std::ptrdiff_t m_EnvWindShared = 0x558; // 
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_Rutger_ForceField_Aura {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 2
            namespace CCitadel_Ability_Chrono_PulseGrenade {
                constexpr std::ptrdiff_t m_vLaunchPosition = 0xC78; // 
                constexpr std::ptrdiff_t m_qLaunchAngle = 0xC84; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Hornet_Sting {
                constexpr std::ptrdiff_t m_flLastTickTime = 0xC0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_VeilWalkerWatcher {
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierNikumanVData {
                constexpr std::ptrdiff_t m_SelfParticle = 0x648; // 
                constexpr std::ptrdiff_t m_AOEFriendParticle = 0x728; // 
                constexpr std::ptrdiff_t m_strAmbientLoopingLocalPlayerSound = 0x808; // 
            }
            // Parent: C_PointClientUIWorldPanel
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_messageText (char)
            namespace C_PointClientUIWorldTextPanel {
                constexpr std::ptrdiff_t m_messageText = 0xA90; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Thumper_4 {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Cadence_SilenceContraptions {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_bInGround (bool)
            // NetworkVarNames: m_SpinEndTime (GameTime_t)
            namespace CCitadel_Ability_Burrow {
                constexpr std::ptrdiff_t m_bInGround = 0xD58; // 
                constexpr std::ptrdiff_t m_SpinEndTime = 0xD5C; // 
                constexpr std::ptrdiff_t m_nBurrowEffect = 0xD60; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_Citadel_Bull_Leap_LandingBonuses {
            }
            // Parent: CCitadel_Item_TrackingProjectileApplyModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Item_Disarm_VData {
                constexpr std::ptrdiff_t m_BuffModifier = 0x1690; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DebuffModifier = 0x16A0; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CScaleFunctionBase
            // Field count: 0
            namespace CScaleFunctionAbilityProperty_BaseWeaponDamage {
            }
            // Parent: C_PointClientUIWorldPanel
            // Field count: 1
            namespace CUnitStatusOverlay {
                constexpr std::ptrdiff_t m_flUIScale = 0xAD0; // 
            }
            // Parent: CCitadel_Item
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_nWeaponPower (int)
            namespace CCitadel_WeaponUpgrade_WeaponEater {
                constexpr std::ptrdiff_t m_nWeaponPower = 0xD70; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_FireRateAura {
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_ComboBreakerHeal {
                constexpr std::ptrdiff_t m_flAmountPerSecond = 0xC0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_BonusDamagePercent {
            }
            // Parent: None
            // Field count: 5
            //
            // Metadata:
            // NetworkVarNames: m_flLatchTime (GameTime_t)
            // NetworkVarNames: m_flLatchValue (float)
            namespace AbilityResource_t {
                constexpr std::ptrdiff_t m_flCurrentValue = 0x8; // 
                constexpr std::ptrdiff_t m_flPrevRegenRate = 0xC; // 
                constexpr std::ptrdiff_t m_flMaxValue = 0x10; // 
                constexpr std::ptrdiff_t m_flLatchTime = 0x14; // 
                constexpr std::ptrdiff_t m_flLatchValue = 0x18; // 
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Cadence_AnthemAOEVData {
                constexpr std::ptrdiff_t m_AuraParticle = 0x648; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_ArmorUpgrade_BulletArmorReductionAura {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_flScopeStartTime (GameTime_t)
            namespace CCitadel_Ability_Hornet_Snipe {
                constexpr std::ptrdiff_t m_flScopeStartTime = 0xEBC; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_HornetMark {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_FlameDashBurnVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Near_Climbable_Rope {
            }
            // Parent: CCitadelModifierVData
            // Field count: 12
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Backdoor_ProtectionVData {
                constexpr std::ptrdiff_t m_flBackdoorProtectionNearbyTrooperRange = 0x608; // 
                constexpr std::ptrdiff_t m_flBackdoorProtectionNearbyTrooperThinkInterval = 0x60C; // 
                constexpr std::ptrdiff_t m_flBackdoorProtectionNearbyTrooperRemovalDuration = 0x610; // 
                constexpr std::ptrdiff_t m_flBackdoorProtectionDamageMitigationFromPlayers = 0x614; // 
                constexpr std::ptrdiff_t m_flHealthPerSecondRegen = 0x618; // 
                constexpr std::ptrdiff_t m_flOutOfCombatHealthRegen = 0x61C; // 
                constexpr std::ptrdiff_t m_flOutOfCombatRegenDelay = 0x620; // 
                constexpr std::ptrdiff_t m_flEffectsLingerTime = 0x624; // 
                constexpr std::ptrdiff_t m_ShieldImpactParticle = 0x628; // 
                constexpr std::ptrdiff_t m_ShieldActiveParticle = 0x708; // 
                constexpr std::ptrdiff_t m_strActiveEffectConfigName = 0x7E8; // 
                constexpr std::ptrdiff_t flShieldImpactDirectionOffset = 0x7F0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_RootVData {
            }
            // Parent: CPlayerPawnComponent
            // Field count: 15
            //
            // Metadata:
            // NetworkVarNames: m_nToggleButtonDownMask (ButtonBitMask_t)
            // NetworkVarNames: m_flMaxspeed (float32)
            // NetworkVarNames: m_arrForceSubtickMoveWhen (float32)
            namespace CPlayer_MovementServices {
                constexpr std::ptrdiff_t m_nImpulse = 0x40; // 
                constexpr std::ptrdiff_t m_nButtons = 0x48; // 
                constexpr std::ptrdiff_t m_nQueuedButtonDownMask = 0x68; // 
                constexpr std::ptrdiff_t m_nQueuedButtonChangeMask = 0x70; // 
                constexpr std::ptrdiff_t m_nButtonDoublePressed = 0x78; // 
                constexpr std::ptrdiff_t m_pButtonPressedCmdNumber = 0x80; // 
                constexpr std::ptrdiff_t m_nLastCommandNumberProcessed = 0x180; // 
                constexpr std::ptrdiff_t m_nToggleButtonDownMask = 0x188; // 
                constexpr std::ptrdiff_t m_flMaxspeed = 0x198; // 
                constexpr std::ptrdiff_t m_arrForceSubtickMoveWhen = 0x19C; // 
                constexpr std::ptrdiff_t m_flForwardMove = 0x1AC; // 
                constexpr std::ptrdiff_t m_flLeftMove = 0x1B0; // 
                constexpr std::ptrdiff_t m_flUpMove = 0x1B4; // 
                constexpr std::ptrdiff_t m_vecLastMovementImpulses = 0x1B8; // 
                constexpr std::ptrdiff_t m_vecOldViewAngles = 0x1C4; // 
            }
            // Parent: CCitadel_Modifier_StunnedVData
            // Field count: 5
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierKnockdownVData {
                constexpr std::ptrdiff_t m_flSatVolumeRadius = 0x6E8; // 
                constexpr std::ptrdiff_t m_flSatVolumeFadeOut = 0x6EC; // 
                constexpr std::ptrdiff_t m_flGravityScale = 0x6F0; // 
                constexpr std::ptrdiff_t m_flGetUpSeqDuration = 0x6F4; // 
                constexpr std::ptrdiff_t m_cameraSequenceGetUp = 0x6F8; // CitadelCameraOperationsSequence_t
            }
            // Parent: CCitadel_Ability_PrimaryWeapon
            // Field count: 2
            namespace CCitadel_Ability_PrimaryWeapon_Slork {
                constexpr std::ptrdiff_t m_angAimAngles = 0xEE8; // 
                constexpr std::ptrdiff_t m_bNeedAimAngleReset = 0xF18; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Mirage_FireBeetles_Debuff_VData {
                constexpr std::ptrdiff_t m_DebuffParticle = 0x608; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_TangoTether_TetherReceiver {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_IncendiaryThinkerVData {
                constexpr std::ptrdiff_t m_GroundParticle = 0x608; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Tier3Boss_Base {
            }
            // Parent: CEntitySubclassVDataBase
            // Field count: 15
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CBasePlayerVData {
                constexpr std::ptrdiff_t m_sModelName = 0x28; // 
                constexpr std::ptrdiff_t m_vecIntrinsicModifiers = 0x108; // 
                constexpr std::ptrdiff_t m_flHeadDamageMultiplier = 0x120; // 
                constexpr std::ptrdiff_t m_flChestDamageMultiplier = 0x130; // 
                constexpr std::ptrdiff_t m_flStomachDamageMultiplier = 0x140; // 
                constexpr std::ptrdiff_t m_flArmDamageMultiplier = 0x150; // 
                constexpr std::ptrdiff_t m_flLegDamageMultiplier = 0x160; // 
                constexpr std::ptrdiff_t m_flHoldBreathTime = 0x170; // 
                constexpr std::ptrdiff_t m_flDrowningDamageInterval = 0x174; // 
                constexpr std::ptrdiff_t m_nDrowningDamageInitial = 0x178; // 
                constexpr std::ptrdiff_t m_nDrowningDamageMax = 0x17C; // 
                constexpr std::ptrdiff_t m_nWaterSpeed = 0x180; // 
                constexpr std::ptrdiff_t m_flUseRange = 0x184; // 
                constexpr std::ptrdiff_t m_flUseAngleTolerance = 0x188; // 
                constexpr std::ptrdiff_t m_flCrouchTime = 0x18C; // 
            }
            // Parent: CCitadelBaseShivAbility
            // Field count: 8
            //
            // Metadata:
            // NetworkVarNames: m_bActive (bool)
            // NetworkVarNames: m_hCurrentTarget (EHANDLE)
            // NetworkVarNames: m_vStartPosition (Vector)
            // NetworkVarNames: m_vDeparturePosition (Vector)
            // NetworkVarNames: m_flDepartureTime (CCitadelAutoScaledTime)
            // NetworkVarNames: m_flArrivalTime (CCitadelAutoScaledTime)
            // NetworkVarNames: m_flDrainSuppressEndTime (GameTime_t)
            namespace CCitadel_Ability_Shiv_KillingBlow {
                constexpr std::ptrdiff_t m_bActive = 0xE38; // 
                constexpr std::ptrdiff_t m_hCurrentTarget = 0xE3C; // 
                constexpr std::ptrdiff_t m_vStartPosition = 0xE40; // 
                constexpr std::ptrdiff_t m_vDeparturePosition = 0xE4C; // 
                constexpr std::ptrdiff_t m_flDepartureTime = 0xE58; // 
                constexpr std::ptrdiff_t m_flArrivalTime = 0xE70; // 
                constexpr std::ptrdiff_t m_vLastKnownSafePos = 0xE88; // 
                constexpr std::ptrdiff_t m_flDrainSuppressEndTime = 0xE98; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityWreckerSalvageVData {
                constexpr std::ptrdiff_t m_SalvageEnemyModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_StunEnemyModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BuffModifier = 0x1568; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Chrono_TimeWall_EffectVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BuffParticle = 0x618; // 
                constexpr std::ptrdiff_t m_DebuffParticle = 0x6F8; // 
                constexpr std::ptrdiff_t m_strDamageSound = 0x7D8; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_TechBleed_ProcVData {
                constexpr std::ptrdiff_t m_BleedModifier = 0x638; // 
                constexpr std::ptrdiff_t m_SlowModifier = 0x648; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 4
            namespace CCitadel_Ability_RocketBarrage {
                constexpr std::ptrdiff_t m_flCurrentTimeScale = 0xE70; // 
                constexpr std::ptrdiff_t m_vecAimPos = 0xE74; // 
                constexpr std::ptrdiff_t m_vecAimVel = 0xE80; // 
                constexpr std::ptrdiff_t m_flLastUpdateTime = 0xE8C; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityBloodShardsVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ImpactParticle = 0x1558; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Upgrade_KineticSash_VData {
                constexpr std::ptrdiff_t m_KineticSashTriggeredModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ClimbRopeSpeedVData {
                constexpr std::ptrdiff_t m_flRampUpTime = 0x608; // 
                constexpr std::ptrdiff_t m_flPercentageMultiplierStart = 0x60C; // 
                constexpr std::ptrdiff_t m_flPercentageMultiplierEnd = 0x610; // 
            }
            // Parent: CEntityComponent
            // Field count: 13
            //
            // Metadata:
            // NetworkVarNames: m_vecAbilities (CHandle<C_CitadelBaseAbility>)
            // NetworkVarNames: m_vecUniversalItems (EntitySubclassID_t)
            // NetworkVarNames: m_arPendingAsyncAbilityReservationSlots (int32)
            // NetworkVarNames: m_arPendingAsyncAbilityReservationAbilityIDs (int32)
            // NetworkVarNames: m_hSelectedAbility (EHANDLE)
            // NetworkVarNames: m_hPreviouslySelectedAbility (EHANDLE)
            // NetworkVarNames: m_bPreviousAbilityQueued (bool)
            // NetworkVarNames: m_flTimeScale (float)
            // NetworkVarNames: m_flParticleTimeScale (float)
            // NetworkVarNames: m_bInInterruptState (bool)
            // NetworkVarNames: m_ResourceStamina (AbilityResource_t)
            // NetworkVarNames: m_ResourceAbility (AbilityResource_t)
            namespace CCitadelAbilityComponent {
                constexpr std::ptrdiff_t m_vecAbilities = 0x70; // 
                constexpr std::ptrdiff_t m_vecUniversalItems = 0x88; // 
                constexpr std::ptrdiff_t m_arPendingAsyncAbilityReservationSlots = 0xA0; // 
                constexpr std::ptrdiff_t m_arPendingAsyncAbilityReservationAbilityIDs = 0xB8; // 
                constexpr std::ptrdiff_t m_hSelectedAbility = 0xD0; // 
                constexpr std::ptrdiff_t m_hPreviouslySelectedAbility = 0xD4; // 
                constexpr std::ptrdiff_t m_bPreviousAbilityQueued = 0xD8; // 
                constexpr std::ptrdiff_t m_flTimeScale = 0xDC; // 
                constexpr std::ptrdiff_t m_flParticleTimeScale = 0xE0; // 
                constexpr std::ptrdiff_t m_bInInterruptState = 0xE4; // 
                constexpr std::ptrdiff_t m_ResourceStamina = 0xE8; // 
                constexpr std::ptrdiff_t m_ResourceAbility = 0x108; // 
                constexpr std::ptrdiff_t m_nExecuteAbilityMask = 0x170; // 
            }
            // Parent: None
            // Field count: 2
            namespace C_EnvWindShared__WindVariationEvent_t {
                constexpr std::ptrdiff_t m_flWindAngleVariation = 0x0; // 
                constexpr std::ptrdiff_t m_flWindSpeedVariation = 0x4; // 
            }
            // Parent: CCitadel_Item
            // Field count: 1
            namespace CCitadel_WeaponUpgrade_InstantReload {
                constexpr std::ptrdiff_t m_bIsManualReloading = 0xC90; // 
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadelModifierAura_Cone {
            }
            // Parent: C_Sprite
            // Field count: 0
            namespace CSpriteOriented {
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityTokamakBreachVData {
                constexpr std::ptrdiff_t m_AllySmokeAOEModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_EnemySmokeAOEModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_PurgeParticle = 0x1568; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityTokamakHeatSinksVData {
                constexpr std::ptrdiff_t m_HeatDotModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Cadence_GrandFinale_Buff {
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_ThrownShiv_Damage_Debuff {
                constexpr std::ptrdiff_t m_nNumTicksRemaining = 0xC0; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_FlameDashVData {
                constexpr std::ptrdiff_t m_FlameDashModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DashBurstSound = 0x1558; // 
                constexpr std::ptrdiff_t m_ChargeHitSound = 0x1568; // 
                constexpr std::ptrdiff_t m_cameraSpeedBoost = 0x1578; // CitadelCameraOperationsSequence_t
            }
            // Parent: CitadelAbilityVData
            // Field count: 7
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_PrimaryWeaponVData {
                constexpr std::ptrdiff_t m_DOFWhileZoomed = 0x1548; // 
                constexpr std::ptrdiff_t m_bDOFFarSettingsAreOffsetByGunRange = 0x1558; // 
                constexpr std::ptrdiff_t m_sDisarmedSound = 0x1560; // 
                constexpr std::ptrdiff_t m_flMinDisarmedSoundInterval = 0x1570; // 
                constexpr std::ptrdiff_t m_sObstructedShotSound = 0x1578; // 
                constexpr std::ptrdiff_t m_flActionReloadTimingStart = 0x1588; // 
                constexpr std::ptrdiff_t m_flActionReloadTimingDuration = 0x158C; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_Tech_Defender_Shredders_Proc {
            }
            // Parent: CCitadel_Modifier_Out_Of_Combat_Health_Regen
            // Field count: 1
            namespace CCitadel_Modifier_Apex_Watcher {
                constexpr std::ptrdiff_t m_bShouldEnableBuff = 0x138; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ColdFrontAOE_VData {
                constexpr std::ptrdiff_t m_TargetModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ReloadSpeedVData {
                constexpr std::ptrdiff_t m_flReloadSpeedPercent = 0x608; // 
                constexpr std::ptrdiff_t m_bDestroyAfterReload = 0x60C; // 
            }
            // Parent: C_ParticleSystem
            // Field count: 5
            //
            // Metadata:
            // NetworkVarNames: m_flAlphaScale (float32)
            // NetworkVarNames: m_flRadiusScale (float32)
            // NetworkVarNames: m_flSelfIllumScale (float32)
            // NetworkVarNames: m_ColorTint (Color)
            // NetworkVarNames: m_hTextureOverride (HRenderTextureStrong)
            namespace C_EnvParticleGlow {
                constexpr std::ptrdiff_t m_flAlphaScale = 0xDE0; // 
                constexpr std::ptrdiff_t m_flRadiusScale = 0xDE4; // 
                constexpr std::ptrdiff_t m_flSelfIllumScale = 0xDE8; // 
                constexpr std::ptrdiff_t m_ColorTint = 0xDEC; // 
                constexpr std::ptrdiff_t m_hTextureOverride = 0xDF0; // 
            }
            // Parent: C_BaseEntity
            // Field count: 15
            namespace C_SoundEventEntity {
                constexpr std::ptrdiff_t m_bStartOnSpawn = 0x558; // 
                constexpr std::ptrdiff_t m_bToLocalPlayer = 0x559; // 
                constexpr std::ptrdiff_t m_bStopOnNew = 0x55A; // 
                constexpr std::ptrdiff_t m_bSaveRestore = 0x55B; // 
                constexpr std::ptrdiff_t m_bSavedIsPlaying = 0x55C; // 
                constexpr std::ptrdiff_t m_flSavedElapsedTime = 0x560; // 
                constexpr std::ptrdiff_t m_iszSourceEntityName = 0x568; // 
                constexpr std::ptrdiff_t m_iszAttachmentName = 0x570; // 
                constexpr std::ptrdiff_t m_onGUIDChanged = 0x578; // 
                constexpr std::ptrdiff_t m_onSoundFinished = 0x5A0; // 
                constexpr std::ptrdiff_t m_flClientCullRadius = 0x5C8; // 
                constexpr std::ptrdiff_t m_iszSoundName = 0x5F8; // 
                constexpr std::ptrdiff_t m_hSource = 0x608; // 
                constexpr std::ptrdiff_t m_nEntityIndexSelection = 0x60C; // 
                constexpr std::ptrdiff_t m_bClientSideOnly = 0x0; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 2
            namespace CCitadel_Ability_SettingSun {
                constexpr std::ptrdiff_t m_TargetPreviews = 0xC78; // 
                constexpr std::ptrdiff_t m_bWasSelected = 0xD40; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_SilenceProc_Immunity {
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_ArmorUpgrade_RegenerativeArmorVData {
                constexpr std::ptrdiff_t m_RegenModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 1
            namespace CCitadel_Modifier_QuickSilver_Watcher {
                constexpr std::ptrdiff_t m_bProcNextHit = 0x210; // 
            }
            // Parent: CCitadelModifier
            // Field count: 3
            namespace CCitadel_Modifier_BaseEventProc {
                constexpr std::ptrdiff_t m_vecProcdUnitsThisShot = 0xC0; // 
                constexpr std::ptrdiff_t m_vecTrackedUnitsThisFrame = 0xD8; // 
                constexpr std::ptrdiff_t m_nLastShotId = 0xF0; // 
            }
            // Parent: CAI_BaseNPCVData
            // Field count: 48
            //
            // Metadata:
            // MGetKV3ClassDefaults
            // MPropertySuppressBaseClassField
            // MPropertySuppressBaseClassField
            // MPropertySuppressBaseClassField
            // MPropertySuppressBaseClassField
            // MPropertySuppressBaseClassField
            // MPropertySuppressBaseClassField
            namespace CAI_CitadelNPCVData {
                constexpr std::ptrdiff_t m_sAG2VariationName = 0x230; // CResourceNameTyped<CWeakHandle<InfoForResourceTypeCNmGraphVariation>>
                constexpr std::ptrdiff_t m_mapBoundAbilities = 0x310; // 
                constexpr std::ptrdiff_t m_flSightRangePlayers = 0x338; // 
                constexpr std::ptrdiff_t m_flSightRangeNPCs = 0x33C; // 
                constexpr std::ptrdiff_t m_MeleeAnimName = 0x340; // 
                constexpr std::ptrdiff_t m_flMeleeAttemptRange = 0x348; // 
                constexpr std::ptrdiff_t m_flMeleeHitRange = 0x34C; // 
                constexpr std::ptrdiff_t m_MeleeAttackPoints = 0x350; // 
                constexpr std::ptrdiff_t m_flMaxHealthBarDrawDistance = 0x368; // 
                constexpr std::ptrdiff_t m_flWalkSpeed = 0x36C; // 
                constexpr std::ptrdiff_t m_flRunSpeed = 0x370; // 
                constexpr std::ptrdiff_t m_flTurnRate = 0x374; // 
                constexpr std::ptrdiff_t m_flAcceleration = 0x378; // 
                constexpr std::ptrdiff_t m_flStepHeight = 0x37C; // 
                constexpr std::ptrdiff_t m_navHull = 0x380; // 
                constexpr std::ptrdiff_t m_bFaceTargetEvenWhenMoving = 0x381; // 
                constexpr std::ptrdiff_t m_BeamStartSound = 0x388; // 
                constexpr std::ptrdiff_t m_BeamStopSound = 0x398; // 
                constexpr std::ptrdiff_t m_BeamPointStartLoopSound = 0x3A8; // 
                constexpr std::ptrdiff_t m_BeamPointEndLoopSound = 0x3B8; // 
                constexpr std::ptrdiff_t m_BeamPointClosestLoopSound = 0x3C8; // 
                constexpr std::ptrdiff_t m_strAmbientLoopSound = 0x3D8; // 
                constexpr std::ptrdiff_t m_DeathSound = 0x3E8; // 
                constexpr std::ptrdiff_t m_strLastHitSound = 0x3F8; // 
                constexpr std::ptrdiff_t m_bPlayLastHitSound = 0x408; // 
                constexpr std::ptrdiff_t m_MeleeHitSound = 0x410; // 
                constexpr std::ptrdiff_t m_MeleeHitPlayerSound = 0x420; // 
                constexpr std::ptrdiff_t m_sDefaultMaterialGroupName = 0x430; // 
                constexpr std::ptrdiff_t m_sEnemyMaterialGroupName = 0x438; // 
                constexpr std::ptrdiff_t m_sTeam1MaterialGroupName = 0x440; // 
                constexpr std::ptrdiff_t m_sTeam2MaterialGroupName = 0x448; // 
                constexpr std::ptrdiff_t m_MeleeSwingParticle = 0x450; // 
                constexpr std::ptrdiff_t m_MeleeActivateParticle = 0x530; // 
                constexpr std::ptrdiff_t m_flModelScale = 0x610; // 
                constexpr std::ptrdiff_t m_DeathParticle = 0x618; // 
                constexpr std::ptrdiff_t m_HealthBarParticle = 0x6F8; // 
                constexpr std::ptrdiff_t m_sHealthBarAttachment = 0x7D8; // 
                constexpr std::ptrdiff_t m_HealthBarColorFriend = 0x7E0; // 
                constexpr std::ptrdiff_t m_HealthBarColorEnemy = 0x7E4; // 
                constexpr std::ptrdiff_t m_HealthBarColorTeam1 = 0x7E8; // 
                constexpr std::ptrdiff_t m_HealthBarColorTeam2 = 0x7EC; // 
                constexpr std::ptrdiff_t m_HealthBarColorTeamNeutral = 0x7F0; // 
                constexpr std::ptrdiff_t m_flHealthBarOffset = 0x7F4; // 
                constexpr std::ptrdiff_t m_flBeamWeaponWidth = 0x7F8; // 
                constexpr std::ptrdiff_t m_flBeamTurnRate = 0x7FC; // 
                constexpr std::ptrdiff_t m_BeamWeaponParticle = 0x800; // 
                constexpr std::ptrdiff_t m_flPhysicsImpulseMultiplier = 0x8E0; // 
                constexpr std::ptrdiff_t m_WeaponInfo = 0x8E8; // 
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Cadence_Crescendo_AOE_VData {
                constexpr std::ptrdiff_t m_AuraParticle = 0x648; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Burrow {
                constexpr std::ptrdiff_t m_flLastDamageTime = 0xC0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierLashGrappleTargetVData {
                constexpr std::ptrdiff_t m_LockingOnParticle = 0x608; // 
                constexpr std::ptrdiff_t m_LockedOnParticle = 0x6E8; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            namespace CCitadel_Ability_HornetMark {
                constexpr std::ptrdiff_t m_nFXIndex = 0xC78; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_DebuffImmunityVData {
                constexpr std::ptrdiff_t m_ShieldParticle = 0x608; // 
                constexpr std::ptrdiff_t m_PlayerShieldParticle = 0x6E8; // 
            }
            // Parent: CNPC_SimpleAnimatingAIVData
            // Field count: 17
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CNPC_ShieldedSentryVData {
                constexpr std::ptrdiff_t m_flZShootPostionOffset = 0x108; // 
                constexpr std::ptrdiff_t m_LaserSightParticle = 0x110; // 
                constexpr std::ptrdiff_t m_KillExplosionParticle = 0x1F0; // 
                constexpr std::ptrdiff_t m_DeployProgressModifier = 0x2D0; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_NearDeathModifier = 0x2E0; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_IntrinsicModifier = 0x2F0; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_sSpawnSound = 0x300; // 
                constexpr std::ptrdiff_t m_sKillExplosionSound = 0x310; // 
                constexpr std::ptrdiff_t m_sTargetAcquiredLocalSound = 0x320; // 
                constexpr std::ptrdiff_t m_sTargetAcquiredSound = 0x330; // 
                constexpr std::ptrdiff_t m_flIdleTurnSpeed = 0x340; // 
                constexpr std::ptrdiff_t m_flIdleTurnAngles = 0x344; // 
                constexpr std::ptrdiff_t m_flTrooperTakeDamageMult = 0x348; // 
                constexpr std::ptrdiff_t m_flNeutralTakeDamageMulti = 0x34C; // 
                constexpr std::ptrdiff_t m_flNotifyEventTime = 0x350; // 
                constexpr std::ptrdiff_t m_flNearDeathDuration = 0x354; // 
                constexpr std::ptrdiff_t m_flMinimapRevealTime = 0x358; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_SleepDaggerAsleepVData {
                constexpr std::ptrdiff_t m_DebuffParticle = 0x608; // 
                constexpr std::ptrdiff_t m_PostSleepModifier = 0x6E8; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelAbilityVData
            // Field count: 13
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityImmobilizeTrapVData {
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_PreviewRingParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_TrapHighlightParticle = 0x1708; // 
                constexpr std::ptrdiff_t m_ArmedParticle = 0x17E8; // 
                constexpr std::ptrdiff_t m_strTripSound = 0x18C8; // 
                constexpr std::ptrdiff_t m_strExplodeSound = 0x18D8; // 
                constexpr std::ptrdiff_t m_strExpiredSound = 0x18E8; // 
                constexpr std::ptrdiff_t m_strImmobilizeTargetSound = 0x18F8; // 
                constexpr std::ptrdiff_t m_strArmingSound = 0x1908; // 
                constexpr std::ptrdiff_t m_TrapModifier = 0x1918; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1928; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DotModifier = 0x1938; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_SlowModifier = 0x1948; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_flDetonateTime (CCitadelAutoScaledTime)
            // NetworkVarNames: m_flStartTime (GameTime_t)
            namespace CCitadel_Ability_FireBomb {
                constexpr std::ptrdiff_t m_flDetonateTime = 0xCF0; // 
                constexpr std::ptrdiff_t m_flStartTime = 0xD08; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Item_SmokeBomb_PreCast {
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_MagicShock_ProcVData {
                constexpr std::ptrdiff_t m_ProcParticle = 0x638; // 
                constexpr std::ptrdiff_t m_hDamageTrackModifier = 0x718; // 
            }
            // Parent: C_BaseModelEntity
            // Field count: 18
            //
            // Metadata:
            // MNetworkIncludeByName
            // MNetworkExcludeByName
            // MNetworkIncludeByUserGroup
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // NetworkVarNames: m_vDirection (Vector)
            // NetworkVarNames: m_iszEffectName (string_t)
            // NetworkVarNames: m_iszSSEffectName (string_t)
            // NetworkVarNames: m_clrOverlay (Color)
            // NetworkVarNames: m_bOn (bool)
            // NetworkVarNames: m_bmaxColor (bool)
            // NetworkVarNames: m_flSize (float32)
            // NetworkVarNames: m_flHazeScale (float32)
            // NetworkVarNames: m_flRotation (float32)
            // NetworkVarNames: m_flHDRColorScale (float32)
            // NetworkVarNames: m_flAlphaHaze (float32)
            // NetworkVarNames: m_flAlphaScale (float32)
            // NetworkVarNames: m_flAlphaHdr (float32)
            // NetworkVarNames: m_flFarZScale (float32)
            namespace C_Sun {
                constexpr std::ptrdiff_t m_fxSSSunFlareEffectIndex = 0x830; // 
                constexpr std::ptrdiff_t m_fxSunFlareEffectIndex = 0x834; // 
                constexpr std::ptrdiff_t m_fdistNormalize = 0x838; // 
                constexpr std::ptrdiff_t m_vSunPos = 0x83C; // 
                constexpr std::ptrdiff_t m_vDirection = 0x848; // 
                constexpr std::ptrdiff_t m_iszEffectName = 0x858; // 
                constexpr std::ptrdiff_t m_iszSSEffectName = 0x860; // 
                constexpr std::ptrdiff_t m_clrOverlay = 0x868; // 
                constexpr std::ptrdiff_t m_bOn = 0x86C; // 
                constexpr std::ptrdiff_t m_bmaxColor = 0x86D; // 
                constexpr std::ptrdiff_t m_flSize = 0x870; // 
                constexpr std::ptrdiff_t m_flHazeScale = 0x874; // 
                constexpr std::ptrdiff_t m_flRotation = 0x878; // 
                constexpr std::ptrdiff_t m_flHDRColorScale = 0x87C; // 
                constexpr std::ptrdiff_t m_flAlphaHaze = 0x880; // 
                constexpr std::ptrdiff_t m_flAlphaScale = 0x884; // 
                constexpr std::ptrdiff_t m_flAlphaHdr = 0x888; // 
                constexpr std::ptrdiff_t m_flFarZScale = 0x88C; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 12
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Shiv_KillingBlowVData {
                constexpr std::ptrdiff_t m_LeapModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ActiveBuff = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_KillableModifier = 0x1568; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_AttackParticle = 0x1578; // 
                constexpr std::ptrdiff_t m_ImpactParticle = 0x1658; // 
                constexpr std::ptrdiff_t m_FlashParticle = 0x1738; // 
                constexpr std::ptrdiff_t m_KillingBlowCastParticle = 0x1818; // 
                constexpr std::ptrdiff_t m_ChargeUpSound = 0x18F8; // 
                constexpr std::ptrdiff_t m_OnKillSound = 0x1908; // 
                constexpr std::ptrdiff_t m_flPreArrivalAttackStartTime = 0x1918; // 
                constexpr std::ptrdiff_t m_flKillableGlowRange = 0x191C; // 
                constexpr std::ptrdiff_t m_flGlowMinTime = 0x1920; // 
            }
            // Parent: CCitadelBaseShivAbility
            // Field count: 8
            //
            // Metadata:
            // NetworkVarNames: m_vStartPosition (Vector)
            // NetworkVarNames: m_vDashDirection (Vector)
            // NetworkVarNames: m_bIsDashing (bool)
            // NetworkVarNames: m_bStartedInAir (bool)
            namespace CCitadel_Ability_ShivDash {
                constexpr std::ptrdiff_t m_vStartPosition = 0xC78; // 
                constexpr std::ptrdiff_t m_vDashDirection = 0xC84; // 
                constexpr std::ptrdiff_t m_bIsDashing = 0xC90; // 
                constexpr std::ptrdiff_t m_bStartedInAir = 0xC91; // 
                constexpr std::ptrdiff_t m_vecHitEnemies = 0xC98; // 
                constexpr std::ptrdiff_t m_vecLastPosition = 0xCB0; // 
                constexpr std::ptrdiff_t m_nReductionsLeft = 0xCBC; // 
                constexpr std::ptrdiff_t m_flStuckTime = 0xEF0; // 
            }
            // Parent: CCitadel_Ability_TrooperGrenade
            // Field count: 0
            namespace CCitadel_Ability_TrooperNeutralGrenade {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_PlayerPinged {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_TrackingProjectileApplyModifier {
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Rutger_Pulse_Target {
                constexpr std::ptrdiff_t m_vAuraCenter = 0x1A0; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityGenericPerson3VData {
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityPsychicLiftVData {
                constexpr std::ptrdiff_t m_LiftModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_TargetParticle = 0x1558; // 
                constexpr std::ptrdiff_t m_TargetCastSound = 0x1638; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ColossusActive_VData {
                constexpr std::ptrdiff_t m_AuraModifier = 0x608; // 
                constexpr std::ptrdiff_t m_ShieldParticle = 0x618; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Discord_Enemy {
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_BulletArmorShredder_Proc {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Bullet_Shield {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_BonusDamagePercentVData {
                constexpr std::ptrdiff_t m_bSelfish = 0x608; // 
            }
            // Parent: CEntityComponent
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_bvDisabledHitGroups (uint32)
            namespace CHitboxComponent {
                constexpr std::ptrdiff_t m_bvDisabledHitGroups = 0x24; // 
            }
            // Parent: C_BaseTrigger
            // Field count: 9
            //
            // Metadata:
            // NetworkVarNames: m_bEnabled (bool)
            // NetworkVarNames: m_MaxWeight (float)
            // NetworkVarNames: m_FadeDuration (float)
            // NetworkVarNames: m_Weight (float)
            // NetworkVarNames: m_lookupFilename (char)
            namespace C_ColorCorrectionVolume {
                constexpr std::ptrdiff_t m_LastEnterWeight = 0x838; // 
                constexpr std::ptrdiff_t m_LastEnterTime = 0x83C; // 
                constexpr std::ptrdiff_t m_LastExitWeight = 0x840; // 
                constexpr std::ptrdiff_t m_LastExitTime = 0x844; // 
                constexpr std::ptrdiff_t m_bEnabled = 0x848; // 
                constexpr std::ptrdiff_t m_MaxWeight = 0x84C; // 
                constexpr std::ptrdiff_t m_FadeDuration = 0x850; // 
                constexpr std::ptrdiff_t m_Weight = 0x854; // 
                constexpr std::ptrdiff_t m_lookupFilename = 0x858; // 
            }
            // Parent: C_BaseModelEntity
            // Field count: 0
            namespace C_PrecipitationBlocker {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Cadence_Gun_Spikes {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 7
            //
            // Metadata:
            // NetworkVarNames: m_vBeamAimPos (Vector)
            namespace CCitadel_Ability_IceBeam {
                constexpr std::ptrdiff_t m_flNextDamageTick = 0x1290; // 
                constexpr std::ptrdiff_t m_vStart = 0x1294; // 
                constexpr std::ptrdiff_t m_vEnd = 0x12A0; // 
                constexpr std::ptrdiff_t m_vecEntitiesHit = 0x12E8; // 
                constexpr std::ptrdiff_t m_vBeamAimPos = 0x1300; // 
                constexpr std::ptrdiff_t m_angBeamAngles = 0x1310; // 
                constexpr std::ptrdiff_t m_bNeedsBeamReset = 0x1328; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Sleep {
            }
            // Parent: CModifierVData
            // Field count: 25
            //
            // Metadata:
            // MGetKV3ClassDefaults
            // MPropertySuppressBaseClassField
            // MPropertySuppressBaseClassField
            namespace CCitadelModifierVData {
                constexpr std::ptrdiff_t m_bIsBuildup = 0x3E8; // 
                constexpr std::ptrdiff_t m_bNetworkValuesForStatsPreview = 0x3E9; // 
                constexpr std::ptrdiff_t m_vecAutoRegisterModifierValueFromAbilityPropertyName = 0x3F0; // 
                constexpr std::ptrdiff_t m_bCasterCountsAsAssister = 0x408; // 
                constexpr std::ptrdiff_t m_flLingeringAssistWindow = 0x40C; // 
                constexpr std::ptrdiff_t m_bDurationCanBeTimeScaled = 0x410; // 
                constexpr std::ptrdiff_t m_bDurationReducible = 0x411; // 
                constexpr std::ptrdiff_t m_eTimeScaleSource = 0x414; // 
                constexpr std::ptrdiff_t m_bDurationAffectedByEffectiveness = 0x418; // 
                constexpr std::ptrdiff_t m_vecSetAndTrackedAnimGraphParams = 0x420; // 
                constexpr std::ptrdiff_t m_vecSetAndTrackedBodyGroups = 0x438; // 
                constexpr std::ptrdiff_t m_eDrawOverheadStatus = 0x450; // 
                constexpr std::ptrdiff_t m_bReverseHudProgressBar = 0x454; // 
                constexpr std::ptrdiff_t m_strSmallIconCssClass = 0x458; // 
                constexpr std::ptrdiff_t m_strHintText = 0x460; // 
                constexpr std::ptrdiff_t m_strHudIcon = 0x468; // 
                constexpr std::ptrdiff_t m_eHudDisplayLocation = 0x478; // 
                constexpr std::ptrdiff_t m_strHudMessageText = 0x480; // 
                constexpr std::ptrdiff_t m_bIsHiddenOverhead = 0x488; // 
                constexpr std::ptrdiff_t m_vecAlwaysShowInStatModifierUI = 0x490; // 
                constexpr std::ptrdiff_t m_OnCreateResponse = 0x4A8; // 
                constexpr std::ptrdiff_t m_cameraSequenceCreated = 0x4E0; // CitadelCameraOperationsSequence_t
                constexpr std::ptrdiff_t m_bEndCreatedSequenceOnRemove = 0x568; // 
                constexpr std::ptrdiff_t m_cameraSequenceRemoved = 0x570; // CitadelCameraOperationsSequence_t
                constexpr std::ptrdiff_t m_sExpiredSound = 0x5F8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 9
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierLockDownDebuffVData {
                constexpr std::ptrdiff_t m_DebuffParticle = 0x608; // 
                constexpr std::ptrdiff_t m_AOEParticleCaster = 0x6E8; // 
                constexpr std::ptrdiff_t m_AOEParticleEnemy = 0x7C8; // 
                constexpr std::ptrdiff_t m_AOEParticleOthers = 0x8A8; // 
                constexpr std::ptrdiff_t m_strFollowLoop = 0x988; // 
                constexpr std::ptrdiff_t m_strExplodeSound = 0x998; // 
                constexpr std::ptrdiff_t m_strEscapedSound = 0x9A8; // 
                constexpr std::ptrdiff_t m_RootModifier = 0x9B8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BulletResistModifier = 0x9C8; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Bounce_Pad_Ally {
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierAirRaidVData {
                constexpr std::ptrdiff_t m_SlowModifier = 0x638; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_strWeaponShootSound = 0x648; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Bull_HealVData {
                constexpr std::ptrdiff_t m_AuraModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Passive_Cloak {
            }
            // Parent: CitadelItemVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Item_ComboBreakerVData {
                constexpr std::ptrdiff_t m_ComboBreakerModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_HealModifier = 0x15A0; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 6
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_SettingSunThinker_VData {
                constexpr std::ptrdiff_t m_TargetParticle = 0x608; // 
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_LingerParticle = 0x7C8; // 
                constexpr std::ptrdiff_t m_LayerParticle = 0x8A8; // 
                constexpr std::ptrdiff_t m_strExplodeSound = 0x988; // 
                constexpr std::ptrdiff_t m_strTargetingCompletedSound = 0x998; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 12
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_PsychicDagger_MakeDaggers_VData {
                constexpr std::ptrdiff_t m_flDesatAmount = 0x608; // 
                constexpr std::ptrdiff_t m_DesatTint = 0x60C; // 
                constexpr std::ptrdiff_t m_SatTint = 0x610; // 
                constexpr std::ptrdiff_t m_Outline = 0x614; // 
                constexpr std::ptrdiff_t m_DaggerShot = 0x618; // 
                constexpr std::ptrdiff_t m_DaggerSpawn = 0x6F8; // 
                constexpr std::ptrdiff_t m_DaggerAoE = 0x7D8; // 
                constexpr std::ptrdiff_t m_DaggerTargetPreview = 0x8B8; // 
                constexpr std::ptrdiff_t m_DaggerShotFail = 0x998; // 
                constexpr std::ptrdiff_t m_DaggerFireSound = 0xA78; // 
                constexpr std::ptrdiff_t m_DaggerMissSound = 0xA88; // 
                constexpr std::ptrdiff_t m_LastDaggerMissSound = 0xA98; // 
            }
            // Parent: CCitadelModifier
            // Field count: 3
            namespace CCitadel_Modifier_GhostBloodShard {
                constexpr std::ptrdiff_t m_flMinSlowAmount = 0xC0; // 
                constexpr std::ptrdiff_t m_flMoveSpeedPenaltyPerStack = 0xC4; // 
                constexpr std::ptrdiff_t m_flSlowDuration = 0xC8; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_LifestrikeGauntlets_VData {
                constexpr std::ptrdiff_t m_SwingParticle = 0x638; // 
                constexpr std::ptrdiff_t m_HitParticle = 0x718; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_AmmoScavenger {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Objective_RegenVData {
                constexpr std::ptrdiff_t m_flOutOfCombatHealthRegen = 0x608; // 
                constexpr std::ptrdiff_t m_flOutOfCombatRegenDelay = 0x60C; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_ApplyDebuff_Proc {
            }
            // Parent: CBaseAnimGraph
            // Field count: 0
            namespace C_Citadel_PickupItemSpawner {
            }
            // Parent: CBaseAnimGraph
            // Field count: 0
            namespace CCitadel_HeroTestOrbSpawner {
            }
            // Parent: CCitadel_Item
            // Field count: 1
            namespace CCitadel_Item_RescueBeam {
                constexpr std::ptrdiff_t m_bCanPull = 0xC90; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityCadenceLullabyVData {
                constexpr std::ptrdiff_t m_SleepAOEModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Chrono_TimeWall_Effect {
            }
            // Parent: CitadelItemVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_WeaponUpgrade_SurgingPowerVData {
                constexpr std::ptrdiff_t m_ModifierSurgingPower = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_CastTargetEffect = 0x15A0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_FireRateAuraVData {
                constexpr std::ptrdiff_t m_FireRateAuraSourceParticle = 0x608; // 
            }
            // Parent: CCitadel_Modifier_Intrinsic_Base
            // Field count: 0
            namespace CCitadel_Modifier_MagicClarityWatcher {
            }
            // Parent: CCitadelModelEntity
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_bAllowRotatingUp (bool)
            // NetworkVarNames: m_bFixedPosition (bool)
            // NetworkVarNames: m_flShieldOffset (float)
            namespace C_Citadel_Shield {
                constexpr std::ptrdiff_t m_bAllowRotatingUp = 0x838; // 
                constexpr std::ptrdiff_t m_bFixedPosition = 0x839; // 
                constexpr std::ptrdiff_t m_flShieldOffset = 0x83C; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Metal {
            }
            // Parent: CCitadel_Modifier_Stunned
            // Field count: 0
            namespace CCitadel_Modifier_Slork_Raging_Current_Damp {
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityGangActivityVData {
                constexpr std::ptrdiff_t m_AbilitySwap = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelAbilityVData
            // Field count: 6
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_SettingSun_VData {
                constexpr std::ptrdiff_t m_BeamTargetParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_UnitTargetParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_SettingSunThinkerModifier = 0x1708; // 
                constexpr std::ptrdiff_t m_flSSCameraPreviewOffset = 0x1718; // 
                constexpr std::ptrdiff_t m_flSSCameraPreviewSpeed = 0x171C; // 
                constexpr std::ptrdiff_t m_flSSCameraPreviewDistance = 0x1720; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 5
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Burrow_VData {
                constexpr std::ptrdiff_t m_BurrowPlayerParticle = 0x608; // 
                constexpr std::ptrdiff_t m_flDesatAmount = 0x6E8; // 
                constexpr std::ptrdiff_t m_DesatTint = 0x6EC; // 
                constexpr std::ptrdiff_t m_SatTint = 0x6F0; // 
                constexpr std::ptrdiff_t m_Outline = 0x6F4; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_BansheeSlugs_Headshot {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ReturnFire {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_BulletResistReductionStack {
            }
            // Parent: CEntitySubclassVDataBase
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CFuncFoliageVData {
                constexpr std::ptrdiff_t m_BulletImpactParticle = 0x28; // 
                constexpr std::ptrdiff_t m_BulletExitParticle = 0x108; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Arcane_Eater_Debuff {
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 2
            namespace CCitadel_Modifier_BaseBulletPreRollProc {
                constexpr std::ptrdiff_t m_nSuppressProcShotID = 0x168; // 
                constexpr std::ptrdiff_t m_vecProcdBulletIDs = 0x170; // 
            }
            // Parent: CPlayer_MovementServices_Humanoid
            // Field count: 6
            //
            // Metadata:
            // NetworkVarNames: m_vPositionDeltaVelocity (CNetworkVelocityVector)
            namespace CCitadelPlayer_MovementServices {
                constexpr std::ptrdiff_t m_vPositionDeltaVelocity = 0x218; // 
                constexpr std::ptrdiff_t m_vecPogoVelocity = 0x248; // 
                constexpr std::ptrdiff_t m_vecSupport = 0x254; // 
                constexpr std::ptrdiff_t m_bColliding = 0x260; // 
                constexpr std::ptrdiff_t m_bLandedOnGround = 0x261; // 
                constexpr std::ptrdiff_t m_bHasFreeCursor = 0x262; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 6
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityWreckingBallVData {
                constexpr std::ptrdiff_t m_SummonParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_SummonReadyParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_SummonParticleAttachment = 0x1708; // 
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x1710; // 
                constexpr std::ptrdiff_t m_AutoThrowModifier = 0x17F0; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_HoldingBallLoop = 0x1800; // 
            }
            // Parent: CCitadelModifier
            // Field count: 2
            namespace CCitadel_Modifier_Gravity_Lasso_Self {
                constexpr std::ptrdiff_t m_bHasUsedBouncePad = 0xC0; // 
                constexpr std::ptrdiff_t m_vCastTargets = 0xC8; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_PsychicLift {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Burning {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_InFountain {
            }
            // Parent: C_BarnLight
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_flInnerAngle (float)
            // NetworkVarNames: m_flOuterAngle (float)
            // NetworkVarNames: m_bShowLight (bool)
            namespace C_OmniLight {
                constexpr std::ptrdiff_t m_flInnerAngle = 0xB78; // 
                constexpr std::ptrdiff_t m_flOuterAngle = 0xB7C; // 
                constexpr std::ptrdiff_t m_bShowLight = 0xB80; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierSlorkAmbushVData {
                constexpr std::ptrdiff_t m_strAmbushEffect = 0x608; // 
            }
            // Parent: CCitadel_Modifier_Invis
            // Field count: 1
            namespace CCitadel_Modifier_Slork_Invis {
                constexpr std::ptrdiff_t m_bHasGoneFullyInvis = 0x2D8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Cadence_Crescendo_PostAOE {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ChargedTackleActive {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_MobileResupply {
            }
            // Parent: CCitadel_Modifier_Base
            // Field count: 0
            namespace CCitadel_Modifier_MagicCarpet_Summon {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_RescueBeamVData {
                constexpr std::ptrdiff_t m_BeamParticle = 0x608; // 
                constexpr std::ptrdiff_t m_ImpactParticle = 0x6E8; // 
            }
            // Parent: C_AI_CitadelNPC
            // Field count: 0
            //
            // Metadata:
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            namespace C_NPC_HornetDrone {
            }
            // Parent: CCitadelModifier
            // Field count: 6
            namespace CModifier_Mirage_SandPhantom {
                constexpr std::ptrdiff_t m_particleStart = 0xC0; // 
                constexpr std::ptrdiff_t m_particleEnd = 0xC4; // 
                constexpr std::ptrdiff_t m_particleTrail = 0xC8; // 
                constexpr std::ptrdiff_t m_vecStartPosition = 0xCC; // 
                constexpr std::ptrdiff_t m_flStartDelay = 0xD8; // 
                constexpr std::ptrdiff_t m_vecApplyOffset = 0xDC; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CModifier_Synth_Grasp_Victim {
                constexpr std::ptrdiff_t m_vecOrigin = 0xC0; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Cadence_Lullaby {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_GangActivity {
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_ShieldedSentry_VData {
                constexpr std::ptrdiff_t m_InnateModifier = 0x1548; // 
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1558; // 
                constexpr std::ptrdiff_t m_flDamageFalloffEndScale = 0x1568; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Hornet_Snipe {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadelBaseAbilityServerOnly {
            }
            // Parent: CEntitySubclassVDataBase
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            // MVDataNodeType
            // MVDataOverlayType
            namespace CScaleFunctionVData {
                constexpr std::ptrdiff_t m_eSpecificStatScaleType = 0x28; // 
                constexpr std::ptrdiff_t m_flStatScale = 0x2C; // 
                constexpr std::ptrdiff_t m_bFunctionDisabled = 0x30; // 
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Thumper_2_AuraVData {
                constexpr std::ptrdiff_t m_AoEParticle = 0x648; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 7
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ItemWalkBackVData {
                constexpr std::ptrdiff_t m_flStopDistance = 0x608; // 
                constexpr std::ptrdiff_t m_flMaxSpeedDistance = 0x60C; // 
                constexpr std::ptrdiff_t m_flSlowSpeed = 0x610; // 
                constexpr std::ptrdiff_t m_flFastSpeed = 0x614; // 
                constexpr std::ptrdiff_t m_flVerticalOffset = 0x618; // 
                constexpr std::ptrdiff_t m_flTolerance = 0x61C; // 
                constexpr std::ptrdiff_t m_flRepathTime = 0x620; // 
            }
            // Parent: C_PointEntity
            // Field count: 0
            namespace CCitadelItemPickupRejuvHeroTestInfoSpawn {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 4
            //
            // Metadata:
            // NetworkVarNames: m_hActiveProjectile (EHANDLE)
            namespace CAbility_Synth_PlasmaFlux {
                constexpr std::ptrdiff_t m_bTeleported = 0xC88; // 
                constexpr std::ptrdiff_t m_flProjectileLaunchTime = 0xC8C; // 
                constexpr std::ptrdiff_t m_flProjectileExpireTime = 0xC90; // 
                constexpr std::ptrdiff_t m_hActiveProjectile = 0xC94; // 
            }
            // Parent: CCitadel_Ability_PrimaryWeaponVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_ShivWeapon_VData {
                constexpr std::ptrdiff_t m_flPushForce = 0x1590; // 
            }
            // Parent: CCitadelModifier
            // Field count: 4
            namespace CCitadel_Modifier_Nano_PredatoryStatue {
                constexpr std::ptrdiff_t m_GameTimeEnabled = 0x100; // 
                constexpr std::ptrdiff_t m_LastCatInAreaTime = 0x104; // 
                constexpr std::ptrdiff_t m_bIsAttacking = 0x108; // 
                constexpr std::ptrdiff_t m_iTargetID = 0x10C; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Guiding_ArrowVData {
                constexpr std::ptrdiff_t m_GlowEnemeyModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_DeathTax {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Low_Health_GlowVData {
                constexpr std::ptrdiff_t m_GlowParticle = 0x608; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ParriedStun {
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_HunterAuraTarget {
                constexpr std::ptrdiff_t m_flDebuffScale = 0x168; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_CQC_Proc {
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_ArmorUpgrade_SlowImmunityVData {
                constexpr std::ptrdiff_t m_ImmunityModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Discord_Friendly {
                constexpr std::ptrdiff_t m_flHealPerSecond = 0xC0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierObscuredVData {
                constexpr std::ptrdiff_t m_flHideDuration = 0x608; // 
                constexpr std::ptrdiff_t m_flRevealDuration = 0x60C; // 
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_HeldItemPickupAuraVData {
                constexpr std::ptrdiff_t m_strFilterAbilityName = 0x648; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_ArmorUpgrade_DamageRecycler {
            }
            // Parent: CitadelAbilityVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityTargetdummy2VData {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Wrecker_Ultimate {
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_BulletArmorShredder_ProcVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x638; // 
            }
            // Parent: CCitadelModifier
            // Field count: 2
            namespace CCitadel_Modifier_Obscured {
                constexpr std::ptrdiff_t m_flStartObscuredAmount = 0xC0; // 
                constexpr std::ptrdiff_t m_AmbientParticles = 0xC8; // CUtlVectorFixedGrowable<ParticleIndex_t,3>
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_ItemPickupAura {
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_Thumper_PullAOE {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_Camouflage {
            }
            // Parent: CAI_NPC_TrooperVData
            // Field count: 10
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CNPC_TrooperBossVData {
                constexpr std::ptrdiff_t m_bMitigateDamageFromPlayers = 0x1628; // 
                constexpr std::ptrdiff_t m_bBarracksGuardian = 0x1629; // 
                constexpr std::ptrdiff_t m_flPlayerAutoAttackRange = 0x162C; // 
                constexpr std::ptrdiff_t m_flMinMeleeAttackTime = 0x1630; // 
                constexpr std::ptrdiff_t m_BackdoorProtectionModifier = 0x1638; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BackdoorBulletResistModifier = 0x1648; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ObjectiveRegen = 0x1658; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_sAngryStart = 0x1668; // 
                constexpr std::ptrdiff_t m_sAngryLoop = 0x1678; // 
                constexpr std::ptrdiff_t m_sAngryStop = 0x1688; // 
            }
            // Parent: None
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_iAttributeDefinitionIndex (attrib_definition_index_t)
            // NetworkVarNames: m_flValue (float)
            namespace C_EconItemAttribute {
                constexpr std::ptrdiff_t m_iAttributeDefinitionIndex = 0x30; // 
                constexpr std::ptrdiff_t m_flValue = 0x34; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityTokamakRadianceVData {
                constexpr std::ptrdiff_t m_RadianceModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_hActiveProjectile (EHANDLE)
            namespace CCitadel_Ability_Perched_Predator {
                constexpr std::ptrdiff_t m_hActiveProjectile = 0xC78; // 
            }
            // Parent: None
            // Field count: 5
            //
            // Metadata:
            // NetworkVarNames: m_nModelID (int32)
            // NetworkVarNames: m_vecPanelSize (Vector2D)
            // NetworkVarNames: m_vecPanelVertices (Vector)
            // NetworkVarNames: m_flThickness (float)
            // NetworkVarNames: m_SurfacePropStringToken (CUtlStringToken)
            namespace ice_path_shard_model_desc_t {
                constexpr std::ptrdiff_t m_nModelID = 0x8; // 
                constexpr std::ptrdiff_t m_vecPanelSize = 0xC; // 
                constexpr std::ptrdiff_t m_vecPanelVertices = 0x18; // 
                constexpr std::ptrdiff_t m_flThickness = 0x30; // 
                constexpr std::ptrdiff_t m_SurfacePropStringToken = 0x34; // 
            }
            // Parent: CCitadel_Modifier_Root
            // Field count: 0
            namespace CCitadel_Modifier_ImmobilizeTrap_Immobilize {
            }
            // Parent: None
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_duration (float32)
            // NetworkVarNames: m_timestamp (float32)
            // NetworkVarNames: m_timescale (float32)
            namespace EngineCountdownTimer {
                constexpr std::ptrdiff_t m_duration = 0x8; // 
                constexpr std::ptrdiff_t m_timestamp = 0xC; // 
                constexpr std::ptrdiff_t m_timescale = 0x10; // 
            }
            // Parent: C_CitadelProjectile
            // Field count: 0
            namespace C_Projectile_Synth_Barrage {
            }
            // Parent: CCitadelModifierAura_Cone
            // Field count: 2
            namespace CCitadel_Modifier_Bull_Heal_Aura {
                constexpr std::ptrdiff_t m_playerAngles = 0xE0; // 
                constexpr std::ptrdiff_t m_ConeParticle = 0xEC; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Slork_Scald {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Nano_Shadow_Debuff {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_WreckerScrapBlast {
            }
            // Parent: CitadelAbilityVData
            // Field count: 15
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityMeleeParryVData {
                constexpr std::ptrdiff_t m_flWhiffDuration = 0x1548; // 
                constexpr std::ptrdiff_t m_flMovementRestrictionTime = 0x154C; // 
                constexpr std::ptrdiff_t m_flActiveTime = 0x1550; // 
                constexpr std::ptrdiff_t m_flParryEndVisualTime = 0x1554; // 
                constexpr std::ptrdiff_t m_flSuccessActiveTime = 0x1558; // 
                constexpr std::ptrdiff_t m_flBossVictimNoMeleeTime = 0x155C; // 
                constexpr std::ptrdiff_t m_flBossVictimCalmTime = 0x1560; // 
                constexpr std::ptrdiff_t m_SuccessfulParryParticle = 0x1568; // 
                constexpr std::ptrdiff_t m_strSuccessfulParrySound = 0x1648; // 
                constexpr std::ptrdiff_t m_ParryActiveModifier = 0x1658; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ParryVictimModifier = 0x1668; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ParryCooldownModifier = 0x1678; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ParryEndVisualModifier = 0x1688; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ParryBossVictimNoMeleeModifier = 0x1698; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ParryBossVictimCalmModifier = 0x16A8; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CBaseAnimGraph
            // Field count: 1
            //
            // Metadata:
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // NetworkVarNames: m_nHitIndex (int)
            namespace C_Citadel_BreakableProp {
                constexpr std::ptrdiff_t m_nHitIndex = 0xB50; // 
            }
            // Parent: CCitadelBaseYamatoAbility
            // Field count: 21
            //
            // Metadata:
            // NetworkVarNames: m_bShadowFormCast (bool)
            // NetworkVarNames: m_vYamatoCastPos (Vector)
            // NetworkVarNames: m_vTargetCastPos (Vector)
            // NetworkVarNames: m_flFlyingToTargetStartTime (GameTime_t)
            // NetworkVarNames: m_flEndAttackTime (GameTime_t)
            // NetworkVarNames: m_flGrappleStartTime (GameTime_t)
            // NetworkVarNames: m_flGrappleArriveTime (GameTime_t)
            // NetworkVarNames: m_flAttackLatchTime (GameTime_t)
            // NetworkVarNames: m_vAttackLatchPos (Vector)
            // NetworkVarNames: m_hTarget (EHANDLE)
            // NetworkVarNames: m_flGrappleShotAttackTime (GameTime_t)
            // NetworkVarNames: m_rgPath (Vector)
            // NetworkVarNames: m_nPathIdx (int)
            // NetworkVarNames: m_nPathSize (int)
            // NetworkVarNames: m_flPathLength (float)
            // NetworkVarNames: m_vFlyingInitialOffsetToPath (Vector)
            // NetworkVarNames: flDistFlown (float)
            namespace CCitadel_Ability_FlyingStrike {
                constexpr std::ptrdiff_t m_desatVolIdx = 0xC80; // 
                constexpr std::ptrdiff_t m_bShadowFormCast = 0xC84; // 
                constexpr std::ptrdiff_t m_vYamatoCastPos = 0xC88; // 
                constexpr std::ptrdiff_t m_vTargetCastPos = 0xC94; // 
                constexpr std::ptrdiff_t m_flFlyingToTargetStartTime = 0xCA0; // 
                constexpr std::ptrdiff_t m_flEndAttackTime = 0xCA4; // 
                constexpr std::ptrdiff_t m_flGrappleStartTime = 0xCA8; // 
                constexpr std::ptrdiff_t m_flGrappleArriveTime = 0xCAC; // 
                constexpr std::ptrdiff_t m_flAttackLatchTime = 0xCB0; // 
                constexpr std::ptrdiff_t m_vAttackLatchPos = 0xCB4; // 
                constexpr std::ptrdiff_t m_hTarget = 0xCC0; // 
                constexpr std::ptrdiff_t m_flGrappleShotAttackTime = 0xCC4; // 
                constexpr std::ptrdiff_t m_rgPath = 0xCCC; // 
                constexpr std::ptrdiff_t m_nPathIdx = 0xDBC; // 
                constexpr std::ptrdiff_t m_nPathSize = 0xDC0; // 
                constexpr std::ptrdiff_t m_flPathLength = 0xDC4; // 
                constexpr std::ptrdiff_t m_vFlyingInitialOffsetToPath = 0xDC8; // 
                constexpr std::ptrdiff_t flDistFlown = 0xDD4; // 
                constexpr std::ptrdiff_t m_vLastSafePos = 0xDD8; // 
                constexpr std::ptrdiff_t m_nGrappleTravelEffect = 0xE90; // 
                constexpr std::ptrdiff_t m_bPathDirty = 0xEE8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_ShivDash {
                constexpr std::ptrdiff_t m_bUseTrail = 0xF8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_TargetPracticeSelfVData {
                constexpr std::ptrdiff_t m_TracerParticle = 0x608; // 
                constexpr std::ptrdiff_t m_strWeaponShootSound = 0x6E8; // 
                constexpr std::ptrdiff_t m_strBulletWhizSound = 0x6F8; // 
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Cadence_SleepAOEVData {
                constexpr std::ptrdiff_t m_AuraParticle = 0x648; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Slork_Raging_Current {
                constexpr std::ptrdiff_t m_bUnitTarget = 0x168; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Cadence_Crescendo_InAOE {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Astro_ShotgunBuffVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Bull_Heal_TargetVData {
                constexpr std::ptrdiff_t m_DrainParticle = 0x608; // 
            }
            // Parent: CCitadel_Modifier_Intrinsic_BaseVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_NapalmProjectileVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_SlowModifier = 0x618; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_WeaponUpgrade_WeaponEaterVData {
                constexpr std::ptrdiff_t m_WeaponEaterTracker = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_ChainLightningEffect
            // Field count: 0
            namespace CCitadel_Modifier_Galvanic_Storm_Effect {
            }
            // Parent: CitadelItemVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CItemAOERootVData {
                constexpr std::ptrdiff_t m_AOEParticle = 0x1590; // 
                constexpr std::ptrdiff_t m_strRootTargetSound = 0x1670; // 
                constexpr std::ptrdiff_t m_TetherModifier = 0x1680; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelItemVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Item_TrackingProjectileApplyModifierVData {
                constexpr std::ptrdiff_t m_ProjectileImpactParticle = 0x1590; // 
                constexpr std::ptrdiff_t m_TargetModifier = 0x1670; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_FriendlyOnlyModifier = 0x1680; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Rutger_CheatDeath_Activated_VData {
                constexpr std::ptrdiff_t m_ActivatedParticle = 0x608; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadelBaseShivAbility {
            }
            // Parent: CCitadelModifierVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ReturnFireVData {
                constexpr std::ptrdiff_t m_AttackerHitFx = 0x608; // 
                constexpr std::ptrdiff_t m_ImpactParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_SpiritReflectTracerReplacement = 0x7C8; // 
                constexpr std::ptrdiff_t m_strAttackerHitSound = 0x8A8; // 
            }
            // Parent: None
            // Field count: 5
            namespace C_BaseFlex__Emphasized_Phoneme {
                constexpr std::ptrdiff_t m_sClassName = 0x0; // 
                constexpr std::ptrdiff_t m_flAmount = 0x18; // 
                constexpr std::ptrdiff_t m_bRequired = 0x1C; // 
                constexpr std::ptrdiff_t m_bBasechecked = 0x1D; // 
                constexpr std::ptrdiff_t m_bValid = 0x1E; // 
            }
            // Parent: None
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_timestamp (GameTime_t)
            // NetworkVarNames: m_nWorldGroupId (WorldGroupId_t)
            namespace IntervalTimer {
                constexpr std::ptrdiff_t m_timestamp = 0x8; // 
                constexpr std::ptrdiff_t m_nWorldGroupId = 0xC; // 
            }
            // Parent: C_CitadelProjectile
            // Field count: 0
            namespace C_Citadel_Projectile_SettingSun {
            }
            // Parent: CCitadel_Modifier_SilencedVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_BubbleVData {
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x8A8; // 
                constexpr std::ptrdiff_t m_ExplodeSound = 0x988; // 
                constexpr std::ptrdiff_t m_BuffModifier = 0x998; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CNPC_SimpleAnimatingAIVData
            // Field count: 12
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CNPC_FieldSentryVData {
                constexpr std::ptrdiff_t m_LaserSightParticle = 0x108; // 
                constexpr std::ptrdiff_t m_KillExplosionParticle = 0x1E8; // 
                constexpr std::ptrdiff_t m_DeployProgressModifier = 0x2C8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_sSpawnSound = 0x2D8; // 
                constexpr std::ptrdiff_t m_sKillExplosionSound = 0x2E8; // 
                constexpr std::ptrdiff_t m_sTargetAcquiredLocalSound = 0x2F8; // 
                constexpr std::ptrdiff_t m_sTargetAcquiredSound = 0x308; // 
                constexpr std::ptrdiff_t m_flIdleTurnSpeed = 0x318; // 
                constexpr std::ptrdiff_t m_flIdleTurnAngles = 0x31C; // 
                constexpr std::ptrdiff_t m_flTrooperTakeDamageMult = 0x320; // 
                constexpr std::ptrdiff_t m_flNeutralTakeDamageMulti = 0x324; // 
                constexpr std::ptrdiff_t m_flNotifyEventTime = 0x328; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_HookSelf {
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_VoidSphereVData {
                constexpr std::ptrdiff_t m_BubbleModifier = 0x1548; // 
                constexpr std::ptrdiff_t m_strCastEffect = 0x1558; // 
                constexpr std::ptrdiff_t m_strAllyPositionPreview = 0x1638; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ExplosiveShots {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Upgrade_AerialAssault {
            }
            // Parent: C_BaseTrigger
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_vLaunchTarget (Vector)
            // NetworkVarNames: m_flLaunchSpeed (float)
            namespace CCitadelCatapultTrigger {
                constexpr std::ptrdiff_t m_vLaunchTarget = 0x838; // 
                constexpr std::ptrdiff_t m_flLaunchSpeed = 0x844; // 
                constexpr std::ptrdiff_t m_nameTarget = 0x848; // 
            }
            // Parent: C_BaseModelEntity
            // Field count: 9
            //
            // Metadata:
            // NetworkVarNames: m_vecLadderDir (Vector)
            // NetworkVarNames: m_vecPlayerMountPositionTop (Vector)
            // NetworkVarNames: m_vecPlayerMountPositionBottom (Vector)
            // NetworkVarNames: m_flAutoRideSpeed (float)
            // NetworkVarNames: m_bFakeLadder (bool)
            namespace C_FuncLadder {
                constexpr std::ptrdiff_t m_vecLadderDir = 0x830; // 
                constexpr std::ptrdiff_t m_Dismounts = 0x840; // CUtlVector<CHandle<C_InfoLadderDismount>>
                constexpr std::ptrdiff_t m_vecLocalTop = 0x858; // 
                constexpr std::ptrdiff_t m_vecPlayerMountPositionTop = 0x864; // 
                constexpr std::ptrdiff_t m_vecPlayerMountPositionBottom = 0x870; // 
                constexpr std::ptrdiff_t m_flAutoRideSpeed = 0x87C; // 
                constexpr std::ptrdiff_t m_bDisabled = 0x880; // 
                constexpr std::ptrdiff_t m_bFakeLadder = 0x881; // 
                constexpr std::ptrdiff_t m_bHasSlack = 0x882; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Synth_Affliction_Debuff_VData {
                constexpr std::ptrdiff_t m_EffectParticle = 0x608; // 
                constexpr std::ptrdiff_t m_DebuffParticle = 0x6E8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Synth_PlasmaFlux_WeaponDamage {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Cadence_SilenceContraptionsVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_TangoTether_Tether {
                constexpr std::ptrdiff_t m_fHealingSoundBuildup = 0xF8; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_MeleeCharge {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Fervor_Bonuses_VData {
                constexpr std::ptrdiff_t m_BonusesParticle = 0x608; // 
                constexpr std::ptrdiff_t m_ActivateBonusesSound = 0x6E8; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_SilencerProcActiveVData {
                constexpr std::ptrdiff_t m_TracerParticle = 0x638; // 
                constexpr std::ptrdiff_t m_SilencerActiveParticle = 0x718; // 
                constexpr std::ptrdiff_t m_SilenceActiveModifier = 0x7F8; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_SoundOpvarSetAABBEntity
            // Field count: 0
            namespace C_SoundOpvarSetOBBEntity {
            }
            // Parent: CPlayerPawnComponent
            // Field count: 4
            //
            // Metadata:
            // NetworkVarNames: m_hMyWeapons (CHandle<C_BasePlayerWeapon>)
            // NetworkVarNames: m_hActiveWeapon (CHandle<CBasePlayerWeapon>)
            // NetworkVarNames: m_hLastWeapon (CHandle<CBasePlayerWeapon>)
            // NetworkVarNames: m_iAmmo (uint16)
            namespace CPlayer_WeaponServices {
                constexpr std::ptrdiff_t m_hMyWeapons = 0x40; // 
                constexpr std::ptrdiff_t m_hActiveWeapon = 0x58; // 
                constexpr std::ptrdiff_t m_hLastWeapon = 0x5C; // 
                constexpr std::ptrdiff_t m_iAmmo = 0x60; // 
            }
            // Parent: None
            // Field count: 3
            namespace CAttributeManager__cached_attribute_float_t {
                constexpr std::ptrdiff_t flIn = 0x0; // 
                constexpr std::ptrdiff_t iAttribHook = 0x8; // 
                constexpr std::ptrdiff_t flOut = 0x10; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Bolo {
                constexpr std::ptrdiff_t m_hRingEffect = 0xC0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelModifierDustStormAuraApplyVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_BulletFlurryWindup {
            }
            // Parent: CBaseAnimGraph
            // Field count: 0
            //
            // Metadata:
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            namespace CCitadelAnimatingModelEntity {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_TargetPracticeDebuff {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Chrono_PulseGrenade_PulseArea {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Wraith_ProjectMind_Shield {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_FlameDashBurn {
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_ZipLineBoost_VData {
                constexpr std::ptrdiff_t m_ZipboostModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_flTimeToActivate = 0x1558; // 
                constexpr std::ptrdiff_t m_flTimeForHint = 0x155C; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 10
            //
            // Metadata:
            // NetworkVarNames: m_bPreparing (bool)
            // NetworkVarNames: m_bTackling (bool)
            // NetworkVarNames: m_flTackleStartTime (GameTime_t)
            // NetworkVarNames: m_flTackleDuration (float)
            // NetworkVarNames: m_vecTackleDir (Vector)
            namespace CCitadel_Ability_SuperNeutralCharge {
                constexpr std::ptrdiff_t m_bPreparing = 0xE38; // 
                constexpr std::ptrdiff_t m_bTackling = 0xE39; // 
                constexpr std::ptrdiff_t m_flTackleStartTime = 0xE3C; // 
                constexpr std::ptrdiff_t m_flTackleDuration = 0xE40; // 
                constexpr std::ptrdiff_t m_vecTackleDir = 0xE44; // 
                constexpr std::ptrdiff_t m_vecLastPosition = 0xE50; // 
                constexpr std::ptrdiff_t m_nStuckFramesCount = 0xE5C; // 
                constexpr std::ptrdiff_t m_vecHitEnemies = 0xE60; // 
                constexpr std::ptrdiff_t m_flPrepareStartTime = 0xE78; // 
                constexpr std::ptrdiff_t m_nDistancePreview = 0xE7C; // 
            }
            // Parent: None
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_nEntIndex (CEntityIndex)
            // NetworkVarNames: m_nTeam (int8)
            // NetworkVarNames: m_nPositionXY (uint16)
            namespace STrooperFOWEntity {
                constexpr std::ptrdiff_t m_nEntIndex = 0x30; // 
                constexpr std::ptrdiff_t m_nTeam = 0x34; // 
                constexpr std::ptrdiff_t m_nPositionXY = 0x36; // 
            }
            // Parent: None
            // Field count: 8
            //
            // Metadata:
            // NetworkVarNames: m_nInteractsAs (uint64)
            // NetworkVarNames: m_nInteractsWith (uint64)
            // NetworkVarNames: m_nInteractsExclude (uint64)
            // NetworkVarNames: m_nEntityId (uint32)
            // NetworkVarNames: m_nOwnerId (uint32)
            // NetworkVarNames: m_nHierarchyId (uint16)
            // NetworkVarNames: m_nCollisionGroup (uint8)
            // NetworkVarNames: m_nCollisionFunctionMask (uint8)
            namespace VPhysicsCollisionAttribute_t {
                constexpr std::ptrdiff_t m_nInteractsAs = 0x8; // 
                constexpr std::ptrdiff_t m_nInteractsWith = 0x10; // 
                constexpr std::ptrdiff_t m_nInteractsExclude = 0x18; // 
                constexpr std::ptrdiff_t m_nEntityId = 0x20; // 
                constexpr std::ptrdiff_t m_nOwnerId = 0x24; // 
                constexpr std::ptrdiff_t m_nHierarchyId = 0x28; // 
                constexpr std::ptrdiff_t m_nCollisionGroup = 0x2A; // 
                constexpr std::ptrdiff_t m_nCollisionFunctionMask = 0x2B; // 
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_HeldItemPickupAura {
            }
            // Parent: CCitadel_Item
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_flEndTime (GameTime_t)
            namespace CCitadel_Item_Bubble {
                constexpr std::ptrdiff_t m_flEndTime = 0xC90; // 
            }
            // Parent: C_BaseEntity
            // Field count: 34
            //
            // Metadata:
            // NetworkVarNames: m_flScattering (float)
            // NetworkVarNames: m_flAnisotropy (float)
            // NetworkVarNames: m_flFadeSpeed (float)
            // NetworkVarNames: m_flDrawDistance (float)
            // NetworkVarNames: m_flFadeInStart (float)
            // NetworkVarNames: m_flFadeInEnd (float)
            // NetworkVarNames: m_flIndirectStrength (float)
            // NetworkVarNames: m_nVolumeDepth (int)
            // NetworkVarNames: m_fFirstVolumeSliceThickness (float)
            // NetworkVarNames: m_nIndirectTextureDimX (int)
            // NetworkVarNames: m_nIndirectTextureDimY (int)
            // NetworkVarNames: m_nIndirectTextureDimZ (int)
            // NetworkVarNames: m_vBoxMins (Vector)
            // NetworkVarNames: m_vBoxMaxs (Vector)
            // NetworkVarNames: m_bActive (bool)
            // NetworkVarNames: m_flStartAnisoTime (GameTime_t)
            // NetworkVarNames: m_flStartScatterTime (GameTime_t)
            // NetworkVarNames: m_flStartDrawDistanceTime (GameTime_t)
            // NetworkVarNames: m_flStartAnisotropy (float)
            // NetworkVarNames: m_flStartScattering (float)
            // NetworkVarNames: m_flStartDrawDistance (float)
            // NetworkVarNames: m_flDefaultAnisotropy (float)
            // NetworkVarNames: m_flDefaultScattering (float)
            // NetworkVarNames: m_flDefaultDrawDistance (float)
            // NetworkVarNames: m_bStartDisabled (bool)
            // NetworkVarNames: m_bEnableIndirect (bool)
            // NetworkVarNames: m_bIndirectUseLPVs (bool)
            // NetworkVarNames: m_bIsMaster (bool)
            // NetworkVarNames: m_hFogIndirectTexture (HRenderTextureStrong)
            // NetworkVarNames: m_nForceRefreshCount (int)
            // NetworkVarNames: m_fNoiseSpeed (float)
            // NetworkVarNames: m_fNoiseStrength (float)
            // NetworkVarNames: m_vNoiseScale (Vector)
            namespace C_EnvVolumetricFogController {
                constexpr std::ptrdiff_t m_flScattering = 0x558; // 
                constexpr std::ptrdiff_t m_flAnisotropy = 0x55C; // 
                constexpr std::ptrdiff_t m_flFadeSpeed = 0x560; // 
                constexpr std::ptrdiff_t m_flDrawDistance = 0x564; // 
                constexpr std::ptrdiff_t m_flFadeInStart = 0x568; // 
                constexpr std::ptrdiff_t m_flFadeInEnd = 0x56C; // 
                constexpr std::ptrdiff_t m_flIndirectStrength = 0x570; // 
                constexpr std::ptrdiff_t m_nVolumeDepth = 0x574; // 
                constexpr std::ptrdiff_t m_fFirstVolumeSliceThickness = 0x578; // 
                constexpr std::ptrdiff_t m_nIndirectTextureDimX = 0x57C; // 
                constexpr std::ptrdiff_t m_nIndirectTextureDimY = 0x580; // 
                constexpr std::ptrdiff_t m_nIndirectTextureDimZ = 0x584; // 
                constexpr std::ptrdiff_t m_vBoxMins = 0x588; // 
                constexpr std::ptrdiff_t m_vBoxMaxs = 0x594; // 
                constexpr std::ptrdiff_t m_bActive = 0x5A0; // 
                constexpr std::ptrdiff_t m_flStartAnisoTime = 0x5A4; // 
                constexpr std::ptrdiff_t m_flStartScatterTime = 0x5A8; // 
                constexpr std::ptrdiff_t m_flStartDrawDistanceTime = 0x5AC; // 
                constexpr std::ptrdiff_t m_flStartAnisotropy = 0x5B0; // 
                constexpr std::ptrdiff_t m_flStartScattering = 0x5B4; // 
                constexpr std::ptrdiff_t m_flStartDrawDistance = 0x5B8; // 
                constexpr std::ptrdiff_t m_flDefaultAnisotropy = 0x5BC; // 
                constexpr std::ptrdiff_t m_flDefaultScattering = 0x5C0; // 
                constexpr std::ptrdiff_t m_flDefaultDrawDistance = 0x5C4; // 
                constexpr std::ptrdiff_t m_bStartDisabled = 0x5C8; // 
                constexpr std::ptrdiff_t m_bEnableIndirect = 0x5C9; // 
                constexpr std::ptrdiff_t m_bIndirectUseLPVs = 0x5CA; // 
                constexpr std::ptrdiff_t m_bIsMaster = 0x5CB; // 
                constexpr std::ptrdiff_t m_hFogIndirectTexture = 0x5D0; // 
                constexpr std::ptrdiff_t m_nForceRefreshCount = 0x5D8; // 
                constexpr std::ptrdiff_t m_fNoiseSpeed = 0x5DC; // 
                constexpr std::ptrdiff_t m_fNoiseStrength = 0x5E0; // 
                constexpr std::ptrdiff_t m_vNoiseScale = 0x5E4; // 
                constexpr std::ptrdiff_t m_bFirstTime = 0x5F0; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_bHoldingBall (bool)
            namespace CCitadel_Ability_WreckingBall {
                constexpr std::ptrdiff_t m_bHoldingBall = 0xCB0; // 
            }
            // Parent: CCitadel_Ability_PrimaryWeapon
            // Field count: 0
            namespace CCitadel_Ability_PrimaryWeapon_BeamWeapon {
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ArcaneEaterProcVData {
                constexpr std::ptrdiff_t m_StealWatcherModifier = 0x638; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_SuperNeutralChargePrepare {
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 6
            //
            // Metadata:
            // MGetKV3ClassDefaults
            // MPropertySuppressBaseClassField
            namespace CCitadel_Modifier_BaseBulletPreRollProcVData {
                constexpr std::ptrdiff_t m_bRollOnceForAllBulletsInAShot = 0x638; // 
                constexpr std::ptrdiff_t m_flMaxBulletsToProcInShot = 0x63C; // 
                constexpr std::ptrdiff_t m_bCanProcMultipleTimesFromSameShot = 0x640; // 
                constexpr std::ptrdiff_t m_bRequiresTargetFilter = 0x641; // 
                constexpr std::ptrdiff_t m_TracerAdditionParticle = 0x648; // 
                constexpr std::ptrdiff_t m_OnBulletRolledProcSound = 0x728; // 
            }
            // Parent: C_CitadelProjectile
            // Field count: 0
            namespace C_Citadel_Projectile_WreckingBall {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierTangoTetherTargetVData {
                constexpr std::ptrdiff_t m_GrappleRopeParticle = 0x608; // 
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Tokamak_AllySmokeAOE_VData {
                constexpr std::ptrdiff_t m_AuraParticle = 0x648; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_ActiveReload {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierTier3BossInvulnVData {
                constexpr std::ptrdiff_t m_ShieldParticle = 0x608; // 
                constexpr std::ptrdiff_t m_flShieldRadius = 0x6E8; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 7
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbility_Mirage_Teleport_VData {
                constexpr std::ptrdiff_t m_BuffModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_FireRateModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_TeleportStartParticle = 0x1568; // 
                constexpr std::ptrdiff_t m_TeleportEndParticle = 0x1648; // 
                constexpr std::ptrdiff_t m_strArriveSound = 0x1728; // 
                constexpr std::ptrdiff_t m_strDepartSound = 0x1738; // 
                constexpr std::ptrdiff_t m_strChannelDestinationSound = 0x1748; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CAbility_Rutger_RocketLauncher {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ChargedTacklePrepare {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_QuickSilverBuffVData {
                constexpr std::ptrdiff_t m_RapidFireParticle = 0x608; // 
            }
            // Parent: CScaleFunctionBase
            // Field count: 0
            namespace CScaleFunctionAbilityPropertyBase {
            }
            // Parent: CPlayer_ObserverServices
            // Field count: 10
            //
            // Metadata:
            // NetworkVarNames: m_hOverrideObserverTarget (CHandle<CBaseEntity>)
            // NetworkVarNames: m_iOverrideObserverMode (ObserverMode_t)
            // NetworkVarNames: m_iSecondsAfterDeathToAllowObserving (int32)
            namespace CCitadelPlayer_ObserverServices {
                constexpr std::ptrdiff_t m_nLastLocalPlayerObservedTeam = 0x58; // 
                constexpr std::ptrdiff_t m_nLastObservedTeam = 0x5C; // 
                constexpr std::ptrdiff_t m_nCurrentObservedTeam = 0x60; // 
                constexpr std::ptrdiff_t m_hLastObserverTarget = 0x64; // 
                constexpr std::ptrdiff_t m_hPreviousTeamTarget = 0x68; // 
                constexpr std::ptrdiff_t m_hOverrideObserverTarget = 0x6C; // 
                constexpr std::ptrdiff_t m_iOverrideObserverMode = 0x70; // 
                constexpr std::ptrdiff_t m_iSecondsAfterDeathToAllowObserving = 0x74; // 
                constexpr std::ptrdiff_t m_angTargetCamera = 0x78; // 
                constexpr std::ptrdiff_t m_vTargetCameraPos = 0x90; // 
            }
            // Parent: CBaseAnimGraph
            // Field count: 13
            //
            // Metadata:
            // NetworkVarNames: m_bActive (bool)
            // NetworkVarNames: m_flStartTime (GameTime_t)
            // NetworkVarNames: m_flStartTimeInCommentary (float32)
            // NetworkVarNames: m_iszCommentaryFile (string_t)
            // NetworkVarNames: m_iszTitle (string_t)
            // NetworkVarNames: m_iszSpeakers (string_t)
            // NetworkVarNames: m_iNodeNumber (int)
            // NetworkVarNames: m_iNodeNumberMax (int)
            // NetworkVarNames: m_bListenedTo (bool)
            // NetworkVarNames: m_hViewPosition (CHandle<C_BaseEntity>)
            namespace C_PointCommentaryNode {
                constexpr std::ptrdiff_t m_bActive = 0xB58; // 
                constexpr std::ptrdiff_t m_bWasActive = 0xB59; // 
                constexpr std::ptrdiff_t m_flEndTime = 0xB5C; // 
                constexpr std::ptrdiff_t m_flStartTime = 0xB60; // 
                constexpr std::ptrdiff_t m_flStartTimeInCommentary = 0xB64; // 
                constexpr std::ptrdiff_t m_iszCommentaryFile = 0xB68; // 
                constexpr std::ptrdiff_t m_iszTitle = 0xB70; // 
                constexpr std::ptrdiff_t m_iszSpeakers = 0xB78; // 
                constexpr std::ptrdiff_t m_iNodeNumber = 0xB80; // 
                constexpr std::ptrdiff_t m_iNodeNumberMax = 0xB84; // 
                constexpr std::ptrdiff_t m_bListenedTo = 0xB88; // 
                constexpr std::ptrdiff_t m_hViewPosition = 0xB98; // 
                constexpr std::ptrdiff_t m_bRestartAfterRestore = 0xB9C; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Cadence_AnthemBuff {
            }
            // Parent: CCitadelModifier
            // Field count: 8
            namespace CCitadel_Modifier_StormCloud {
                constexpr std::ptrdiff_t m_flNextRandomLightningStrike = 0xC0; // 
                constexpr std::ptrdiff_t m_flStartTime = 0xC4; // 
                constexpr std::ptrdiff_t m_flRadiusIncrementPerSecond = 0xC8; // 
                constexpr std::ptrdiff_t m_vCastPosition = 0xCC; // 
                constexpr std::ptrdiff_t m_bFiredEndingSoonSound = 0xD8; // 
                constexpr std::ptrdiff_t m_nLastTickForLightningCenterCalc = 0xDC; // 
                constexpr std::ptrdiff_t m_vecLightningCenter = 0xE0; // 
                constexpr std::ptrdiff_t m_nSatVolumeIndex = 0xEC; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_LightningBallVData {
                constexpr std::ptrdiff_t m_ZapParticle = 0x608; // 
                constexpr std::ptrdiff_t m_TargetScreenParticleEffect = 0x6E8; // 
            }
            // Parent: CCitadel_Modifier_Burning
            // Field count: 0
            namespace CCitadel_Modifier_Afterburn_DOT {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_IncendiaryProjectile {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Disarmed {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Thumper_2 {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_GangActivity_AbilitySwap {
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_UltCombo_Self {
                constexpr std::ptrdiff_t m_angles = 0xC0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_PoisonBullet_PoisonBuildup {
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Upgrade_ArcaneMedallion_VData {
                constexpr std::ptrdiff_t m_TriggeredModifier = 0x638; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 12
            //
            // Metadata:
            // NetworkVarNames: m_flDashAngle (float)
            // NetworkVarNames: m_nLastGroundDashTick (int)
            // NetworkVarNames: m_flGroundDashCastTime (GameTime_t)
            // NetworkVarNames: m_flGroundDashEndTime (CCitadelAutoScaledTime)
            // NetworkVarNames: m_flAirDashCastTime (GameTime_t)
            // NetworkVarNames: m_flAirDashDragStartTime (GameTime_t)
            // NetworkVarNames: m_nConsecutiveAirDashes (int8)
            // NetworkVarNames: m_nConsecutiveDownDashes (int8)
            // NetworkVarNames: m_bDownAirDash (bool)
            namespace CCitadel_Ability_Dash {
                constexpr std::ptrdiff_t m_flDashAngle = 0xC78; // 
                constexpr std::ptrdiff_t m_GroundDashExecuteTime = 0xC7C; // 
                constexpr std::ptrdiff_t m_nLastGroundDashTick = 0xC80; // 
                constexpr std::ptrdiff_t m_flGroundDashCastTime = 0xC84; // 
                constexpr std::ptrdiff_t m_bTagCanActivateGroundDash = 0xC88; // 
                constexpr std::ptrdiff_t m_flGroundDashEndTime = 0xC90; // 
                constexpr std::ptrdiff_t m_flAirDashCastTime = 0xCA8; // 
                constexpr std::ptrdiff_t m_flAirDashDragStartTime = 0xCAC; // 
                constexpr std::ptrdiff_t m_nConsecutiveAirDashes = 0xCB0; // 
                constexpr std::ptrdiff_t m_nConsecutiveDownDashes = 0xCB1; // 
                constexpr std::ptrdiff_t m_bDownAirDash = 0xCB2; // 
                constexpr std::ptrdiff_t m_hJumpAbility = 0xE68; // CHandle<CCitadel_Ability_Jump>
            }
            // Parent: CCitadel_Modifier_Bullet_Shield
            // Field count: 0
            namespace CCitadel_Modifier_Tech_Shield {
            }
            // Parent: CEntitySubclassVDataBase
            // Field count: 22
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAI_BaseNPCVData {
                constexpr std::ptrdiff_t m_sModelName = 0x28; // 
                constexpr std::ptrdiff_t m_hFootstepSounds = 0x108; // 
                constexpr std::ptrdiff_t m_vecNavLinkMovementNames = 0x110; // 
                constexpr std::ptrdiff_t m_nMaxHealth = 0x128; // 
                constexpr std::ptrdiff_t m_vecIntrinsicModifiers = 0x130; // 
                constexpr std::ptrdiff_t m_statusEffectMap = 0x148; // 
                constexpr std::ptrdiff_t m_vecAttachments = 0x150; // CUtlVector<NPCAttachmentDesc_t>
                constexpr std::ptrdiff_t m_flHeadDamageMultiplier = 0x168; // 
                constexpr std::ptrdiff_t m_flChestDamageMultiplier = 0x178; // 
                constexpr std::ptrdiff_t m_flStomachDamageMultiplier = 0x188; // 
                constexpr std::ptrdiff_t m_flArmDamageMultiplier = 0x198; // 
                constexpr std::ptrdiff_t m_flLegDamageMultiplier = 0x1A8; // 
                constexpr std::ptrdiff_t m_nMaxAdditionalAmmoBalancingShots = 0x1B8; // 
                constexpr std::ptrdiff_t m_bTakesDamage = 0x1C8; // 
                constexpr std::ptrdiff_t m_DestructiblePartsDataByHitGroup = 0x1D0; // CUtlOrderedMap<HitGroup_t,CAI_BaseNPC_DestructiblePartHitGroupInfoAndData>
                constexpr std::ptrdiff_t m_bAllowNonZUpMovement = 0x1F8; // 
                constexpr std::ptrdiff_t m_bRequestCapsuleCollision = 0x1F9; // 
                constexpr std::ptrdiff_t m_flCapsuleRadiusOverride = 0x1FC; // 
                constexpr std::ptrdiff_t m_flCapsuleHeightOverride = 0x200; // 
                constexpr std::ptrdiff_t m_bAllowAnimgraphMotorMovementStates = 0x204; // 
                constexpr std::ptrdiff_t m_vecActionDesiredShared = 0x208; // 
                constexpr std::ptrdiff_t m_sPlayerKilledNpcSound = 0x220; // 
            }
            // Parent: None
            // Field count: 5
            //
            // Metadata:
            // NetworkVarNames: localSound (Vector)
            // NetworkVarNames: soundscapeIndex (int32)
            // NetworkVarNames: localBits (uint8)
            // NetworkVarNames: soundscapeEntityListIndex (int)
            // NetworkVarNames: soundEventHash (uint32)
            namespace audioparams_t {
                constexpr std::ptrdiff_t localSound = 0x8; // 
                constexpr std::ptrdiff_t soundscapeIndex = 0x68; // 
                constexpr std::ptrdiff_t localBits = 0x6C; // 
                constexpr std::ptrdiff_t soundscapeEntityListIndex = 0x70; // 
                constexpr std::ptrdiff_t soundEventHash = 0x74; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_BaseProjectileAOEModifier {
            }
            // Parent: CCitadelBaseYamatoAbility
            // Field count: 0
            namespace CCitadel_Ability_HealingSlash {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_DebugIsVisibleToEnemyTeam {
            }
            // Parent: C_AI_CitadelNPC
            // Field count: 0
            namespace C_NPC_MortarSentry {
            }
            // Parent: C_AI_CitadelNPC
            // Field count: 0
            //
            // Metadata:
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            namespace C_NPC_FlyingDrone {
            }
            // Parent: CCitadel_Item
            // Field count: 1
            namespace CCitadel_Item_DivinersKevlar {
                constexpr std::ptrdiff_t m_bExecuted = 0xC90; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_Synth_Pulse_Escape {
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbility_Rutger_RocketLauncher_VData {
                constexpr std::ptrdiff_t m_ImpactParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_ShootParticle = 0x1628; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Radiance {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_TeleportToGangster {
            }
            // Parent: CCitadel_Ability_PrimaryWeapon
            // Field count: 0
            namespace CCitadel_Ability_ShivWeapon {
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_PsychicDaggerVData {
                constexpr std::ptrdiff_t m_MakeDaggersModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 5
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierPowerJumpVData {
                constexpr std::ptrdiff_t m_FloatParticle = 0x608; // 
                constexpr std::ptrdiff_t m_flAirDrag = 0x6E8; // 
                constexpr std::ptrdiff_t m_flVerticalCameraOffset = 0x6EC; // 
                constexpr std::ptrdiff_t m_flVerticalCameraOffsetLerpTime = 0x6F0; // 
                constexpr std::ptrdiff_t m_flVerticalCameraOffsetBias = 0x6F4; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 4
            //
            // Metadata:
            // NetworkVarNames: m_anglesCharging (QAngle)
            // NetworkVarNames: m_flChargeStartTime (GameTime_t)
            // NetworkVarNames: m_flFastChargeEndTime (GameTime_t)
            // NetworkVarNames: m_bHitAPlayer (bool)
            namespace CCitadel_Ability_Bull_Charge {
                constexpr std::ptrdiff_t m_anglesCharging = 0xEE0; // 
                constexpr std::ptrdiff_t m_flChargeStartTime = 0xEEC; // 
                constexpr std::ptrdiff_t m_flFastChargeEndTime = 0xEF0; // 
                constexpr std::ptrdiff_t m_bHitAPlayer = 0xEF4; // 
            }
            // Parent: CCitadel_Ability_PrimaryWeapon
            // Field count: 0
            namespace CCitadel_Ability_PrimaryWeapon_Empty {
            }
            // Parent: CitadelAbilityVData
            // Field count: 56
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilitySlideVData {
                constexpr std::ptrdiff_t m_flMinAngleToConsiderASlope = 0x1548; // 
                constexpr std::ptrdiff_t m_flSlideMaxSlopeMaxAccSpeed = 0x154C; // 
                constexpr std::ptrdiff_t m_flSlideMinSlopeMaxAccSpeed = 0x1550; // 
                constexpr std::ptrdiff_t m_flButtonPressWindow = 0x1554; // 
                constexpr std::ptrdiff_t m_flTurnSpeed = 0x1558; // 
                constexpr std::ptrdiff_t m_flSlideMinSlopeAcceleration = 0x155C; // 
                constexpr std::ptrdiff_t m_flSlideMaxSlopeAcceleration = 0x1560; // 
                constexpr std::ptrdiff_t m_flTurnMinAngDiff = 0x1564; // 
                constexpr std::ptrdiff_t m_flTurnMaxAngDiff = 0x1568; // 
                constexpr std::ptrdiff_t m_flLandedFlatGroundFrictionGraceTime = 0x156C; // 
                constexpr std::ptrdiff_t m_flFlatGroundFrictionGraceTime = 0x1570; // 
                constexpr std::ptrdiff_t m_flFrictionFlatGroundGrace = 0x1574; // 
                constexpr std::ptrdiff_t m_flFrictionFlatGround = 0x1578; // 
                constexpr std::ptrdiff_t m_flFrictionMinSlope = 0x157C; // 
                constexpr std::ptrdiff_t m_flFrictionMaxSlope = 0x1580; // 
                constexpr std::ptrdiff_t m_flFrictionUphillMinSlope = 0x1584; // 
                constexpr std::ptrdiff_t m_flFrictionUphillMaxSlope = 0x1588; // 
                constexpr std::ptrdiff_t m_flLandingSlopeScaleBias = 0x158C; // 
                constexpr std::ptrdiff_t m_flBoostMinTriggerSpeed = 0x1590; // 
                constexpr std::ptrdiff_t m_flBoostMaxTriggerSpeed = 0x1594; // 
                constexpr std::ptrdiff_t m_flBoostMinSpeed = 0x1598; // 
                constexpr std::ptrdiff_t m_flBoostMaxSpeed = 0x159C; // 
                constexpr std::ptrdiff_t m_flMinActivationSpeed = 0x15A0; // 
                constexpr std::ptrdiff_t m_flMinSustainSpeed = 0x15A4; // 
                constexpr std::ptrdiff_t m_flSprintBoostSpeed = 0x15A8; // 
                constexpr std::ptrdiff_t m_flDashSlideStartTime = 0x15AC; // 
                constexpr std::ptrdiff_t m_flDashSlideSpeed = 0x15B0; // 
                constexpr std::ptrdiff_t m_flDashSlideFailSpeed = 0x15B4; // 
                constexpr std::ptrdiff_t m_strDashSlideActivate = 0x15B8; // 
                constexpr std::ptrdiff_t m_flDashSlideFrictionTime = 0x15C8; // 
                constexpr std::ptrdiff_t m_flDashSlideFriction = 0x15CC; // 
                constexpr std::ptrdiff_t m_flDashMinActivationSpeed = 0x15D0; // 
                constexpr std::ptrdiff_t m_flAccMinSlopeDeg = 0x15D4; // 
                constexpr std::ptrdiff_t m_flAccMaxSlopeDeg = 0x15D8; // 
                constexpr std::ptrdiff_t m_flAccMinSlopeScale = 0x15DC; // 
                constexpr std::ptrdiff_t m_flSlideProbeForwardOffset = 0x15E0; // 
                constexpr std::ptrdiff_t m_flSlideActivationProbeForwardOffset = 0x15E4; // 
                constexpr std::ptrdiff_t m_flMaxDistanceBetweenProbeSamples = 0x15E8; // 
                constexpr std::ptrdiff_t m_flInitialSlideUseForwardProbeTime = 0x15EC; // 
                constexpr std::ptrdiff_t m_flCurrentSlopeSampleDistance = 0x15F0; // 
                constexpr std::ptrdiff_t m_flSampleVelDiffStdDevScaleCutoff = 0x15F4; // 
                constexpr std::ptrdiff_t m_flSlopeFacingAngleToActivate = 0x15F8; // 
                constexpr std::ptrdiff_t m_flAirDragAfterJump = 0x15FC; // 
                constexpr std::ptrdiff_t m_flAirDragAfterJumpTime = 0x1600; // 
                constexpr std::ptrdiff_t m_flAirDragMaxAngle = 0x1604; // 
                constexpr std::ptrdiff_t m_flAirDragResetTime = 0x1608; // 
                constexpr std::ptrdiff_t m_flLateSlideJumpWindow = 0x160C; // 
                constexpr std::ptrdiff_t m_SlideEffectRemap = 0x1610; // 
                constexpr std::ptrdiff_t m_GetupSpeedCurve = 0x1620; // 
                constexpr std::ptrdiff_t m_flGetupBusyDuration = 0x1660; // 
                constexpr std::ptrdiff_t m_cameraSequenceStartSliding = 0x1668; // CitadelCameraOperationsSequence_t
                constexpr std::ptrdiff_t m_cameraSequenceEndSliding = 0x16F0; // CitadelCameraOperationsSequence_t
                constexpr std::ptrdiff_t m_SlideParticle = 0x1778; // 
                constexpr std::ptrdiff_t m_strStartSound = 0x1858; // 
                constexpr std::ptrdiff_t m_strLoopingSound = 0x1868; // 
                constexpr std::ptrdiff_t m_strStopSound = 0x1878; // 
            }
            // Parent: C_BaseEntity
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_nMode (int)
            // NetworkVarNames: m_vBoxSize (Vector)
            // NetworkVarNames: m_bEnabled (bool)
            namespace C_InfoVisibilityBox {
                constexpr std::ptrdiff_t m_nMode = 0x55C; // 
                constexpr std::ptrdiff_t m_vBoxSize = 0x560; // 
                constexpr std::ptrdiff_t m_bEnabled = 0x56C; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Targetdummy_4 {
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityTargetPracticeVData {
                constexpr std::ptrdiff_t m_TargetPracticeSelfModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_TargetPracticeEnemyModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Afterburn {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_MetalSkin {
            }
            // Parent: CCitadel_Ability_TrooperGrenade
            // Field count: 0
            namespace CCitadel_Ability_TrooperBossGrenade {
            }
            // Parent: None
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_hStableHandle (uint64)
            namespace CModifierHandleBase {
                constexpr std::ptrdiff_t m_hStableHandle = 0x8; // 
            }
            // Parent: C_AI_BaseNPC
            // Field count: 7
            //
            // Metadata:
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByUserGroup
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkOverride
            // NetworkVarNames: m_bBeamActive (bool)
            // NetworkVarNames: m_vecWeakPoints (WeakPoint_t)
            // NetworkVarNames: m_bMinion (bool)
            // NetworkVarNames: m_hLookTarget (EHANDLE)
            // NetworkVarNames: m_CCitadelAbilityComponent (CCitadelAbilityComponent::Storage_t)
            namespace C_AI_CitadelNPC {
                constexpr std::ptrdiff_t m_bBeamActive = 0xD94; // 
                constexpr std::ptrdiff_t m_vEyeBeamTarget = 0xD98; // 
                constexpr std::ptrdiff_t m_nPlayerTeamEvent = 0x1258; // 
                constexpr std::ptrdiff_t m_vecWeakPoints = 0x12A8; // C_UtlVectorEmbeddedNetworkVar<WeakPoint_t>
                constexpr std::ptrdiff_t m_bMinion = 0x12F8; // 
                constexpr std::ptrdiff_t m_hLookTarget = 0x12FC; // 
                constexpr std::ptrdiff_t m_CCitadelAbilityComponent = 0x1300; // 
            }
            // Parent: C_Sprite
            // Field count: 2
            namespace C_FireSprite {
                constexpr std::ptrdiff_t m_vecMoveDir = 0x940; // 
                constexpr std::ptrdiff_t m_bFadeFromAbove = 0x94C; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Killing_Blow_Glow {
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Nano_ShadowVData {
                constexpr std::ptrdiff_t m_ShadowModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_PurgeModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelAbilityVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_FissureWallVData {
                constexpr std::ptrdiff_t m_FriendlyWallParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_EnemyWallParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_WallTravelSoundLoop = 0x1708; // 
                constexpr std::ptrdiff_t m_WallModifier = 0x1718; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Upgrade_WeaponPowerForHealthVData {
                constexpr std::ptrdiff_t m_BuffModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_HollowPoint_ProcVData {
                constexpr std::ptrdiff_t m_TracerParticle = 0x608; // 
                constexpr std::ptrdiff_t m_ParticleModifier = 0x6E8; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_DamageOnHitGround {
            }
            // Parent: None
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_SourceItemID (AbilityID_t)
            // NetworkVarNames: m_TargetAbilityID (AbilityID_t)
            namespace ItemImbuementPair_t {
                constexpr std::ptrdiff_t m_SourceItemID = 0x30; // 
                constexpr std::ptrdiff_t m_TargetAbilityID = 0x34; // 
            }
            // Parent: CCitadel_Item
            // Field count: 1
            namespace CCitadel_Upgrade_AmmoScavenger {
                constexpr std::ptrdiff_t m_hLastOrbTarget = 0xC90; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityTeleportToGangsterVData {
            }
            // Parent: CCitadelBaseAbilityServerOnly
            // Field count: 0
            namespace CCitadel_Ability_MedicHeal {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Intrinsic_Base {
            }
            // Parent: C_BaseTrigger
            // Field count: 8
            namespace C_Precipitation {
                constexpr std::ptrdiff_t m_flDensity = 0x838; // 
                constexpr std::ptrdiff_t m_flParticleInnerDist = 0x848; // 
                constexpr std::ptrdiff_t m_pParticleDef = 0x850; // 
                constexpr std::ptrdiff_t m_tParticlePrecipTraceTimer = 0x878; // 
                constexpr std::ptrdiff_t m_bActiveParticlePrecipEmitter = 0x880; // 
                constexpr std::ptrdiff_t m_bParticlePrecipInitialized = 0x881; // 
                constexpr std::ptrdiff_t m_bHasSimulatedSinceLastSceneObjectUpdate = 0x882; // 
                constexpr std::ptrdiff_t m_nAvailableSheetSequencesMaxIndex = 0x884; // 
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_ArmorUpgrade_RegeneratingBulletShieldVData {
                constexpr std::ptrdiff_t m_ActiveModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_QuickSilverVData {
                constexpr std::ptrdiff_t m_BuffModifier = 0x638; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ProcParticle = 0x648; // 
            }
            // Parent: CEntitySubclassVDataBase
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CNPC_SimpleAnimatingAIVData {
                constexpr std::ptrdiff_t m_sModelName = 0x28; // 
            }
            // Parent: C_CitadelProjectile
            // Field count: 0
            namespace C_TrackedProjectile_Synth_PlasmaFlux {
            }
            // Parent: CBaseDashCastAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityCadenceSilenceContraptionsVData {
                constexpr std::ptrdiff_t m_SilenceContraptionsModifier = 0x15D0; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CEntitySubclassVDataBase
            // Field count: 7
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CPrecipitationVData {
                constexpr std::ptrdiff_t m_szParticlePrecipitationEffect = 0x28; // 
                constexpr std::ptrdiff_t m_flInnerDistance = 0x108; // 
                constexpr std::ptrdiff_t m_nAttachType = 0x10C; // 
                constexpr std::ptrdiff_t m_bBatchSameVolumeType = 0x110; // 
                constexpr std::ptrdiff_t m_nRTEnvCP = 0x114; // 
                constexpr std::ptrdiff_t m_nRTEnvCPComponent = 0x118; // 
                constexpr std::ptrdiff_t m_szModifier = 0x120; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 2
            namespace CCitadel_Ability_Tengu_Urn {
                constexpr std::ptrdiff_t m_vLaunchPosition = 0xC78; // 
                constexpr std::ptrdiff_t m_qLaunchAngle = 0xC84; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Killing_Blow_GlowVData {
                constexpr std::ptrdiff_t m_ShivOnlyDeathStatus = 0x608; // 
                constexpr std::ptrdiff_t m_ShivOnlyDeathTrail = 0x6E8; // 
                constexpr std::ptrdiff_t m_strShivOnlyActivateSound = 0x7C8; // 
                constexpr std::ptrdiff_t m_strShivOnlyLoopSound = 0x7D8; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Astro_Rifle {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Decoy_Tracker {
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_ArmorUpgrade_ActiveBulletShieldVData {
                constexpr std::ptrdiff_t m_TempShieldModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_FullSpectrumVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x638; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BonusDamageModifier = 0x648; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_Intrinsic_Base
            // Field count: 0
            namespace CCitadel_Modifier_OneVsOne {
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_ControlPointCapturerAura {
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_AccuracyTracker {
                constexpr std::ptrdiff_t m_flProgress = 0xC0; // 
            }
            // Parent: CCitadel_Modifier_InvisVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Slork_Invis_VData {
                constexpr std::ptrdiff_t m_AmbushModifier = 0x8C0; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_VisibleModifier = 0x8D0; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_GenericPerson_1 {
            }
            // Parent: CitadelAbilityVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityGenericPerson1VData {
            }
            // Parent: CCitadelModifier
            // Field count: 4
            namespace CCitadel_Modifier_PerchedPredatorDrag {
                constexpr std::ptrdiff_t m_qRelativeOffset = 0x130; // 
                constexpr std::ptrdiff_t m_flRelativeDist = 0x13C; // 
                constexpr std::ptrdiff_t m_vecOffsetDir = 0x140; // 
                constexpr std::ptrdiff_t m_hFollowEnt = 0x14C; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 5
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityPsychicPulseVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1548; // 
                constexpr std::ptrdiff_t m_PulseParticle = 0x1558; // 
                constexpr std::ptrdiff_t m_flCastEffectLifetime = 0x1638; // 
                constexpr std::ptrdiff_t m_flConeAngle = 0x163C; // 
                constexpr std::ptrdiff_t m_flConeHalfWidth = 0x1640; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Hornet_Chain_Connection {
                constexpr std::ptrdiff_t m_vecOrigin = 0xC0; // 
            }
            // Parent: CitadelItemVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Item_Savior_VData {
                constexpr std::ptrdiff_t m_SaviorModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_CastParticle = 0x15A0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 3
            namespace CCitadel_Modifier_BulletFlurry {
                constexpr std::ptrdiff_t m_nEffectId = 0x130; // 
                constexpr std::ptrdiff_t m_flNextSequenceChange = 0x134; // 
                constexpr std::ptrdiff_t m_nCurrentPose = 0x138; // 
            }
            // Parent: CCitadel_Modifier_BaseBulletPreRollProcVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_MedicBulletsVData {
                constexpr std::ptrdiff_t m_ImpactParticle = 0x738; // 
            }
            // Parent: None
            // Field count: 6
            namespace CBuoyancyHelper {
                constexpr std::ptrdiff_t m_nFluidType = 0x18; // 
                constexpr std::ptrdiff_t m_flFluidDensity = 0x1C; // 
                constexpr std::ptrdiff_t m_vecFractionOfWheelSubmergedForWheelFriction = 0x20; // 
                constexpr std::ptrdiff_t m_vecWheelFrictionScales = 0x38; // 
                constexpr std::ptrdiff_t m_vecFractionOfWheelSubmergedForWheelDrag = 0x50; // 
                constexpr std::ptrdiff_t m_vecWheelDrag = 0x68; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_Aura_Base {
            }
            // Parent: C_BaseModelEntity
            // Field count: 4
            //
            // Metadata:
            // NetworkVarNames: m_bEnabled (bool)
            // NetworkVarNames: m_DialogXMLName (string_t)
            // NetworkVarNames: m_PanelClassName (string_t)
            // NetworkVarNames: m_PanelID (string_t)
            namespace C_BaseClientUIEntity {
                constexpr std::ptrdiff_t m_bEnabled = 0x838; // 
                constexpr std::ptrdiff_t m_DialogXMLName = 0x840; // 
                constexpr std::ptrdiff_t m_PanelClassName = 0x848; // 
                constexpr std::ptrdiff_t m_PanelID = 0x850; // 
            }
            // Parent: C_BaseModelEntity
            // Field count: 3
            namespace C_FuncTrackTrain {
                constexpr std::ptrdiff_t m_nLongAxis = 0x830; // 
                constexpr std::ptrdiff_t m_flRadius = 0x834; // 
                constexpr std::ptrdiff_t m_flLineLength = 0x838; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Mirage_SandPhantom_Proc {
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilitySleepBombVData {
                constexpr std::ptrdiff_t m_ExplosionParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_AuraModifier = 0x1628; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_RocketLauncher {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_HighAlert {
            }
            // Parent: CCitadelModifierVData
            // Field count: 8
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Bebop_LaserBeamVData {
                constexpr std::ptrdiff_t m_SlowModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BeamParticle = 0x618; // 
                constexpr std::ptrdiff_t m_BeamParticleLocal = 0x6F8; // 
                constexpr std::ptrdiff_t m_BeamHitParticle = 0x7D8; // 
                constexpr std::ptrdiff_t m_strLaserStartSound = 0x8B8; // 
                constexpr std::ptrdiff_t m_strLaserEndSound = 0x8C8; // 
                constexpr std::ptrdiff_t m_strLaserLoopSound = 0x8D8; // 
                constexpr std::ptrdiff_t m_strLaserHitSound = 0x8E8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Wraith_RapidFire {
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Bull_Heal_Target {
                constexpr std::ptrdiff_t m_flTetherRangeSquared = 0x1D8; // 
            }
            // Parent: CPlayer_CameraServices
            // Field count: 1
            namespace CCitadelPlayer_CameraServices {
                constexpr std::ptrdiff_t m_hPrevPostProcessingVolume = 0x230; // CHandle<C_PostProcessingVolume>
            }
            // Parent: C_AI_CitadelNPC
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_iLane (int)
            // NetworkVarNames: m_hTargetedEnemy (EHANDLE)
            // NetworkVarNames: m_flHealingChargeParticlePct (float)
            namespace C_NPC_Trooper {
                constexpr std::ptrdiff_t m_iLane = 0x14A0; // 
                constexpr std::ptrdiff_t m_hTargetedEnemy = 0x14A4; // 
                constexpr std::ptrdiff_t m_flHealingChargeParticlePct = 0x14A8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_WreckerSalvageBuffVData {
                constexpr std::ptrdiff_t m_WeaponBuffParticle = 0x608; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Astro_ShotgunBuff {
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityAstroRifleVData {
                constexpr std::ptrdiff_t m_SelfModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_SlowModifier = 0x1568; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 5
            //
            // Metadata:
            // NetworkVarNames: m_vStrikeVel (Vector)
            // NetworkVarNames: m_flStartHeight (float)
            namespace CCitadel_Ability_LashDownStrike {
                constexpr std::ptrdiff_t m_ImpactTime = 0xD20; // 
                constexpr std::ptrdiff_t m_vDamagePos = 0xD24; // 
                constexpr std::ptrdiff_t m_PreviewEffect = 0xD34; // 
                constexpr std::ptrdiff_t m_vStrikeVel = 0xEF8; // 
                constexpr std::ptrdiff_t m_flStartHeight = 0xF04; // 
            }
            // Parent: CCitadel_Modifier_StunnedVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierPsychicLiftVData {
                constexpr std::ptrdiff_t m_LiftParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_strStartSound = 0x7C8; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 5
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityMeleeVData {
                constexpr std::ptrdiff_t m_flMeleeInputBufferTime = 0x1548; // 
                constexpr std::ptrdiff_t m_flCollisionDistance = 0x154C; // 
                constexpr std::ptrdiff_t m_flHeavyAttackRequiredHoldTime = 0x1550; // 
                constexpr std::ptrdiff_t m_flLightAttackMaxHoldTime = 0x1554; // 
                constexpr std::ptrdiff_t m_MeleeDamageFlags = 0x1558; // 
            }
            // Parent: None
            // Field count: 13
            //
            // Metadata:
            // NetworkVarNames: m_nModelID (int32)
            // NetworkVarNames: m_hMaterialBase (HMaterialStrong)
            // NetworkVarNames: m_hMaterialDamageOverlay (HMaterialStrong)
            // NetworkVarNames: m_solid (ShardSolid_t)
            // NetworkVarNames: m_vecPanelSize (Vector2D)
            // NetworkVarNames: m_vecStressPositionA (Vector2D)
            // NetworkVarNames: m_vecStressPositionB (Vector2D)
            // NetworkVarNames: m_vecPanelVertices (Vector2D)
            // NetworkVarNames: m_vInitialPanelVertices (Vector4D)
            // NetworkVarNames: m_flGlassHalfThickness (float)
            // NetworkVarNames: m_bHasParent (bool)
            // NetworkVarNames: m_bParentFrozen (bool)
            // NetworkVarNames: m_SurfacePropStringToken (CUtlStringToken)
            namespace shard_model_desc_t {
                constexpr std::ptrdiff_t m_nModelID = 0x8; // 
                constexpr std::ptrdiff_t m_hMaterialBase = 0x10; // CStrongHandle<InfoForResourceTypeIMaterial2>
                constexpr std::ptrdiff_t m_hMaterialDamageOverlay = 0x18; // CStrongHandle<InfoForResourceTypeIMaterial2>
                constexpr std::ptrdiff_t m_solid = 0x20; // 
                constexpr std::ptrdiff_t m_vecPanelSize = 0x24; // 
                constexpr std::ptrdiff_t m_vecStressPositionA = 0x2C; // 
                constexpr std::ptrdiff_t m_vecStressPositionB = 0x34; // 
                constexpr std::ptrdiff_t m_vecPanelVertices = 0x40; // C_NetworkUtlVectorBase<Vector2D>
                constexpr std::ptrdiff_t m_vInitialPanelVertices = 0x58; // C_NetworkUtlVectorBase<Vector4D>
                constexpr std::ptrdiff_t m_flGlassHalfThickness = 0x70; // 
                constexpr std::ptrdiff_t m_bHasParent = 0x74; // 
                constexpr std::ptrdiff_t m_bParentFrozen = 0x75; // 
                constexpr std::ptrdiff_t m_SurfacePropStringToken = 0x78; // 
            }
            // Parent: None
            // Field count: 1
            namespace C_SceneEntity__QueuedEvents_t {
                constexpr std::ptrdiff_t starttime = 0x0; // 
            }
            // Parent: CCitadelAnimatingModelEntity
            // Field count: 6
            //
            // Metadata:
            // NetworkVarNames: m_eLootType (int32)
            // NetworkVarNames: m_nCurrencyValue (int32)
            // NetworkVarNames: m_iszModelName (string_t)
            // NetworkVarNames: m_flModelScale (float)
            // NetworkVarNames: m_hTargetPlayer (EHANDLE)
            // NetworkVarNames: m_flFallRate (float)
            namespace C_CitadelItemPickup {
                constexpr std::ptrdiff_t m_eLootType = 0xB60; // 
                constexpr std::ptrdiff_t m_nCurrencyValue = 0xB64; // 
                constexpr std::ptrdiff_t m_iszModelName = 0xB68; // 
                constexpr std::ptrdiff_t m_flModelScale = 0xB70; // 
                constexpr std::ptrdiff_t m_hTargetPlayer = 0xB74; // 
                constexpr std::ptrdiff_t m_flFallRate = 0xB78; // 
            }
            // Parent: CBaseAnimGraph
            // Field count: 4
            namespace CBaseProp {
                constexpr std::ptrdiff_t m_bModelOverrodeBlockLOS = 0xB50; // 
                constexpr std::ptrdiff_t m_iShapeType = 0xB54; // 
                constexpr std::ptrdiff_t m_bConformToCollisionBounds = 0xB58; // 
                constexpr std::ptrdiff_t m_mPreferredCatchTransform = 0xB5C; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_BreakablePropSpeedPickup {
            }
            // Parent: CCitadel_Modifier_Intrinsic_Base
            // Field count: 2
            namespace CCitadel_Modifier_ThrowSandProjectile {
                constexpr std::ptrdiff_t m_vInitialCastPosition = 0x130; // 
                constexpr std::ptrdiff_t m_iParticleEffect = 0x13C; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_PuddleVData {
                constexpr std::ptrdiff_t m_puddleAoeDamageFx = 0x608; // 
                constexpr std::ptrdiff_t m_TargetDamageFx = 0x6E8; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityHornetStingVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_HitParticle = 0x1558; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 10
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierStormCloudVData {
                constexpr std::ptrdiff_t m_ZapFriendly = 0x608; // 
                constexpr std::ptrdiff_t m_DrawFriendly = 0x6E8; // 
                constexpr std::ptrdiff_t m_AoEFriendly = 0x7C8; // 
                constexpr std::ptrdiff_t m_ZapEnemy = 0x8A8; // 
                constexpr std::ptrdiff_t m_DrawEnemy = 0x988; // 
                constexpr std::ptrdiff_t m_AoEEnemy = 0xA68; // 
                constexpr std::ptrdiff_t m_strChannelEndingSoonSound = 0xB48; // 
                constexpr std::ptrdiff_t m_strChannelFinishedSound = 0xB58; // 
                constexpr std::ptrdiff_t m_strDamageRecievedSound = 0xB68; // 
                constexpr std::ptrdiff_t m_strAmbientZapSound = 0xB78; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_MidBossAggroEnemy {
            }
            // Parent: None
            // Field count: 21
            namespace CBaseModifier {
                constexpr std::ptrdiff_t m_nSerialNumber = 0x28; // 
                constexpr std::ptrdiff_t m_flLastAppliedTime = 0x2C; // 
                constexpr std::ptrdiff_t m_flCreationTime = 0x30; // 
                constexpr std::ptrdiff_t m_flDuration = 0x34; // 
                constexpr std::ptrdiff_t m_hCaster = 0x38; // 
                constexpr std::ptrdiff_t m_hAbility = 0x3C; // 
                constexpr std::ptrdiff_t m_hAuraProvider = 0x40; // 
                constexpr std::ptrdiff_t m_nAbilitySubclassID = 0x58; // 
                constexpr std::ptrdiff_t m_iAttributes = 0x5C; // 
                constexpr std::ptrdiff_t m_iTeam = 0x5D; // 
                constexpr std::ptrdiff_t m_iStackCount = 0x5E; // 
                constexpr std::ptrdiff_t m_iMaxStackCount = 0x60; // 
                constexpr std::ptrdiff_t m_pVecStackDecayTimes = 0x68; // 
                constexpr std::ptrdiff_t m_eDestroyReason = 0x70; // 
                constexpr std::ptrdiff_t m_bDisabled = 0x71; // 
                constexpr std::ptrdiff_t m_bSuppressSendModifier = 0x72; // 
                constexpr std::ptrdiff_t m_flThinkInterval = 0x74; // 
                constexpr std::ptrdiff_t m_flThinkIntervalStartTime = 0x78; // 
                constexpr std::ptrdiff_t m_flTimeScale = 0x7C; // 
                constexpr std::ptrdiff_t m_pVecTrackedObjects = 0x80; // 
                constexpr std::ptrdiff_t m_hModifierListHandle = 0x88; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Guiding_Arrow {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_QuickSilver_Buff {
            }
            // Parent: C_BaseModelEntity
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_timeLaunch (GameTime_t)
            namespace CItemXP {
                constexpr std::ptrdiff_t m_timeLaunch = 0x850; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Synth_Grasp_Victim_VData {
                constexpr std::ptrdiff_t m_strVictimTetheredSound = 0x608; // 
                constexpr std::ptrdiff_t m_GraspVictimParticle = 0x618; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityRapidFireVData {
            }
            // Parent: CitadelAbilityVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityRiotProtocolVData {
                constexpr std::ptrdiff_t m_ChargeUpParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_CastParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_CastDelayModifier = 0x1708; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_WardenBuffModifier = 0x1718; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Chrono_KineticCarbineVData {
                constexpr std::ptrdiff_t m_TracerParticle = 0x608; // 
                constexpr std::ptrdiff_t m_FullyChargedParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_strFullyCharged = 0x7C8; // 
                constexpr std::ptrdiff_t m_strShotSound = 0x7D8; // 
            }
            // Parent: C_BaseEntity
            // Field count: 0
            namespace C_CitadelMinimapBoundary {
            }
            // Parent: CCitadelAnimatingModelEntity
            // Field count: 5
            //
            // Metadata:
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // NetworkVarNames: m_CCitadelAbilityComponent (CCitadelAbilityComponent::Storage_t)
            // NetworkVarNames: m_vecWeakPoints (WeakPoint_t)
            // NetworkVarNames: m_bDestroyed (bool)
            // NetworkVarNames: m_bActive (bool)
            // NetworkVarNames: m_bFinal (bool)
            namespace C_Citadel_Destroyable_Building {
                constexpr std::ptrdiff_t m_CCitadelAbilityComponent = 0xB58; // 
                constexpr std::ptrdiff_t m_vecWeakPoints = 0xCF8; // 
                constexpr std::ptrdiff_t m_bDestroyed = 0xD48; // 
                constexpr std::ptrdiff_t m_bActive = 0xD49; // 
                constexpr std::ptrdiff_t m_bFinal = 0xD4A; // 
            }
            // Parent: CCitadel_Item
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_nNumStacks (int)
            namespace CItem_RestorativeLocket {
                constexpr std::ptrdiff_t m_nNumStacks = 0xD38; // 
            }
            // Parent: CCitadel_Item
            // Field count: 1
            namespace CCitadel_TechUpgrade_SuperAcolyteGloves {
                constexpr std::ptrdiff_t fl_StoredDamage = 0xCC8; // 
            }
            // Parent: CLogicalEntity
            // Field count: 12
            namespace CPointTemplate {
                constexpr std::ptrdiff_t m_iszWorldName = 0x558; // 
                constexpr std::ptrdiff_t m_iszSource2EntityLumpName = 0x560; // 
                constexpr std::ptrdiff_t m_iszEntityFilterName = 0x568; // 
                constexpr std::ptrdiff_t m_flTimeoutInterval = 0x570; // 
                constexpr std::ptrdiff_t m_bAsynchronouslySpawnEntities = 0x574; // 
                constexpr std::ptrdiff_t m_pOutputOnSpawned = 0x578; // 
                constexpr std::ptrdiff_t m_clientOnlyEntityBehavior = 0x5A0; // PointTemplateClientOnlyEntityBehavior_t
                constexpr std::ptrdiff_t m_ownerSpawnGroupType = 0x5A4; // PointTemplateOwnerSpawnGroupType_t
                constexpr std::ptrdiff_t m_createdSpawnGroupHandles = 0x5A8; // 
                constexpr std::ptrdiff_t m_SpawnedEntityHandles = 0x5C0; // 
                constexpr std::ptrdiff_t m_ScriptSpawnCallback = 0x5D8; // 
                constexpr std::ptrdiff_t m_ScriptCallbackScope = 0x5E0; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityFealtyVData {
                constexpr std::ptrdiff_t m_TargetModifier = 0x1548; // 
            }
            // Parent: CCitadel_Modifier_Disarmed
            // Field count: 0
            namespace CCitadel_Modifier_ThrowSandDebuff {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Decoy_Self_Buff {
            }
            // Parent: CCitadelModifierVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_HornetSnipeVData {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_WingBlast {
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_LifeDrainVData {
                constexpr std::ptrdiff_t m_LifeDrainTargetModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_LifeDrainCasterModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_BoxingGloveVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x638; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_SwingParticle = 0x648; // 
                constexpr std::ptrdiff_t m_HitParticle = 0x728; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_Item_Bleeding_Bullets_Active {
            }
            // Parent: CCitadel_Modifier_Silenced
            // Field count: 0
            namespace CCitadel_Modifier_ModDisruptor {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_ArmorUpgrade_CloakingDeviceActive {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Chomp_LowHealth_Glow {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Slork_Chomp {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Haze_StackingDamage {
            }
            // Parent: CitadelAbilityVData
            // Field count: 17
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Viscous_TelepunchVData {
                constexpr std::ptrdiff_t m_PortalParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_CastParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_PunchParticle = 0x1708; // 
                constexpr std::ptrdiff_t m_WallPunchParticle = 0x17E8; // 
                constexpr std::ptrdiff_t m_CeilingPunchParticle = 0x18C8; // 
                constexpr std::ptrdiff_t m_EnemyPortalSound = 0x19A8; // 
                constexpr std::ptrdiff_t m_SelfPortalSound = 0x19B8; // 
                constexpr std::ptrdiff_t m_WindupSound = 0x19C8; // 
                constexpr std::ptrdiff_t m_PunchSound = 0x19D8; // 
                constexpr std::ptrdiff_t m_PunchRollSlowModifier = 0x19E8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ImpactModifier = 0x19F8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_flEnemyPortalTelegraphTime = 0x1A08; // 
                constexpr std::ptrdiff_t m_flSelfPortalTelegraphTime = 0x1A0C; // 
                constexpr std::ptrdiff_t m_flWindupTime = 0x1A10; // 
                constexpr std::ptrdiff_t m_flAttackTime = 0x1A14; // 
                constexpr std::ptrdiff_t m_flGroundTraceOnPlayerHitDistance = 0x1A18; // 
                constexpr std::ptrdiff_t m_flPlayerCheckSphereRadius = 0x1A1C; // 
            }
            // Parent: C_LightEntity
            // Field count: 0
            namespace C_LightCapsuleEntity {
            }
            // Parent: C_PointEntity
            // Field count: 5
            namespace CInfoDynamicShadowHint {
                constexpr std::ptrdiff_t m_bDisabled = 0x558; // 
                constexpr std::ptrdiff_t m_flRange = 0x55C; // 
                constexpr std::ptrdiff_t m_nImportance = 0x560; // 
                constexpr std::ptrdiff_t m_nLightChoice = 0x564; // 
                constexpr std::ptrdiff_t m_hLight = 0x568; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Slork_InvisVData {
                constexpr std::ptrdiff_t m_InvisModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_PreventHealingModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_AmbushExplosionParticle = 0x1568; // 
                constexpr std::ptrdiff_t m_AmbushExplosionSound = 0x1648; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 5
            //
            // Metadata:
            // NetworkVarNames: m_nFastFireBulletsLeft (int)
            // NetworkVarNames: m_flBlitzEndTime (CCitadelAutoScaledTime)
            namespace CAbility_Synth_Blitz {
                constexpr std::ptrdiff_t m_vecSpecialShots = 0xC78; // 
                constexpr std::ptrdiff_t m_nFastFireBulletsLeft = 0xC90; // 
                constexpr std::ptrdiff_t m_flBlitzEndTime = 0xC98; // 
                constexpr std::ptrdiff_t m_bCanApplyTechAmp = 0xCB0; // 
                constexpr std::ptrdiff_t m_bCanLifesteal = 0xCB1; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ConsumedProtectionRacket {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_TargetPractice {
            }
            // Parent: None
            // Field count: 0
            //
            // Metadata:
            // MPulseProvideFeatureTag
            // MPulseLibraryBindings
            namespace CTakeDamageInfoAPI {
            }
            // Parent: None
            // Field count: 0
            //
            // Metadata:
            // MPulseProvideFeatureTag
            // MPulseLibraryBindings
            namespace C_BaseEntityAPI {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_ArmorUpgrade_HighImpactArmor {
            }
            // Parent: CitadelAbilityVData
            // Field count: 8
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbility_Synth_Pulse_VData {
                constexpr std::ptrdiff_t m_EscapeModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_AoEParticle = 0x1568; // 
                constexpr std::ptrdiff_t m_EffectParticle = 0x1648; // 
                constexpr std::ptrdiff_t m_ChannelParticle = 0x1728; // 
                constexpr std::ptrdiff_t m_HitParticle = 0x1808; // 
                constexpr std::ptrdiff_t m_strExpireSound = 0x18E8; // 
                constexpr std::ptrdiff_t m_cameraSequenceInSatchel = 0x18F8; // CitadelCameraOperationsSequence_t
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Thumper_3 {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_RocketBarrageVolleyVData {
                constexpr std::ptrdiff_t m_strFireSound = 0x608; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ZiplineKnockdownImmune {
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierContainmentVictimVData {
                constexpr std::ptrdiff_t m_AreaParticle = 0x608; // 
                constexpr std::ptrdiff_t m_ChainedParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_DebuffParticle = 0x7C8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Slow {
            }
            // Parent: None
            // Field count: 10
            //
            // Metadata:
            // NetworkVarNames: m_iGlowType (int32)
            // NetworkVarNames: m_iGlowTeam (int32)
            // NetworkVarNames: m_nGlowRange (int32)
            // NetworkVarNames: m_nGlowRangeMin (int32)
            // NetworkVarNames: m_glowColorOverride (Color)
            // NetworkVarNames: m_bFlashing (bool)
            // NetworkVarNames: m_flGlowTime (float)
            // NetworkVarNames: m_flGlowStartTime (float)
            namespace CGlowProperty {
                constexpr std::ptrdiff_t m_fGlowColor = 0x8; // 
                constexpr std::ptrdiff_t m_iGlowType = 0x30; // 
                constexpr std::ptrdiff_t m_iGlowTeam = 0x34; // 
                constexpr std::ptrdiff_t m_nGlowRange = 0x38; // 
                constexpr std::ptrdiff_t m_nGlowRangeMin = 0x3C; // 
                constexpr std::ptrdiff_t m_glowColorOverride = 0x40; // 
                constexpr std::ptrdiff_t m_bFlashing = 0x44; // 
                constexpr std::ptrdiff_t m_flGlowTime = 0x48; // 
                constexpr std::ptrdiff_t m_flGlowStartTime = 0x4C; // 
                constexpr std::ptrdiff_t m_bGlowing = 0x50; // 
            }
            // Parent: C_BaseTrigger
            // Field count: 13
            //
            // Metadata:
            // NetworkVarNames: m_gravityScale (float)
            // NetworkVarNames: m_linearLimit (float)
            // NetworkVarNames: m_linearDamping (float)
            // NetworkVarNames: m_angularLimit (float)
            // NetworkVarNames: m_angularDamping (float)
            // NetworkVarNames: m_linearForce (float)
            // NetworkVarNames: m_flFrequency (float)
            // NetworkVarNames: m_flDampingRatio (float)
            // NetworkVarNames: m_vecLinearForcePointAt (Vector)
            // NetworkVarNames: m_bCollapseToForcePoint (bool)
            // NetworkVarNames: m_vecLinearForcePointAtWorld (Vector)
            // NetworkVarNames: m_vecLinearForceDirection (Vector)
            // NetworkVarNames: m_bConvertToDebrisWhenPossible (bool)
            namespace C_TriggerPhysics {
                constexpr std::ptrdiff_t m_gravityScale = 0x838; // 
                constexpr std::ptrdiff_t m_linearLimit = 0x83C; // 
                constexpr std::ptrdiff_t m_linearDamping = 0x840; // 
                constexpr std::ptrdiff_t m_angularLimit = 0x844; // 
                constexpr std::ptrdiff_t m_angularDamping = 0x848; // 
                constexpr std::ptrdiff_t m_linearForce = 0x84C; // 
                constexpr std::ptrdiff_t m_flFrequency = 0x850; // 
                constexpr std::ptrdiff_t m_flDampingRatio = 0x854; // 
                constexpr std::ptrdiff_t m_vecLinearForcePointAt = 0x858; // 
                constexpr std::ptrdiff_t m_bCollapseToForcePoint = 0x864; // 
                constexpr std::ptrdiff_t m_vecLinearForcePointAtWorld = 0x868; // 
                constexpr std::ptrdiff_t m_vecLinearForceDirection = 0x874; // 
                constexpr std::ptrdiff_t m_bConvertToDebrisWhenPossible = 0x880; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Mirage_SandPhantom_ProcReady {
            }
            // Parent: CCitadelModifierVData
            // Field count: 8
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_HookTargetVData {
                constexpr std::ptrdiff_t m_flApproachingWhooshAnticipationTime = 0x608; // 
                constexpr std::ptrdiff_t m_flCloseEnoughDistance = 0x60C; // 
                constexpr std::ptrdiff_t m_flTossUpSpeed = 0x610; // 
                constexpr std::ptrdiff_t m_SlowModifier = 0x618; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_HookRetrieveParticle = 0x628; // 
                constexpr std::ptrdiff_t m_strRetractSound = 0x708; // 
                constexpr std::ptrdiff_t m_strRetractSoundEnd = 0x718; // 
                constexpr std::ptrdiff_t m_strApproachingWhooshSound = 0x728; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_TargetPracticeSelf {
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_SilencerProcActive {
            }
            // Parent: CitadelItemVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CItem_RestorativeLocket_VData {
                constexpr std::ptrdiff_t m_CastParticle = 0x1590; // 
                constexpr std::ptrdiff_t m_TrailParticle = 0x1670; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_CharmedWraps_VData {
                constexpr std::ptrdiff_t m_SwingParticle = 0x638; // 
                constexpr std::ptrdiff_t m_HitParticle = 0x718; // 
            }
            // Parent: C_LightEntity
            // Field count: 0
            namespace C_LightDirectionalEntity {
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_SleepBomb_Aura {
            }
            // Parent: C_BaseEntity
            // Field count: 18
            //
            // Metadata:
            // NetworkVarNames: m_Entity_hCubemapTexture (HRenderTextureStrong)
            // NetworkVarNames: m_Entity_bCustomCubemapTexture (bool)
            // NetworkVarNames: m_Entity_flInfluenceRadius (float)
            // NetworkVarNames: m_Entity_vBoxProjectMins (Vector)
            // NetworkVarNames: m_Entity_vBoxProjectMaxs (Vector)
            // NetworkVarNames: m_Entity_bMoveable (bool)
            // NetworkVarNames: m_Entity_nHandshake (int)
            // NetworkVarNames: m_Entity_nEnvCubeMapArrayIndex (int)
            // NetworkVarNames: m_Entity_nPriority (int)
            // NetworkVarNames: m_Entity_flEdgeFadeDist (float)
            // NetworkVarNames: m_Entity_vEdgeFadeDists (Vector)
            // NetworkVarNames: m_Entity_flDiffuseScale (float)
            // NetworkVarNames: m_Entity_bStartDisabled (bool)
            // NetworkVarNames: m_Entity_bDefaultEnvMap (bool)
            // NetworkVarNames: m_Entity_bDefaultSpecEnvMap (bool)
            // NetworkVarNames: m_Entity_bIndoorCubeMap (bool)
            // NetworkVarNames: m_Entity_bCopyDiffuseFromDefaultCubemap (bool)
            // NetworkVarNames: m_Entity_bEnabled (bool)
            namespace C_EnvCubemap {
                constexpr std::ptrdiff_t m_Entity_hCubemapTexture = 0x5D8; // 
                constexpr std::ptrdiff_t m_Entity_bCustomCubemapTexture = 0x5E0; // 
                constexpr std::ptrdiff_t m_Entity_flInfluenceRadius = 0x5E4; // 
                constexpr std::ptrdiff_t m_Entity_vBoxProjectMins = 0x5E8; // 
                constexpr std::ptrdiff_t m_Entity_vBoxProjectMaxs = 0x5F4; // 
                constexpr std::ptrdiff_t m_Entity_bMoveable = 0x600; // 
                constexpr std::ptrdiff_t m_Entity_nHandshake = 0x604; // 
                constexpr std::ptrdiff_t m_Entity_nEnvCubeMapArrayIndex = 0x608; // 
                constexpr std::ptrdiff_t m_Entity_nPriority = 0x60C; // 
                constexpr std::ptrdiff_t m_Entity_flEdgeFadeDist = 0x610; // 
                constexpr std::ptrdiff_t m_Entity_vEdgeFadeDists = 0x614; // 
                constexpr std::ptrdiff_t m_Entity_flDiffuseScale = 0x620; // 
                constexpr std::ptrdiff_t m_Entity_bStartDisabled = 0x624; // 
                constexpr std::ptrdiff_t m_Entity_bDefaultEnvMap = 0x625; // 
                constexpr std::ptrdiff_t m_Entity_bDefaultSpecEnvMap = 0x626; // 
                constexpr std::ptrdiff_t m_Entity_bIndoorCubeMap = 0x627; // 
                constexpr std::ptrdiff_t m_Entity_bCopyDiffuseFromDefaultCubemap = 0x628; // 
                constexpr std::ptrdiff_t m_Entity_bEnabled = 0x638; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            namespace CCitadel_Ability_Yakuza_Shakedown {
                constexpr std::ptrdiff_t m_IgnoreChannelSlow = 0xC78; // 
            }
            // Parent: CitadelItemVData
            // Field count: 5
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Item_CheatDeathVData {
                constexpr std::ptrdiff_t m_DamagePulseParticle = 0x1590; // 
                constexpr std::ptrdiff_t m_DamageTargetParticle = 0x1670; // 
                constexpr std::ptrdiff_t m_sHealPulseSound = 0x1750; // 
                constexpr std::ptrdiff_t m_sHealAndDamagePulseSound = 0x1760; // 
                constexpr std::ptrdiff_t m_DeathImmuneModifier = 0x1770; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 2
            namespace CCitadel_Modifier_Succor_Move {
                constexpr std::ptrdiff_t m_bHasPulled = 0xC0; // 
                constexpr std::ptrdiff_t m_bIsPulling = 0xC1; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Upgrade_WeaponPowerForHealth {
            }
            // Parent: CCitadel_Ability_PrimaryWeapon
            // Field count: 0
            namespace CCitadel_Ability_PrimaryWeapon_Cadence {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_AirLift_Grab {
            }
            // Parent: CCitadelModifier
            // Field count: 9
            namespace CCitadel_Modifier_ChronoSwap_BubbleMove {
                constexpr std::ptrdiff_t m_bOtherIsInFrontAtStart = 0xC0; // 
                constexpr std::ptrdiff_t m_vOtherToDest = 0xC4; // 
                constexpr std::ptrdiff_t m_vStart = 0xD0; // 
                constexpr std::ptrdiff_t m_vDest = 0xDC; // 
                constexpr std::ptrdiff_t m_hOther = 0xE8; // 
                constexpr std::ptrdiff_t m_vLastSafePos = 0xEC; // 
                constexpr std::ptrdiff_t m_nNumTicks = 0xF8; // 
                constexpr std::ptrdiff_t m_nTicksLeft = 0xFC; // 
                constexpr std::ptrdiff_t m_nBeamIndex = 0x100; // 
            }
            // Parent: CCitadel_Modifier_Base_Buildup
            // Field count: 0
            namespace CCitadel_Modifier_Silence_Buildup {
            }
            // Parent: CBaseAnimGraph
            // Field count: 6
            namespace C_Citadel_FissureWall {
                constexpr std::ptrdiff_t m_vStartPos = 0xB50; // 
                constexpr std::ptrdiff_t m_vEndPos = 0xB5C; // 
                constexpr std::ptrdiff_t m_flStartEmitTime = 0xB68; // 
                constexpr std::ptrdiff_t m_flEndEmitTime = 0xB6C; // 
                constexpr std::ptrdiff_t m_bSolid = 0xB70; // 
                constexpr std::ptrdiff_t m_nTouchCount = 0xB74; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 12
            //
            // Metadata:
            // MGetKV3ClassDefaults
            // MPropertySuppressBaseClassField
            namespace CCitadel_Modifier_Mirage_SandPhantom_Proc_VData {
                constexpr std::ptrdiff_t m_bRollOnceForAllBulletsInAShot = 0x608; // 
                constexpr std::ptrdiff_t m_flMaxBulletsToProcInShot = 0x60C; // 
                constexpr std::ptrdiff_t m_bCanProcMultipleTimesFromSameShot = 0x610; // 
                constexpr std::ptrdiff_t m_bRequiresTargetFilter = 0x611; // 
                constexpr std::ptrdiff_t m_ProcReadyModifier = 0x618; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_PassiveVictimModifier = 0x628; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ProcReadyParticle = 0x638; // 
                constexpr std::ptrdiff_t m_TracerAdditionParticle = 0x718; // 
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x7F8; // 
                constexpr std::ptrdiff_t m_OnBulletRolledProcSound = 0x8D8; // 
                constexpr std::ptrdiff_t m_ProcSound = 0x8E8; // 
                constexpr std::ptrdiff_t m_ExplodeSound = 0x8F8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_ViscousBall {
                constexpr std::ptrdiff_t m_nDirectionParticleIndex = 0xC0; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_PassiveBeefyVData {
                constexpr std::ptrdiff_t m_HealParticle = 0x1548; // 
            }
            // Parent: CCitadelModifier
            // Field count: 2
            namespace CCitadel_Modifier_IntensifyingClip {
                constexpr std::ptrdiff_t m_LastThinkTime = 0x130; // 
                constexpr std::ptrdiff_t m_flSpinUpTime = 0x134; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_Ricochet_Proc {
            }
            // Parent: CBaseAnimGraph
            // Field count: 4
            //
            // Metadata:
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            namespace CPropAnimatingBreakable {
                constexpr std::ptrdiff_t m_stages = 0xB50; // 
                constexpr std::ptrdiff_t m_OnTakeDamage = 0xB68; // 
                constexpr std::ptrdiff_t m_OnFinalBreak = 0xB90; // 
                constexpr std::ptrdiff_t m_OnStageAdvanced = 0xBB8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ShakedownPulse {
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityStickyBombVData {
                constexpr std::ptrdiff_t m_BombAttachedModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_CastBombParticle = 0x1558; // 
            }
            // Parent: C_BaseEntity
            // Field count: 25
            //
            // Metadata:
            // NetworkVarNames: m_bDisabled (bool)
            // NetworkVarNames: m_bUpdateOnClient (bool)
            // NetworkVarNames: m_nInputType (ValueRemapperInputType_t)
            // NetworkVarNames: m_hRemapLineStart (CHandle<CBaseEntity>)
            // NetworkVarNames: m_hRemapLineEnd (CHandle<CBaseEntity>)
            // NetworkVarNames: m_flMaximumChangePerSecond (float)
            // NetworkVarNames: m_flDisengageDistance (float)
            // NetworkVarNames: m_flEngageDistance (float)
            // NetworkVarNames: m_bRequiresUseKey (bool)
            // NetworkVarNames: m_nOutputType (ValueRemapperOutputType_t)
            // NetworkVarNames: m_hOutputEntities (CHandle<C_BaseEntity>)
            // NetworkVarNames: m_nHapticsType (ValueRemapperHapticsType_t)
            // NetworkVarNames: m_nMomentumType (ValueRemapperMomentumType_t)
            // NetworkVarNames: m_flMomentumModifier (float)
            // NetworkVarNames: m_flSnapValue (float)
            // NetworkVarNames: m_nRatchetType (ValueRemapperRatchetType_t)
            // NetworkVarNames: m_flInputOffset (float)
            namespace C_PointValueRemapper {
                constexpr std::ptrdiff_t m_bDisabled = 0x558; // 
                constexpr std::ptrdiff_t m_bDisabledOld = 0x559; // 
                constexpr std::ptrdiff_t m_bUpdateOnClient = 0x55A; // 
                constexpr std::ptrdiff_t m_nInputType = 0x55C; // 
                constexpr std::ptrdiff_t m_hRemapLineStart = 0x560; // 
                constexpr std::ptrdiff_t m_hRemapLineEnd = 0x564; // 
                constexpr std::ptrdiff_t m_flMaximumChangePerSecond = 0x568; // 
                constexpr std::ptrdiff_t m_flDisengageDistance = 0x56C; // 
                constexpr std::ptrdiff_t m_flEngageDistance = 0x570; // 
                constexpr std::ptrdiff_t m_bRequiresUseKey = 0x574; // 
                constexpr std::ptrdiff_t m_nOutputType = 0x578; // 
                constexpr std::ptrdiff_t m_hOutputEntities = 0x580; // 
                constexpr std::ptrdiff_t m_nHapticsType = 0x598; // 
                constexpr std::ptrdiff_t m_nMomentumType = 0x59C; // 
                constexpr std::ptrdiff_t m_flMomentumModifier = 0x5A0; // 
                constexpr std::ptrdiff_t m_flSnapValue = 0x5A4; // 
                constexpr std::ptrdiff_t m_flCurrentMomentum = 0x5A8; // 
                constexpr std::ptrdiff_t m_nRatchetType = 0x5AC; // 
                constexpr std::ptrdiff_t m_flRatchetOffset = 0x5B0; // 
                constexpr std::ptrdiff_t m_flInputOffset = 0x5B4; // 
                constexpr std::ptrdiff_t m_bEngaged = 0x5B8; // 
                constexpr std::ptrdiff_t m_bFirstUpdate = 0x5B9; // 
                constexpr std::ptrdiff_t m_flPreviousValue = 0x5BC; // 
                constexpr std::ptrdiff_t m_flPreviousUpdateTickTime = 0x5C0; // 
                constexpr std::ptrdiff_t m_vecPreviousTestPoint = 0x5C4; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Spin {
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierQuarantineVData {
                constexpr std::ptrdiff_t m_BubbleParticle = 0x608; // 
                constexpr std::ptrdiff_t m_BubbleExplodeParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_SilenceModifier = 0x7C8; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Neutral_Debuff_Pushback {
            }
            // Parent: C_Citadel_BreakblePropPickup
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_iGoldReward (int)
            namespace C_Citadel_BreakblePropGoldPickup {
                constexpr std::ptrdiff_t m_iGoldReward = 0xB68; // 
            }
            // Parent: CCitadel_Item
            // Field count: 1
            namespace CCitadel_Item_Intensifying_Clip {
                constexpr std::ptrdiff_t m_flSpinUpTime = 0xCC8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_BreakablePropFireRatePickup {
            }
            // Parent: C_EnvCubemap
            // Field count: 0
            namespace C_EnvCubemapBox {
            }
            // Parent: CEntitySubclassVDataBase
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelViscousBallVData {
                constexpr std::ptrdiff_t m_sModelName = 0x28; // 
                constexpr std::ptrdiff_t m_flPhysicsRadius = 0x108; // 
            }
            // Parent: CitadelItemVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_WeaponUpgrade_HeadshotBooster_VData {
                constexpr std::ptrdiff_t m_HeadShotVictimSound = 0x1590; // 
                constexpr std::ptrdiff_t m_HeadShotConfirmationSound = 0x15A0; // 
            }
            // Parent: C_NPC_Trooper
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_CCitadelPlayerClipComponent (CCitadelPlayerClipComponent::Storage_t)
            // NetworkVarNames: m_flFadeOutStart (GameTime_t)
            // NetworkVarNames: m_flFadeOutEnd (GameTime_t)
            namespace C_NPC_TrooperBoss {
                constexpr std::ptrdiff_t m_CCitadelPlayerClipComponent = 0x14E8; // 
                constexpr std::ptrdiff_t m_flFadeOutStart = 0x1514; // 
                constexpr std::ptrdiff_t m_flFadeOutEnd = 0x1518; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_ThrowSand {
            }
            // Parent: CitadelAbilityVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityBouncePadVData {
                constexpr std::ptrdiff_t m_BounceModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_AllyBounceModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_SpeedOnLandModifier = 0x1568; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_NoBounceModifier = 0x1578; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_RocketBarrageVolley {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 6
            //
            // Metadata:
            // NetworkVarNames: m_bUsingThisMelee (bool)
            // NetworkVarNames: m_bUsingMeleeTagActive (bool)
            // NetworkVarNames: m_bHitWithThisAttack (bool)
            // NetworkVarNames: m_flLastActivateTime (GameTime_t)
            // NetworkVarNames: m_flNextAttackAllowedTime (GameTime_t)
            // NetworkVarNames: m_flAttackTriggeredTime (GameTime_t)
            namespace CCitadel_Ability_Melee_Base {
                constexpr std::ptrdiff_t m_bUsingThisMelee = 0xC78; // 
                constexpr std::ptrdiff_t m_bUsingMeleeTagActive = 0xC79; // 
                constexpr std::ptrdiff_t m_bHitWithThisAttack = 0xC7A; // 
                constexpr std::ptrdiff_t m_flLastActivateTime = 0xC7C; // 
                constexpr std::ptrdiff_t m_flNextAttackAllowedTime = 0xC80; // 
                constexpr std::ptrdiff_t m_flAttackTriggeredTime = 0xC84; // 
            }
            // Parent: CCitadel_Modifier_ChainLightningEffect
            // Field count: 0
            namespace CCitadel_Modifier_PowerSurge_ChainLightning {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_FullSpectrumDamage {
            }
            // Parent: C_BaseEntity
            // Field count: 5
            //
            // Metadata:
            // NetworkVarNames: m_iszStackName (string_t)
            // NetworkVarNames: m_iszOperatorName (string_t)
            // NetworkVarNames: m_iszOpvarName (string_t)
            // NetworkVarNames: m_iOpvarIndex (int)
            // NetworkVarNames: m_bUseAutoCompare (bool)
            namespace C_SoundOpvarSetPointBase {
                constexpr std::ptrdiff_t m_iszStackName = 0x558; // 
                constexpr std::ptrdiff_t m_iszOperatorName = 0x560; // 
                constexpr std::ptrdiff_t m_iszOpvarName = 0x568; // 
                constexpr std::ptrdiff_t m_iOpvarIndex = 0x570; // 
                constexpr std::ptrdiff_t m_bUseAutoCompare = 0x574; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_TechDamagePulse {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Tier3BossInvuln {
            }
            // Parent: C_Breakable
            // Field count: 0
            namespace C_PhysBox {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_PristineEmblem_VData {
                constexpr std::ptrdiff_t m_TracerParticle = 0x608; // 
                constexpr std::ptrdiff_t m_ParticleModifier = 0x6E8; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: None
            // Field count: 0
            //
            // Metadata:
            // MPulseProvideFeatureTag
            // MPulseLibraryBindings
            namespace CPathSimpleAPI {
            }
            // Parent: C_BaseTrigger
            // Field count: 0
            namespace C_CitadelShopTunnelTrigger {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_ModDisruptor {
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_FrenzyAura {
            }
            // Parent: CitadelAbilityVData
            // Field count: 13
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Nano_Pounce_VData {
                constexpr std::ptrdiff_t m_LeapModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ActiveBuff = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_SlowModifier = 0x1568; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_AttackParticle = 0x1578; // 
                constexpr std::ptrdiff_t m_FlashParticle = 0x1658; // 
                constexpr std::ptrdiff_t m_CastParticle = 0x1738; // 
                constexpr std::ptrdiff_t m_ExplodeSlowParticle = 0x1818; // 
                constexpr std::ptrdiff_t m_PrimaryHitParticle = 0x18F8; // 
                constexpr std::ptrdiff_t m_AttackSound = 0x19D8; // 
                constexpr std::ptrdiff_t m_strExplodeSound = 0x19E8; // 
                constexpr std::ptrdiff_t m_flPreArrivalAttackStartTime = 0x19F8; // 
                constexpr std::ptrdiff_t m_flAllyMinTargetRange = 0x19FC; // 
                constexpr std::ptrdiff_t m_flTargetVerticalOffset = 0x1A00; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityHornetChainVData {
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_strExplodeSound = 0x1628; // 
                constexpr std::ptrdiff_t m_ChainModifier = 0x1638; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DisarmModifier = 0x1648; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 11
            //
            // Metadata:
            // NetworkVarNames: m_hProjectile (EHANDLE)
            // NetworkVarNames: m_flArrowSpeed (float)
            // NetworkVarNames: m_flSnapAnglesBackTime (GameTime_t)
            // NetworkVarNames: m_nBonusTechPower (int)
            namespace CCitadel_Ability_GuidedArrow {
                constexpr std::ptrdiff_t m_hProjectile = 0xC80; // 
                constexpr std::ptrdiff_t m_flArrowSpeed = 0xC84; // 
                constexpr std::ptrdiff_t m_flSnapAnglesBackTime = 0xC88; // 
                constexpr std::ptrdiff_t m_nBonusTechPower = 0xC8C; // 
                constexpr std::ptrdiff_t m_flCastTime = 0xC90; // 
                constexpr std::ptrdiff_t m_bNeedsExplosion = 0xC94; // 
                constexpr std::ptrdiff_t m_vProjectileRemovedOrigin = 0xC98; // 
                constexpr std::ptrdiff_t m_angCasterAnglesAtCastTime = 0xCA4; // 
                constexpr std::ptrdiff_t m_flTravelDistance = 0xCB0; // 
                constexpr std::ptrdiff_t m_bInKillFlow = 0xCB4; // 
                constexpr std::ptrdiff_t m_flProjectileTurnVel = 0xCB8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_FireBombVData {
                constexpr std::ptrdiff_t m_ChargeParticle = 0x608; // 
                constexpr std::ptrdiff_t m_GroundParticle = 0x6E8; // 
            }
            // Parent: CCitadel_Ability_Melee_Base
            // Field count: 10
            //
            // Metadata:
            // NetworkVarNames: m_flParryWindowEndTime (GameTime_t)
            // NetworkVarNames: m_flNextParryTime (GameTime_t)
            // NetworkVarNames: m_flStateStartTime (GameTime_t)
            // NetworkVarNames: m_flDashStartTime (GameTime_t)
            // NetworkVarNames: m_eCurrentAttackState (EMeleeHold_AttackState)
            // NetworkVarNames: m_eCurrentAttackType (EMeleeHold_AttackType)
            // NetworkVarNames: m_vAirDashDir (Vector)
            // NetworkVarNames: m_bAttackStartedWhileSliding (bool)
            namespace CCitadel_Ability_HoldMelee {
                constexpr std::ptrdiff_t m_flParryWindowEndTime = 0xCF8; // 
                constexpr std::ptrdiff_t m_flNextParryTime = 0xCFC; // 
                constexpr std::ptrdiff_t m_flStateStartTime = 0xD00; // 
                constexpr std::ptrdiff_t m_flDashStartTime = 0xD04; // 
                constexpr std::ptrdiff_t m_eCurrentAttackState = 0xD08; // 
                constexpr std::ptrdiff_t m_eCurrentAttackType = 0xD0C; // 
                constexpr std::ptrdiff_t m_vAirDashDir = 0xD10; // 
                constexpr std::ptrdiff_t m_bAttackStartedWhileSliding = 0xD1C; // 
                constexpr std::ptrdiff_t m_bCreatedChargeEffects = 0xD1D; // 
                constexpr std::ptrdiff_t m_angForced = 0xD20; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelModifierApexWatcherVData {
                constexpr std::ptrdiff_t m_BuffModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelAbilityVData
            // Field count: 22
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityJumpVData {
                constexpr std::ptrdiff_t m_flShootingLockoutAfterJump = 0x1548; // 
                constexpr std::ptrdiff_t m_DashJumpParticle = 0x1550; // 
                constexpr std::ptrdiff_t m_AirJumpParticle = 0x1630; // 
                constexpr std::ptrdiff_t m_WallJumpParticle = 0x1710; // 
                constexpr std::ptrdiff_t m_AirJumpExecutedSound = 0x17F0; // 
                constexpr std::ptrdiff_t m_flMantleRefundWindow = 0x1800; // 
                constexpr std::ptrdiff_t m_flZiplineRefundWindow = 0x1804; // 
                constexpr std::ptrdiff_t m_flLateJumpGraceWindow = 0x1808; // 
                constexpr std::ptrdiff_t m_flMaxSpeedDelta = 0x180C; // 
                constexpr std::ptrdiff_t m_strDashJumpActivate = 0x1810; // 
                constexpr std::ptrdiff_t m_flDashJumpStartTime = 0x1820; // 
                constexpr std::ptrdiff_t m_flDashJumpEndTime = 0x1824; // 
                constexpr std::ptrdiff_t m_flDashJumpDistanceInMeters = 0x1828; // 
                constexpr std::ptrdiff_t m_flDashJumpVerticalSpeed = 0x1830; // 
                constexpr std::ptrdiff_t m_flDashJumpMissMaxSpeed = 0x1834; // 
                constexpr std::ptrdiff_t m_flDashJumpMantleDisableTime = 0x1838; // 
                constexpr std::ptrdiff_t m_WallJumpExecutedSound = 0x1840; // 
                constexpr std::ptrdiff_t m_flCollidedWallMaxDist = 0x1850; // 
                constexpr std::ptrdiff_t m_flRemapSpeedToWallJumpVelocityDist = 0x1854; // 
                constexpr std::ptrdiff_t m_flWallJumpNormalSpeed = 0x1864; // 
                constexpr std::ptrdiff_t m_WallJumpAirDragCurve = 0x1868; // 
                constexpr std::ptrdiff_t m_flMaxWallYawOffset = 0x18A8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Objective_BulletReistVData {
                constexpr std::ptrdiff_t m_BulletResist = 0x608; // 
                constexpr std::ptrdiff_t m_BulletResistReductionPerHero = 0x60C; // 
            }
            // Parent: None
            // Field count: 6
            //
            // Metadata:
            // NetworkVarNames: m_hOuter (EHANDLE)
            // NetworkVarNames: m_nCritHitGroup (HitGroup_t)
            // NetworkVarNames: m_nBodyGroup (int)
            // NetworkVarNames: m_bPermanentlyBroken (bool)
            // NetworkVarNames: m_nBrokenBodygroupIndex (int)
            namespace WeakPoint_t {
                constexpr std::ptrdiff_t m_bRegistered = 0x3C; // 
                constexpr std::ptrdiff_t m_hOuter = 0x40; // 
                constexpr std::ptrdiff_t m_nCritHitGroup = 0x44; // 
                constexpr std::ptrdiff_t m_nBodyGroup = 0x48; // 
                constexpr std::ptrdiff_t m_bPermanentlyBroken = 0x4C; // 
                constexpr std::ptrdiff_t m_nBrokenBodygroupIndex = 0x50; // 
            }
            // Parent: CBaseAnimGraph
            // Field count: 1
            //
            // Metadata:
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByUserGroup
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // NetworkVarNames: m_hEnemy (EHANDLE)
            namespace C_NPC_SimpleAnimatingAI {
                constexpr std::ptrdiff_t m_hEnemy = 0xB50; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_Empty {
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Slork_Raging_Current_Countdown {
                constexpr std::ptrdiff_t m_hRingEffect = 0xC0; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 8
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_IcePathVData {
                constexpr std::ptrdiff_t m_IcePathModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_flMomentumDecayRate = 0x1558; // 
                constexpr std::ptrdiff_t m_flMomentumWeight = 0x155C; // 
                constexpr std::ptrdiff_t m_flMaxPitchChange = 0x1560; // 
                constexpr std::ptrdiff_t m_flMaxPitchUp = 0x1564; // 
                constexpr std::ptrdiff_t m_flMaxPitchDown = 0x1568; // 
                constexpr std::ptrdiff_t m_flMaxHeight = 0x156C; // 
                constexpr std::ptrdiff_t m_flForwardAngleBias = 0x1570; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_HealthSwapVData {
                constexpr std::ptrdiff_t m_SwapParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_SwapModifier = 0x1628; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_PreCastModifier = 0x1638; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BuffModifier = 0x1648; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_SiphonBullets_RestoreHealth {
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_EscalatingExposureProcWatcher {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_CanDamageMidBoss {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_SingleTargetStun {
            }
            // Parent: C_BaseTrigger
            // Field count: 15
            //
            // Metadata:
            // NetworkVarNames: m_flInitialRadius (float)
            // NetworkVarNames: m_flEndRadius (float)
            // NetworkVarNames: m_flProgress (float)
            // NetworkVarNames: m_flCaptureTime (float)
            // NetworkVarNames: m_hUnlockPrereq (EHANDLE)
            // NetworkVarNames: m_bAvailable (bool)
            // NetworkVarNames: m_bIsBeingCaptured (bool)
            // NetworkVarNames: m_bIsBeingBlocked (bool)
            namespace CCitadelControlPointTrigger {
                constexpr std::ptrdiff_t m_flInitialRadius = 0x838; // 
                constexpr std::ptrdiff_t m_flEndRadius = 0x83C; // 
                constexpr std::ptrdiff_t m_flProgress = 0x840; // 
                constexpr std::ptrdiff_t m_flCaptureTime = 0x844; // 
                constexpr std::ptrdiff_t m_hUnlockPrereq = 0x848; // 
                constexpr std::ptrdiff_t m_bAvailable = 0x84C; // 
                constexpr std::ptrdiff_t m_bIsBeingCaptured = 0x84D; // 
                constexpr std::ptrdiff_t m_bIsBeingBlocked = 0x84E; // 
                constexpr std::ptrdiff_t m_flLastTouchedTime = 0x858; // 
                constexpr std::ptrdiff_t m_vecBeamTarget = 0x85C; // 
                constexpr std::ptrdiff_t m_vecBeamStart = 0x868; // 
                constexpr std::ptrdiff_t m_nFXProgressBeam = 0x874; // 
                constexpr std::ptrdiff_t m_strUnlockPrereq = 0x878; // 
                constexpr std::ptrdiff_t m_strBeamStart = 0x880; // 
                constexpr std::ptrdiff_t m_strBeamTarget = 0x888; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 9
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierLastBreathVData {
                constexpr std::ptrdiff_t m_ShieldParticle = 0x608; // 
                constexpr std::ptrdiff_t m_BulletShieldHitParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_TechShieldHitParticle = 0x7C8; // 
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x8A8; // 
                constexpr std::ptrdiff_t m_strStartSound = 0x988; // 
                constexpr std::ptrdiff_t m_ExplodeSound = 0x998; // 
                constexpr std::ptrdiff_t m_flShieldImpactEffectDuration = 0x9A8; // 
                constexpr std::ptrdiff_t m_BulletShieldImpactModifier = 0x9B0; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_TechShieldImpactModifier = 0x9C0; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Nano_PredatoryStatueTargetVData {
                constexpr std::ptrdiff_t m_strLaserHitSound = 0x608; // 
                constexpr std::ptrdiff_t m_strLaserStartSound = 0x618; // 
                constexpr std::ptrdiff_t m_strLaserLoopSound = 0x628; // 
                constexpr std::ptrdiff_t m_DebuffModifier = 0x638; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_PsychicDagger_MakeDaggers {
                constexpr std::ptrdiff_t m_nSatVolumeIndex = 0xC0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Bull_Leap_Boosting_CrashVData {
                constexpr std::ptrdiff_t m_DragModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_CrashTrailParticle = 0x618; // 
                constexpr std::ptrdiff_t m_flCollideRadius = 0x6F8; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 39
            //
            // Metadata:
            // NetworkVarNames: m_flNextPrimaryAttack (GameTime_t)
            // NetworkVarNames: m_iClip (int32)
            // NetworkVarNames: m_iBonusClip (int32)
            // NetworkVarNames: m_flSpreadPenalty (float)
            // NetworkVarNames: m_flZoomTime (GameTime_t)
            // NetworkVarNames: m_flZoomOutTime (GameTime_t)
            // NetworkVarNames: m_iSpreadIndex (int8)
            // NetworkVarNames: m_nShotRecoilIndex (int16)
            // NetworkVarNames: m_flNextShotRecoilRecoveryTime (GameTime_t)
            // NetworkVarNames: m_bIsZoomed (bool)
            // NetworkVarNames: m_nBurstShotsRemaining (uint8)
            // NetworkVarNames: m_nShotNumber (uint32)
            // NetworkVarNames: m_bInReload (bool)
            // NetworkVarNames: m_bSingleShotReloadFirstBullet (bool)
            // NetworkVarNames: m_reloadQueuedStartTime (GameTime_t)
            // NetworkVarNames: m_flReloadAvailableTime (GameTime_t)
            // NetworkVarNames: m_bCanActiveReload (bool)
            // NetworkVarNames: m_flLastAttackTime (GameTime_t)
            // NetworkVarNames: m_flNextAttackDelayStartTime (GameTime_t)
            // NetworkVarNames: m_flNextAttackDelayEndTime (GameTime_t)
            // NetworkVarNames: m_flAttackDelayPauseTotalTime (float)
            // NetworkVarNames: m_flAttackDelayPauseEndTime (GameTime_t)
            // NetworkVarNames: m_eNextAttackDelayReason (ENextAttackDelayReason_t)
            // NetworkVarNames: m_bInputPressedWhileSelected (bool)
            // NetworkVarNames: m_eActiveFireMode (EFireMode_t)
            namespace CCitadel_Ability_PrimaryWeapon {
                constexpr std::ptrdiff_t m_flNextPrimaryAttack = 0xC78; // 
                constexpr std::ptrdiff_t m_iClip = 0xC7C; // 
                constexpr std::ptrdiff_t m_iBonusClip = 0xC80; // 
                constexpr std::ptrdiff_t m_flSpreadPenalty = 0xC84; // 
                constexpr std::ptrdiff_t m_flZoomTime = 0xC88; // 
                constexpr std::ptrdiff_t m_flZoomOutTime = 0xC8C; // 
                constexpr std::ptrdiff_t m_iSpreadIndex = 0xC90; // 
                constexpr std::ptrdiff_t m_nShotRecoilIndex = 0xC92; // 
                constexpr std::ptrdiff_t m_flNextShotRecoilRecoveryTime = 0xC94; // 
                constexpr std::ptrdiff_t m_bIsZoomed = 0xC98; // 
                constexpr std::ptrdiff_t m_nBurstShotsRemaining = 0xC99; // 
                constexpr std::ptrdiff_t m_nShotNumber = 0xC9C; // 
                constexpr std::ptrdiff_t m_bInReload = 0xCA0; // 
                constexpr std::ptrdiff_t m_bSingleShotReloadFirstBullet = 0xCA1; // 
                constexpr std::ptrdiff_t m_reloadQueuedStartTime = 0xCA4; // 
                constexpr std::ptrdiff_t m_flReloadAvailableTime = 0xCA8; // 
                constexpr std::ptrdiff_t m_bCanActiveReload = 0xCAC; // 
                constexpr std::ptrdiff_t m_flLastAttackTime = 0xCB0; // 
                constexpr std::ptrdiff_t m_flNextAttackDelayStartTime = 0xCB4; // 
                constexpr std::ptrdiff_t m_flNextAttackDelayEndTime = 0xCB8; // 
                constexpr std::ptrdiff_t m_flAttackDelayPauseTotalTime = 0xCBC; // 
                constexpr std::ptrdiff_t m_flAttackDelayPauseEndTime = 0xCC0; // 
                constexpr std::ptrdiff_t m_eNextAttackDelayReason = 0xCC4; // 
                constexpr std::ptrdiff_t m_bInputPressedWhileSelected = 0xCC8; // 
                constexpr std::ptrdiff_t m_eActiveFireMode = 0xCCC; // 
                constexpr std::ptrdiff_t m_angRecoilAngles = 0xCD0; // 
                constexpr std::ptrdiff_t m_angRecoilToAdd = 0xCDC; // 
                constexpr std::ptrdiff_t m_angRecoilRecovery = 0xCE8; // 
                constexpr std::ptrdiff_t m_flRecoilStartTime = 0xCF4; // 
                constexpr std::ptrdiff_t m_flRecoilRecoverySpeed = 0xCF8; // 
                constexpr std::ptrdiff_t m_flAddApproachSpeed = 0xCFC; // 
                constexpr std::ptrdiff_t m_bFireBackwards = 0xD00; // 
                constexpr std::ptrdiff_t m_currentSpread = 0xD04; // 
                constexpr std::ptrdiff_t m_currentMaxSpread = 0xD08; // 
                constexpr std::ptrdiff_t m_currentFireSpread = 0xD0C; // 
                constexpr std::ptrdiff_t m_flCurrentSpinRate = 0xD10; // 
                constexpr std::ptrdiff_t m_fFireDuration = 0xD18; // 
                constexpr std::ptrdiff_t m_bFireOnEmpty = 0xD1D; // 
                constexpr std::ptrdiff_t m_flNextDisarmSound = 0xD20; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 5
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_SleepBombVData {
                constexpr std::ptrdiff_t m_BombParticle = 0x608; // 
                constexpr std::ptrdiff_t m_ExplodeDamageFriendlyParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_ExplodeDamageEnemyParticle = 0x7C8; // 
                constexpr std::ptrdiff_t m_SleepModifier = 0x8A8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_strExplodeSound = 0x8B8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_StompDebuff {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Surging_PowerVData {
                constexpr std::ptrdiff_t m_BerserkerSound = 0x608; // 
                constexpr std::ptrdiff_t m_ModifierActiveDisplay = 0x618; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Neutral_Debuff_PushbackVData {
                constexpr std::ptrdiff_t m_flPushSpeed = 0x608; // 
                constexpr std::ptrdiff_t m_flPushRange = 0x60C; // 
            }
            // Parent: CInfoDynamicShadowHint
            // Field count: 2
            namespace CInfoDynamicShadowHintBox {
                constexpr std::ptrdiff_t m_vBoxMins = 0x570; // 
                constexpr std::ptrdiff_t m_vBoxMaxs = 0x57C; // 
            }
            // Parent: C_CitadelProjectile
            // Field count: 0
            namespace C_Projectile_Mirage_Tornado {
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilitySlorkScaldVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ImpactParticle = 0x1558; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 7
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierAirLiftGrabVData {
                constexpr std::ptrdiff_t m_GrabEffect = 0x608; // 
                constexpr std::ptrdiff_t m_flLiftHorizontal = 0x6E8; // 
                constexpr std::ptrdiff_t m_flLiftHeight = 0x6EC; // 
                constexpr std::ptrdiff_t m_flFollowDampingFactor = 0x6F0; // 
                constexpr std::ptrdiff_t m_flFollowDistance = 0x6F4; // 
                constexpr std::ptrdiff_t m_flAllyGrabCancelTime = 0x6F8; // 
                constexpr std::ptrdiff_t m_flAllyPossibleStuckDistance = 0x6FC; // 
            }
            // Parent: CCitadelModifier
            // Field count: 2
            namespace CCitadel_Modifier_Wrecker_Ultimate_GrabEnemy {
                constexpr std::ptrdiff_t m_vHoldOffset = 0xC0; // 
                constexpr std::ptrdiff_t m_flLastTouchTime = 0xCC; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_FissureWall {
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_WeaponUpgrade_InstantReloadVData {
                constexpr std::ptrdiff_t m_ReloadParticle = 0x1590; // 
            }
            // Parent: CCitadelModifier
            // Field count: 3
            namespace CCitadel_Modifier_TeleportToObjective {
                constexpr std::ptrdiff_t m_vDest = 0xC0; // 
                constexpr std::ptrdiff_t m_angDestAngles = 0xCC; // 
                constexpr std::ptrdiff_t m_vDestVelocity = 0xD8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_PlayerDisconnected {
            }
            // Parent: C_PointEntity
            // Field count: 0
            namespace C_InfoPortalLink {
            }
            // Parent: C_BaseModelEntity
            // Field count: 4
            //
            // Metadata:
            // MNetworkExcludeByName
            // NetworkVarNames: m_ShardDesc (ice_path_shard_model_desc_t)
            // NetworkVarNames: m_qForward (QAngle)
            // NetworkVarNames: m_flStartTime (GameTime_t)
            // NetworkVarNames: m_flEndTime (GameTime_t)
            namespace C_Citadel_Ice_Path_Shard_Physics {
                constexpr std::ptrdiff_t m_ShardDesc = 0x830; // 
                constexpr std::ptrdiff_t m_qForward = 0x868; // 
                constexpr std::ptrdiff_t m_flStartTime = 0x874; // 
                constexpr std::ptrdiff_t m_flEndTime = 0x878; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_UtilityUpgrade_RocketBoots {
            }
            // Parent: CitadelAbilityVData
            // Field count: 7
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityPerchedPredatorVData {
                constexpr std::ptrdiff_t m_ExplodeBaseParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_ExplodeFriendlyParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_ExplodeEnemyParticle = 0x1708; // 
                constexpr std::ptrdiff_t m_strExplodeSound = 0x17E8; // 
                constexpr std::ptrdiff_t m_ModifierDragEnemy = 0x17F8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_flOnHitDetonateTimer = 0x1808; // 
                constexpr std::ptrdiff_t m_flTraceTravelRadius = 0x180C; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_UppercutClipSize {
                constexpr std::ptrdiff_t m_nPreClipSize = 0xF8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_SpeedBoostVData {
                constexpr std::ptrdiff_t m_flMoveSpeedBoost = 0x608; // 
            }
            // Parent: C_SoundOpvarSetPointEntity
            // Field count: 0
            namespace C_SoundOpvarSetPathCornerEntity {
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CBaseTriggerAbilityVData {
                constexpr std::ptrdiff_t m_AbilityToTrigger = 0x1548; // 
                constexpr std::ptrdiff_t m_flMinCancelTime = 0x1558; // 
                constexpr std::ptrdiff_t m_eHintFeatureToMarkUsedOnTrigger = 0x155C; // 
            }
            // Parent: C_BaseEntity
            // Field count: 18
            //
            // Metadata:
            // NetworkVarNames: m_flEndDistance (float)
            // NetworkVarNames: m_flStartDistance (float)
            // NetworkVarNames: m_flFogFalloffExponent (float)
            // NetworkVarNames: m_bHeightFogEnabled (bool)
            // NetworkVarNames: m_flFogHeightWidth (float)
            // NetworkVarNames: m_flFogHeightEnd (float)
            // NetworkVarNames: m_flFogHeightStart (float)
            // NetworkVarNames: m_flFogHeightExponent (float)
            // NetworkVarNames: m_flLODBias (float)
            // NetworkVarNames: m_bActive (bool)
            // NetworkVarNames: m_bStartDisabled (bool)
            // NetworkVarNames: m_flFogMaxOpacity (float)
            // NetworkVarNames: m_nCubemapSourceType (int)
            // NetworkVarNames: m_hSkyMaterial (HMaterialStrong)
            // NetworkVarNames: m_iszSkyEntity (string_t)
            // NetworkVarNames: m_hFogCubemapTexture (HRenderTextureStrong)
            // NetworkVarNames: m_bHasHeightFogEnd (bool)
            namespace C_EnvCubemapFog {
                constexpr std::ptrdiff_t m_flEndDistance = 0x558; // 
                constexpr std::ptrdiff_t m_flStartDistance = 0x55C; // 
                constexpr std::ptrdiff_t m_flFogFalloffExponent = 0x560; // 
                constexpr std::ptrdiff_t m_bHeightFogEnabled = 0x564; // 
                constexpr std::ptrdiff_t m_flFogHeightWidth = 0x568; // 
                constexpr std::ptrdiff_t m_flFogHeightEnd = 0x56C; // 
                constexpr std::ptrdiff_t m_flFogHeightStart = 0x570; // 
                constexpr std::ptrdiff_t m_flFogHeightExponent = 0x574; // 
                constexpr std::ptrdiff_t m_flLODBias = 0x578; // 
                constexpr std::ptrdiff_t m_bActive = 0x57C; // 
                constexpr std::ptrdiff_t m_bStartDisabled = 0x57D; // 
                constexpr std::ptrdiff_t m_flFogMaxOpacity = 0x580; // 
                constexpr std::ptrdiff_t m_nCubemapSourceType = 0x584; // 
                constexpr std::ptrdiff_t m_hSkyMaterial = 0x588; // CStrongHandle<InfoForResourceTypeIMaterial2>
                constexpr std::ptrdiff_t m_iszSkyEntity = 0x590; // 
                constexpr std::ptrdiff_t m_hFogCubemapTexture = 0x598; // 
                constexpr std::ptrdiff_t m_bHasHeightFogEnd = 0x5A0; // 
                constexpr std::ptrdiff_t m_bFirstTime = 0x5A1; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityGenericPerson2VData {
            }
            // Parent: CCitadel_Modifier_Sleep
            // Field count: 0
            namespace CCitadel_Modifier_PoisonBullet_Poisoned {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Afterburn_DOT_VData {
                constexpr std::ptrdiff_t m_sAfterburnParticle = 0x608; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Fervor_Bonuses {
                constexpr std::ptrdiff_t m_nBonusesParticle = 0xC0; // 
            }
            // Parent: CCitadelModifierAura
            // Field count: 3
            namespace CCitadel_Modifier_Rutger_Pulse_Aura {
                constexpr std::ptrdiff_t m_flStartRadius = 0xE0; // 
                constexpr std::ptrdiff_t m_flEndRadius = 0xE4; // 
                constexpr std::ptrdiff_t m_flSpreadDuration = 0xE8; // 
            }
            // Parent: CCitadel_Item
            // Field count: 1
            namespace CCitadel_ArmorUpgrade_DoubleJump {
                constexpr std::ptrdiff_t m_nTickJumped = 0xC90; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_PayloadCarrier {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Dust_Storm_Aura_Apply {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierChargedTacklePrepareVData {
                constexpr std::ptrdiff_t m_PrepareParticle = 0x608; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_flParryStartTime (GameTime_t)
            // NetworkVarNames: m_bAttackParried (bool)
            // NetworkVarNames: m_flParrySuccessTime (GameTime_t)
            namespace CCitadel_Ability_MeleeParry {
                constexpr std::ptrdiff_t m_flParryStartTime = 0xC78; // 
                constexpr std::ptrdiff_t m_bAttackParried = 0xC7C; // 
                constexpr std::ptrdiff_t m_flParrySuccessTime = 0xC80; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_BerserkerDamageStack {
            }
            // Parent: CCitadel_Modifier_BaseBulletPreRollProc
            // Field count: 1
            namespace CCitadel_Modifier_ExplosiveBullets {
                constexpr std::ptrdiff_t m_BuffedShotId = 0x1F8; // 
            }
            // Parent: None
            // Field count: 4
            //
            // Metadata:
            // NetworkVarNames: m_SourceAbilityID (AbilityID_t)
            // NetworkVarNames: m_TargetAbilityID (AbilityID_t)
            // NetworkVarNames: m_eValType (EModifierValue)
            // NetworkVarNames: m_flValue (float)
            namespace DynamicAbilityValues_t {
                constexpr std::ptrdiff_t m_SourceAbilityID = 0x30; // 
                constexpr std::ptrdiff_t m_TargetAbilityID = 0x34; // 
                constexpr std::ptrdiff_t m_eValType = 0x38; // 
                constexpr std::ptrdiff_t m_flValue = 0x3C; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_ArmorUpgrade_MetalSkin {
            }
            // Parent: CitadelAbilityVData
            // Field count: 8
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Spinning_BladeVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_CatchIndicator = 0x1558; // 
                constexpr std::ptrdiff_t m_CatchParticle = 0x1638; // 
                constexpr std::ptrdiff_t m_strThrowSound = 0x1718; // 
                constexpr std::ptrdiff_t m_strReturnSound = 0x1728; // 
                constexpr std::ptrdiff_t m_strCatchSound = 0x1738; // 
                constexpr std::ptrdiff_t m_strFailSound = 0x1748; // 
                constexpr std::ptrdiff_t m_strHitSound = 0x1758; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 34
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Tengu_AirLiftVData {
                constexpr std::ptrdiff_t m_FlyingModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_GrabModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_HoldBombModifier = 0x1568; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DroppedBuffModifier = 0x1578; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ExplodingAllyModifier = 0x1588; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_AoEModifier = 0x1598; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_InitialExplodeParticle = 0x15A8; // 
                constexpr std::ptrdiff_t m_HoldBombEffect = 0x1688; // 
                constexpr std::ptrdiff_t m_strExplodeSound = 0x1768; // 
                constexpr std::ptrdiff_t m_flAirDrag = 0x1778; // 
                constexpr std::ptrdiff_t m_flMaxFallSpeed = 0x177C; // 
                constexpr std::ptrdiff_t m_flTargetAirSpeedFast = 0x1780; // 
                constexpr std::ptrdiff_t m_flTargetAirSpeedBase = 0x1784; // 
                constexpr std::ptrdiff_t m_flAcceleration = 0x1788; // 
                constexpr std::ptrdiff_t m_flDecceleration = 0x178C; // 
                constexpr std::ptrdiff_t m_flAirSideSpeedPercent = 0x1790; // 
                constexpr std::ptrdiff_t m_flBoostTime = 0x1794; // 
                constexpr std::ptrdiff_t m_flBoostSpeedUp = 0x1798; // 
                constexpr std::ptrdiff_t m_flMinFlyHeight = 0x179C; // 
                constexpr std::ptrdiff_t m_flMaxFlyHeight = 0x17A0; // 
                constexpr std::ptrdiff_t m_flMaxPitchUp = 0x17A4; // 
                constexpr std::ptrdiff_t m_flMaxPitchDown = 0x17A8; // 
                constexpr std::ptrdiff_t m_flAllyDelayedBoostTime = 0x17AC; // 
                constexpr std::ptrdiff_t m_flChannelingAirDrag = 0x17B0; // 
                constexpr std::ptrdiff_t m_flChannelingMaxFallSpeed = 0x17B4; // 
                constexpr std::ptrdiff_t m_flBombReleaseSpeed = 0x17B8; // 
                constexpr std::ptrdiff_t m_flBombReleasePitch = 0x17BC; // 
                constexpr std::ptrdiff_t m_flBombDropReleaseOffset = 0x17C0; // 
                constexpr std::ptrdiff_t m_flHoldBombOffsetX = 0x17C4; // 
                constexpr std::ptrdiff_t m_flHoldBombOffsetY = 0x17C8; // 
                constexpr std::ptrdiff_t m_flHoldBombOffsetZ = 0x17CC; // 
                constexpr std::ptrdiff_t m_flAnglePitchBias = 0x17D0; // 
                constexpr std::ptrdiff_t m_flTrackAmount = 0x17D4; // 
                constexpr std::ptrdiff_t m_flMoveCollideSpeed = 0x17D8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ChronoSwap_BubbleMoveVData {
                constexpr std::ptrdiff_t m_BeamParticle = 0x608; // 
                constexpr std::ptrdiff_t m_HealParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_DamageParticle = 0x7C8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Stabilizing_Tripod_Self_Debuff {
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Hero_Clone {
                constexpr std::ptrdiff_t m_bMimicOwner = 0xC0; // 
            }
            // Parent: None
            // Field count: 17
            //
            // Metadata:
            // NetworkVarNames: m_collisionAttribute (VPhysicsCollisionAttribute_t)
            // NetworkVarNames: m_vecMins (Vector)
            // NetworkVarNames: m_vecMaxs (Vector)
            // NetworkVarNames: m_usSolidFlags (uint8)
            // NetworkVarNames: m_nSolidType (SolidType_t)
            // NetworkVarNames: m_triggerBloat (uint8)
            // NetworkVarNames: m_nSurroundType (SurroundingBoundsType_t)
            // NetworkVarNames: m_CollisionGroup (uint8)
            // NetworkVarNames: m_nEnablePhysics (uint8)
            // NetworkVarNames: m_vecSpecifiedSurroundingMins (Vector)
            // NetworkVarNames: m_vecSpecifiedSurroundingMaxs (Vector)
            // NetworkVarNames: m_vCapsuleCenter1 (Vector)
            // NetworkVarNames: m_vCapsuleCenter2 (Vector)
            // NetworkVarNames: m_flCapsuleRadius (float)
            namespace CCollisionProperty {
                constexpr std::ptrdiff_t m_collisionAttribute = 0x10; // 
                constexpr std::ptrdiff_t m_vecMins = 0x40; // 
                constexpr std::ptrdiff_t m_vecMaxs = 0x4C; // 
                constexpr std::ptrdiff_t m_usSolidFlags = 0x5A; // 
                constexpr std::ptrdiff_t m_nSolidType = 0x5B; // 
                constexpr std::ptrdiff_t m_triggerBloat = 0x5C; // 
                constexpr std::ptrdiff_t m_nSurroundType = 0x5D; // 
                constexpr std::ptrdiff_t m_CollisionGroup = 0x5E; // 
                constexpr std::ptrdiff_t m_nEnablePhysics = 0x5F; // 
                constexpr std::ptrdiff_t m_flBoundingRadius = 0x60; // 
                constexpr std::ptrdiff_t m_vecSpecifiedSurroundingMins = 0x64; // 
                constexpr std::ptrdiff_t m_vecSpecifiedSurroundingMaxs = 0x70; // 
                constexpr std::ptrdiff_t m_vecSurroundingMaxs = 0x7C; // 
                constexpr std::ptrdiff_t m_vecSurroundingMins = 0x88; // 
                constexpr std::ptrdiff_t m_vCapsuleCenter1 = 0x94; // 
                constexpr std::ptrdiff_t m_vCapsuleCenter2 = 0xA0; // 
                constexpr std::ptrdiff_t m_flCapsuleRadius = 0xAC; // 
            }
            // Parent: None
            // Field count: 8
            //
            // Metadata:
            // NetworkVarNames: m_hSequence (HSequence)
            // NetworkVarNames: m_flPrevCycle (float32)
            // NetworkVarNames: m_flCycle (float32)
            namespace CNetworkedSequenceOperation {
                constexpr std::ptrdiff_t m_hSequence = 0x8; // 
                constexpr std::ptrdiff_t m_flPrevCycle = 0xC; // 
                constexpr std::ptrdiff_t m_flCycle = 0x10; // 
                constexpr std::ptrdiff_t m_flWeight = 0x14; // 
                constexpr std::ptrdiff_t m_bSequenceChangeNetworked = 0x1C; // 
                constexpr std::ptrdiff_t m_bDiscontinuity = 0x1D; // 
                constexpr std::ptrdiff_t m_flPrevCycleFromDiscontinuity = 0x20; // 
                constexpr std::ptrdiff_t m_flPrevCycleForAnimEventDetection = 0x24; // 
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Cadence_GrandFinaleAOEVData {
                constexpr std::ptrdiff_t m_AuraParticle = 0x648; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Targetdummy_Inherent {
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityShivDeferDamageVData {
                constexpr std::ptrdiff_t m_ActiveCastParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_flDeferredDamageApplicationInterval = 0x1628; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Bebop_Hook_BulletAmp {
            }
            // Parent: CCitadel_Modifier_StatStealBase
            // Field count: 0
            namespace CCitadel_Modifier_Arcane_Eater_Watcher {
            }
            // Parent: CTier3BossAbility
            // Field count: 0
            namespace CCitadel_Ability_Weapon_BossTier3 {
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CBaseLockonAbilityVData {
                constexpr std::ptrdiff_t m_TargetModifier = 0x1548; // 
                constexpr std::ptrdiff_t m_strApplyLockonStack = 0x1558; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_Synth_Grasp_Caster {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_bActive (bool)
            namespace CCitadel_Ability_RiotProtocol {
                constexpr std::ptrdiff_t m_bActive = 0xC78; // 
            }
            // Parent: CCitadel_Modifier_Intrinsic_BaseVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ThrowSandProjectileVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Intimidated_Debuff {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Astro_Rifle_DebuffVData {
                constexpr std::ptrdiff_t m_SlowModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_strTargetHitSound = 0x618; // 
            }
            // Parent: CitadelItemVData
            // Field count: 11
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Upgrade_MagicCarpetVData {
                constexpr std::ptrdiff_t m_SummonParticle = 0x1590; // 
                constexpr std::ptrdiff_t m_FlyingCarpetModifier = 0x1670; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_SummonFlyingCarpetModifier = 0x1680; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_SummonFlyingCarpetVisualModifier = 0x1690; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_FlyingCarpetVisualModifier = 0x16A0; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ShieldModifier = 0x16B0; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_flSummonVisualDuration = 0x16C0; // 
                constexpr std::ptrdiff_t m_flBurstSpeedBonus = 0x16C4; // 
                constexpr std::ptrdiff_t m_flBurstSpeedMin = 0x16C8; // 
                constexpr std::ptrdiff_t m_flBurstSpeedDuration = 0x16CC; // 
                constexpr std::ptrdiff_t m_flMinDistanceAboveGround = 0x16D0; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_FullSpectrum {
            }
            // Parent: CCitadel_Modifier_Tier3Boss_Base
            // Field count: 18
            namespace CCitadel_Modifier_Tier3Boss_LaserBeam {
                constexpr std::ptrdiff_t m_flSoundStartTime = 0xC8; // 
                constexpr std::ptrdiff_t m_vStart = 0xD0; // 
                constexpr std::ptrdiff_t m_vEnd = 0xDC; // 
                constexpr std::ptrdiff_t m_vPrevEnd = 0xE8; // 
                constexpr std::ptrdiff_t m_flAngleBetweenTrace = 0xF4; // 
                constexpr std::ptrdiff_t m_flPlayerDamagePerTick = 0xF8; // 
                constexpr std::ptrdiff_t m_flNPCDamagePerTick = 0xFC; // 
                constexpr std::ptrdiff_t m_flNextDamageTick = 0x100; // 
                constexpr std::ptrdiff_t m_vecEntitiesHit = 0x108; // 
                constexpr std::ptrdiff_t m_flDamageTickRate = 0x120; // 
                constexpr std::ptrdiff_t m_flLastShakeTime = 0x124; // 
                constexpr std::ptrdiff_t m_bSweepRightFirst = 0x128; // 
                constexpr std::ptrdiff_t m_vecBeamTarget = 0x12C; // 
                constexpr std::ptrdiff_t m_flLastBeamUpdateTime = 0x138; // 
                constexpr std::ptrdiff_t m_vecEnemyPosition = 0x13C; // 
                constexpr std::ptrdiff_t m_nTrackingIndex = 0x148; // 
                constexpr std::ptrdiff_t m_bPreviewMode = 0x14C; // 
                constexpr std::ptrdiff_t m_hAttachment = 0x14D; // 
            }
            // Parent: None
            // Field count: 13
            //
            // Metadata:
            // NetworkVarNames: m_vecProviders (EHANDLE)
            // NetworkVarNames: m_nDisabledGroups (uint32)
            // NetworkVarNames: m_bvEnabledStateMask (uint32)
            // NetworkVarNames: m_bvDisabledStateMask (uint32)
            // NetworkVarNames: m_bvEnabledPredictedStateMask (uint32)
            namespace CModifierProperty {
                constexpr std::ptrdiff_t __m_pChainEntity = 0x8; // 
                constexpr std::ptrdiff_t m_hOwner = 0x30; // 
                constexpr std::ptrdiff_t m_nProviderVisitedFlags = 0x194; // 
                constexpr std::ptrdiff_t m_bModifierStatesDirty = 0x195; // 
                constexpr std::ptrdiff_t m_bPredictedOwner = 0x196; // 
                constexpr std::ptrdiff_t m_iLockRefCount = 0x197; // 
                constexpr std::ptrdiff_t m_hHandle = 0x198; // 
                constexpr std::ptrdiff_t m_nBroadcastEventListenerMask = 0x19C; // 
                constexpr std::ptrdiff_t m_vecProviders = 0x1A8; // 
                constexpr std::ptrdiff_t m_nDisabledGroups = 0x1C0; // 
                constexpr std::ptrdiff_t m_bvEnabledStateMask = 0x1C4; // 
                constexpr std::ptrdiff_t m_bvDisabledStateMask = 0x1DC; // 
                constexpr std::ptrdiff_t m_bvEnabledPredictedStateMask = 0x1F4; // 
            }
            // Parent: C_AI_CitadelNPC
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_flForwardSpeed (float)
            // NetworkVarNames: m_hOwnerPawn (CHandle<CBaseEntity>)
            namespace C_NPC_NanoRollermine {
                constexpr std::ptrdiff_t m_flForwardSpeed = 0x14B8; // 
                constexpr std::ptrdiff_t m_hOwnerPawn = 0x14BC; // 
            }
            // Parent: C_AI_CitadelNPC
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_hOwner (EHANDLE)
            namespace C_NPC_HeroCloneTrooper {
                constexpr std::ptrdiff_t m_hOwner = 0x14A0; // 
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_TenguUrn_Aura {
            }
            // Parent: CCitadelModifier
            // Field count: 4
            namespace CGameModifier_OverrideTargetIdentifier {
                constexpr std::ptrdiff_t m_sTargetIdentifier = 0xC0; // 
                constexpr std::ptrdiff_t m_hTarget = 0xC8; // 
                constexpr std::ptrdiff_t m_sAttachmentName = 0xD0; // 
                constexpr std::ptrdiff_t m_hAttachment = 0xD8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_FealtyTarget {
            }
            // Parent: CitadelAbilityVData
            // Field count: 7
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_RocketBarrageVData {
                constexpr std::ptrdiff_t m_BarrageModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_MoveSlowModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ImpactParticle = 0x1568; // 
                constexpr std::ptrdiff_t m_strExplodeSound = 0x1648; // 
                constexpr std::ptrdiff_t m_cameraSequenceSelected = 0x1658; // CitadelCameraOperationsSequence_t
                constexpr std::ptrdiff_t m_flMoveSpeedReductionPct = 0x16E0; // 
                constexpr std::ptrdiff_t m_flHeightTestDistance = 0x16E4; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_IncendiaryDebuff {
            }
            // Parent: CEntitySubclassVDataBase
            // Field count: 40
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_XPOrbVData {
                constexpr std::ptrdiff_t m_bIsObjective = 0x28; // 
                constexpr std::ptrdiff_t m_strOrbClaimed = 0x30; // 
                constexpr std::ptrdiff_t m_strOrbClaimedTeammate = 0x40; // 
                constexpr std::ptrdiff_t m_strOrbDenied = 0x50; // 
                constexpr std::ptrdiff_t m_strOrbDeniedPlayer = 0x60; // 
                constexpr std::ptrdiff_t m_sOrbModel = 0x70; // 
                constexpr std::ptrdiff_t m_sFriendlyGlowParticle = 0x150; // 
                constexpr std::ptrdiff_t m_sEnemyGlowParticle = 0x230; // 
                constexpr std::ptrdiff_t m_sGoldReceivedParticle = 0x310; // 
                constexpr std::ptrdiff_t m_sFriendlyOrbDeniedParticle = 0x3F0; // 
                constexpr std::ptrdiff_t m_sEnemyOrbDeniedParticle = 0x4D0; // 
                constexpr std::ptrdiff_t m_sFriendlyOrbEarnedParticle = 0x5B0; // 
                constexpr std::ptrdiff_t m_sEnemyOrbEarnedParticle = 0x690; // 
                constexpr std::ptrdiff_t m_flOrbSpawnDelayMin = 0x770; // 
                constexpr std::ptrdiff_t m_flOrbSpawnDelayMax = 0x774; // 
                constexpr std::ptrdiff_t m_flOrbSpawnOffsetZ = 0x778; // 
                constexpr std::ptrdiff_t m_flOrbSpawnOffsetRandomXYZ = 0x77C; // 
                constexpr std::ptrdiff_t m_flGravityScale = 0x780; // 
                constexpr std::ptrdiff_t m_flLateralSpeedMin = 0x784; // 
                constexpr std::ptrdiff_t m_flLateralSpeedMax = 0x788; // 
                constexpr std::ptrdiff_t m_flLateralMoveDuration = 0x78C; // 
                constexpr std::ptrdiff_t m_flUpSpeedMin = 0x790; // 
                constexpr std::ptrdiff_t m_flUpSpeedMax = 0x794; // 
                constexpr std::ptrdiff_t m_flBurstSpeedMultiplier = 0x798; // 
                constexpr std::ptrdiff_t m_flBurstSpeedDuration = 0x79C; // 
                constexpr std::ptrdiff_t m_flOscillateFrequency = 0x7A0; // 
                constexpr std::ptrdiff_t m_flLifeTime = 0x7A4; // 
                constexpr std::ptrdiff_t m_flRadius = 0x7A8; // 
                constexpr std::ptrdiff_t m_flCollisionRadius = 0x7AC; // 
                constexpr std::ptrdiff_t m_flInvulDuration = 0x7B0; // 
                constexpr std::ptrdiff_t m_bUseKillerPlaneOffsets = 0x7B4; // 
                constexpr std::ptrdiff_t m_flKillerPlaneOffset = 0x7B8; // 
                constexpr std::ptrdiff_t m_flKillerPlaneHorizontalDecayRate = 0x7BC; // 
                constexpr std::ptrdiff_t m_flKillerPlaneHorizontalSpeedX = 0x7C0; // 
                constexpr std::ptrdiff_t m_flKillerPlaneHorizontalSpeedY = 0x7C4; // 
                constexpr std::ptrdiff_t m_flKillerPlaneVerticalSpeed = 0x7C8; // 
                constexpr std::ptrdiff_t m_flKillerPlaneSpeedNoise = 0x7CC; // 
                constexpr std::ptrdiff_t m_flKillerPlaneLaunchOffset = 0x7D0; // 
                constexpr std::ptrdiff_t m_flKillerPlaneLaunchDelay = 0x7D4; // 
                constexpr std::ptrdiff_t m_flOrbClaimWindow = 0x7D8; // 
            }
            // Parent: None
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_ID (CUtlStringToken)
            // NetworkVarNames: m_Values (Vector4D)
            namespace EntityRenderAttribute_t {
                constexpr std::ptrdiff_t m_ID = 0x30; // 
                constexpr std::ptrdiff_t m_Values = 0x34; // 
            }
            // Parent: C_PhysicsProp
            // Field count: 1
            //
            // Metadata:
            // MNetworkExcludeByName
            // NetworkVarNames: m_ShardDesc (shard_model_desc_t)
            namespace C_ShatterGlassShardPhysics {
                constexpr std::ptrdiff_t m_ShardDesc = 0xCE8; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityTargetdummy3VData {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 7
            //
            // Metadata:
            // NetworkVarNames: m_flStartTime (GameTime_t)
            // NetworkVarNames: m_flLandedTime (GameTime_t)
            // NetworkVarNames: m_bLanded (bool)
            // NetworkVarNames: m_bFalling (bool)
            // NetworkVarNames: m_bInStoneForm (bool)
            // NetworkVarNames: m_flStartHeight (float)
            namespace CCitadel_Ability_Tengu_StoneForm {
                constexpr std::ptrdiff_t m_flStartTime = 0xE38; // 
                constexpr std::ptrdiff_t m_flLandedTime = 0xE3C; // 
                constexpr std::ptrdiff_t m_bLanded = 0xE40; // 
                constexpr std::ptrdiff_t m_bFalling = 0xE41; // 
                constexpr std::ptrdiff_t m_bInStoneForm = 0xE42; // 
                constexpr std::ptrdiff_t m_flStartHeight = 0xE44; // 
                constexpr std::ptrdiff_t m_nStoneFormEffect = 0xE48; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_CheatDeathImmunity {
            }
            // Parent: C_BaseModelEntity
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_CLightComponent (CLightComponent::Storage_t)
            namespace C_LightEntity {
                constexpr std::ptrdiff_t m_CLightComponent = 0x830; // 
            }
            // Parent: CCitadelModifierAura
            // Field count: 1
            namespace CCitadel_Modifier_Cadence_Crescendo_AOE {
                constexpr std::ptrdiff_t m_nTicks = 0xE8; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbility_Synth_Grasp_VData {
                constexpr std::ptrdiff_t m_CasterModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_VictimModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BulletShieldModifier = 0x1568; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_bInFlight (bool)
            namespace CCitadel_Ability_Tokamak_DyingStar {
                constexpr std::ptrdiff_t m_nRollFXIndex = 0xC78; // 
                constexpr std::ptrdiff_t m_bInFlight = 0xC7C; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Cadence_SleepingVData {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 2
            namespace CCitadel_Ability_IceGrenade {
                constexpr std::ptrdiff_t m_vLaunchPosition = 0xC78; // 
                constexpr std::ptrdiff_t m_qLaunchAngle = 0xC84; // 
            }
            // Parent: CCitadelModifier
            // Field count: 3
            namespace CCitadel_Modifier_ChargePullEnemy {
                constexpr std::ptrdiff_t m_vecOffsetDir = 0xC0; // 
                constexpr std::ptrdiff_t m_flTackleRadius = 0xCC; // 
                constexpr std::ptrdiff_t m_flPullTargetSpeed = 0xD0; // 
            }
            // Parent: CitadelItemVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_WeaponUpgrade_Headhunter_VData {
                constexpr std::ptrdiff_t m_HeadshotBuffModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_HeadShotVictimSound = 0x15A0; // 
                constexpr std::ptrdiff_t m_HeadShotConfirmationSound = 0x15B0; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_SlowingTech_Proc {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Quarantine {
            }
            // Parent: CCitadel_Modifier_ShieldTracker_Base
            // Field count: 0
            namespace CCitadel_Modifier_ShieldTracker_Bullet {
            }
            // Parent: CCitadelModifier
            // Field count: 4
            namespace CCitadel_Modifier_Base_Buildup {
                constexpr std::ptrdiff_t m_flLastBuildupAppliedTime = 0xC0; // 
                constexpr std::ptrdiff_t m_flDelayedDieTimeRemaining = 0xC4; // 
                constexpr std::ptrdiff_t m_bInDelayTime = 0xC8; // 
                constexpr std::ptrdiff_t m_flBuildUpDecayDelayFromWeaponCycleTime = 0xCC; // 
            }
            // Parent: C_BaseEntity
            // Field count: 6
            //
            // Metadata:
            // NetworkVarNames: m_flVisibilityStrength (float)
            // NetworkVarNames: m_flFogDistanceMultiplier (float)
            // NetworkVarNames: m_flFogMaxDensityMultiplier (float)
            // NetworkVarNames: m_flFadeTime (float)
            // NetworkVarNames: m_bStartDisabled (bool)
            // NetworkVarNames: m_bIsEnabled (bool)
            namespace C_PlayerVisibility {
                constexpr std::ptrdiff_t m_flVisibilityStrength = 0x558; // 
                constexpr std::ptrdiff_t m_flFogDistanceMultiplier = 0x55C; // 
                constexpr std::ptrdiff_t m_flFogMaxDensityMultiplier = 0x560; // 
                constexpr std::ptrdiff_t m_flFadeTime = 0x564; // 
                constexpr std::ptrdiff_t m_bStartDisabled = 0x568; // 
                constexpr std::ptrdiff_t m_bIsEnabled = 0x569; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityRocketLauncherVData {
                constexpr std::ptrdiff_t m_ExplosionParticle = 0x1548; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Warden_CrowdControl_Debuff {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_flDashEndTime (CCitadelAutoScaledTime)
            // NetworkVarNames: m_bIsSpeedBursting (bool)
            namespace CCitadel_Ability_FlameDash {
                constexpr std::ptrdiff_t m_flDashEndTime = 0xC78; // 
                constexpr std::ptrdiff_t m_bIsSpeedBursting = 0xC90; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ArcaneEaterDebuffVData {
                constexpr std::ptrdiff_t m_DebuffParticle = 0x608; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_Inhibitor_Proc {
            }
            // Parent: CitadelAbilityVData
            // Field count: 24
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Climb_RopeVData {
                constexpr std::ptrdiff_t m_flMinButtonHoldTimeToActivate = 0x1548; // 
                constexpr std::ptrdiff_t m_flClimbSpeedUp = 0x154C; // 
                constexpr std::ptrdiff_t m_flClimbSpeedDown = 0x1550; // 
                constexpr std::ptrdiff_t m_flClimbSpeedDownMax = 0x1554; // 
                constexpr std::ptrdiff_t m_flClimbDownAccelTime = 0x1558; // 
                constexpr std::ptrdiff_t m_flLatchSpeed = 0x155C; // 
                constexpr std::ptrdiff_t m_flAttachOffset = 0x1560; // 
                constexpr std::ptrdiff_t m_flMinReconnectTime = 0x1564; // 
                constexpr std::ptrdiff_t m_flSideMoveReduction = 0x1568; // 
                constexpr std::ptrdiff_t m_flTopOffset = 0x156C; // 
                constexpr std::ptrdiff_t m_flBottomOffset = 0x1570; // 
                constexpr std::ptrdiff_t m_flTraceRadiusSize = 0x1574; // 
                constexpr std::ptrdiff_t m_flStopTimeToShoot = 0x1578; // 
                constexpr std::ptrdiff_t m_flJumpOffVertical = 0x157C; // 
                constexpr std::ptrdiff_t m_flJumpOffHorizontal = 0x1580; // 
                constexpr std::ptrdiff_t m_flDuckOffVertical = 0x1584; // 
                constexpr std::ptrdiff_t m_flDuckOffHorizontal = 0x1588; // 
                constexpr std::ptrdiff_t m_flActivateRange = 0x158C; // 
                constexpr std::ptrdiff_t m_flJumpToRoofRayCheckDist = 0x1590; // 
                constexpr std::ptrdiff_t m_flMinTimeToRoofCheck = 0x1594; // 
                constexpr std::ptrdiff_t m_flTimeToHintRefresh = 0x1598; // 
                constexpr std::ptrdiff_t m_iMaxHintCount = 0x159C; // 
                constexpr std::ptrdiff_t m_flClimbRopeSlowDurationOnHit = 0x15A0; // 
                constexpr std::ptrdiff_t m_ClimbRopeSlowOnHitModifier = 0x15A8; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: None
            // Field count: 25
            //
            // Metadata:
            // NetworkVarNames: dirPrimary (Vector)
            // NetworkVarNames: colorPrimary (Color)
            // NetworkVarNames: colorSecondary (Color)
            // NetworkVarNames: colorPrimaryLerpTo (Color)
            // NetworkVarNames: colorSecondaryLerpTo (Color)
            // NetworkVarNames: start (float32)
            // NetworkVarNames: end (float32)
            // NetworkVarNames: farz (float32)
            // NetworkVarNames: maxdensity (float32)
            // NetworkVarNames: exponent (float32)
            // NetworkVarNames: HDRColorScale (float32)
            // NetworkVarNames: skyboxFogFactor (float32)
            // NetworkVarNames: skyboxFogFactorLerpTo (float32)
            // NetworkVarNames: startLerpTo (float32)
            // NetworkVarNames: endLerpTo (float32)
            // NetworkVarNames: maxdensityLerpTo (float32)
            // NetworkVarNames: lerptime (GameTime_t)
            // NetworkVarNames: duration (float32)
            // NetworkVarNames: blendtobackground (float32)
            // NetworkVarNames: scattering (float32)
            // NetworkVarNames: locallightscale (float32)
            // NetworkVarNames: enable (bool)
            // NetworkVarNames: blend (bool)
            // NetworkVarNames: m_bNoReflectionFog (bool)
            namespace fogparams_t {
                constexpr std::ptrdiff_t dirPrimary = 0x8; // 
                constexpr std::ptrdiff_t colorPrimary = 0x14; // 
                constexpr std::ptrdiff_t colorSecondary = 0x18; // 
                constexpr std::ptrdiff_t colorPrimaryLerpTo = 0x1C; // 
                constexpr std::ptrdiff_t colorSecondaryLerpTo = 0x20; // 
                constexpr std::ptrdiff_t start = 0x24; // 
                constexpr std::ptrdiff_t end = 0x28; // 
                constexpr std::ptrdiff_t farz = 0x2C; // 
                constexpr std::ptrdiff_t maxdensity = 0x30; // 
                constexpr std::ptrdiff_t exponent = 0x34; // 
                constexpr std::ptrdiff_t HDRColorScale = 0x38; // 
                constexpr std::ptrdiff_t skyboxFogFactor = 0x3C; // 
                constexpr std::ptrdiff_t skyboxFogFactorLerpTo = 0x40; // 
                constexpr std::ptrdiff_t startLerpTo = 0x44; // 
                constexpr std::ptrdiff_t endLerpTo = 0x48; // 
                constexpr std::ptrdiff_t maxdensityLerpTo = 0x4C; // 
                constexpr std::ptrdiff_t lerptime = 0x50; // 
                constexpr std::ptrdiff_t duration = 0x54; // 
                constexpr std::ptrdiff_t blendtobackground = 0x58; // 
                constexpr std::ptrdiff_t scattering = 0x5C; // 
                constexpr std::ptrdiff_t locallightscale = 0x60; // 
                constexpr std::ptrdiff_t enable = 0x64; // 
                constexpr std::ptrdiff_t blend = 0x65; // 
                constexpr std::ptrdiff_t m_bNoReflectionFog = 0x66; // 
                constexpr std::ptrdiff_t m_bPadding = 0x67; // 
            }
            // Parent: C_CitadelProjectile
            // Field count: 2
            namespace C_Citadel_Projectile_Tier2Boss_RocketBarrage {
                constexpr std::ptrdiff_t m_nLaserParticleIndex = 0x8B8; // 
                constexpr std::ptrdiff_t m_vecSmoothedVelocity = 0x8BC; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_BreakablePropClipSizePickupVData {
                constexpr std::ptrdiff_t m_flClipSize = 0x608; // 
                constexpr std::ptrdiff_t m_nClipCount = 0x60C; // 
                constexpr std::ptrdiff_t m_flFireRate = 0x610; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 5
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityHatTrickVData {
                constexpr std::ptrdiff_t m_SpectatingProjectileParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_ExplosionParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_HatTrickChannelParticle = 0x1708; // 
                constexpr std::ptrdiff_t m_DebuffModifier = 0x17E8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_strExplodeSound = 0x17F8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 7
            namespace CCitadel_Modifier_VoidSphere {
                constexpr std::ptrdiff_t m_bTeleported = 0xC0; // 
                constexpr std::ptrdiff_t m_particleStart = 0xC4; // 
                constexpr std::ptrdiff_t m_particleEnd = 0xC8; // 
                constexpr std::ptrdiff_t m_particleTrail = 0xCC; // 
                constexpr std::ptrdiff_t m_vecEndLocation = 0xD0; // 
                constexpr std::ptrdiff_t m_vecStartPosition = 0xDC; // 
                constexpr std::ptrdiff_t m_vecEndLocationCaster = 0xE8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ZiplineKnockdownImmuneVData {
                constexpr std::ptrdiff_t m_ZipLineEnemyKnockdownProtectionParticle = 0x608; // 
                constexpr std::ptrdiff_t m_ZipLineSelfKnockdownProtectionParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_ZipLineKnockdownProtectionStatusParticle = 0x7C8; // 
                constexpr std::ptrdiff_t m_ZipLineKnockdownProtectionStatusEnemyParticle = 0x8A8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Upgrade_OverdriveClip_Reload {
                constexpr std::ptrdiff_t m_nStartingClipSize = 0xC0; // 
            }
            // Parent: CitadelItemVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_ArmorUpgrade_HealOnLevelVData {
            }
            // Parent: CCitadelYamatoBaseVData
            // Field count: 26
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelAbilityFlyingStrikeVData {
                constexpr std::ptrdiff_t m_flJumpFallSpeedMax = 0x1550; // 
                constexpr std::ptrdiff_t m_flJumpAirDrag = 0x1554; // 
                constexpr std::ptrdiff_t m_flJumpAirSpeedMax = 0x1558; // 
                constexpr std::ptrdiff_t m_flFlyingCloseEnoughToTarget = 0x155C; // 
                constexpr std::ptrdiff_t m_curveSpeedScale = 0x1560; // 
                constexpr std::ptrdiff_t m_flAnimToStrikePointTime = 0x15A0; // 
                constexpr std::ptrdiff_t m_flAnimToStrikeArrivalBias = 0x15A4; // 
                constexpr std::ptrdiff_t m_flGrappleShotFloatTime = 0x15A8; // 
                constexpr std::ptrdiff_t m_flGrappleShotDelayToFlyOnHit = 0x15AC; // 
                constexpr std::ptrdiff_t m_flGrappleSpeed = 0x15B0; // 
                constexpr std::ptrdiff_t m_SlowModifier = 0x15B8; // 
                constexpr std::ptrdiff_t m_GrappleTargetModifier = 0x15C8; // 
                constexpr std::ptrdiff_t m_WeaponBuffModifier = 0x15D8; // 
                constexpr std::ptrdiff_t m_LeapParticle = 0x15E8; // 
                constexpr std::ptrdiff_t m_ImpactParticle = 0x16C8; // 
                constexpr std::ptrdiff_t m_SlashParticle = 0x17A8; // 
                constexpr std::ptrdiff_t m_BulletGrappleTracerParticle = 0x1888; // 
                constexpr std::ptrdiff_t m_EnemyGrappleParticle = 0x1968; // 
                constexpr std::ptrdiff_t m_strDamageTarget = 0x1A48; // 
                constexpr std::ptrdiff_t m_strStartFlyingToTarget = 0x1A58; // 
                constexpr std::ptrdiff_t m_strStartAttack = 0x1A68; // 
                constexpr std::ptrdiff_t m_strGrappleHitTarget = 0x1A78; // 
                constexpr std::ptrdiff_t m_strGrappleHitWorld = 0x1A88; // 
                constexpr std::ptrdiff_t m_strGrappleHitNothing = 0x1A98; // 
                constexpr std::ptrdiff_t m_cameraSequenceFlying = 0x1AA8; // CitadelCameraOperationsSequence_t
                constexpr std::ptrdiff_t m_cameraSequenceAttacking = 0x1B30; // CitadelCameraOperationsSequence_t
            }
            // Parent: CCitadel_Modifier_Base
            // Field count: 0
            namespace CCitadel_Modifier_FlyingStrikeTarget {
            }
            // Parent: CitadelAbilityVData
            // Field count: 8
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityGooGrenadeVData {
                constexpr std::ptrdiff_t m_GooGrenadeImpactModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_GooGrenadePuddleAuraModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_GooGrenadeSkipParticle = 0x1568; // 
                constexpr std::ptrdiff_t m_GooGrenadeExplodeParticle = 0x1648; // 
                constexpr std::ptrdiff_t m_GrenadeHitImpactSound = 0x1728; // 
                constexpr std::ptrdiff_t m_GrenadeMissImpactSound = 0x1738; // 
                constexpr std::ptrdiff_t m_flMinRestitution = 0x1748; // 
                constexpr std::ptrdiff_t m_flMaxRestitution = 0x174C; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 5
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_FireBombVData {
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_ExplodeSound = 0x1628; // 
                constexpr std::ptrdiff_t m_ProgressBarModifier = 0x1638; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_FireBombModifier = 0x1648; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1658; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_Tier3Boss_Base
            // Field count: 0
            namespace CCitadel_Modifier_Tier3_DamagePulse {
            }
            // Parent: C_GameRulesProxy
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_pGameRules (C_CitadelGameRules*)
            namespace C_CitadelGameRulesProxy {
                constexpr std::ptrdiff_t m_pGameRules = 0x558; // 
            }
            // Parent: C_BaseEntity
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_timeLastUpdate (GameTime_t)
            // NetworkVarNames: m_vecFOWEntities (STrooperFOWEntity)
            namespace CCitadelTrooperMinimap {
                constexpr std::ptrdiff_t m_timeLastUpdate = 0x558; // 
                constexpr std::ptrdiff_t m_vecFOWEntities = 0x560; // 
            }
            // Parent: C_NPC_SimpleAnimatingAI
            // Field count: 1
            //
            // Metadata:
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // NetworkVarNames: m_vecUnitStatusOffset (Vector)
            namespace C_NPC_BaseDefenseSentry {
                constexpr std::ptrdiff_t m_vecUnitStatusOffset = 0xB58; // 
            }
            // Parent: C_DynamicProp
            // Field count: 5
            //
            // Metadata:
            // NetworkVarNames: m_strDefaultSkin (CUtlString)
            // NetworkVarNames: m_strFriendlySkin (CUtlString)
            // NetworkVarNames: m_strEnemySkin (CUtlString)
            // NetworkVarNames: m_bIsWorld (bool)
            namespace C_Citadel_DynamicProp {
                constexpr std::ptrdiff_t m_nPlayerTeamEvent = 0xE00; // 
                constexpr std::ptrdiff_t m_strDefaultSkin = 0xE08; // 
                constexpr std::ptrdiff_t m_strFriendlySkin = 0xE10; // 
                constexpr std::ptrdiff_t m_strEnemySkin = 0xE18; // 
                constexpr std::ptrdiff_t m_bIsWorld = 0xE20; // 
            }
            // Parent: CBaseAnimGraph
            // Field count: 19
            //
            // Metadata:
            // NetworkVarNames: m_flexWeight (float32)
            // NetworkVarNames: m_blinktoggle (bool)
            namespace C_BaseFlex {
                constexpr std::ptrdiff_t m_flexWeight = 0xB60; // 
                constexpr std::ptrdiff_t m_vLookTargetPosition = 0xB78; // 
                constexpr std::ptrdiff_t m_blinktoggle = 0xB90; // 
                constexpr std::ptrdiff_t m_nLastFlexUpdateFrameCount = 0xBF0; // 
                constexpr std::ptrdiff_t m_CachedViewTarget = 0xBF4; // 
                constexpr std::ptrdiff_t m_nNextSceneEventId = 0xC00; // 
                constexpr std::ptrdiff_t m_iBlink = 0xC04; // 
                constexpr std::ptrdiff_t m_blinktime = 0xC08; // 
                constexpr std::ptrdiff_t m_prevblinktoggle = 0xC0C; // 
                constexpr std::ptrdiff_t m_iJawOpen = 0xC10; // 
                constexpr std::ptrdiff_t m_flJawOpenAmount = 0xC14; // 
                constexpr std::ptrdiff_t m_flBlinkAmount = 0xC18; // 
                constexpr std::ptrdiff_t m_iMouthAttachment = 0xC1C; // 
                constexpr std::ptrdiff_t m_iEyeAttachment = 0xC1D; // 
                constexpr std::ptrdiff_t m_bResetFlexWeightsOnModelChange = 0xC1E; // 
                constexpr std::ptrdiff_t m_nEyeOcclusionRendererBone = 0xC38; // 
                constexpr std::ptrdiff_t m_mEyeOcclusionRendererCameraToBoneTransform = 0xC3C; // 
                constexpr std::ptrdiff_t m_vEyeOcclusionRendererHalfExtent = 0xC6C; // 
                constexpr std::ptrdiff_t m_PhonemeClasses = 0xC88; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_DPS_Aura {
            }
            // Parent: C_BaseEntity
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_iCurrentMaxRagdollCount (int8)
            namespace C_RagdollManager {
                constexpr std::ptrdiff_t m_iCurrentMaxRagdollCount = 0x558; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 7
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Mirage_FireBeetles_VData {
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_CasterModifier = 0x1628; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1638; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_RecentlyDebuffedModifier = 0x1648; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_StealWatcherModifier = 0x1658; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ExplosionSound = 0x1668; // 
                constexpr std::ptrdiff_t m_strHitConfirm = 0x1678; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityTargetdummy4VData {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_SleepDagger_Drowsy_VData {
                constexpr std::ptrdiff_t m_SleepModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 7
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierIcePathVData {
                constexpr std::ptrdiff_t m_FrontModel = 0x608; // 
                constexpr std::ptrdiff_t m_BodyModel = 0x6E8; // 
                constexpr std::ptrdiff_t m_GroundParticle = 0x7C8; // 
                constexpr std::ptrdiff_t m_FloatingParticle = 0x8A8; // 
                constexpr std::ptrdiff_t m_IcePathBuffParticle = 0x988; // 
                constexpr std::ptrdiff_t m_FriendlyAuraModifier = 0xA68; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BonusSpiritLingerModifier = 0xA78; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_VitalitySuppressor {
                constexpr std::ptrdiff_t m_flLastTickTime = 0xC0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_SlowVData {
            }
            // Parent: C_BaseModelEntity
            // Field count: 12
            //
            // Metadata:
            // NetworkVarNames: m_hSkyMaterial (HMaterialStrong)
            // NetworkVarNames: m_hSkyMaterialLightingOnly (HMaterialStrong)
            // NetworkVarNames: m_bStartDisabled (bool)
            // NetworkVarNames: m_vTintColor (Color)
            // NetworkVarNames: m_vTintColorLightingOnly (Color)
            // NetworkVarNames: m_flBrightnessScale (float)
            // NetworkVarNames: m_nFogType (int)
            // NetworkVarNames: m_flFogMinStart (float)
            // NetworkVarNames: m_flFogMinEnd (float)
            // NetworkVarNames: m_flFogMaxStart (float)
            // NetworkVarNames: m_flFogMaxEnd (float)
            // NetworkVarNames: m_bEnabled (bool)
            namespace C_EnvSky {
                constexpr std::ptrdiff_t m_hSkyMaterial = 0x830; // CStrongHandle<InfoForResourceTypeIMaterial2>
                constexpr std::ptrdiff_t m_hSkyMaterialLightingOnly = 0x838; // CStrongHandle<InfoForResourceTypeIMaterial2>
                constexpr std::ptrdiff_t m_bStartDisabled = 0x840; // 
                constexpr std::ptrdiff_t m_vTintColor = 0x841; // 
                constexpr std::ptrdiff_t m_vTintColorLightingOnly = 0x845; // 
                constexpr std::ptrdiff_t m_flBrightnessScale = 0x84C; // 
                constexpr std::ptrdiff_t m_nFogType = 0x850; // 
                constexpr std::ptrdiff_t m_flFogMinStart = 0x854; // 
                constexpr std::ptrdiff_t m_flFogMinEnd = 0x858; // 
                constexpr std::ptrdiff_t m_flFogMaxStart = 0x85C; // 
                constexpr std::ptrdiff_t m_flFogMaxEnd = 0x860; // 
                constexpr std::ptrdiff_t m_bEnabled = 0x864; // 
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Item_Discord_Aura_Enemy {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ItemPickupPunchable {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Slork_Riptide {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Slork_Raging_Current {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Rutger_CheatDeath {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Tokamak_Breach {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 19
            //
            // Metadata:
            // NetworkVarNames: m_flGroundDashJumpStartTime (CCitadelAutoScaledTime)
            // NetworkVarNames: m_flGroundDashJumpEndTime (CCitadelAutoScaledTime)
            // NetworkVarNames: m_bJumped (bool)
            // NetworkVarNames: m_bCanDashJump (bool)
            // NetworkVarNames: m_nDesiredAirJumpCount (int)
            // NetworkVarNames: m_nExecutedAirJumpCount (int)
            // NetworkVarNames: m_bInSlideJump (bool)
            // NetworkVarNames: m_nConsecutiveAirJumps (int8)
            // NetworkVarNames: m_nConsecutiveWallJumps (int8)
            namespace CCitadel_Ability_Jump {
                constexpr std::ptrdiff_t m_flLastTimeOnZipLine = 0xC78; // 
                constexpr std::ptrdiff_t m_flLastOnGroundTime = 0xC7C; // 
                constexpr std::ptrdiff_t m_flPhaseStartTime = 0xC80; // 
                constexpr std::ptrdiff_t m_flJumpTime = 0xC84; // 
                constexpr std::ptrdiff_t m_LastJumpType = 0xC88; // 
                constexpr std::ptrdiff_t m_bShouldCreateAirJumpEffects = 0xC89; // 
                constexpr std::ptrdiff_t m_flDoubleJumpFailTime = 0xC8C; // 
                constexpr std::ptrdiff_t m_eDoubleJumpFailReason = 0xC90; // 
                constexpr std::ptrdiff_t m_vWallJumpNormalUsed = 0xC94; // 
                constexpr std::ptrdiff_t m_flGroundDashJumpStartTime = 0xDB8; // 
                constexpr std::ptrdiff_t m_flGroundDashJumpEndTime = 0xDD0; // 
                constexpr std::ptrdiff_t m_bJumped = 0xDE8; // 
                constexpr std::ptrdiff_t m_bCanDashJump = 0xDE9; // 
                constexpr std::ptrdiff_t m_nDesiredAirJumpCount = 0xDEC; // 
                constexpr std::ptrdiff_t m_nExecutedAirJumpCount = 0xDF0; // 
                constexpr std::ptrdiff_t m_bInSlideJump = 0xDF4; // 
                constexpr std::ptrdiff_t m_nConsecutiveAirJumps = 0xDF5; // 
                constexpr std::ptrdiff_t m_nConsecutiveWallJumps = 0xDF6; // 
                constexpr std::ptrdiff_t m_vLastWallCollidedWithNormal = 0xDF8; // 
            }
            // Parent: C_PointEntity
            // Field count: 0
            namespace CInfoTarget {
            }
            // Parent: CCitadel_Modifier_Intrinsic_Base
            // Field count: 0
            namespace CCitadel_Modifier_PredatorPrecision {
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_TechUpgrade_SuperAcolyteGlovesVData {
                constexpr std::ptrdiff_t m_SpiritMeleeProcModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_TechCleaveVData {
                constexpr std::ptrdiff_t m_CleavePlayerParticle = 0x608; // 
                constexpr std::ptrdiff_t m_CleaveTrooperParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_sVictimSound = 0x7C8; // 
            }
            // Parent: CScaleFunctionBase
            // Field count: 0
            namespace CScaleFunctionAbilityPropertyMultiStats {
            }
            // Parent: C_BreakableProp
            // Field count: 23
            //
            // Metadata:
            // NetworkVarNames: m_bUseHitboxesForRenderBox (bool)
            // NetworkVarNames: m_bUseAnimGraph (bool)
            namespace C_DynamicProp {
                constexpr std::ptrdiff_t m_bUseHitboxesForRenderBox = 0xCD8; // 
                constexpr std::ptrdiff_t m_bUseAnimGraph = 0xCD9; // 
                constexpr std::ptrdiff_t m_pOutputAnimBegun = 0xCE0; // 
                constexpr std::ptrdiff_t m_pOutputAnimOver = 0xD08; // 
                constexpr std::ptrdiff_t m_pOutputAnimLoopCycleOver = 0xD30; // 
                constexpr std::ptrdiff_t m_OnAnimReachedStart = 0xD58; // 
                constexpr std::ptrdiff_t m_OnAnimReachedEnd = 0xD80; // 
                constexpr std::ptrdiff_t m_iszIdleAnim = 0xDA8; // 
                constexpr std::ptrdiff_t m_nIdleAnimLoopMode = 0xDB0; // 
                constexpr std::ptrdiff_t m_bRandomizeCycle = 0xDB4; // 
                constexpr std::ptrdiff_t m_bStartDisabled = 0xDB5; // 
                constexpr std::ptrdiff_t m_bFiredStartEndOutput = 0xDB6; // 
                constexpr std::ptrdiff_t m_bForceNpcExclude = 0xDB7; // 
                constexpr std::ptrdiff_t m_bCreateNonSolid = 0xDB8; // 
                constexpr std::ptrdiff_t m_bIsOverrideProp = 0xDB9; // 
                constexpr std::ptrdiff_t m_iInitialGlowState = 0xDBC; // 
                constexpr std::ptrdiff_t m_nGlowRange = 0xDC0; // 
                constexpr std::ptrdiff_t m_nGlowRangeMin = 0xDC4; // 
                constexpr std::ptrdiff_t m_glowColor = 0xDC8; // 
                constexpr std::ptrdiff_t m_nGlowTeam = 0xDCC; // 
                constexpr std::ptrdiff_t m_iCachedFrameCount = 0xDD0; // 
                constexpr std::ptrdiff_t m_vecCachedRenderMins = 0xDD4; // 
                constexpr std::ptrdiff_t m_vecCachedRenderMaxs = 0xDE0; // 
            }
            // Parent: CCitadel_Item
            // Field count: 1
            namespace CCitadel_ArmorUpgrade_SpellShield {
                constexpr std::ptrdiff_t fl_mSpellShieldBreakTime = 0xC90; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 6
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityChargedTackleVData {
                constexpr std::ptrdiff_t m_ChargePreviewParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_ChargePrepareModifier = 0x1628; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ChargeActiveModifier = 0x1638; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BuffModifier = 0x1648; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DragModifier = 0x1658; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_strHitSound = 0x1668; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_SpilledBloodThinkerVData {
                constexpr std::ptrdiff_t m_SpilledBloodParticle = 0x608; // 
                constexpr std::ptrdiff_t m_flTickRate = 0x6E8; // 
                constexpr std::ptrdiff_t m_flHeight = 0x6EC; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Fervor {
            }
            // Parent: CCitadelModifier
            // Field count: 2
            namespace CCitadel_Modifier_AttachTarget {
                constexpr std::ptrdiff_t m_hTarget = 0xC0; // 
                constexpr std::ptrdiff_t m_vecOffset = 0xC4; // 
            }
            // Parent: CEntitySubclassVDataBase
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CDestructableBuildingVData {
                constexpr std::ptrdiff_t m_iMaxHealthFinal = 0x28; // 
                constexpr std::ptrdiff_t m_iMaxHealthGenerator = 0x2C; // 
                constexpr std::ptrdiff_t m_ObjectiveRegen = 0x30; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BackdoorBulletResistModifier = 0x40; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CEntityComponent
            // Field count: 10
            namespace CPropDataComponent {
                constexpr std::ptrdiff_t m_flDmgModBullet = 0x10; // 
                constexpr std::ptrdiff_t m_flDmgModClub = 0x14; // 
                constexpr std::ptrdiff_t m_flDmgModExplosive = 0x18; // 
                constexpr std::ptrdiff_t m_flDmgModFire = 0x1C; // 
                constexpr std::ptrdiff_t m_iszPhysicsDamageTableName = 0x20; // 
                constexpr std::ptrdiff_t m_iszBasePropData = 0x28; // 
                constexpr std::ptrdiff_t m_nInteractions = 0x30; // 
                constexpr std::ptrdiff_t m_bSpawnMotionDisabled = 0x34; // 
                constexpr std::ptrdiff_t m_nDisableTakePhysicsDamageSpawnFlag = 0x38; // 
                constexpr std::ptrdiff_t m_nMotionDisabledSpawnFlag = 0x3C; // 
            }
            // Parent: C_AI_CitadelNPC
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_bPlayingIdle (bool)
            // NetworkVarNames: m_bShieldActive (bool)
            namespace C_NPC_TrooperNeutral {
                constexpr std::ptrdiff_t m_bPlayingIdle = 0x14A0; // 
                constexpr std::ptrdiff_t m_bShieldActive = 0x14A1; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Chomp_LowHealth_GlowVData {
                constexpr std::ptrdiff_t m_strLocalStatusEffect = 0x608; // 
            }
            // Parent: CCitadel_Modifier_StunnedVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierGravityLassoEnemyVData {
                constexpr std::ptrdiff_t m_LassoEffect = 0x6E8; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Wraith_RapidFireVData {
                constexpr std::ptrdiff_t m_CastParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_TargetBuffSound = 0x1628; // 
                constexpr std::ptrdiff_t m_RapidFireModifier = 0x1638; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CBaseAnimGraph
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_hTouchedPlayeres (CHandle<C_BasePlayerPawn>)
            namespace C_ItemWeaponParts {
                constexpr std::ptrdiff_t m_hTouchedPlayeres = 0xB70; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityStackingDamageVData {
                constexpr std::ptrdiff_t m_StackingModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 2
            namespace CCitadel_Modifier_TechDamageProcWatcher {
                constexpr std::ptrdiff_t m_flNextProcTime = 0x168; // 
                constexpr std::ptrdiff_t m_shotProced = 0x16C; // 
            }
            // Parent: C_NPC_Boss_Tier2
            // Field count: 0
            namespace C_NPC_Boss_Tier2_Sidelanes {
            }
            // Parent: C_CitadelProjectile
            // Field count: 0
            namespace C_Citadel_Projectile_BloodBomb {
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Item_Discord_AuraVData_Enemy {
                constexpr std::ptrdiff_t m_strAreaEffectEnemy = 0x648; // 
                constexpr std::ptrdiff_t m_strAreaEffectFriendly = 0x728; // 
                constexpr std::ptrdiff_t m_strAreaEffectSelf = 0x808; // 
            }
            // Parent: C_BaseEntity
            // Field count: 8
            //
            // Metadata:
            // NetworkVarNames: m_iszStackName (string_t)
            // NetworkVarNames: m_iszOperatorName (string_t)
            // NetworkVarNames: m_iszOpvarName (string_t)
            // NetworkVarNames: m_vDistanceInnerMins (Vector)
            // NetworkVarNames: m_vDistanceInnerMaxs (Vector)
            // NetworkVarNames: m_vDistanceOuterMins (Vector)
            // NetworkVarNames: m_vDistanceOuterMaxs (Vector)
            // NetworkVarNames: m_nAABBDirection (int)
            namespace CCitadelSoundOpvarSetOBB {
                constexpr std::ptrdiff_t m_iszStackName = 0x570; // 
                constexpr std::ptrdiff_t m_iszOperatorName = 0x578; // 
                constexpr std::ptrdiff_t m_iszOpvarName = 0x580; // 
                constexpr std::ptrdiff_t m_vDistanceInnerMins = 0x588; // 
                constexpr std::ptrdiff_t m_vDistanceInnerMaxs = 0x594; // 
                constexpr std::ptrdiff_t m_vDistanceOuterMins = 0x5A0; // 
                constexpr std::ptrdiff_t m_vDistanceOuterMaxs = 0x5AC; // 
                constexpr std::ptrdiff_t m_nAABBDirection = 0x5B8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Slork_RagingCurrentVData {
                constexpr std::ptrdiff_t m_CountdownModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_WaterAuraParticle = 0x618; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 7
            //
            // Metadata:
            // NetworkVarNames: m_bActive (bool)
            // NetworkVarNames: m_hCurrentTarget (EHANDLE)
            // NetworkVarNames: m_vStartPosition (Vector)
            // NetworkVarNames: m_vDeparturePosition (Vector)
            // NetworkVarNames: m_flDepartureTime (CCitadelAutoScaledTime)
            // NetworkVarNames: m_flArrivalTime (CCitadelAutoScaledTime)
            namespace CCitadel_Ability_Nano_Pounce {
                constexpr std::ptrdiff_t m_bActive = 0xEE0; // 
                constexpr std::ptrdiff_t m_hCurrentTarget = 0xEE4; // 
                constexpr std::ptrdiff_t m_vStartPosition = 0xEE8; // 
                constexpr std::ptrdiff_t m_vDeparturePosition = 0xEF4; // 
                constexpr std::ptrdiff_t m_flDepartureTime = 0xF00; // 
                constexpr std::ptrdiff_t m_flArrivalTime = 0xF18; // 
                constexpr std::ptrdiff_t m_vLastKnownSafePos = 0xF30; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_AOERoot {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Wrecker_UltimateGrabEnemyVData {
                constexpr std::ptrdiff_t m_EnemyHeroStasisEffect = 0x608; // 
                constexpr std::ptrdiff_t m_EnemyHeroGrabEffect = 0x6E8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_Synth_Barrage_Amp {
            }
            // Parent: CitadelAbilityVData
            // Field count: 8
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityHornetLeapVData {
                constexpr std::ptrdiff_t m_flChannelingAirDrag = 0x1548; // 
                constexpr std::ptrdiff_t m_flChannelingMaxFallSpeed = 0x154C; // 
                constexpr std::ptrdiff_t m_flVerticalMoveSpeedPercent = 0x1550; // 
                constexpr std::ptrdiff_t m_flAirDrag = 0x1554; // 
                constexpr std::ptrdiff_t m_LeapModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DustParticle = 0x1568; // 
                constexpr std::ptrdiff_t m_TrailParticle = 0x1648; // 
                constexpr std::ptrdiff_t m_CastParticle = 0x1728; // 
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Item_AOE_Tech_ShieldVData {
                constexpr std::ptrdiff_t m_DurationModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_GameRules
            // Field count: 0
            namespace C_SingleplayRules {
            }
            // Parent: CBaseAnimGraph
            // Field count: 25
            namespace C_LocalTempEntity {
                constexpr std::ptrdiff_t flags = 0xB50; // 
                constexpr std::ptrdiff_t die = 0xB54; // 
                constexpr std::ptrdiff_t m_flFrameMax = 0xB58; // 
                constexpr std::ptrdiff_t x = 0xB5C; // 
                constexpr std::ptrdiff_t y = 0xB60; // 
                constexpr std::ptrdiff_t fadeSpeed = 0xB64; // 
                constexpr std::ptrdiff_t bounceFactor = 0xB68; // 
                constexpr std::ptrdiff_t hitSound = 0xB6C; // 
                constexpr std::ptrdiff_t priority = 0xB70; // 
                constexpr std::ptrdiff_t tentOffset = 0xB74; // 
                constexpr std::ptrdiff_t m_vecTempEntAngVelocity = 0xB80; // 
                constexpr std::ptrdiff_t tempent_renderamt = 0xB8C; // 
                constexpr std::ptrdiff_t m_vecNormal = 0xB90; // 
                constexpr std::ptrdiff_t m_flSpriteScale = 0xB9C; // 
                constexpr std::ptrdiff_t m_nFlickerFrame = 0xBA0; // 
                constexpr std::ptrdiff_t m_flFrameRate = 0xBA4; // 
                constexpr std::ptrdiff_t m_flFrame = 0xBA8; // 
                constexpr std::ptrdiff_t m_pszImpactEffect = 0xBB0; // 
                constexpr std::ptrdiff_t m_pszParticleEffect = 0xBB8; // 
                constexpr std::ptrdiff_t m_bParticleCollision = 0xBC0; // 
                constexpr std::ptrdiff_t m_iLastCollisionFrame = 0xBC4; // 
                constexpr std::ptrdiff_t m_vLastCollisionOrigin = 0xBC8; // 
                constexpr std::ptrdiff_t m_vecTempEntVelocity = 0xBD4; // 
                constexpr std::ptrdiff_t m_vecPrevAbsOrigin = 0xBE0; // 
                constexpr std::ptrdiff_t m_vecTempEntAcceleration = 0xBEC; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_Thumper_Bullet_Watcher {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Protection_Racket {
            }
            // Parent: CCitadelBaseYamatoAbility
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_flExplodeEndTime (GameTime_t)
            // NetworkVarNames: m_flBuffEndTime (GameTime_t)
            namespace CCitadel_Ability_InfinitySlash {
                constexpr std::ptrdiff_t m_flExplodeEndTime = 0xCF0; // 
                constexpr std::ptrdiff_t m_flBuffEndTime = 0xCF4; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadelModifierProjectilePitchingLoopSoundThinker {
            }
            // Parent: CEntitySubclassVDataBase
            // Field count: 8
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_HeroTestOrbSpawnerVData {
                constexpr std::ptrdiff_t m_iGoldValue = 0x28; // 
                constexpr std::ptrdiff_t m_flSpawnRate = 0x2C; // 
                constexpr std::ptrdiff_t m_flFirstSpawnTime = 0x30; // 
                constexpr std::ptrdiff_t m_hModel = 0x38; // 
                constexpr std::ptrdiff_t m_flModelScale = 0x118; // 
                constexpr std::ptrdiff_t m_flSpawnOffset = 0x11C; // 
                constexpr std::ptrdiff_t m_AmbientParticle = 0x120; // 
                constexpr std::ptrdiff_t m_SpawnParticle = 0x200; // 
            }
            // Parent: None
            // Field count: 2
            namespace C_EnvWindShared__WindAveEvent_t {
                constexpr std::ptrdiff_t m_flStartWindSpeed = 0x0; // 
                constexpr std::ptrdiff_t m_flAveWindSpeed = 0x4; // 
            }
            // Parent: C_LightDirectionalEntity
            // Field count: 0
            namespace C_LightEnvironmentEntity {
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_Tokamak_EnemySmokeAOE {
            }
            // Parent: CCitadelPlayerController
            // Field count: 0
            namespace CCitadelPreviewPlayerController {
            }
            // Parent: CAI_CitadelNPCVData
            // Field count: 41
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CNPC_Boss_Tier3VData {
                constexpr std::ptrdiff_t m_nPhase2Health = 0xF60; // 
                constexpr std::ptrdiff_t m_flEyeZOffset = 0xF64; // 
                constexpr std::ptrdiff_t m_flDefaultMoveSpeed = 0xF68; // 
                constexpr std::ptrdiff_t m_flNoShieldMoveSpeed = 0xF6C; // 
                constexpr std::ptrdiff_t m_flDyingMoveSpeed = 0xF70; // 
                constexpr std::ptrdiff_t m_flMovingToFinalPositionSpeed = 0xF74; // 
                constexpr std::ptrdiff_t m_DeathSmallExplosionParticle = 0xF78; // 
                constexpr std::ptrdiff_t m_DeathLargeExplosionParticle = 0x1058; // 
                constexpr std::ptrdiff_t m_WeakpointBrokenExplosionParticle = 0x1138; // 
                constexpr std::ptrdiff_t m_ChargeUpExplosionParticle = 0x1218; // 
                constexpr std::ptrdiff_t m_strWIPModelName = 0x12F8; // 
                constexpr std::ptrdiff_t m_DyingSmallExplosion = 0x13D8; // 
                constexpr std::ptrdiff_t m_AvatarKilledSound = 0x13E8; // 
                constexpr std::ptrdiff_t m_AvatarBecomePatronSound = 0x13F8; // 
                constexpr std::ptrdiff_t m_PatronLandedSound = 0x1408; // 
                constexpr std::ptrdiff_t m_PatronKilledSound = 0x1418; // 
                constexpr std::ptrdiff_t m_LaserSound = 0x1428; // 
                constexpr std::ptrdiff_t m_LaserBeamModifier = 0x1438; // 
                constexpr std::ptrdiff_t m_DyingModifier = 0x1448; // 
                constexpr std::ptrdiff_t m_VulnerableModifier = 0x1458; // 
                constexpr std::ptrdiff_t m_Phase1Modifier = 0x1468; // 
                constexpr std::ptrdiff_t m_Phase2Modifier = 0x1478; // 
                constexpr std::ptrdiff_t m_BackdoorProtection = 0x1488; // 
                constexpr std::ptrdiff_t m_ObjectiveRegen = 0x1498; // 
                constexpr std::ptrdiff_t m_LaserChargingParticle = 0x14A8; // 
                constexpr std::ptrdiff_t m_LaserBeamEffect = 0x1588; // 
                constexpr std::ptrdiff_t m_LaserPreviewEffect = 0x1668; // 
                constexpr std::ptrdiff_t m_LaserDamageEffect = 0x1748; // 
                constexpr std::ptrdiff_t m_flLaserTargetingZOffset = 0x1828; // 
                constexpr std::ptrdiff_t m_flLaserTrackingSpeed = 0x182C; // 
                constexpr std::ptrdiff_t m_flLaserTrackingMaxSpeed = 0x1830; // 
                constexpr std::ptrdiff_t m_flLaserCastingTrackSpeed = 0x1834; // 
                constexpr std::ptrdiff_t m_flLaserCastingTrackMaxSpeed = 0x1838; // 
                constexpr std::ptrdiff_t m_flLaserDPSToPlayers = 0x183C; // 
                constexpr std::ptrdiff_t m_flLaserDPSToNPCs = 0x1840; // 
                constexpr std::ptrdiff_t m_flNoShieldLaserTrackingSpeed = 0x1844; // 
                constexpr std::ptrdiff_t m_flNoShieldLaserTrackingMaxSpeed = 0x1848; // 
                constexpr std::ptrdiff_t m_flNoShieldLaserCastingTrackSpeed = 0x184C; // 
                constexpr std::ptrdiff_t m_flNoShieldLaserCastingTrackMaxSpeed = 0x1850; // 
                constexpr std::ptrdiff_t m_flNoShieldLaserDPSToPlayers = 0x1854; // 
                constexpr std::ptrdiff_t m_flNoShieldLaserDPSToNPCs = 0x1858; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 2
            namespace CCitadel_Ability_Hornet_Chain {
                constexpr std::ptrdiff_t m_vLaunchPosition = 0xC78; // 
                constexpr std::ptrdiff_t m_qLaunchAngle = 0xC84; // 
            }
            // Parent: CitadelItemVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CItemSingleTargetStunVData {
                constexpr std::ptrdiff_t m_StunDelayModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_CastParticle = 0x15A0; // 
            }
            // Parent: CCitadel_Item_TrackingProjectileApplyModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CItem_WitheringWhip_VData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1690; // 
            }
            // Parent: C_PointEntity
            // Field count: 9
            //
            // Metadata:
            // NetworkVarNames: m_bDisabled (bool)
            // NetworkVarNames: m_nResolutionX (int)
            // NetworkVarNames: m_nResolutionY (int)
            // NetworkVarNames: m_szLayoutFileName (string_t)
            // NetworkVarNames: m_RenderAttrName (string_t)
            // NetworkVarNames: m_TargetEntities (CHandle<C_BaseModelEntity>)
            // NetworkVarNames: m_nTargetChangeCount (int)
            // NetworkVarNames: m_vecCSSClasses (string_t)
            namespace CInfoOffscreenPanoramaTexture {
                constexpr std::ptrdiff_t m_bDisabled = 0x558; // 
                constexpr std::ptrdiff_t m_nResolutionX = 0x55C; // 
                constexpr std::ptrdiff_t m_nResolutionY = 0x560; // 
                constexpr std::ptrdiff_t m_szLayoutFileName = 0x568; // 
                constexpr std::ptrdiff_t m_RenderAttrName = 0x570; // 
                constexpr std::ptrdiff_t m_TargetEntities = 0x578; // 
                constexpr std::ptrdiff_t m_nTargetChangeCount = 0x590; // 
                constexpr std::ptrdiff_t m_vecCSSClasses = 0x598; // C_NetworkUtlVectorBase<CUtlSymbolLarge>
                constexpr std::ptrdiff_t m_bCheckCSSClasses = 0x710; // 
            }
            // Parent: C_BaseModelEntity
            // Field count: 7
            //
            // Metadata:
            // NetworkVarNames: m_Flags (uint8)
            // NetworkVarNames: m_LightStyle (uint8)
            // NetworkVarNames: m_Radius (float32)
            // NetworkVarNames: m_Exponent (int32)
            // NetworkVarNames: m_InnerAngle (float32)
            // NetworkVarNames: m_OuterAngle (float32)
            // NetworkVarNames: m_SpotRadius (float32)
            namespace C_DynamicLight {
                constexpr std::ptrdiff_t m_Flags = 0x830; // 
                constexpr std::ptrdiff_t m_LightStyle = 0x831; // 
                constexpr std::ptrdiff_t m_Radius = 0x834; // 
                constexpr std::ptrdiff_t m_Exponent = 0x838; // 
                constexpr std::ptrdiff_t m_InnerAngle = 0x83C; // 
                constexpr std::ptrdiff_t m_OuterAngle = 0x840; // 
                constexpr std::ptrdiff_t m_SpotRadius = 0x844; // 
            }
            // Parent: CCitadel_Ability_PrimaryWeaponVData
            // Field count: 10
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_PrimaryWeapon_SlorkVData {
                constexpr std::ptrdiff_t m_HitParticle = 0x1590; // 
                constexpr std::ptrdiff_t m_WeaponShapeParticle = 0x1670; // 
                constexpr std::ptrdiff_t m_WeaponRangeAssistParticle = 0x1750; // 
                constexpr std::ptrdiff_t m_nNumConePoints = 0x1830; // 
                constexpr std::ptrdiff_t m_flRoundPerSecond = 0x1834; // 
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1838; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_PoisonSprayerHitSound = 0x1848; // 
                constexpr std::ptrdiff_t m_WeaponLoopStartSound = 0x1858; // 
                constexpr std::ptrdiff_t m_WeaponLoopSound = 0x1868; // 
                constexpr std::ptrdiff_t m_WeaponLoopEndSound = 0x1878; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Nano_Shadow {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Bull_Leap_BoostingVData {
                constexpr std::ptrdiff_t m_BoostTrailParticle = 0x608; // 
            }
            // Parent: CitadelItemVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_ArmorUpgrade_CloakingDeviceActive_VData {
                constexpr std::ptrdiff_t m_AmbushModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_InvisModifier = 0x15A0; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_TeamRelativeParticle {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Rutger_CheatDeath_Activated {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Warden_HighAlert {
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ImmobilizeTrapDOT_ThinkerVData {
                constexpr std::ptrdiff_t m_GroundParticle = 0x608; // 
                constexpr std::ptrdiff_t m_flTickRate = 0x6E8; // 
                constexpr std::ptrdiff_t m_flHeight = 0x6EC; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 23
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityGuidedArrowVData {
                constexpr std::ptrdiff_t m_cameraCancelledTransitionBacktoArcher = 0x1548; // CitadelCameraOperationsSequence_t
                constexpr std::ptrdiff_t m_cameraExplodedTransitionBackToArcher = 0x15D0; // CitadelCameraOperationsSequence_t
                constexpr std::ptrdiff_t m_flCameraHoldAtExplosion = 0x1658; // 
                constexpr std::ptrdiff_t m_flFadeToBlackTime = 0x165C; // 
                constexpr std::ptrdiff_t m_SpectatingProjectileParticle = 0x1660; // 
                constexpr std::ptrdiff_t m_ExplosionParticle = 0x1740; // 
                constexpr std::ptrdiff_t m_GuidedArrowChannelParticle = 0x1820; // 
                constexpr std::ptrdiff_t m_ProjectileModel = 0x1900; // 
                constexpr std::ptrdiff_t m_ArrowOffsetX = 0x19E0; // 
                constexpr std::ptrdiff_t m_ArrowCameraDistance = 0x19E4; // 
                constexpr std::ptrdiff_t m_ArrowCameraHeightOffset = 0x19E8; // 
                constexpr std::ptrdiff_t m_ArrowInitialPitch = 0x19EC; // 
                constexpr std::ptrdiff_t m_GuidingModifier = 0x19F0; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1A00; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_KillCheckModifier = 0x1A10; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_strExplodeSound = 0x1A20; // 
                constexpr std::ptrdiff_t m_flTrackAmount = 0x1A30; // 
                constexpr std::ptrdiff_t m_flSpeedAccel = 0x1A34; // 
                constexpr std::ptrdiff_t m_flSpeedDeccel = 0x1A38; // 
                constexpr std::ptrdiff_t m_flBaseProjectileSpeed = 0x1A3C; // 
                constexpr std::ptrdiff_t m_flMaxProjectileSpeed = 0x1A40; // 
                constexpr std::ptrdiff_t m_flArrowModelTurnSpringStrength = 0x1A44; // 
                constexpr std::ptrdiff_t m_flKillCheckWindow = 0x1A48; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityPowerJumpVData {
                constexpr std::ptrdiff_t m_JumpParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_InAirModifier = 0x1628; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_PowerJumpModifier = 0x1638; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_ArmorUpgrade_PersonalRejuvenator {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_PayloadPusherAuraTarget {
            }
            // Parent: C_BaseModelEntity
            // Field count: 0
            namespace C_TriggerVolume {
            }
            // Parent: C_FuncBrush
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_EffectName (string_t)
            // NetworkVarNames: m_bState (bool)
            namespace C_FuncElectrifiedVolume {
                constexpr std::ptrdiff_t m_nAmbientEffect = 0x830; // 
                constexpr std::ptrdiff_t m_EffectName = 0x838; // 
                constexpr std::ptrdiff_t m_bState = 0x840; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Tokamak_Radiance {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelModifierCadenceGunSpikesVData {
                constexpr std::ptrdiff_t m_strSmallIconCssClassMax = 0x608; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Cadence_GrandFinale_BuffVData {
                constexpr std::ptrdiff_t m_BuildUpModifier = 0x608; // 
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x618; // 
                constexpr std::ptrdiff_t m_ExplodeSound = 0x6F8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Cadence_AnthemBuffVData {
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelYamatoBaseVData {
                constexpr std::ptrdiff_t m_flShadowFormSpeed = 0x1548; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_TangoTether_TetherReceiverVData {
                constexpr std::ptrdiff_t m_strAttackBuffParticle = 0x608; // 
                constexpr std::ptrdiff_t m_TetherSound = 0x6E8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_WreckerSalvageVData {
                constexpr std::ptrdiff_t m_SalvageBeam = 0x608; // 
                constexpr std::ptrdiff_t m_ConnectBeam = 0x6E8; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_hProjectile (CHandle<CCitadelProjectile>)
            namespace CCitadel_Ability_HatTrick {
                constexpr std::ptrdiff_t m_hProjectile = 0xC78; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Ricochet_ProcVData {
                constexpr std::ptrdiff_t m_RicochetTracerParticle = 0x638; // 
            }
            // Parent: CCitadelBaseAbilityServerOnly
            // Field count: 0
            namespace CCitadel_Ability_Weapon_BossTier2 {
            }
            // Parent: CCitadelModifier
            // Field count: 7
            namespace CCitadel_Modifier_Invis {
                constexpr std::ptrdiff_t m_bInvis = 0x248; // 
                constexpr std::ptrdiff_t m_flStartInvisTime = 0x24C; // 
                constexpr std::ptrdiff_t m_bFullyInvis = 0x250; // 
                constexpr std::ptrdiff_t m_flLastDamageTaken = 0x254; // 
                constexpr std::ptrdiff_t m_flLastSpotted = 0x258; // 
                constexpr std::ptrdiff_t m_nDetectionRangeRing = 0x25C; // 
                constexpr std::ptrdiff_t m_nFullInvisEffect = 0x260; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Mirage_SandPhantom_VData {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Mirage_Tornado_Caster {
            }
            // Parent: CCitadel_Modifier_Sleep
            // Field count: 0
            namespace CCitadel_Modifier_SleepBomb_Asleep {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Lockdown_BulletResist {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_WreckerUltimate_Invincible {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Lash {
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_BloodBombVData {
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_SpilledBloodModifier = 0x1628; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_strBloodSpillStatName = 0x1638; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_LongRangeSlowingTech_Proc {
            }
            // Parent: C_BaseEntity
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_flFadeStartDist (float32)
            // NetworkVarNames: m_flFadeEndDist (float32)
            namespace C_EnvDetailController {
                constexpr std::ptrdiff_t m_flFadeStartDist = 0x558; // 
                constexpr std::ptrdiff_t m_flFadeEndDist = 0x55C; // 
            }
            // Parent: CEntityInstance
            // Field count: 81
            //
            // Metadata:
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByUserGroup
            // MNetworkExcludeByUserGroup
            // MNetworkExcludeByUserGroup
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // NetworkVarNames: m_CBodyComponent (CBodyComponent::Storage_t)
            // NetworkVarNames: m_pModifierProp (CModifierProperty*)
            // NetworkVarNames: m_iMaxHealth (int32)
            // NetworkVarNames: m_iHealth (int32)
            // NetworkVarNames: m_lifeState (uint8)
            // NetworkVarNames: m_bTakesDamage (bool)
            // NetworkVarNames: m_nTakeDamageFlags (TakeDamageFlags_t)
            // NetworkVarNames: m_nPlatformType (EntityPlatformTypes_t)
            // NetworkVarNames: m_ubInterpolationFrame (uint8)
            // NetworkVarNames: m_nSubclassID (EntitySubclassID_t)
            // NetworkVarNames: m_flAnimTime (float32)
            // NetworkVarNames: m_flSimulationTime (float32)
            // NetworkVarNames: m_flCreateTime (GameTime_t)
            // NetworkVarNames: m_flSpeed (float)
            // NetworkVarNames: m_bClientSideRagdoll (bool)
            // NetworkVarNames: m_iTeamNum (uint8)
            // NetworkVarNames: m_spawnflags (uint32)
            // NetworkVarNames: m_nNextThinkTick (GameTick_t)
            // NetworkVarNames: m_fFlags (uint32)
            // NetworkVarNames: m_hEffectEntity (CHandle<CBaseEntity>)
            // NetworkVarNames: m_hOwnerEntity (CHandle<CBaseEntity>)
            // NetworkVarNames: m_MoveCollide (MoveCollide_t)
            // NetworkVarNames: m_MoveType (MoveType_t)
            // NetworkVarNames: m_flWaterLevel (float32)
            // NetworkVarNames: m_fEffects (uint32)
            // NetworkVarNames: m_hGroundEntity (CHandle<CBaseEntity>)
            // NetworkVarNames: m_nGroundBodyIndex (int)
            // NetworkVarNames: m_flFriction (float32)
            // NetworkVarNames: m_flElasticity (float32)
            // NetworkVarNames: m_flGravityScale (float32)
            // NetworkVarNames: m_flTimeScale (float32)
            // NetworkVarNames: m_bAnimatedEveryTick (bool)
            // NetworkVarNames: m_flNavIgnoreUntilTime (GameTime_t)
            namespace C_BaseEntity {
                constexpr std::ptrdiff_t m_CBodyComponent = 0x38; // 
                constexpr std::ptrdiff_t m_NetworkTransmitComponent = 0x40; // 
                constexpr std::ptrdiff_t m_nLastThinkTick = 0x320; // 
                constexpr std::ptrdiff_t m_pGameSceneNode = 0x328; // 
                constexpr std::ptrdiff_t m_pRenderComponent = 0x330; // 
                constexpr std::ptrdiff_t m_pCollision = 0x338; // 
                constexpr std::ptrdiff_t m_pModifierProp = 0x340; // 
                constexpr std::ptrdiff_t m_iMaxHealth = 0x348; // 
                constexpr std::ptrdiff_t m_iHealth = 0x34C; // 
                constexpr std::ptrdiff_t m_lifeState = 0x350; // 
                constexpr std::ptrdiff_t m_bTakesDamage = 0x351; // 
                constexpr std::ptrdiff_t m_nTakeDamageFlags = 0x358; // 
                constexpr std::ptrdiff_t m_nPlatformType = 0x360; // 
                constexpr std::ptrdiff_t m_ubInterpolationFrame = 0x361; // 
                constexpr std::ptrdiff_t m_hSceneObjectController = 0x364; // 
                constexpr std::ptrdiff_t m_nNoInterpolationTick = 0x368; // 
                constexpr std::ptrdiff_t m_nVisibilityNoInterpolationTick = 0x36C; // 
                constexpr std::ptrdiff_t m_flProxyRandomValue = 0x370; // 
                constexpr std::ptrdiff_t m_iEFlags = 0x374; // 
                constexpr std::ptrdiff_t m_nWaterType = 0x378; // 
                constexpr std::ptrdiff_t m_bInterpolateEvenWithNoModel = 0x379; // 
                constexpr std::ptrdiff_t m_bPredictionEligible = 0x37A; // 
                constexpr std::ptrdiff_t m_bApplyLayerMatchIDToModel = 0x37B; // 
                constexpr std::ptrdiff_t m_tokLayerMatchID = 0x37C; // 
                constexpr std::ptrdiff_t m_nSubclassID = 0x380; // 
                constexpr std::ptrdiff_t m_nSimulationTick = 0x390; // 
                constexpr std::ptrdiff_t m_iCurrentThinkContext = 0x394; // 
                constexpr std::ptrdiff_t m_aThinkFunctions = 0x398; // 
                constexpr std::ptrdiff_t m_bDisabledContextThinks = 0x3B0; // 
                constexpr std::ptrdiff_t m_flAnimTime = 0x3B4; // 
                constexpr std::ptrdiff_t m_flSimulationTime = 0x3B8; // 
                constexpr std::ptrdiff_t m_nSceneObjectOverrideFlags = 0x3BC; // 
                constexpr std::ptrdiff_t m_bHasSuccessfullyInterpolated = 0x3BD; // 
                constexpr std::ptrdiff_t m_bHasAddedVarsToInterpolation = 0x3BE; // 
                constexpr std::ptrdiff_t m_bRenderEvenWhenNotSuccessfullyInterpolated = 0x3BF; // 
                constexpr std::ptrdiff_t m_nInterpolationLatchDirtyFlags = 0x3C0; // 
                constexpr std::ptrdiff_t m_ListEntry = 0x3C8; // 
                constexpr std::ptrdiff_t m_flCreateTime = 0x3E0; // 
                constexpr std::ptrdiff_t m_flSpeed = 0x3E4; // 
                constexpr std::ptrdiff_t m_EntClientFlags = 0x3E8; // 
                constexpr std::ptrdiff_t m_bClientSideRagdoll = 0x3EA; // 
                constexpr std::ptrdiff_t m_iTeamNum = 0x3EB; // 
                constexpr std::ptrdiff_t m_spawnflags = 0x3EC; // 
                constexpr std::ptrdiff_t m_nNextThinkTick = 0x3F0; // 
                constexpr std::ptrdiff_t m_fFlags = 0x3F4; // 
                constexpr std::ptrdiff_t m_vecAbsVelocity = 0x3F8; // 
                constexpr std::ptrdiff_t m_vecVelocity = 0x408; // 
                constexpr std::ptrdiff_t m_hEffectEntity = 0x438; // 
                constexpr std::ptrdiff_t m_hOwnerEntity = 0x43C; // 
                constexpr std::ptrdiff_t m_MoveCollide = 0x440; // 
                constexpr std::ptrdiff_t m_MoveType = 0x441; // 
                constexpr std::ptrdiff_t m_nActualMoveType = 0x442; // 
                constexpr std::ptrdiff_t m_flWaterLevel = 0x444; // 
                constexpr std::ptrdiff_t m_fEffects = 0x448; // 
                constexpr std::ptrdiff_t m_hGroundEntity = 0x44C; // 
                constexpr std::ptrdiff_t m_nGroundBodyIndex = 0x450; // 
                constexpr std::ptrdiff_t m_flFriction = 0x454; // 
                constexpr std::ptrdiff_t m_flElasticity = 0x458; // 
                constexpr std::ptrdiff_t m_flGravityScale = 0x45C; // 
                constexpr std::ptrdiff_t m_flTimeScale = 0x460; // 
                constexpr std::ptrdiff_t m_bAnimatedEveryTick = 0x464; // 
                constexpr std::ptrdiff_t m_flNavIgnoreUntilTime = 0x468; // 
                constexpr std::ptrdiff_t m_hThink = 0x46C; // 
                constexpr std::ptrdiff_t m_fBBoxVisFlags = 0x478; // 
                constexpr std::ptrdiff_t m_bPredictable = 0x479; // 
                constexpr std::ptrdiff_t m_bRenderWithViewModels = 0x47A; // 
                constexpr std::ptrdiff_t m_nSplitUserPlayerPredictionSlot = 0x47C; // 
                constexpr std::ptrdiff_t m_nFirstPredictableCommand = 0x480; // 
                constexpr std::ptrdiff_t m_nLastPredictableCommand = 0x484; // 
                constexpr std::ptrdiff_t m_hOldMoveParent = 0x488; // 
                constexpr std::ptrdiff_t m_Particles = 0x490; // 
                constexpr std::ptrdiff_t m_vecPredictedScriptFloats = 0x4B8; // 
                constexpr std::ptrdiff_t m_vecPredictedScriptFloatIDs = 0x4D0; // 
                constexpr std::ptrdiff_t m_nNextScriptVarRecordID = 0x500; // 
                constexpr std::ptrdiff_t m_vecAngVelocity = 0x510; // 
                constexpr std::ptrdiff_t m_DataChangeEventRef = 0x51C; // 
                constexpr std::ptrdiff_t m_dependencies = 0x520; // 
                constexpr std::ptrdiff_t m_nCreationTick = 0x538; // 
                constexpr std::ptrdiff_t m_bAnimTimeChanged = 0x545; // 
                constexpr std::ptrdiff_t m_bSimulationTimeChanged = 0x546; // 
                constexpr std::ptrdiff_t m_sUniqueHammerID = 0x550; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 7
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Mirage_SandPhantom_WhirlwindEvasion_VData {
                constexpr std::ptrdiff_t m_AttackerHitFx = 0x608; // 
                constexpr std::ptrdiff_t m_ImpactParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_playerBuffSelf = 0x7C8; // 
                constexpr std::ptrdiff_t m_playerBuffEnemy = 0x8A8; // 
                constexpr std::ptrdiff_t m_ReflectedBulletTracerParticle = 0x988; // 
                constexpr std::ptrdiff_t m_strAttackerHitSound = 0xA68; // 
                constexpr std::ptrdiff_t m_strVictimHitSound = 0xA78; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Cadence_SilenceContraptionsDebuff {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Spinning_Blade {
            }
            // Parent: CCitadelModifierVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierAirLiftExplodeTargetVData {
                constexpr std::ptrdiff_t m_strSilenceTargetSound = 0x608; // 
                constexpr std::ptrdiff_t m_SilenceModifier = 0x618; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_SlowModifier = 0x628; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BulletResistModifier = 0x638; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_DeathTax {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_StaticCharge {
            }
            // Parent: CitadelItemVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_ArmorUpgrade_DebuffReducerVData {
                constexpr std::ptrdiff_t m_DebuffReducedParticle = 0x1590; // 
                constexpr std::ptrdiff_t m_PurgeCastParticle = 0x1670; // 
                constexpr std::ptrdiff_t m_MoveSpeedModifier = 0x1750; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CScaleFunctionBase
            // Field count: 0
            namespace CScaleFunctionAbilityProperty_TechDamage {
            }
            // Parent: None
            // Field count: 11
            //
            // Metadata:
            // NetworkVarNames: m_nameStringableIndex (int32)
            namespace CEntityIdentity {
                constexpr std::ptrdiff_t m_nameStringableIndex = 0x14; // 
                constexpr std::ptrdiff_t m_name = 0x18; // 
                constexpr std::ptrdiff_t m_designerName = 0x20; // 
                constexpr std::ptrdiff_t m_flags = 0x30; // 
                constexpr std::ptrdiff_t m_worldGroupId = 0x38; // 
                constexpr std::ptrdiff_t m_fDataObjectTypes = 0x3C; // 
                constexpr std::ptrdiff_t m_PathIndex = 0x40; // 
                constexpr std::ptrdiff_t m_pPrev = 0x58; // 
                constexpr std::ptrdiff_t m_pNext = 0x60; // 
                constexpr std::ptrdiff_t m_pPrevByClass = 0x68; // 
                constexpr std::ptrdiff_t m_pNextByClass = 0x70; // 
            }
            // Parent: CCitadelAnimatingModelEntity
            // Field count: 5
            //
            // Metadata:
            // NetworkVarNames: m_flUpFactor (float)
            // NetworkVarNames: m_flBounceVelocity (float)
            namespace C_Citadel_Bounce_Pad {
                constexpr std::ptrdiff_t m_flUpFactor = 0xB58; // 
                constexpr std::ptrdiff_t m_flBounceVelocity = 0xB5C; // 
                constexpr std::ptrdiff_t m_flBarrelBounceVelocity = 0xB60; // 
                constexpr std::ptrdiff_t m_flBarrelUpFactor = 0xB64; // 
                constexpr std::ptrdiff_t m_bSpeedOnLand = 0xB68; // 
            }
            // Parent: C_BreakableProp
            // Field count: 1
            //
            // Metadata:
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByUserGroup
            // MNetworkExcludeByName
            // MNetworkExcludeByUserGroup
            // MNetworkIncludeByName
            // NetworkVarNames: m_bAwake (bool)
            namespace C_PhysicsProp {
                constexpr std::ptrdiff_t m_bAwake = 0xCD8; // 
            }
            // Parent: CBaseProp
            // Field count: 29
            //
            // Metadata:
            // NetworkVarNames: m_CPropDataComponent (CPropDataComponent::Storage_t)
            // NetworkVarNames: m_noGhostCollision (bool)
            namespace C_BreakableProp {
                constexpr std::ptrdiff_t m_CPropDataComponent = 0xB90; // 
                constexpr std::ptrdiff_t m_OnBreak = 0xBD0; // 
                constexpr std::ptrdiff_t m_OnHealthChanged = 0xBF8; // CEntityOutputTemplate<float32>
                constexpr std::ptrdiff_t m_OnTakeDamage = 0xC20; // 
                constexpr std::ptrdiff_t m_impactEnergyScale = 0xC48; // 
                constexpr std::ptrdiff_t m_iMinHealthDmg = 0xC4C; // 
                constexpr std::ptrdiff_t m_flPressureDelay = 0xC50; // 
                constexpr std::ptrdiff_t m_flDefBurstScale = 0xC54; // 
                constexpr std::ptrdiff_t m_vDefBurstOffset = 0xC58; // 
                constexpr std::ptrdiff_t m_hBreaker = 0xC64; // 
                constexpr std::ptrdiff_t m_PerformanceMode = 0xC68; // 
                constexpr std::ptrdiff_t m_flPreventDamageBeforeTime = 0xC6C; // 
                constexpr std::ptrdiff_t m_BreakableContentsType = 0xC70; // 
                constexpr std::ptrdiff_t m_strBreakableContentsPropGroupOverride = 0xC78; // 
                constexpr std::ptrdiff_t m_strBreakableContentsParticleOverride = 0xC80; // 
                constexpr std::ptrdiff_t m_bHasBreakPiecesOrCommands = 0xC88; // 
                constexpr std::ptrdiff_t m_explodeDamage = 0xC8C; // 
                constexpr std::ptrdiff_t m_explodeRadius = 0xC90; // 
                constexpr std::ptrdiff_t m_explosionDelay = 0xC98; // 
                constexpr std::ptrdiff_t m_explosionBuildupSound = 0xCA0; // 
                constexpr std::ptrdiff_t m_explosionCustomEffect = 0xCA8; // 
                constexpr std::ptrdiff_t m_explosionCustomSound = 0xCB0; // 
                constexpr std::ptrdiff_t m_explosionModifier = 0xCB8; // 
                constexpr std::ptrdiff_t m_hPhysicsAttacker = 0xCC0; // 
                constexpr std::ptrdiff_t m_flLastPhysicsInfluenceTime = 0xCC4; // 
                constexpr std::ptrdiff_t m_flDefaultFadeScale = 0xCC8; // 
                constexpr std::ptrdiff_t m_hLastAttacker = 0xCCC; // 
                constexpr std::ptrdiff_t m_hFlareEnt = 0xCD0; // 
                constexpr std::ptrdiff_t m_noGhostCollision = 0xCD4; // 
            }
            // Parent: CCitadelBaseLockonAbility
            // Field count: 4
            //
            // Metadata:
            // NetworkVarNames: m_EGrappleState (ELashGrappleState)
            // NetworkVarNames: m_flStateEnterTime (GameTime_t)
            // NetworkVarNames: m_flNextStateTime (GameTime_t)
            // NetworkVarNames: m_flBoostEndTime (GameTime_t)
            namespace CCitadel_Ability_Lash_Ultimate {
                constexpr std::ptrdiff_t m_EGrappleState = 0xDF2; // 
                constexpr std::ptrdiff_t m_flStateEnterTime = 0xDF4; // 
                constexpr std::ptrdiff_t m_flNextStateTime = 0xDF8; // 
                constexpr std::ptrdiff_t m_flBoostEndTime = 0xDFC; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelModifierItemPickupTimerVData {
                constexpr std::ptrdiff_t m_TimerToSilence = 0x608; // 
                constexpr std::ptrdiff_t m_SilenceDuration = 0x60C; // 
                constexpr std::ptrdiff_t m_SilenceModifier = 0x610; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Rutger_Pulse_VData {
                constexpr std::ptrdiff_t m_AuraModifier = 0x1548; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityThumper1VData {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Uppercut_Buff {
            }
            // Parent: CitadelAbilityVData
            // Field count: 37
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityViscousBowlingVData {
                constexpr std::ptrdiff_t m_TransformStartFx = 0x1548; // 
                constexpr std::ptrdiff_t m_ExplodeFX = 0x1628; // 
                constexpr std::ptrdiff_t m_WallImpactFx = 0x1708; // 
                constexpr std::ptrdiff_t m_BallTrailFx = 0x17E8; // 
                constexpr std::ptrdiff_t m_GroundImpactParticle = 0x18C8; // 
                constexpr std::ptrdiff_t m_JumpParticle = 0x19A8; // 
                constexpr std::ptrdiff_t m_DirectionParticle = 0x1A88; // 
                constexpr std::ptrdiff_t m_flVerticalCameraOffsetLerpTime = 0x1B68; // 
                constexpr std::ptrdiff_t m_flVerticalCameraOffsetBias = 0x1B6C; // 
                constexpr std::ptrdiff_t m_flVerticalCameraOffset = 0x1B70; // 
                constexpr std::ptrdiff_t m_flDistanceCameraOffsetLerpTime = 0x1B74; // 
                constexpr std::ptrdiff_t m_flDistanceCameraOffsetBias = 0x1B78; // 
                constexpr std::ptrdiff_t m_flDistanceCameraOffset = 0x1B7C; // 
                constexpr std::ptrdiff_t m_strPopGraphParamter = 0x1B80; // 
                constexpr std::ptrdiff_t m_BallJumpSound = 0x1B88; // 
                constexpr std::ptrdiff_t m_EnterBallSound = 0x1B98; // 
                constexpr std::ptrdiff_t m_BallLoopSound = 0x1BA8; // 
                constexpr std::ptrdiff_t m_ExitBallSound = 0x1BB8; // 
                constexpr std::ptrdiff_t m_WallImpactSound = 0x1BC8; // 
                constexpr std::ptrdiff_t m_PlayerImpactSound = 0x1BD8; // 
                constexpr std::ptrdiff_t m_ImpactModifier = 0x1BE8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DamagePreventionModifier = 0x1BF8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_RollingModifier = 0x1C08; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_flTransformToBallTime = 0x1C18; // 
                constexpr std::ptrdiff_t m_flTransformFromBallTime = 0x1C1C; // 
                constexpr std::ptrdiff_t m_flAirTurnRatio = 0x1C20; // 
                constexpr std::ptrdiff_t m_flWallTurnRatioMax = 0x1C24; // 
                constexpr std::ptrdiff_t m_flWallTurnRatioMin = 0x1C28; // 
                constexpr std::ptrdiff_t m_flTurnRatio = 0x1C2C; // 
                constexpr std::ptrdiff_t m_flDefaultBallSpeed = 0x1C30; // 
                constexpr std::ptrdiff_t m_flFastBallSpeed = 0x1C34; // 
                constexpr std::ptrdiff_t m_flSpeedAccel = 0x1C38; // 
                constexpr std::ptrdiff_t m_flSpeedDeccel = 0x1C3C; // 
                constexpr std::ptrdiff_t m_flElasticity = 0x1C40; // 
                constexpr std::ptrdiff_t m_flWallCheckGroundOffset = 0x1C44; // 
                constexpr std::ptrdiff_t m_flWallPauseTime = 0x1C48; // 
                constexpr std::ptrdiff_t m_flWallAngleMin = 0x1C4C; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Nearby_Enemy_Boost {
            }
            // Parent: CCitadelModifierVData
            // Field count: 6
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Base_BuildupVData {
                constexpr std::ptrdiff_t m_bUseBaseWeaponCycleTimeForDelay = 0x608; // 
                constexpr std::ptrdiff_t m_flCycleTimeDelayAdd = 0x60C; // 
                constexpr std::ptrdiff_t m_flBuildUpDecayDelay = 0x610; // 
                constexpr std::ptrdiff_t m_eBuildupMode = 0x614; // 
                constexpr std::ptrdiff_t m_bBuildupAffectedByEffectiveness = 0x618; // 
                constexpr std::ptrdiff_t m_bPassBuildupEffectivenessToFillModifier = 0x619; // 
            }
            // Parent: C_CitadelItemPickup
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_CCitadelAbilityComponent (CCitadelAbilityComponent::Storage_t)
            // NetworkVarNames: m_bPickedUp (bool)
            namespace CCitadelItemPickupRejuv {
                constexpr std::ptrdiff_t m_CCitadelAbilityComponent = 0xB88; // 
                constexpr std::ptrdiff_t m_bPickedUp = 0xD28; // 
            }
            // Parent: C_BaseToggle
            // Field count: 0
            //
            // Metadata:
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkOverride
            namespace C_FuncMoveLinear {
            }
            // Parent: C_BaseModelEntity
            // Field count: 24
            //
            // Metadata:
            // MNetworkIncludeByUserGroup
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkIncludeByName
            // MNetworkOverride
            // NetworkVarNames: m_flFrameRate (float32)
            // NetworkVarNames: m_flHDRColorScale (float32)
            // NetworkVarNames: m_nNumBeamEnts (uint8)
            // NetworkVarNames: m_hBaseMaterial (HMaterialStrong)
            // NetworkVarNames: m_nHaloIndex (HMaterialStrong)
            // NetworkVarNames: m_nBeamType (BeamType_t)
            // NetworkVarNames: m_nBeamFlags (uint32)
            // NetworkVarNames: m_hAttachEntity (CHandle<CBaseEntity>)
            // NetworkVarNames: m_nAttachIndex (AttachmentHandle_t)
            // NetworkVarNames: m_fWidth (float32)
            // NetworkVarNames: m_fEndWidth (float32)
            // NetworkVarNames: m_fFadeLength (float32)
            // NetworkVarNames: m_fHaloScale (float32)
            // NetworkVarNames: m_fAmplitude (float32)
            // NetworkVarNames: m_fStartFrame (float32)
            // NetworkVarNames: m_fSpeed (float32)
            // NetworkVarNames: m_flFrame (float32)
            // NetworkVarNames: m_nClipStyle (BeamClipStyle_t)
            // NetworkVarNames: m_bTurnedOff (bool)
            // NetworkVarNames: m_vecEndPos (Vector)
            namespace C_Beam {
                constexpr std::ptrdiff_t m_flFrameRate = 0x830; // 
                constexpr std::ptrdiff_t m_flHDRColorScale = 0x834; // 
                constexpr std::ptrdiff_t m_flFireTime = 0x838; // 
                constexpr std::ptrdiff_t m_flDamage = 0x83C; // 
                constexpr std::ptrdiff_t m_nNumBeamEnts = 0x840; // 
                constexpr std::ptrdiff_t m_queryHandleHalo = 0x844; // 
                constexpr std::ptrdiff_t m_hBaseMaterial = 0x868; // CStrongHandle<InfoForResourceTypeIMaterial2>
                constexpr std::ptrdiff_t m_nHaloIndex = 0x870; // CStrongHandle<InfoForResourceTypeIMaterial2>
                constexpr std::ptrdiff_t m_nBeamType = 0x878; // 
                constexpr std::ptrdiff_t m_nBeamFlags = 0x87C; // 
                constexpr std::ptrdiff_t m_hAttachEntity = 0x880; // 
                constexpr std::ptrdiff_t m_nAttachIndex = 0x8A8; // 
                constexpr std::ptrdiff_t m_fWidth = 0x8B4; // 
                constexpr std::ptrdiff_t m_fEndWidth = 0x8B8; // 
                constexpr std::ptrdiff_t m_fFadeLength = 0x8BC; // 
                constexpr std::ptrdiff_t m_fHaloScale = 0x8C0; // 
                constexpr std::ptrdiff_t m_fAmplitude = 0x8C4; // 
                constexpr std::ptrdiff_t m_fStartFrame = 0x8C8; // 
                constexpr std::ptrdiff_t m_fSpeed = 0x8CC; // 
                constexpr std::ptrdiff_t m_flFrame = 0x8D0; // 
                constexpr std::ptrdiff_t m_nClipStyle = 0x8D4; // 
                constexpr std::ptrdiff_t m_bTurnedOff = 0x8D8; // 
                constexpr std::ptrdiff_t m_vecEndPos = 0x8DC; // 
                constexpr std::ptrdiff_t m_hEndEntity = 0x8E8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ZiplineBoostVData {
                constexpr std::ptrdiff_t m_flRampUpTime = 0x608; // 
                constexpr std::ptrdiff_t m_flPercentageSpeedIncrease = 0x60C; // 
                constexpr std::ptrdiff_t m_cameraSequenceStartBoost = 0x610; // CitadelCameraOperationsSequence_t
            }
            // Parent: CBaseAnimGraph
            // Field count: 0
            namespace C_ItemAmmo {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Slork_Scald {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_LashGrappleTarget {
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Snipe_Glow {
                constexpr std::ptrdiff_t m_nFXIndex = 0xC0; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_TechOverflowProcWatcher {
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilitySlorkChompVData {
                constexpr std::ptrdiff_t m_ChompHobbled = 0x1548; // 
                constexpr std::ptrdiff_t m_ChompGrapple = 0x1558; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Tokamak_HeatSinks {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 6
            //
            // Metadata:
            // NetworkVarNames: m_bFlying (bool)
            // NetworkVarNames: m_bFlyingStarted (bool)
            // NetworkVarNames: m_bIsGrabbing (bool)
            // NetworkVarNames: m_bIsHoldingBomb (bool)
            // NetworkVarNames: m_flCurrentSpeed (float)
            namespace CCitadel_Ability_Tengu_AirLift {
                constexpr std::ptrdiff_t m_nHoldBombEffect = 0xC78; // 
                constexpr std::ptrdiff_t m_bFlying = 0xE78; // 
                constexpr std::ptrdiff_t m_bFlyingStarted = 0xE79; // 
                constexpr std::ptrdiff_t m_bIsGrabbing = 0xE7A; // 
                constexpr std::ptrdiff_t m_bIsHoldingBomb = 0xE7B; // 
                constexpr std::ptrdiff_t m_flCurrentSpeed = 0xE7C; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Nikuman {
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityChronoSwapVData {
                constexpr std::ptrdiff_t m_BubbleMoveModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_strSwapStarted = 0x1558; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Frenzy_MoveSpeed {
                constexpr std::ptrdiff_t m_flMoveSpeedPerStack = 0xC0; // 
            }
            // Parent: C_BaseEntity
            // Field count: 4
            //
            // Metadata:
            // NetworkVarNames: m_flCameraDist (float)
            // NetworkVarNames: m_flCameraPitch (float)
            // NetworkVarNames: m_flCameraHeight (float)
            // NetworkVarNames: m_hTarget (EHANDLE)
            namespace CCitadelSpectateDirectedCamera {
                constexpr std::ptrdiff_t m_flCameraDist = 0x55C; // 
                constexpr std::ptrdiff_t m_flCameraPitch = 0x560; // 
                constexpr std::ptrdiff_t m_flCameraHeight = 0x564; // 
                constexpr std::ptrdiff_t m_hTarget = 0x568; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 9
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityExplosiveBarrelVData {
                constexpr std::ptrdiff_t m_BarrelExplodeParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_MirvExplodeParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_BarrelBurnParticle = 0x1708; // 
                constexpr std::ptrdiff_t m_strExplodeSound = 0x17E8; // 
                constexpr std::ptrdiff_t m_strMirvExplodeSound = 0x17F8; // 
                constexpr std::ptrdiff_t m_strRiccochetSound = 0x1808; // 
                constexpr std::ptrdiff_t m_strBarrelSoundLp = 0x1818; // 
                constexpr std::ptrdiff_t m_strBarrelLaunchSound = 0x1828; // 
                constexpr std::ptrdiff_t m_strBarrelMeleedSound = 0x1838; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 7
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_MobileResupplyVData {
                constexpr std::ptrdiff_t m_flResupplyForceScale = 0x1548; // 
                constexpr std::ptrdiff_t m_flResupplyUp = 0x154C; // 
                constexpr std::ptrdiff_t m_strKilledSound = 0x1550; // 
                constexpr std::ptrdiff_t m_AuraModifier = 0x1560; // 
                constexpr std::ptrdiff_t m_DispenserModel = 0x1570; // 
                constexpr std::ptrdiff_t m_SprayParticle = 0x1650; // 
                constexpr std::ptrdiff_t m_DestroyedParticle = 0x1730; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Fervor_VData {
                constexpr std::ptrdiff_t m_FervorParticle = 0x608; // 
                constexpr std::ptrdiff_t m_BonusesModifier = 0x6E8; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_BaseShield
            // Field count: 0
            namespace CCitadel_Modifier_RegeneratingBulletShield {
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_WeaponPowerForHealth {
                constexpr std::ptrdiff_t m_flHealthDrained = 0xC0; // 
            }
            // Parent: C_DynamicProp
            // Field count: 0
            namespace C_DynamicPropAlias_prop_dynamic_override {
            }
            // Parent: CCitadel_Item_Bubble
            // Field count: 0
            namespace CCitadel_Item_Stasis_Bomb {
            }
            // Parent: C_PointEntity
            // Field count: 9
            //
            // Metadata:
            // NetworkVarNames: m_iszOverlayNames (string_t)
            // NetworkVarNames: m_flOverlayTimes (float32)
            // NetworkVarNames: m_flStartTime (GameTime_t)
            // NetworkVarNames: m_iDesiredOverlay (int32)
            // NetworkVarNames: m_bIsActive (bool)
            namespace C_EnvScreenOverlay {
                constexpr std::ptrdiff_t m_iszOverlayNames = 0x558; // 
                constexpr std::ptrdiff_t m_flOverlayTimes = 0x5A8; // 
                constexpr std::ptrdiff_t m_flStartTime = 0x5D0; // 
                constexpr std::ptrdiff_t m_iDesiredOverlay = 0x5D4; // 
                constexpr std::ptrdiff_t m_bIsActive = 0x5D8; // 
                constexpr std::ptrdiff_t m_bWasActive = 0x5D9; // 
                constexpr std::ptrdiff_t m_iCachedDesiredOverlay = 0x5DC; // 
                constexpr std::ptrdiff_t m_iCurrentOverlay = 0x5E0; // 
                constexpr std::ptrdiff_t m_flCurrentOverlayTime = 0x5E4; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Mirage_FireScarabs_HealthLoss_VData {
                constexpr std::ptrdiff_t m_SiphonParticle = 0x608; // 
                constexpr std::ptrdiff_t m_HealModifier = 0x6E8; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelAbilityVData
            // Field count: 5
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityTokamakHeatSinksInherentVData {
                constexpr std::ptrdiff_t m_HotTracerParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_HotWeaponFxParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_strHotWeaponShootSound = 0x1708; // 
                constexpr std::ptrdiff_t m_strOverheatRed = 0x1718; // 
                constexpr std::ptrdiff_t m_strOverheatFull = 0x1728; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 12
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_TangoTether_TetherVData {
                constexpr std::ptrdiff_t m_TetherSound = 0x608; // 
                constexpr std::ptrdiff_t m_HealSound = 0x618; // 
                constexpr std::ptrdiff_t m_HitIndicator = 0x628; // 
                constexpr std::ptrdiff_t m_GrappleHitSound = 0x638; // 
                constexpr std::ptrdiff_t m_BuffModifier = 0x648; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DisconnectingModifier = 0x658; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DisconnectedModifier = 0x668; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_LockedTargetModifier = 0x678; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_flMinConnectTime = 0x688; // 
                constexpr std::ptrdiff_t m_flDisconnectDistanceBuffer = 0x68C; // 
                constexpr std::ptrdiff_t m_flCandidateCloserDistance = 0x690; // 
                constexpr std::ptrdiff_t m_flTargetAwayDistance = 0x694; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 9
            //
            // Metadata:
            // NetworkVarNames: m_hProjectile (EHANDLE)
            // NetworkVarNames: m_flArrowSpeed (float)
            // NetworkVarNames: m_flSnapAnglesBackTime (GameTime_t)
            namespace CCitadel_Ability_WreckerTeleport {
                constexpr std::ptrdiff_t m_hProjectile = 0xC80; // 
                constexpr std::ptrdiff_t m_flArrowSpeed = 0xC84; // 
                constexpr std::ptrdiff_t m_flSnapAnglesBackTime = 0xC88; // 
                constexpr std::ptrdiff_t m_flCastTimeDamage = 0xC8C; // 
                constexpr std::ptrdiff_t m_flCastTime = 0xC90; // 
                constexpr std::ptrdiff_t m_bNeedsExplosion = 0xC94; // 
                constexpr std::ptrdiff_t m_vProjectileRemovedOrigin = 0xC98; // 
                constexpr std::ptrdiff_t m_angCasterAnglesAtCastTime = 0xCA4; // 
                constexpr std::ptrdiff_t m_flTravelDistance = 0xCB0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_SnipeGlowVData {
                constexpr std::ptrdiff_t m_GlowParticle = 0x608; // 
            }
            // Parent: CCitadelModifier
            // Field count: 5
            namespace CCitadel_Modifier_ChargeDragEnemy {
                constexpr std::ptrdiff_t m_qRelativeOffset = 0xC0; // 
                constexpr std::ptrdiff_t m_flRelativeDist = 0xCC; // 
                constexpr std::ptrdiff_t m_flMaxDist = 0xD0; // 
                constexpr std::ptrdiff_t m_vecOffsetDir = 0xD4; // 
                constexpr std::ptrdiff_t m_vecStartPosition = 0xE0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 2
            namespace CCitadel_Modifier_Containment_Victim {
                constexpr std::ptrdiff_t m_flTetherRadius = 0xC0; // 
                constexpr std::ptrdiff_t m_vecOrigin = 0xC4; // 
            }
            // Parent: CBaseAnimGraph
            // Field count: 5
            namespace CCitadel_GrandFinaleStage {
                constexpr std::ptrdiff_t m_vStartPos = 0xB50; // 
                constexpr std::ptrdiff_t m_vEndPos = 0xB5C; // 
                constexpr std::ptrdiff_t m_flStartEmitTime = 0xB68; // 
                constexpr std::ptrdiff_t m_flEndEmitTime = 0xB6C; // 
                constexpr std::ptrdiff_t m_nTouchCount = 0xB70; // 
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_VacuumAura {
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadelModifierAura_Default {
            }
            // Parent: C_ModelPointEntity
            // Field count: 12
            //
            // Metadata:
            // NetworkVarNames: m_messageText (char)
            // NetworkVarNames: m_FontName (char)
            // NetworkVarNames: m_bEnabled (bool)
            // NetworkVarNames: m_bFullbright (bool)
            // NetworkVarNames: m_flWorldUnitsPerPx (float)
            // NetworkVarNames: m_flFontSize (float)
            // NetworkVarNames: m_flDepthOffset (float)
            // NetworkVarNames: m_Color (Color)
            // NetworkVarNames: m_nJustifyHorizontal (PointWorldTextJustifyHorizontal_t)
            // NetworkVarNames: m_nJustifyVertical (PointWorldTextJustifyVertical_t)
            // NetworkVarNames: m_nReorientMode (PointWorldTextReorientMode_t)
            namespace C_PointWorldText {
                constexpr std::ptrdiff_t m_bForceRecreateNextUpdate = 0x838; // 
                constexpr std::ptrdiff_t m_messageText = 0x848; // 
                constexpr std::ptrdiff_t m_FontName = 0xA48; // 
                constexpr std::ptrdiff_t m_bEnabled = 0xA88; // 
                constexpr std::ptrdiff_t m_bFullbright = 0xA89; // 
                constexpr std::ptrdiff_t m_flWorldUnitsPerPx = 0xA8C; // 
                constexpr std::ptrdiff_t m_flFontSize = 0xA90; // 
                constexpr std::ptrdiff_t m_flDepthOffset = 0xA94; // 
                constexpr std::ptrdiff_t m_Color = 0xA98; // 
                constexpr std::ptrdiff_t m_nJustifyHorizontal = 0xA9C; // 
                constexpr std::ptrdiff_t m_nJustifyVertical = 0xAA0; // 
                constexpr std::ptrdiff_t m_nReorientMode = 0xAA4; // 
            }
            // Parent: C_BaseEntity
            // Field count: 0
            namespace C_CitadelPortraitWorldCallbackHandler {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Wraith_RapidFire {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ShieldImpactVData {
                constexpr std::ptrdiff_t m_ShieldBreakParticle = 0x608; // 
                constexpr std::ptrdiff_t m_ShieldBreakSound = 0x6E8; // 
            }
            // Parent: CEntityComponent
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_nHeroID (HeroID_t)
            // NetworkVarNames: m_nHeroLoading (HeroID_t)
            namespace CCitadelHeroComponent {
                constexpr std::ptrdiff_t m_nHeroID = 0x14; // 
                constexpr std::ptrdiff_t m_nHeroLoading = 0x18; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_Charge_Mastery {
            }
            // Parent: CCitadel_Modifier_Invis
            // Field count: 0
            namespace CCitadel_Modifier_Ult_Shadow {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Infuser_VData {
                constexpr std::ptrdiff_t m_BuffParticle = 0x608; // 
            }
            // Parent: None
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_flTime (GameTime_t)
            namespace CCitadelAutoScaledTime {
                constexpr std::ptrdiff_t m_flTime = 0x8; // 
            }
            // Parent: CAI_CitadelNPCVData
            // Field count: 8
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CNPC_MidBossVData {
                constexpr std::ptrdiff_t m_iStartingHealth = 0xF60; // 
                constexpr std::ptrdiff_t m_iHealthGainPerMinute = 0xF64; // 
                constexpr std::ptrdiff_t m_flAggroTime = 0xF68; // 
                constexpr std::ptrdiff_t m_DyingSmallExplosion = 0xF70; // 
                constexpr std::ptrdiff_t m_DyingFinalExplosion = 0x1050; // 
                constexpr std::ptrdiff_t m_flDyingDuration = 0x1130; // 
                constexpr std::ptrdiff_t m_KnockbackAura = 0x1138; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_AggroEnemy = 0x1148; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierAuraVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Thumper_PullAOE_VData {
                constexpr std::ptrdiff_t m_AuraParticle = 0x648; // 
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_Nikuman {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_TechUpgrade_Infuser {
            }
            // Parent: CitadelAbilityVData
            // Field count: 11
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Tengu_StoneFormVData {
                constexpr std::ptrdiff_t m_CastParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_ImpactParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_StoneFormParticle = 0x1708; // 
                constexpr std::ptrdiff_t m_CastTargetSound = 0x17E8; // 
                constexpr std::ptrdiff_t m_strImpactSound = 0x17F8; // 
                constexpr std::ptrdiff_t m_strFallCollideImpactSound = 0x1808; // 
                constexpr std::ptrdiff_t m_DragModifier = 0x1818; // 
                constexpr std::ptrdiff_t m_strTrueFormModel = 0x1828; // 
                constexpr std::ptrdiff_t m_flLandHoldTime = 0x1908; // 
                constexpr std::ptrdiff_t m_flRisingTime = 0x190C; // 
                constexpr std::ptrdiff_t m_flCollideRadius = 0x1910; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 6
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_UltComboVData {
                constexpr std::ptrdiff_t m_MeleeSwingParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_MeleeImpactParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_SelfModifier = 0x1708; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_TargetModifier = 0x1718; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_KillCheckModifier = 0x1728; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_flKillCheckWindow = 0x1738; // 
            }
            // Parent: CCitadel_Ability_PrimaryWeapon
            // Field count: 0
            namespace CCitadel_Ability_Shotgun_Astro {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Astro_Rifle_Self {
            }
            // Parent: CCitadelModifierVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_DragEnemyVData {
                constexpr std::ptrdiff_t m_flForwardOffset = 0x608; // 
                constexpr std::ptrdiff_t m_flVerticalOffset = 0x60C; // 
                constexpr std::ptrdiff_t m_flDragDistance = 0x610; // 
                constexpr std::ptrdiff_t m_flForceDistScale = 0x614; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProc
            // Field count: 0
            namespace CCitadel_Modifier_SilenceProcWatcher {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_vecComponentsConsumed (EntitySubclassID_t)
            namespace CCitadel_Item {
                constexpr std::ptrdiff_t m_vecComponentsConsumed = 0xC78; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityDustStormVData {
                constexpr std::ptrdiff_t m_DustStormAura = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_GrenadeTrailModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelItemVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_UtilityUpgrade_DebuffImmunityVData {
                constexpr std::ptrdiff_t m_DebuffImmunityModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelItemVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_UtilityUpgrade_RocketBootsVData {
                constexpr std::ptrdiff_t m_LaunchParticle = 0x1590; // 
                constexpr std::ptrdiff_t m_InAirWatcherModifier = 0x1670; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_BaseBulletPreRollProcVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_CritShotVData {
                constexpr std::ptrdiff_t m_SlowModifier = 0x738; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_CritSound = 0x748; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_WarpStone_Caster_VData {
                constexpr std::ptrdiff_t m_playerBuffSelf = 0x608; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_SiphonBullets_HealthLoss_VData {
                constexpr std::ptrdiff_t m_SiphonParticle = 0x608; // 
                constexpr std::ptrdiff_t m_HealModifier = 0x6E8; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_BerserkerVData {
                constexpr std::ptrdiff_t m_BerserkerSound = 0x608; // 
                constexpr std::ptrdiff_t m_StackModifier = 0x618; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Bullet_Shield_Pulse {
            }
            // Parent: CCitadelModifier
            // Field count: 2
            namespace CCitadel_Modifier_Delayed_Stun {
                constexpr std::ptrdiff_t m_hRingEffect = 0xC0; // 
                constexpr std::ptrdiff_t m_flRadius = 0xC4; // 
            }
            // Parent: CCitadelModifier
            // Field count: 4
            namespace CCitadel_Modifier_HeroUpgradeBonuses {
                constexpr std::ptrdiff_t m_pOwningPlayer = 0xC0; // 
                constexpr std::ptrdiff_t m_flWeaponPower = 0xC8; // 
                constexpr std::ptrdiff_t m_flArmorPower = 0xCC; // 
                constexpr std::ptrdiff_t m_flTechPower = 0xD0; // 
            }
            // Parent: C_DynamicProp
            // Field count: 7
            //
            // Metadata:
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByName
            // MNetworkExcludeByUserGroup
            // MNetworkExcludeByName
            // MNetworkExcludeByUserGroup
            // MNetworkIncludeByName
            // NetworkVarNames: m_eDoorState (DoorState_t)
            // NetworkVarNames: m_bLocked (bool)
            // NetworkVarNames: m_closedPosition (Vector)
            // NetworkVarNames: m_closedAngles (QAngle)
            // NetworkVarNames: m_hMaster (CHandle<C_BasePropDoor>)
            namespace C_BasePropDoor {
                constexpr std::ptrdiff_t m_eDoorState = 0xE00; // 
                constexpr std::ptrdiff_t m_modelChanged = 0xE04; // 
                constexpr std::ptrdiff_t m_bLocked = 0xE05; // 
                constexpr std::ptrdiff_t m_closedPosition = 0xE08; // 
                constexpr std::ptrdiff_t m_closedAngles = 0xE14; // 
                constexpr std::ptrdiff_t m_hMaster = 0xE20; // 
                constexpr std::ptrdiff_t m_vWhereToSetLightingOrigin = 0xE24; // 
            }
            // Parent: C_PointEntity
            // Field count: 0
            namespace C_PointEntityAlias_info_target_portrait_root {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_PhantomStrike {
            }
            // Parent: CCitadel_Ability_PrimaryWeapon
            // Field count: 0
            namespace CCitadel_Ability_Shotgun_Astro_Backwards {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_PoisonBullets {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_SelfVacuum {
            }
            // Parent: CCitadelModifier
            // Field count: 7
            namespace CCitadel_Modifier_ShieldTracker_Base {
                constexpr std::ptrdiff_t m_vecShield = 0xC0; // 
                constexpr std::ptrdiff_t m_flShieldDamageTime = 0xCC; // 
                constexpr std::ptrdiff_t m_flShieldBreakTime = 0xD0; // 
                constexpr std::ptrdiff_t m_flShieldBreakHealAmount = 0xD4; // 
                constexpr std::ptrdiff_t m_flShieldBreakHealDone = 0xD8; // 
                constexpr std::ptrdiff_t m_bShieldHealingAfterBreak = 0xDC; // 
                constexpr std::ptrdiff_t m_bForceRegen = 0xDD; // 
            }
            // Parent: C_AI_CitadelNPC
            // Field count: 0
            namespace C_NPC_MidBoss {
            }
            // Parent: CBaseAnimGraph
            // Field count: 0
            namespace CCitadelItemMetal {
            }
            // Parent: CCitadel_Modifier_Stunned
            // Field count: 4
            namespace CCitadel_Modifier_VacuumAuraTarget {
                constexpr std::ptrdiff_t m_flMaxDist = 0x138; // 
                constexpr std::ptrdiff_t m_vecOffsetDir = 0x13C; // 
                constexpr std::ptrdiff_t m_vecStartPosition = 0x148; // 
                constexpr std::ptrdiff_t m_flAOERadius = 0x154; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CModifier_CloakingDevice_Active_Ambush {
                constexpr std::ptrdiff_t m_nAmbushParticle = 0xC0; // 
            }
            // Parent: CitadelItemVData
            // Field count: 7
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_ArmorUpgrade_AblativeCoatVData {
                constexpr std::ptrdiff_t m_RestoreEffectModifier = 0x1590; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_OnTakeDamageEffectModifier = 0x15A0; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_OnBreakEffectModifier = 0x15B0; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ResistBuffModifier = 0x15C0; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_flOnTakeDamageEffectDuration = 0x15D0; // 
                constexpr std::ptrdiff_t m_flOnBreakEffectDuration = 0x15D4; // 
                constexpr std::ptrdiff_t m_flOnRestoreEffectDuration = 0x15D8; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ActiveDisarm_SpiritSteal {
            }
            // Parent: C_BreakableProp
            // Field count: 6
            namespace C_PhysPropClientside {
                constexpr std::ptrdiff_t m_flTouchDelta = 0xCD8; // 
                constexpr std::ptrdiff_t m_fDeathTime = 0xCDC; // 
                constexpr std::ptrdiff_t m_inertiaScale = 0xCE0; // 
                constexpr std::ptrdiff_t m_vecDamagePosition = 0xCE4; // 
                constexpr std::ptrdiff_t m_vecDamageDirection = 0xCF0; // 
                constexpr std::ptrdiff_t m_nDamageType = 0xCFC; // 
            }
            // Parent: C_CitadelProjectile
            // Field count: 0
            namespace C_Projectile_Perched_Predator {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_Mirage_FireBeetles_Buff {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 4
            //
            // Metadata:
            // NetworkVarNames: m_vecTeleportPosition (Vector)
            // NetworkVarNames: m_vecTeleportPositionNormal (Vector)
            // NetworkVarNames: m_eTelepunchState (ETelepunchState_t)
            // NetworkVarNames: m_flNextStateTime (GameTime_t)
            namespace CCitadel_Ability_Viscous_Telepunch {
                constexpr std::ptrdiff_t m_vecTeleportPosition = 0xE70; // 
                constexpr std::ptrdiff_t m_vecTeleportPositionNormal = 0xE7C; // 
                constexpr std::ptrdiff_t m_eTelepunchState = 0xE88; // ETelepunchState_t
                constexpr std::ptrdiff_t m_flNextStateTime = 0xE8C; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_vecPuddleModifiers (CUtlVector<EHANDLE>)
            namespace CCitadel_Ability_GooGrenade {
                constexpr std::ptrdiff_t m_vecPuddleModifiers = 0xC78; // 
                constexpr std::ptrdiff_t m_LastDetonateTime = 0xEC0; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 6
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_ViscousWeapon_Alt_VData {
                constexpr std::ptrdiff_t m_strChargingParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_ImpactParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_FiringParticle = 0x1708; // 
                constexpr std::ptrdiff_t m_ExplosionSound = 0x17E8; // 
                constexpr std::ptrdiff_t m_ChargeSound = 0x17F8; // 
                constexpr std::ptrdiff_t m_ShootSound = 0x1808; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 4
            //
            // Metadata:
            // NetworkVarNames: m_bAirCast (bool)
            namespace CCitadel_Ability_Chrono_TimeWall {
                constexpr std::ptrdiff_t m_hChargingParticle = 0xC78; // 
                constexpr std::ptrdiff_t m_vSpawnPos = 0xC7C; // 
                constexpr std::ptrdiff_t m_qAngles = 0xC88; // 
                constexpr std::ptrdiff_t m_bAirCast = 0xC94; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ServerOnly {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_flDashCastStartTime (GameTime_t)
            // NetworkVarNames: m_vDashCastDir (Vector)
            namespace CCitadelBaseDashCastAbility {
                constexpr std::ptrdiff_t m_hAbilityToTrigger = 0xC78; // 
                constexpr std::ptrdiff_t m_flDashCastStartTime = 0xC7C; // 
                constexpr std::ptrdiff_t m_vDashCastDir = 0xC80; // 
            }
            // Parent: C_BaseEntity
            // Field count: 4
            //
            // Metadata:
            // NetworkVarNames: m_bDisabled (bool)
            // NetworkVarNames: m_iszSoundAreaType (string_t)
            // NetworkVarNames: m_vPos (Vector)
            namespace C_SoundAreaEntityBase {
                constexpr std::ptrdiff_t m_bDisabled = 0x558; // 
                constexpr std::ptrdiff_t m_bWasEnabled = 0x560; // 
                constexpr std::ptrdiff_t m_iszSoundAreaType = 0x568; // 
                constexpr std::ptrdiff_t m_vPos = 0x570; // 
            }
            // Parent: C_BaseEntity
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_fog (fogparams_t)
            namespace C_FogController {
                constexpr std::ptrdiff_t m_fog = 0x558; // 
                constexpr std::ptrdiff_t m_bUseAngles = 0x5C0; // 
                constexpr std::ptrdiff_t m_iChangedVariables = 0x5C4; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_Mirage_FireScarabs_HealthLoss {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ShivDashVData {
                constexpr std::ptrdiff_t m_DashParticle = 0x608; // 
                constexpr std::ptrdiff_t m_DashTrailParticle = 0x6E8; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 10
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_BurrowVData {
                constexpr std::ptrdiff_t m_ExplodeParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_BurrowStartParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_BurrowEndParticle = 0x1708; // 
                constexpr std::ptrdiff_t m_BurrowInGroundParticle = 0x17E8; // 
                constexpr std::ptrdiff_t m_BurrowModifier = 0x18C8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_SpinModifier = 0x18D8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_strBurrowEndSound = 0x18E8; // 
                constexpr std::ptrdiff_t m_flChannelEndEnemyPopUpForce = 0x18F8; // 
                constexpr std::ptrdiff_t m_flChannelEndEnemyPopUpCylinderHeight = 0x18FC; // 
                constexpr std::ptrdiff_t m_cameraSpinStart = 0x1900; // CitadelCameraOperationsSequence_t
            }
            // Parent: CCitadel_Modifier_BaseBulletPreRollProc
            // Field count: 0
            namespace CCitadel_Modifier_CritShot {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Savior_VData {
                constexpr std::ptrdiff_t m_BuffParticle = 0x608; // 
                constexpr std::ptrdiff_t m_TrailParticle = 0x6E8; // 
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_Cadence_AnthemAOE {
            }
            // Parent: CitadelAbilityVData
            // Field count: 16
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityWreckerTeleportVData {
                constexpr std::ptrdiff_t m_SpectatingProjectileParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_ExplosionParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_ChannelParticle = 0x1708; // 
                constexpr std::ptrdiff_t m_CastParticle = 0x17E8; // 
                constexpr std::ptrdiff_t m_ArrowOffsetX = 0x18C8; // 
                constexpr std::ptrdiff_t m_ArrowCameraDistance = 0x18CC; // 
                constexpr std::ptrdiff_t m_ArrowCameraHeightOffset = 0x18D0; // 
                constexpr std::ptrdiff_t m_ArrowInitialPitch = 0x18D4; // 
                constexpr std::ptrdiff_t m_GuidingModifier = 0x18D8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DebuffModifier = 0x18E8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_strExplodeSound = 0x18F8; // 
                constexpr std::ptrdiff_t m_flTrackAmount = 0x1908; // 
                constexpr std::ptrdiff_t m_flSpeedAccel = 0x190C; // 
                constexpr std::ptrdiff_t m_flSpeedDeccel = 0x1910; // 
                constexpr std::ptrdiff_t m_flBaseProjectileSpeed = 0x1914; // 
                constexpr std::ptrdiff_t m_flMaxProjectileSpeed = 0x1918; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Savior {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Objective_Regen {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_BulletResistReductionStackVData {
                constexpr std::ptrdiff_t m_bSelfish = 0x608; // 
            }
            // Parent: CPlayerPawnComponent
            // Field count: 0
            namespace CPlayer_ItemServices {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_ArmorUpgrade_ActiveBulletShield {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_vecLockonTargets (LockonTarget_t)
            // NetworkVarNames: m_LockOnStartTime (GameTime_t)
            namespace CCitadelBaseLockonAbility {
                constexpr std::ptrdiff_t m_vecLockonTargets = 0xD90; // C_UtlVectorEmbeddedNetworkVar<LockonTarget_t>
                constexpr std::ptrdiff_t m_LockOnStartTime = 0xDE0; // 
                constexpr std::ptrdiff_t m_nTargetingLightEffect = 0xDE8; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CAbility_Rutger_CheatDeath {
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_BoucePadVData {
                constexpr std::ptrdiff_t m_StompParticle = 0x608; // 
                constexpr std::ptrdiff_t m_strImpactSound = 0x6E8; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 5
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityStompVData {
                constexpr std::ptrdiff_t m_StompParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_strStompExplosionSound = 0x1628; // 
                constexpr std::ptrdiff_t m_strCastDelayLocalPlayerSound = 0x1638; // 
                constexpr std::ptrdiff_t m_DebuffModifier = 0x1648; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BulletResistModifier = 0x1658; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_PassiveBeefy {
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityStormCloudVData {
                constexpr std::ptrdiff_t m_StormCloudModifier = 0x1548; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Tech_Bleed {
                constexpr std::ptrdiff_t m_hRingEffect = 0xC0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 2
            namespace CCitadel_Modifier_HoldingGoldenIdol {
                constexpr std::ptrdiff_t m_iIdolParticle = 0x130; // 
                constexpr std::ptrdiff_t m_nGoldValue = 0x134; // 
            }
            // Parent: C_BaseModelEntity
            // Field count: 0
            namespace C_FuncBrush {
            }
            // Parent: C_BaseEntity
            // Field count: 8
            //
            // Metadata:
            // NetworkVarNames: m_worldName (string_t)
            // NetworkVarNames: m_layerName (string_t)
            // NetworkVarNames: m_bWorldLayerVisible (bool)
            // NetworkVarNames: m_bEntitiesSpawned (bool)
            namespace CInfoWorldLayer {
                constexpr std::ptrdiff_t m_pOutputOnEntitiesSpawned = 0x558; // 
                constexpr std::ptrdiff_t m_worldName = 0x580; // 
                constexpr std::ptrdiff_t m_layerName = 0x588; // 
                constexpr std::ptrdiff_t m_bWorldLayerVisible = 0x590; // 
                constexpr std::ptrdiff_t m_bEntitiesSpawned = 0x591; // 
                constexpr std::ptrdiff_t m_bCreateAsChildSpawnGroup = 0x592; // 
                constexpr std::ptrdiff_t m_hLayerSpawnGroup = 0x594; // 
                constexpr std::ptrdiff_t m_bWorldLayerActuallyVisible = 0x598; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 7
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_ShivDaggerVData {
                constexpr std::ptrdiff_t m_DamageDebuffModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_SlowDebuffModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DaggerStuckParticle = 0x1568; // 
                constexpr std::ptrdiff_t m_DaggerImpactParticle = 0x1648; // 
                constexpr std::ptrdiff_t m_DaggerExplodeParticle = 0x1728; // 
                constexpr std::ptrdiff_t m_strDaggerHitSound = 0x1808; // 
                constexpr std::ptrdiff_t m_strDaggerExplodeSound = 0x1818; // 
            }
            // Parent: CCitadel_Modifier_Stunned
            // Field count: 2
            namespace CCitadel_Modifier_PsychicLift {
                constexpr std::ptrdiff_t m_vecFloatDest = 0x138; // 
                constexpr std::ptrdiff_t m_vecStartingPos = 0x144; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_NearDeathFX {
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_ZiplineSpeedVData {
                constexpr std::ptrdiff_t m_flPercentageMultiplierStart = 0x608; // 
                constexpr std::ptrdiff_t m_flPercentageMultiplierEnd = 0x60C; // 
                constexpr std::ptrdiff_t m_flRampUpTime = 0x610; // 
            }
            // Parent: C_BaseCombatCharacter
            // Field count: 0
            namespace C_NetTestBaseCombatCharacter {
            }
            // Parent: C_AI_CitadelNPC
            // Field count: 0
            namespace C_Citadel_PestilenceDroneDispenser {
            }
            // Parent: CBaseAnimGraph
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_bActive (bool)
            // NetworkVarNames: m_sPickupName (CUtlString)
            // NetworkVarNames: m_nNameOffset (int)
            namespace C_Citadel_BreakblePropPickup {
                constexpr std::ptrdiff_t m_bActive = 0xB50; // 
                constexpr std::ptrdiff_t m_sPickupName = 0xB58; // 
                constexpr std::ptrdiff_t m_nNameOffset = 0xB60; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CGameModifier_FireUserEntityIOVData {
                constexpr std::ptrdiff_t m_FireOnAdded = 0x608; // 
                constexpr std::ptrdiff_t m_FireOnRemoved = 0x60C; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_GangActivity_Cancel {
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Shakedown_TargetVData {
                constexpr std::ptrdiff_t m_RootModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_PulseModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_WingBlastPush {
                constexpr std::ptrdiff_t m_vPush = 0xC0; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 7
            //
            // Metadata:
            // NetworkVarNames: m_flVertOffset (float)
            // NetworkVarNames: m_flHorizGap (float)
            // NetworkVarNames: m_vStartPos (Vector)
            // NetworkVarNames: m_vTargetPos (Vector)
            // NetworkVarNames: m_angFacing (QAngle)
            // NetworkVarNames: m_nMantleTypeIndex (int)
            // NetworkVarNames: m_flStartTime (GameTime_t)
            namespace CCitadel_Ability_Mantle {
                constexpr std::ptrdiff_t m_flVertOffset = 0xC78; // 
                constexpr std::ptrdiff_t m_flHorizGap = 0xC7C; // 
                constexpr std::ptrdiff_t m_vStartPos = 0xC80; // 
                constexpr std::ptrdiff_t m_vTargetPos = 0xC8C; // 
                constexpr std::ptrdiff_t m_angFacing = 0xC98; // 
                constexpr std::ptrdiff_t m_nMantleTypeIndex = 0xCA4; // 
                constexpr std::ptrdiff_t m_flStartTime = 0xCA8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_NearDeathFXVData {
                constexpr std::ptrdiff_t m_EnemyNearDeathParticle = 0x608; // 
                constexpr std::ptrdiff_t m_FriendlyNearDeathParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_sSelfDestructStart = 0x7C8; // 
                constexpr std::ptrdiff_t m_sSelfDestructEnd = 0x7D8; // 
            }
            // Parent: C_AI_CitadelNPC
            // Field count: 0
            namespace C_NPC_CarpetBombDrone {
            }
            // Parent: C_CitadelItemPickup
            // Field count: 0
            namespace CCitadelItemPickupIdol {
            }
            // Parent: C_Citadel_BreakblePropPickup
            // Field count: 0
            namespace C_Citadel_BreakblePropModifierPickup {
            }
            // Parent: CBaseAnimGraph
            // Field count: 2
            namespace C_PhysMagnet {
                constexpr std::ptrdiff_t m_aAttachedObjectsFromServer = 0xB50; // 
                constexpr std::ptrdiff_t m_aAttachedObjects = 0xB68; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Slork_LastBreathVData {
                constexpr std::ptrdiff_t m_ShieldModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_AirLiftExplodingAlly {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 2
            namespace CCitadel_Ability_Wrecker_Ultimate {
                constexpr std::ptrdiff_t m_angBeamAngles = 0xC98; // 
                constexpr std::ptrdiff_t m_bNeedsBeamReset = 0xCB0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 8
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadelModifierChronoPulseGrenadePulseAreaVData {
                constexpr std::ptrdiff_t m_DebuffModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_SlowModifier = 0x618; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_PreviewRingParticle = 0x628; // 
                constexpr std::ptrdiff_t m_AreaEffect = 0x708; // 
                constexpr std::ptrdiff_t m_strArmingSound = 0x7E8; // 
                constexpr std::ptrdiff_t m_strArmedSound = 0x7F8; // 
                constexpr std::ptrdiff_t m_strLoopingSound = 0x808; // 
                constexpr std::ptrdiff_t m_strHitSound = 0x818; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_bLeaping (bool)
            // NetworkVarNames: m_flLeapStartTime (GameTime_t)
            namespace CCitadel_Ability_HornetLeap {
                constexpr std::ptrdiff_t m_bLeaping = 0xC7A; // 
                constexpr std::ptrdiff_t m_flLeapStartTime = 0xC7C; // 
                constexpr std::ptrdiff_t m_nFXIndex = 0xC80; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ChainLightningEffect {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_VexBarrier_Shield {
            }
            // Parent: None
            // Field count: 4
            //
            // Metadata:
            // NetworkVarNames: m_pEntity (CEntityIdentity*)
            // NetworkVarNames: m_CScriptComponent (CScriptComponent::Storage_t)
            namespace CEntityInstance {
                constexpr std::ptrdiff_t m_iszPrivateVScripts = 0x8; // 
                constexpr std::ptrdiff_t m_pEntity = 0x10; // 
                constexpr std::ptrdiff_t m_CScriptComponent = 0x28; // 
                constexpr std::ptrdiff_t m_bVisibleinPVS = 0x30; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_ArmorUpgrade_Frenzy {
            }
            // Parent: C_PointClientUIWorldPanel
            // Field count: 1
            namespace C_InWorldKeyBindPanel {
                constexpr std::ptrdiff_t m_hPlayer = 0xA90; // 
            }
            // Parent: CBasePlayerController
            // Field count: 25
            //
            // Metadata:
            // NetworkVarNames: m_ePlayState (EPlayerPlayState)
            // NetworkVarNames: m_iGuidedBotMatchLastHits (int)
            // NetworkVarNames: m_iGuidedBotMatchOrbsSecured (int)
            // NetworkVarNames: m_iGuidedBotMatchOrbsDenied (int)
            // NetworkVarNames: m_iGuidedBotMatchDamageToGuardians (int)
            // NetworkVarNames: m_iGuidedBotMatchDamageToPlayers (int)
            // NetworkVarNames: m_iGuidedBotMatchDamageTaken (int)
            // NetworkVarNames: m_iGuidedBotMatchNetWorth (int)
            // NetworkVarNames: m_iGuidedBotMatchModsPurchased (int)
            // NetworkVarNames: m_iGuidedBotMatchAbilityUpgrades (int)
            // NetworkVarNames: m_flGuideBotMatchLastTaskNagVO (float)
            // NetworkVarNames: m_flGuideBotLastTimeTaskCompleted (float)
            // NetworkVarNames: m_eGuidedBotMatchObjective (EGuidedBotMatchObjective)
            // NetworkVarNames: m_nAssignedLane (int8)
            // NetworkVarNames: m_nOriginalLaneAssignment (int8)
            // NetworkVarNames: m_bIsKingPanda (bool)
            // NetworkVarNames: m_bBotDisconnectTakeover (bool)
            // NetworkVarNames: m_bInTeamChat (bool)
            // NetworkVarNames: m_bInPartyChat (bool)
            // NetworkVarNames: m_hHeroPawn (CHandle<CCitadelPlayerPawn>)
            // NetworkVarNames: m_PlayerDataGlobal (PlayerDataGlobal_t)
            // NetworkVarNames: m_nDeathReplayAvailable (int8)
            // NetworkVarNames: m_unLobbyPlayerSlot (CitadelLobbyPlayerSlot_t)
            namespace CCitadelPlayerController {
                constexpr std::ptrdiff_t m_ePlayState = 0x6F0; // 
                constexpr std::ptrdiff_t m_iGuidedBotMatchLastHits = 0x6F4; // 
                constexpr std::ptrdiff_t m_iGuidedBotMatchOrbsSecured = 0x6F8; // 
                constexpr std::ptrdiff_t m_iGuidedBotMatchOrbsDenied = 0x6FC; // 
                constexpr std::ptrdiff_t m_iGuidedBotMatchDamageToGuardians = 0x700; // 
                constexpr std::ptrdiff_t m_iGuidedBotMatchDamageToPlayers = 0x704; // 
                constexpr std::ptrdiff_t m_iGuidedBotMatchDamageTaken = 0x708; // 
                constexpr std::ptrdiff_t m_iGuidedBotMatchNetWorth = 0x70C; // 
                constexpr std::ptrdiff_t m_iGuidedBotMatchModsPurchased = 0x710; // 
                constexpr std::ptrdiff_t m_iGuidedBotMatchAbilityUpgrades = 0x714; // 
                constexpr std::ptrdiff_t m_flGuideBotMatchLastTaskNagVO = 0x718; // 
                constexpr std::ptrdiff_t m_flGuideBotLastTimeTaskCompleted = 0x71C; // 
                constexpr std::ptrdiff_t m_eGuidedBotMatchObjective = 0x720; // 
                constexpr std::ptrdiff_t m_nAssignedLane = 0x724; // 
                constexpr std::ptrdiff_t m_nOriginalLaneAssignment = 0x725; // 
                constexpr std::ptrdiff_t m_bIsKingPanda = 0x726; // 
                constexpr std::ptrdiff_t m_bBotDisconnectTakeover = 0x727; // 
                constexpr std::ptrdiff_t m_bInTeamChat = 0x728; // 
                constexpr std::ptrdiff_t m_bInPartyChat = 0x729; // 
                constexpr std::ptrdiff_t m_hHeroPawn = 0x72C; // 
                constexpr std::ptrdiff_t m_PlayerDataGlobal = 0x768; // 
                constexpr std::ptrdiff_t m_nDeathReplayAvailable = 0x940; // 
                constexpr std::ptrdiff_t m_unLobbyPlayerSlot = 0x941; // 
                constexpr std::ptrdiff_t m_bHasCheckedFriendName = 0x942; // 
                constexpr std::ptrdiff_t m_sFriendName = 0x948; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_GenericPerson_2 {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            namespace CCitadel_Ability_Ghost_BloodShards {
                constexpr std::ptrdiff_t m_vecDamagedTargets = 0xDC8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Intrinsic_BaseVData {
            }
            // Parent: C_CitadelProjectile
            // Field count: 0
            namespace CCitadel_Projectile_Cyclone {
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadelModifier_Viscous_Goo_Aura {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Intimidated {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_TargetPracticeEnemy {
            }
            // Parent: C_BaseEntity
            // Field count: 0
            namespace C_PortraitWorldCallbackHandler {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierPowerGeneratorVData {
                constexpr std::ptrdiff_t m_EffectToTitan = 0x608; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 7
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_VoidSphereVData {
                constexpr std::ptrdiff_t m_TeleportStartParticle = 0x608; // 
                constexpr std::ptrdiff_t m_TeleportEndParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_TeleportTrailParticle = 0x7C8; // 
                constexpr std::ptrdiff_t m_TeleportModelParticle = 0x8A8; // 
                constexpr std::ptrdiff_t m_BuffModifier = 0x988; // 
                constexpr std::ptrdiff_t m_flPreTeleportDuration = 0x998; // 
                constexpr std::ptrdiff_t m_strAmbientLoopingLocalPlayerSound = 0x9A0; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 7
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Chrono_TimeWallVData {
                constexpr std::ptrdiff_t m_AuraModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_TimeWallParticle = 0x1558; // 
                constexpr std::ptrdiff_t m_TimeWallChargeParticle = 0x1638; // 
                constexpr std::ptrdiff_t m_TimeWallHitParticle = 0x1718; // 
                constexpr std::ptrdiff_t m_TimeWallHitTimerParticle = 0x17F8; // 
                constexpr std::ptrdiff_t m_strWallCreated = 0x18D8; // 
                constexpr std::ptrdiff_t m_strChargeUpSound = 0x18E8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_GhostBloodShardDebuffVData {
                constexpr std::ptrdiff_t m_BloodShardDebuffParticle = 0x608; // 
            }
            // Parent: CCitadelModifier
            // Field count: 2
            namespace CCitadel_Modifier_DPSTracker {
                constexpr std::ptrdiff_t m_flProgress = 0xC0; // 
                constexpr std::ptrdiff_t m_flDistToTarget = 0xC4; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Slork_LastBreath {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Synth_Blitz {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Urn_Debuff {
            }
            // Parent: CitadelAbilityVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityChargedShotVData {
                constexpr std::ptrdiff_t m_ChannelParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_ChannelStartParticle = 0x1628; // 
                constexpr std::ptrdiff_t m_ShootParticle = 0x1708; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Aerial_Assault {
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_Dust_Storm_Aura {
            }
            // Parent: C_CitadelProjectile
            // Field count: 0
            namespace C_CitadelHornetStingProjectile {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_Item_CheatDeath {
            }
            // Parent: CCitadelModifier
            // Field count: 4
            namespace CCitadel_Modifier_Chomp_Hobbled {
                constexpr std::ptrdiff_t m_LastUpdate = 0xC0; // 
                constexpr std::ptrdiff_t m_flDamageTime = 0xC4; // 
                constexpr std::ptrdiff_t m_flMovementTime = 0xC8; // 
                constexpr std::ptrdiff_t m_hGrappler = 0xCC; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierChompGrappleVData {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_AirLift_Explode_Target {
            }
            // Parent: CitadelAbilityVData
            // Field count: 10
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityHookVData {
                constexpr std::ptrdiff_t m_SelfModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_TargetModifier = 0x1558; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BulletAmpModifier = 0x1568; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_ShieldModifier = 0x1578; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_HookOutParticle = 0x1588; // 
                constexpr std::ptrdiff_t m_strHookSuccessSound = 0x1668; // 
                constexpr std::ptrdiff_t m_strHookAllySound = 0x1678; // 
                constexpr std::ptrdiff_t m_strHookMissSound = 0x1688; // 
                constexpr std::ptrdiff_t m_strHookImpactGeoSound = 0x1698; // 
                constexpr std::ptrdiff_t m_SelfBuffCastSound = 0x16A8; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 4
            //
            // Metadata:
            // NetworkVarNames: m_bIcePathing (bool)
            // NetworkVarNames: m_qLastAngles (QAngle)
            // NetworkVarNames: m_vLastVelocity (Vector)
            // NetworkVarNames: m_bFirstMovementTick (bool)
            namespace CCitadel_Ability_IcePath {
                constexpr std::ptrdiff_t m_bIcePathing = 0xCE8; // 
                constexpr std::ptrdiff_t m_qLastAngles = 0xCEC; // 
                constexpr std::ptrdiff_t m_vLastVelocity = 0xCF8; // 
                constexpr std::ptrdiff_t m_bFirstMovementTick = 0xD04; // 
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_LearningHeroAbility {
                constexpr std::ptrdiff_t m_sDescription = 0xC0; // 
            }
            // Parent: None
            // Field count: 33
            //
            // Metadata:
            // NetworkVarNames: m_hParent (CGameSceneNodeHandle)
            // NetworkVarNames: m_vecOrigin (CNetworkOriginCellCoordQuantizedVector)
            // NetworkVarNames: m_angRotation (QAngle)
            // NetworkVarNames: m_flScale (float)
            // NetworkVarNames: m_name (CUtlStringToken)
            // NetworkVarNames: m_hierarchyAttachName (CUtlStringToken)
            namespace CGameSceneNode {
                constexpr std::ptrdiff_t m_nodeToWorld = 0x10; // 
                constexpr std::ptrdiff_t m_pOwner = 0x30; // 
                constexpr std::ptrdiff_t m_pParent = 0x38; // 
                constexpr std::ptrdiff_t m_pChild = 0x40; // 
                constexpr std::ptrdiff_t m_pNextSibling = 0x48; // 
                constexpr std::ptrdiff_t m_hParent = 0x78; // 
                constexpr std::ptrdiff_t m_vecOrigin = 0x88; // CNetworkOriginCellCoordQuantizedVector
                constexpr std::ptrdiff_t m_angRotation = 0xC0; // 
                constexpr std::ptrdiff_t m_flScale = 0xCC; // 
                constexpr std::ptrdiff_t m_vecAbsOrigin = 0xD0; // 
                constexpr std::ptrdiff_t m_angAbsRotation = 0xDC; // 
                constexpr std::ptrdiff_t m_flAbsScale = 0xE8; // 
                constexpr std::ptrdiff_t m_nParentAttachmentOrBone = 0xEC; // 
                constexpr std::ptrdiff_t m_bDebugAbsOriginChanges = 0xEE; // 
                constexpr std::ptrdiff_t m_bDormant = 0xEF; // 
                constexpr std::ptrdiff_t m_bForceParentToBeNetworked = 0xF0; // 
                constexpr std::ptrdiff_t m_bDirtyHierarchy = 0x0; // 
                constexpr std::ptrdiff_t m_bDirtyBoneMergeInfo = 0x0; // 
                constexpr std::ptrdiff_t m_bNetworkedPositionChanged = 0x0; // 
                constexpr std::ptrdiff_t m_bNetworkedAnglesChanged = 0x0; // 
                constexpr std::ptrdiff_t m_bNetworkedScaleChanged = 0x0; // 
                constexpr std::ptrdiff_t m_bWillBeCallingPostDataUpdate = 0x0; // 
                constexpr std::ptrdiff_t m_bBoneMergeFlex = 0x0; // 
                constexpr std::ptrdiff_t m_nLatchAbsOrigin = 0x0; // 
                constexpr std::ptrdiff_t m_bDirtyBoneMergeBoneToRoot = 0x0; // 
                constexpr std::ptrdiff_t m_nHierarchicalDepth = 0xF3; // 
                constexpr std::ptrdiff_t m_nHierarchyType = 0xF4; // 
                constexpr std::ptrdiff_t m_nDoNotSetAnimTimeInInvalidatePhysicsCount = 0xF5; // 
                constexpr std::ptrdiff_t m_name = 0xF8; // 
                constexpr std::ptrdiff_t m_hierarchyAttachName = 0x138; // 
                constexpr std::ptrdiff_t m_flZOffset = 0x13C; // 
                constexpr std::ptrdiff_t m_flClientLocalScale = 0x140; // 
                constexpr std::ptrdiff_t m_vRenderOrigin = 0x144; // 
            }
            // Parent: C_Citadel_BreakblePropPickup
            // Field count: 0
            namespace C_Citadel_BreakblePropHealthPickup {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierVData_SetModelScale {
                constexpr std::ptrdiff_t m_flScale = 0x608; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_Riptide {
            }
            // Parent: CCitadelModifier
            // Field count: 2
            namespace CModifier_Mirage_Tornado_Lift {
                constexpr std::ptrdiff_t m_vecFloatDest = 0x130; // 
                constexpr std::ptrdiff_t m_vecStartingPos = 0x13C; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CAbility_Rutger_ForceField {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 15
            //
            // Metadata:
            // NetworkVarNames: m_flGroundDashSlideTime (CCitadelAutoScaledTime)
            // NetworkVarNames: m_flSlowGetupStartTime (GameTime_t)
            // NetworkVarNames: m_bShouldTriggerSlowGetup (bool)
            // NetworkVarNames: m_bWantsSlide (bool)
            // NetworkVarNames: m_bAirborneWhenDuckPressed (bool)
            // NetworkVarNames: m_bIsSliding (bool)
            // NetworkVarNames: m_flSpeedAdjust (float)
            // NetworkVarNames: m_flDuckPressedTime (GameTime_t)
            // NetworkVarNames: m_flSlideChangeTime (GameTime_t)
            // NetworkVarNames: m_flSlidingOnFlatStartTime (GameTime_t)
            // NetworkVarNames: m_nJumpsThisSlideSession (int)
            // NetworkVarNames: m_flOnGroundStartTime (GameTime_t)
            // NetworkVarNames: m_flDashSlideStartTime (GameTime_t)
            namespace CCitadel_Ability_Slide {
                constexpr std::ptrdiff_t m_flGroundDashSlideTime = 0xCD0; // 
                constexpr std::ptrdiff_t m_flSlowGetupStartTime = 0xCE8; // 
                constexpr std::ptrdiff_t m_bShouldTriggerSlowGetup = 0xCEC; // 
                constexpr std::ptrdiff_t m_bWantsSlide = 0xCED; // 
                constexpr std::ptrdiff_t m_bAirborneWhenDuckPressed = 0xCEE; // 
                constexpr std::ptrdiff_t m_bIsSliding = 0xCEF; // 
                constexpr std::ptrdiff_t m_flSpeedAdjust = 0xCF0; // 
                constexpr std::ptrdiff_t m_flDuckPressedTime = 0xCF4; // 
                constexpr std::ptrdiff_t m_flSlideChangeTime = 0xCF8; // 
                constexpr std::ptrdiff_t m_flSlidingOnFlatStartTime = 0xCFC; // 
                constexpr std::ptrdiff_t m_nJumpsThisSlideSession = 0xD00; // 
                constexpr std::ptrdiff_t m_flOnGroundStartTime = 0xD04; // 
                constexpr std::ptrdiff_t m_flDashSlideStartTime = 0xD08; // 
                constexpr std::ptrdiff_t m_bStartedSlideViaProbeSlope = 0xD0C; // 
                constexpr std::ptrdiff_t m_nSlideEffectIndex = 0xD10; // 
            }
            // Parent: C_AI_CitadelNPC
            // Field count: 6
            //
            // Metadata:
            // NetworkVarNames: m_iLane (int)
            // NetworkVarNames: m_nElectricBeamCasts (int)
            // NetworkVarNames: m_eAliveState (ETier3State_t)
            // NetworkVarNames: m_ePhase (ETier3Phase_t)
            namespace C_NPC_Boss_Tier3 {
                constexpr std::ptrdiff_t m_iLane = 0x14A0; // 
                constexpr std::ptrdiff_t m_angTargeting1 = 0x14A8; // 
                constexpr std::ptrdiff_t m_angTargeting2 = 0x14C0; // 
                constexpr std::ptrdiff_t m_nElectricBeamCasts = 0x14D8; // 
                constexpr std::ptrdiff_t m_eAliveState = 0x14DC; // 
                constexpr std::ptrdiff_t m_ePhase = 0x14E0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_BreakablePropExtraGoldPickupVData {
                constexpr std::ptrdiff_t m_iBaseExtraGoldBounty = 0x608; // 
                constexpr std::ptrdiff_t m_iPerMinuteExtraGoldBounty = 0x60C; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Astro_Shotgun_Toggle_VData {
                constexpr std::ptrdiff_t m_BuffModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_SpellShield_Buff {
            }
            // Parent: CCitadel_Modifier_Intrinsic_BaseVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_MagicStormWatcherVData {
                constexpr std::ptrdiff_t m_BuffModifier = 0x608; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 4
            namespace CCitadel_Modifier_TrooperDisabledInvulnerability {
                constexpr std::ptrdiff_t m_flBulletResistancePctMax = 0xC0; // 
                constexpr std::ptrdiff_t m_bShieldUp = 0xC4; // 
                constexpr std::ptrdiff_t m_flShieldUpTime = 0xC8; // 
                constexpr std::ptrdiff_t m_trackInfo = 0xCC; // 
            }
            // Parent: C_BaseEntity
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_hEntAttached (CHandle<C_BaseEntity>)
            // NetworkVarNames: m_bCheapEffect (bool)
            namespace C_EntityFlame {
                constexpr std::ptrdiff_t m_hEntAttached = 0x558; // 
                constexpr std::ptrdiff_t m_hOldAttached = 0x580; // 
                constexpr std::ptrdiff_t m_bCheapEffect = 0x584; // 
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_FlameDashGroundAura {
            }
            // Parent: C_BaseModelEntity
            // Field count: 0
            namespace C_Breakable {
            }
            // Parent: CCitadel_Ability_Melee_Base
            // Field count: 1
            namespace CCitadel_Ability_Uppercut {
                constexpr std::ptrdiff_t m_bShouldUseResources = 0xF28; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_vecPulseTargets (EHANDLE)
            namespace CCitadel_Ability_PsychicPulse {
                constexpr std::ptrdiff_t m_vecPulseTargets = 0xCB0; // 
            }
            // Parent: C_BaseEntity
            // Field count: 0
            namespace C_TintController {
            }
            // Parent: CPlayerPawnComponent
            // Field count: 0
            namespace CPlayer_AutoaimServices {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_WingBlastApply {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_ImmobilizeTrap_Debuff {
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_WeaponUpgrade_Headhunter {
            }
            // Parent: C_BaseModelEntity
            // Field count: 24
            //
            // Metadata:
            // NetworkVarNames: m_hSpriteMaterial (HMaterialStrong)
            // NetworkVarNames: m_hAttachedToEntity (CHandle<CBaseEntity>)
            // NetworkVarNames: m_nAttachment (AttachmentHandle_t)
            // NetworkVarNames: m_flSpriteFramerate (float32)
            // NetworkVarNames: m_flFrame (float32)
            // NetworkVarNames: m_nBrightness (uint32)
            // NetworkVarNames: m_flBrightnessDuration (float32)
            // NetworkVarNames: m_flSpriteScale (float32)
            // NetworkVarNames: m_flScaleDuration (float32)
            // NetworkVarNames: m_bWorldSpaceScale (bool)
            // NetworkVarNames: m_flGlowProxySize (float32)
            // NetworkVarNames: m_flHDRColorScale (float32)
            namespace C_Sprite {
                constexpr std::ptrdiff_t m_hSpriteMaterial = 0x830; // CStrongHandle<InfoForResourceTypeIMaterial2>
                constexpr std::ptrdiff_t m_hAttachedToEntity = 0x838; // 
                constexpr std::ptrdiff_t m_nAttachment = 0x83C; // 
                constexpr std::ptrdiff_t m_flSpriteFramerate = 0x840; // 
                constexpr std::ptrdiff_t m_flFrame = 0x844; // 
                constexpr std::ptrdiff_t m_flDieTime = 0x848; // 
                constexpr std::ptrdiff_t m_nBrightness = 0x858; // 
                constexpr std::ptrdiff_t m_flBrightnessDuration = 0x85C; // 
                constexpr std::ptrdiff_t m_flSpriteScale = 0x860; // 
                constexpr std::ptrdiff_t m_flScaleDuration = 0x864; // 
                constexpr std::ptrdiff_t m_bWorldSpaceScale = 0x868; // 
                constexpr std::ptrdiff_t m_flGlowProxySize = 0x86C; // 
                constexpr std::ptrdiff_t m_flHDRColorScale = 0x870; // 
                constexpr std::ptrdiff_t m_flLastTime = 0x874; // 
                constexpr std::ptrdiff_t m_flMaxFrame = 0x878; // 
                constexpr std::ptrdiff_t m_flStartScale = 0x87C; // 
                constexpr std::ptrdiff_t m_flDestScale = 0x880; // 
                constexpr std::ptrdiff_t m_flScaleTimeStart = 0x884; // 
                constexpr std::ptrdiff_t m_nStartBrightness = 0x888; // 
                constexpr std::ptrdiff_t m_nDestBrightness = 0x88C; // 
                constexpr std::ptrdiff_t m_flBrightnessTimeStart = 0x890; // 
                constexpr std::ptrdiff_t m_hOldSpriteMaterial = 0x898; // CWeakHandle<InfoForResourceTypeIMaterial2>
                constexpr std::ptrdiff_t m_nSpriteWidth = 0x938; // 
                constexpr std::ptrdiff_t m_nSpriteHeight = 0x93C; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 8
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityBullChargeVData {
                constexpr std::ptrdiff_t m_cameraSequenceImpact = 0x1548; // CitadelCameraOperationsSequence_t
                constexpr std::ptrdiff_t m_ModifierTossAirControlLockout = 0x15D0; // 
                constexpr std::ptrdiff_t m_ModifierWeaponPowerIncrease = 0x15E0; // 
                constexpr std::ptrdiff_t m_ModifierChargeDragEnemy = 0x15F0; // 
                constexpr std::ptrdiff_t m_ModifierBullCharging = 0x1600; // 
                constexpr std::ptrdiff_t m_WallImpactParticle = 0x1610; // 
                constexpr std::ptrdiff_t m_strWallSlamSound = 0x16F0; // 
                constexpr std::ptrdiff_t m_flWallStunLookAheadDist = 0x1700; // 
            }
            // Parent: C_TeamplayRules
            // Field count: 48
            //
            // Metadata:
            // NetworkVarNames: m_bFreezePeriod (bool)
            // NetworkVarNames: m_fLevelStartTime (GameTime_t)
            // NetworkVarNames: m_flGameStartTime (GameTime_t)
            // NetworkVarNames: m_flRoundStartTime (GameTime_t)
            // NetworkVarNames: m_eGameState (EGameState)
            // NetworkVarNames: m_hTowerAmber (EHANDLE)
            // NetworkVarNames: m_hTowerSapphire (EHANDLE)
            // NetworkVarNames: m_bEnemyInAmberBase (bool)
            // NetworkVarNames: m_bEnemyInSapphireBase (bool)
            // NetworkVarNames: m_vMinimapMins (Vector)
            // NetworkVarNames: m_vMinimapMaxs (Vector)
            // NetworkVarNames: m_bMatchSafeToAbandon (bool)
            // NetworkVarNames: m_bNoDeathEnabled (bool)
            // NetworkVarNames: m_bFastCooldownsEnabled (bool)
            // NetworkVarNames: m_bStaminaCooldownsEnabled (bool)
            // NetworkVarNames: m_bUnlimitedAmmoEnabled (bool)
            // NetworkVarNames: m_bInfiniteResourcesEnabled (bool)
            // NetworkVarNames: m_bFlexSlotsForcedUnlocked (bool)
            // NetworkVarNames: m_eMatchMode (ECitadelMatchMode)
            // NetworkVarNames: m_eGameMode (ECitadelGameMode)
            // NetworkVarNames: m_unSpectatorCount (uint32)
            // NetworkVarNames: m_hTrooperMinimap (CHandle<CCitadelTrooperMinimap>)
            // NetworkVarNames: m_hCurrentHeroDrafterRebels (EHANDLE)
            // NetworkVarNames: m_hCurrentHeroDrafterCombine (EHANDLE)
            // NetworkVarNames: m_bServerPaused (bool)
            // NetworkVarNames: m_iPauseTeam (int)
            // NetworkVarNames: m_nMatchClockUpdateTick (int)
            // NetworkVarNames: m_flMatchClockAtLastUpdate (float)
            // NetworkVarNames: m_bRequiresReportCardDismissal (bool)
            // NetworkVarNames: m_eGGTeam (int)
            // NetworkVarNames: m_flGGEndsAtTime (GameTime_t)
            // NetworkVarNames: m_unMatchID (MatchID_t)
            // NetworkVarNames: m_nExperimentalGameplayState (int)
            // NetworkVarNames: m_flHeroDiedTime (GameTime_t)
            namespace C_CitadelGameRules {
                constexpr std::ptrdiff_t m_bFreezePeriod = 0x58; // 
                constexpr std::ptrdiff_t m_fLevelStartTime = 0x5C; // 
                constexpr std::ptrdiff_t m_flGameStartTime = 0x60; // 
                constexpr std::ptrdiff_t m_flRoundStartTime = 0x64; // 
                constexpr std::ptrdiff_t m_eGameState = 0x68; // 
                constexpr std::ptrdiff_t m_hTowerAmber = 0x6C; // 
                constexpr std::ptrdiff_t m_hTowerSapphire = 0x70; // 
                constexpr std::ptrdiff_t m_bEnemyInAmberBase = 0x74; // 
                constexpr std::ptrdiff_t m_bEnemyInSapphireBase = 0x75; // 
                constexpr std::ptrdiff_t m_vMinimapMins = 0x78; // 
                constexpr std::ptrdiff_t m_vMinimapMaxs = 0x84; // 
                constexpr std::ptrdiff_t m_bMatchSafeToAbandon = 0x90; // 
                constexpr std::ptrdiff_t m_bNoDeathEnabled = 0x91; // 
                constexpr std::ptrdiff_t m_bFastCooldownsEnabled = 0x92; // 
                constexpr std::ptrdiff_t m_bStaminaCooldownsEnabled = 0x93; // 
                constexpr std::ptrdiff_t m_bUnlimitedAmmoEnabled = 0x94; // 
                constexpr std::ptrdiff_t m_bInfiniteResourcesEnabled = 0x95; // 
                constexpr std::ptrdiff_t m_bFlexSlotsForcedUnlocked = 0x96; // 
                constexpr std::ptrdiff_t m_eMatchMode = 0x98; // 
                constexpr std::ptrdiff_t m_eGameMode = 0x9C; // 
                constexpr std::ptrdiff_t m_unSpectatorCount = 0xA0; // 
                constexpr std::ptrdiff_t m_hTrooperMinimap = 0xA4; // 
                constexpr std::ptrdiff_t m_hCurrentHeroDrafterRebels = 0xA8; // 
                constexpr std::ptrdiff_t m_hCurrentHeroDrafterCombine = 0xAC; // 
                constexpr std::ptrdiff_t m_bDontUploadStats = 0xB0; // 
                constexpr std::ptrdiff_t m_bServerPaused = 0x9E08; // 
                constexpr std::ptrdiff_t m_iPauseTeam = 0x9E0C; // 
                constexpr std::ptrdiff_t m_nMatchClockUpdateTick = 0x9E10; // 
                constexpr std::ptrdiff_t m_flMatchClockAtLastUpdate = 0x9E14; // 
                constexpr std::ptrdiff_t m_flPauseTime = 0x9E18; // 
                constexpr std::ptrdiff_t m_pausingPlayerId = 0x9E20; // 
                constexpr std::ptrdiff_t m_unpausingPlayerId = 0x9E24; // 
                constexpr std::ptrdiff_t m_fPauseRawTime = 0x9E28; // 
                constexpr std::ptrdiff_t m_fPauseCurTime = 0x9E2C; // 
                constexpr std::ptrdiff_t m_fUnpauseRawTime = 0x9E30; // 
                constexpr std::ptrdiff_t m_fUnpauseCurTime = 0x9E34; // 
                constexpr std::ptrdiff_t m_bRequiresReportCardDismissal = 0x9E88; // 
                constexpr std::ptrdiff_t m_flPreGameWaitEndTime = 0x9E8C; // 
                constexpr std::ptrdiff_t m_flReportCardDismissalWaitStart = 0x9E90; // 
                constexpr std::ptrdiff_t m_nLastPreGameCount = 0x9E94; // 
                constexpr std::ptrdiff_t m_eGGTeam = 0x9E98; // 
                constexpr std::ptrdiff_t m_flGGEndsAtTime = 0x9E9C; // 
                constexpr std::ptrdiff_t m_unMatchID = 0x9EA0; // 
                constexpr std::ptrdiff_t m_nExperimentalGameplayState = 0x9EA8; // 
                constexpr std::ptrdiff_t m_nPlayerDeathEventID = 0x9EAC; // 
                constexpr std::ptrdiff_t m_nReplayChangedEvent = 0x9EB0; // 
                constexpr std::ptrdiff_t m_nGameOverEvent = 0x9EB4; // 
                constexpr std::ptrdiff_t m_flHeroDiedTime = 0x9ED8; // 
            }
            // Parent: CCitadelModifierAura
            // Field count: 0
            namespace CCitadel_Modifier_Tier2Boss_RocketDamage_Aura {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_Rutger_Pulse_VData {
                constexpr std::ptrdiff_t m_strSilenceTargetSound = 0x608; // 
            }
            // Parent: CitadelAbilityVData
            // Field count: 9
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityShivDashVData {
                constexpr std::ptrdiff_t m_DashModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_DashImpactEffect = 0x1558; // 
                constexpr std::ptrdiff_t m_DashSwingEffect = 0x1638; // 
                constexpr std::ptrdiff_t m_DashLineEffect = 0x1718; // 
                constexpr std::ptrdiff_t m_strDashStartWithTargets = 0x17F8; // 
                constexpr std::ptrdiff_t m_strDashStartEcho = 0x1808; // 
                constexpr std::ptrdiff_t m_strDashStartMiss = 0x1818; // 
                constexpr std::ptrdiff_t m_strDashHitEnemy = 0x1828; // 
                constexpr std::ptrdiff_t m_flEchoDelay = 0x1838; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Nano_Pounce_Self {
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 0
            namespace CCitadel_Ability_MobileResupply {
            }
            // Parent: CitadelAbilityVData
            // Field count: 12
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CAbilityHornetSnipeVData {
                constexpr std::ptrdiff_t m_AssassinateShotParticle = 0x1548; // 
                constexpr std::ptrdiff_t m_AssassinateShotParticleOwnerOnly = 0x1628; // 
                constexpr std::ptrdiff_t m_LaserSightParticle = 0x1708; // 
                constexpr std::ptrdiff_t m_LaserSightParticleOwnerOnly = 0x17E8; // 
                constexpr std::ptrdiff_t m_SnipeModifier = 0x18C8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_BuffOnKillModifier = 0x18D8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_GlowEnemyModifier = 0x18E8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_strSnipeImpactSound = 0x18F8; // 
                constexpr std::ptrdiff_t m_flMinScopeTimeToShoot = 0x1908; // 
                constexpr std::ptrdiff_t m_flScopeTimeToFullPower = 0x190C; // 
                constexpr std::ptrdiff_t m_flScopeMinPowerFrac = 0x1910; // 
                constexpr std::ptrdiff_t m_flFadeToBlackTime = 0x1914; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_AblativeCoatResistBuff {
            }
            // Parent: CCitadelModifierVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifierVitalitySuppressorVData {
                constexpr std::ptrdiff_t m_DebuffParticle = 0x608; // 
            }
            // Parent: C_AI_CitadelNPC
            // Field count: 0
            namespace C_CitadelPlayerBotNPCBrain {
            }
            // Parent: C_DynamicProp
            // Field count: 0
            //
            // Metadata:
            // MNetworkIncludeByName
            namespace C_AnimGraph2TestProp {
            }
            // Parent: CBaseAnimGraph
            // Field count: 8
            //
            // Metadata:
            // NetworkVarNames: m_ragPos (Vector)
            // NetworkVarNames: m_ragAngles (QAngle)
            // NetworkVarNames: m_flBlendWeight (float32)
            // NetworkVarNames: m_hRagdollSource (EHANDLE)
            namespace C_RagdollProp {
                constexpr std::ptrdiff_t m_ragPos = 0xB58; // 
                constexpr std::ptrdiff_t m_ragAngles = 0xB70; // 
                constexpr std::ptrdiff_t m_flBlendWeight = 0xB88; // 
                constexpr std::ptrdiff_t m_hRagdollSource = 0xB8C; // 
                constexpr std::ptrdiff_t m_iEyeAttachment = 0xB90; // 
                constexpr std::ptrdiff_t m_flBlendWeightCurrent = 0xB94; // 
                constexpr std::ptrdiff_t m_parentPhysicsBoneIndices = 0xB98; // 
                constexpr std::ptrdiff_t m_worldSpaceBoneComputationOrder = 0xBB0; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_WeaponUpgrade_BansheeSlugs {
            }
            // Parent: CitadelAbilityVData
            // Field count: 9
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CBaseDashCastAbilityVData {
                constexpr std::ptrdiff_t m_AbilityToTrigger = 0x1548; // 
                constexpr std::ptrdiff_t m_flDashCastTriggerRadius = 0x1558; // 
                constexpr std::ptrdiff_t m_flDashSpeed = 0x155C; // 
                constexpr std::ptrdiff_t m_bSnapToZeroSpeedOnEnd = 0x1560; // 
                constexpr std::ptrdiff_t m_bUseCurveToDefineSpeed = 0x1561; // 
                constexpr std::ptrdiff_t m_MovementSpeedCurve = 0x1568; // 
                constexpr std::ptrdiff_t m_flMovementSpeedCurveAvgSpeed = 0x15A8; // 
                constexpr std::ptrdiff_t m_strTargetHitSound = 0x15B0; // 
                constexpr std::ptrdiff_t m_strMissSound = 0x15C0; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CModifier_Mirage_Traveler_MovementSpeed {
            }
            // Parent: CCitadelModifierVData
            // Field count: 0
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CModifier_Synth_Barrage_Amp_VData {
            }
            // Parent: CitadelAbilityVData
            // Field count: 2
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_Gravity_Lasso_VData {
                constexpr std::ptrdiff_t m_GravityLassoSelf = 0x1548; // 
                constexpr std::ptrdiff_t m_GravityLassoTarget = 0x1558; // 
            }
            // Parent: CCitadel_Modifier_BaseEventProcVData
            // Field count: 4
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_MeleeCharge_VData {
                constexpr std::ptrdiff_t m_SwingParticle = 0x638; // 
                constexpr std::ptrdiff_t m_HitParticle = 0x718; // 
                constexpr std::ptrdiff_t m_ReloadVisualModifier = 0x7F8; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_AmmoAddedVisualModifier = 0x808; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CitadelItemVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Item_HealthRegenAuraVData {
                constexpr std::ptrdiff_t m_HealParticle = 0x1590; // 
                constexpr std::ptrdiff_t m_CastHealParticle = 0x1670; // 
                constexpr std::ptrdiff_t m_HealingPulseTrackerModifier = 0x1750; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadel_Modifier_RegeneratingTechShield
            // Field count: 0
            namespace CCitadel_Modifier_GalvanicStormTechShield {
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Root {
            }
            // Parent: C_BaseEntity
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_CCitadelHeroComponent (CCitadelHeroComponent::Storage_t)
            namespace C_HeroPreview {
                constexpr std::ptrdiff_t m_CCitadelHeroComponent = 0x558; // 
            }
            // Parent: None
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: nType (FixAngleSet_t)
            // NetworkVarNames: qAngle (QAngle)
            // NetworkVarNames: nIndex (uint32)
            namespace ViewAngleServerChange_t {
                constexpr std::ptrdiff_t nType = 0x30; // 
                constexpr std::ptrdiff_t qAngle = 0x34; // 
                constexpr std::ptrdiff_t nIndex = 0x40; // 
            }
            // Parent: CCitadel_Item
            // Field count: 0
            namespace CCitadel_ArmorUpgrade_Colossus {
            }
            // Parent: CCitadel_Ability_BaseHeldItemVData
            // Field count: 8
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Ability_GoldenIdolVData {
                constexpr std::ptrdiff_t m_sIdolDropOffSound = 0x1628; // 
                constexpr std::ptrdiff_t m_DropoffTimerModifier = 0x1638; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_Bonus01 = 0x1648; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_Bonus02 = 0x1658; // CEmbeddedSubclass<CCitadelModifier>
                constexpr std::ptrdiff_t m_flInstantGoldPercentage = 0x1668; // 
                constexpr std::ptrdiff_t m_iComebackBounty = 0x166C; // 
                constexpr std::ptrdiff_t m_iComebackGoldThreshold = 0x1670; // 
                constexpr std::ptrdiff_t m_flCasterBonusPercent = 0x1674; // 
            }
            // Parent: CCitadelModifier
            // Field count: 0
            namespace CCitadel_Modifier_Slork_Visible {
            }
            // Parent: CitadelAbilityVData
            // Field count: 1
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Slork_Raging_CurrentVData {
                constexpr std::ptrdiff_t m_AuraModifier = 0x1548; // CEmbeddedSubclass<CCitadelModifier>
            }
            // Parent: CCitadelModifier
            // Field count: 1
            namespace CCitadel_Modifier_Thumper_Ability_2 {
                constexpr std::ptrdiff_t m_vLastPosition = 0xC0; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 3
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_BulletFlurryVData {
                constexpr std::ptrdiff_t m_ImpactParticle = 0x608; // 
                constexpr std::ptrdiff_t m_strAttackerHitSound = 0x6E8; // 
                constexpr std::ptrdiff_t m_strVictimHitSound = 0x6F8; // 
            }
            // Parent: C_CitadelBaseAbility
            // Field count: 1
            //
            // Metadata:
            // NetworkVarNames: m_bCardIsFlying (bool)
            namespace CCitadel_Ability_CardToss {
                constexpr std::ptrdiff_t m_bCardIsFlying = 0xEF8; // 
            }
            // Parent: CCitadelModifierVData
            // Field count: 5
            //
            // Metadata:
            // MGetKV3ClassDefaults
            namespace CCitadel_Modifier_TeleportToObjectiveVData {
                constexpr std::ptrdiff_t m_TeleportOriginParticle = 0x608; // 
                constexpr std::ptrdiff_t m_TeleportDestinationParticle = 0x6E8; // 
                constexpr std::ptrdiff_t m_TeleportStartSound = 0x7C8; // 
                constexpr std::ptrdiff_t m_TeleportCompleteSound = 0x7D8; // 
                constexpr std::ptrdiff_t m_TeleportArriveSound = 0x7E8; // 
            }
            // Parent: None
            // Field count: 3
            //
            // Metadata:
            // NetworkVarNames: m_SourceModifierID (EntitySubclassID_t)
            // NetworkVarNames: m_eValType (EModifierValue)
            // NetworkVarNames: m_flValue (float)
            namespace StatViewerModifierValues_t {
                constexpr std::ptrdiff_t m_SourceModifierID = 0x30; // 
                constexpr std::ptrdiff_t m_eValType = 0x34; // 
                constexpr std::ptrdiff_t m_flValue = 0x38; // 
            }
            // Parent: None
            // Field count: 2
            //
            // Metadata:
            // NetworkVarNames: m_Transforms (CTransform)
            // NetworkVarNames: m_hOwner (EHANDLE)
            namespace PhysicsRagdollPose_t {
                constexpr std::ptrdiff_t m_Transforms = 0x8; // C_NetworkUtlVectorBase<CTransform>
                constexpr std::ptrdiff_t m_hOwner = 0x20; // 
            }
        }
    }
}
