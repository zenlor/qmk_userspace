{
  description = "qmk userspace";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable-small";
    flakelight.url = "github:nix-community/flakelight";
  };
  outputs = {self, flakelight, nixpkgs, ...}@inputs: flakelight ./. {
    inherit inputs;
    systems = nixpkgs.lib.systems.flakeExposed;

    devShell.packages = pkgs: with pkgs; [
      qmk
      nixpkgs-fmt
      nixd
    ];
  };
}
