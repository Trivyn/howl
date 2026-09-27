// The HOWL differential oracle: ELK and HermiT behind one pinned OWL API
// (SPEC.md §10 item 1). A harness, never part of the product build.
plugins {
    // Provisions the pinned JDK when the host has none (see build.gradle.kts).
    id("org.gradle.toolchains.foojay-resolver-convention") version "1.0.0"
}

rootProject.name = "oracle"
