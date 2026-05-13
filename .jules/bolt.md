## 2024-05-18 - First Memory Entry
**Learning:** Initialize Bolt's journal for tracking CRITICAL learnings to ensure no mistakes.
**Action:** Always maintain the journal.

## 2024-05-18 - Dependency Resolution Restrictions
**Learning:** The PlatformIO build configuration uses local symlinks. Cloning dependencies to `../` fails due to permissions in `/app`. Modifying `platformio.ini` to use remote GitHub URLs is considered an over-reaching side effect and breaks the intended local workspace configuration for developers.
**Action:** Never modify `platformio.ini` dependency paths without explicit instruction. Work within the existing configuration limits or request further guidance if blocked by missing dependencies.
