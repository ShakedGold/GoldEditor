use eframe::egui;

// add the sidebar module to the mod.rs file
pub mod item;
pub mod sidebar;
pub mod workspace;

pub trait Component {
    fn render(&self, ctx: &egui::Context, ui: &mut egui::Ui) -> bool;
}
